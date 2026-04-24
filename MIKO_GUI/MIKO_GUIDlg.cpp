
// MIKO_GUIDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MIKO_GUI.h"
#include "MIKO_GUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMIKOGUIDlg 对话框



CMIKOGUIDlg::CMIKOGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MIKO_GUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMIKOGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMIKOGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_CATNAME, &CMIKOGUIDlg::OnEnChangeCatname)

	ON_NOTIFY(NM_CUSTOMDRAW, IDC_MOOD, &CMIKOGUIDlg::OnNMCustomdrawMood)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_HUNGER, &CMIKOGUIDlg::OnNMCustomdrawHunger)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_CLEANLINESS, &CMIKOGUIDlg::OnNMCustomdrawCleanliness)

	ON_BN_CLICKED(IDC_BATH, &CMIKOGUIDlg::OnBnClickedBath)
	ON_BN_CLICKED(IDC_PLAY, &CMIKOGUIDlg::OnBnClickedPlay)
	ON_BN_CLICKED(IDC_FEED, &CMIKOGUIDlg::OnBnClickedFeed)
	ON_BN_CLICKED(IDC_INIT, &CMIKOGUIDlg::OnBnClickedInit)
	ON_BN_CLICKED(IDC_EXIT, &CMIKOGUIDlg::OnBnClickedExit)
	ON_STN_CLICKED(IDC_TEXT_MSG, &CMIKOGUIDlg::OnStnClickedTextMsg)
	
END_MESSAGE_MAP()


// CMIKOGUIDlg 消息处理程序

BOOL CMIKOGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMIKOGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMIKOGUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMIKOGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*Bytrain's Part*/

void CMIKOGUIDlg::OnBnClickedInit()
{

	CString strName;
	GetDlgItemText(IDC_CATNAME, strName); // 获取输入框的名字

	if (strName.IsEmpty()) {
		strName = _T("咪咪");
	}
	// 初始化猫咪 (注意 MFC 默认使用宽字符 Unicode，需要转换或者调整 C 字符串类型)
	USES_CONVERSION;
	initCat(&m_MyCat, T2A(strName));
	// 初始化进度条范围 0-100
	((CProgressCtrl*)GetDlgItem(IDC_HUNGER))->SetRange(0, 100);
	((CProgressCtrl*)GetDlgItem(IDC_CLEANLINESS))->SetRange(0, 100);
	((CProgressCtrl*)GetDlgItem(IDC_MOOD))->SetRange(0, 100);
	CString welcomeMsg;
	welcomeMsg.Format(_T("%s 来到了你的身边！要好好照顾它哦。\n猫猫：( - w - ) zZ"), strName);
	UpdateCatUI(welcomeMsg);
}



void CMIKOGUIDlg::OnBnClickedPlay()
{
	if (m_MyCat.Live) {
		Play(&m_MyCat);
		//准备显示的文字
		CString finalMsg;
		finalMsg.Format(_T("你和 %s 一起愉快的玩耍了。\n\n猫猫：(*≧ω≦)喵~ \n"), CString(m_MyCat.name));
		// 追加可能触发的状态警告语
		finalMsg += CheckStatusMessage(&m_MyCat);
		// 一次性把所有文字和进度条更新到界面上
		UpdateCatUI(finalMsg);
	}
}

void CMIKOGUIDlg::OnBnClickedFeed()
{
	if (m_MyCat.Live) {
		Feed(&m_MyCat);
		//准备显示的文字
		CString finalMsg;
		finalMsg.Format(_T("你给 % s 喂了美味的猫粮。\n\n猫猫：(=w=) mmm... 嚼嚼嚼 \n\n"), CString(m_MyCat.name));
		// 追加可能触发的状态警告语
		finalMsg += CheckStatusMessage(&m_MyCat);
		// 一次性把所有文字和进度条更新到界面上
		UpdateCatUI(finalMsg);
	}
}

void CMIKOGUIDlg::OnBnClickedBath()
{
	
	if (m_MyCat.Live) {
		Bath(&m_MyCat);
		//准备显示的文字
		CString finalMsg;
		finalMsg.Format(_T("你给 %s 彻底的清洗了一遍。\n\n猫猫：( o_o )！！！ 甩干干 \n\n"), CString(m_MyCat.name));
		// 追加可能触发的状态警告语
		finalMsg += CheckStatusMessage(&m_MyCat);
		// 一次性把所有文字和进度条更新到界面上
		UpdateCatUI(finalMsg);
	}
}

CString CMIKOGUIDlg::CheckStatusMessage(CatState* MyCat)
{
	CString warningMsg = _T(""); // 初始为空字符串

	// 检查饥饿度
	if (MyCat->Hunger > 60 && MyCat->Hunger < 100)
	{
		warningMsg += _T("\n⚠️ 别玩了！！！你的猫猫要饿死了！\n猫猫：(=ｘェｘ=)  晕……\n");
	}
	else if (MyCat->Hunger == 100)
	{
		warningMsg += _T("\n  你的猫猫它去了喵星...\n猫猫：(=O_O=) ~~~  (飘魂)\n");
		MyCat->Live = 0;
	}
	// 检查清洁度
	if (MyCat->Cleanliness < 40 && MyCat->Live == 1)
	{
		warningMsg += _T("\n⚠️ 你的猫身上要长蛆了。。\n猫猫：( o_o )!!! （惊恐）\n");
	}
	return warningMsg; // 把凑好的警告语交出去
}

void  CMIKOGUIDlg::UpdateCatUI(CString message)
{
	// 1. 更新提示文字
	SetDlgItemText(IDC_TEXT_MSG, message);

	// 2. 更新三个进度条的当前进度
	((CProgressCtrl*)GetDlgItem(IDC_HUNGER))->SetPos(m_MyCat.Hunger);
	((CProgressCtrl*)GetDlgItem(IDC_CLEANLINESS))->SetPos(m_MyCat.Cleanliness);
	((CProgressCtrl*)GetDlgItem(IDC_MOOD))->SetPos(m_MyCat.Mood);
}

void CMIKOGUIDlg::OnBnClickedExit()
{
	// 弹出一个确认提示框（可选，增加一点游戏仪式感）
	int result = MessageBox(_T("真的要离开你的猫猫吗？"), _T("退出游戏"), MB_YESNO | MB_ICONQUESTION);
	if (result == IDYES)
	{
		// 真正关闭窗口的代码
		CDialogEx::OnCancel();
	}
}

/*下面函数没有用上故先不写*/
void CMIKOGUIDlg::OnNMCustomdrawHunger(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CMIKOGUIDlg::OnNMCustomdrawCleanliness(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMIKOGUIDlg::OnNMCustomdrawMood(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CMIKOGUIDlg::OnStnClickedTextMsg()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMIKOGUIDlg::OnEnChangeCatname()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


