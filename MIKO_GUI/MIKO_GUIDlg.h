
// MIKO_GUIDlg.h: 头文件
//

#pragma once

#include "PetCat.h"

// CMIKOGUIDlg 对话框
class CMIKOGUIDlg : public CDialogEx
{
// 构造
public:
	CMIKOGUIDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CatState m_MyCat;                  // 定义猫咪结构体
	void UpdateCatUI(CString message); // 申明 UI 刷新函数
	CString CheckStatusMessage(CatState* MyCat);	   // 申明获取检测状态函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MIKO_GUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedBath();
	afx_msg void OnEnChangeCatname();
	afx_msg void OnNMCustomdrawMood(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedFeed();
	afx_msg void OnBnClickedInit();
	afx_msg void OnNMCustomdrawHunger(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawCleanliness(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnStnClickedTextMsg();
	afx_msg void OnBnClickedExit();
};
