
/*
* ***************************************************************************************************************************
* @file	PetCat.c
* @author	Bytrain
* @brief	本文件为有关宠物猫的一切函数定义
* @version	v1.0
* @date		2026.4.21
*/
#include "pch.h"
#include "PetCat.h"
// 初始化一只新猫
void initCat(CatState * MyCat, char* name) 
{
	strncpy(MyCat->name, name, MAX_NAME - 1);
	MyCat->name[MAX_NAME - 1] = '\0';	//习惯性防御
	MyCat->Hunger = 30;
	MyCat->Cleanliness = 50;
	MyCat->Mood = 40;
	MyCat->Live = 1;
}

/*void ShowStatus(CatState* MyCat)
{
	printf("下面是你的宠物 %s 的状态\n", MyCat->name);
	printf("****************************************\n");
	printf("名字：  %s \n", MyCat->name);
	printf("饥饿度：%d \n", MyCat->Hunger);
	printf("清洁度：%d \n", MyCat->Cleanliness);
	printf("心情度：%d \n", MyCat->Mood);
	if (MyCat->Hunger > 50)
	{
		printf("猫猫：( ; w ; )委屈屈....\n\n");
	}
	else
	{
		printf("猫猫：( - w - ) zZ\n\n");
	}
}

void CheckStatus(CatState* MyCat)
{
	if (MyCat->Hunger > 80)
	{
		printf("别玩了！！！你的猫猫要饿死了！\n\n");
		printf("猫猫：(=ｘェｘ=)  晕……\n\n");
	}
	if (MyCat->Cleanliness < 40)
	{
		printf("你的猫身上要长蛆了。。\n\n");
		printf("猫猫：( o_o )!!! （惊恐）\n\n");
	}
	if (MyCat->Hunger  == 100)
	{
		printf("你的猫猫它去了喵星\n\n");
		printf("猫猫：(=O_O=) ~~~  (飘魂)\n\n");
		MyCat->Live = 0;
	}

}*/
void Feed(CatState * MyCat)
{
/*	printf("你给 %s 喂了美味的猫粮。\n\n", MyCat->name);
	printf("猫猫：(=w=) mmm... 嚼嚼嚼 \n\n");*/
	/*投喂减少饥饿度，增加心情度*/
	MyCat->Hunger -= Feed_HungerValue;
	MyCat->Mood += Feed_Moodvalue;
	/*边界防溢出*/
	if (MyCat->Hunger < 0)
	{
		MyCat->Hunger = 0;
	}
	if (MyCat->Mood > 100)
	{
		MyCat->Mood = 100;
	}
}

void Play(CatState* MyCat)
{
/*	printf("你和 %s 一起愉快的玩耍了。\n\n", MyCat->name);
	printf("猫猫：(*≧ω≦)喵~ \n\n");*/
	/*玩耍增加饥饿度，增加心情度*/
	MyCat->Hunger += Play_HungerValue;
	MyCat->Mood   += Play_MoodValue;
	/*边界防溢出*/
	if (MyCat->Hunger >100)
	{
		MyCat->Hunger = 100;
	}
	if (MyCat->Mood > 100)
	{
		MyCat->Mood = 100;
	}
}

void Bath(CatState* MyCat)
{
/*	printf("你给 %s 彻底的清洗了一遍。\n\n", MyCat->name);
	printf("猫猫：( o_o )！！！ 甩干干 \n\n");*/
	/*洗澡增加清洁度，减少心情度*/
	MyCat->Cleanliness += Bath_Cleanvalue;
	MyCat->Mood		   -= Bath_Moodvalue;
	/*边界防溢出*/
	if (MyCat->Cleanliness > 100)
	{
		MyCat->Cleanliness = 100;
	}
	if (MyCat->Mood < 0)
	{
		MyCat->Mood = 0;
	}
}
