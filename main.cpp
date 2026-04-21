
#include "main.h"
#include "PetCat.h"
int main()
{
   
	CatState MyCat;
	char name[MAX_NAME];
    int choice = 5;
    printf("====== 电子宠物猫 ======\n");
    printf("给你的猫咪起个名字: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // 去掉换行符
    if (strlen(name) == 0) {
        strcpy(name, "咪咪");
    }
    initCat(&MyCat, name);
    printf("\n%s 来到了你的身边！要好好照顾它哦。\n\n", MyCat.name);
    ShowStatus(&MyCat);
    printf("请选择操作:\n");
    printf("1. 投喂\n");
    printf("2. 洗澡\n");
    printf("3. 玩耍\n");
    printf("4. 查看状态\n");
    printf("0. 退出游戏\n");
    printf("请输入数字选择: ");
    while (MyCat.Live)
    {
        scanf("%d", &choice);
        getchar(); // 吃掉回车
        switch (choice) {
        case 1:
            Feed(&MyCat);
            break;
        case 2:
            Bath(&MyCat);
            break;
        case 3:
            Play(&MyCat);
            break;
        case 4:
            ShowStatus(&MyCat);
            break;
        case 0:
            printf("你离开了 %s...\n", MyCat.name);
            system("pause");
            return 0;
        default:
            printf("无效选项，请重新选择。\n");
            continue;
        }
    }
    printf("游戏结束。\n");
	return 0;
}
