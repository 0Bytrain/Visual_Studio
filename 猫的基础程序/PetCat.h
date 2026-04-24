#pragma once
/*
* ***************************************************************************************************************************
* @file	PetCat.c
* @author	Bytrain
* @brief	本文件为有关宠物猫的一切参数定义
* @version	v1.0
* @date		2026.4.21
*/
#ifndef __CAT_H
#define __CAT_H

#include "string.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "main.h"
#define MAX_NAME						20  //名字最大长度
#define Feed_HungerValue				20	//定义每次投喂会减少的饥饿度
#define Feed_Moodvalue					10  //定义每次投喂会增加的心情度

#define Bath_Moodvalue					30  //定义每次洗澡会降低的心情度
#define Bath_Cleanvalue					60	//定义每次洗澡会提升的清洁度

#define Play_MoodValue					20  //定义每次玩耍会增加的心情度
#define Play_HungerValue				40	//定义每次玩耍会增加的饥饿度
typedef struct
{
	char name[MAX_NAME];//名字小于长度20
	int Hunger;			//饥饿度越高则越饥饿；0~100
	int Cleanliness;	//清洁度；0~100
	int Mood;			//心情指数；0~100
	int Live;			//存活状态
}CatState;

 void initCat(CatState* MyCat, char* name);
 void ShowStatus(CatState* MyCat);
 void Feed(CatState* MyCat);
 void Play(CatState* MyCat);
 void Bath(CatState* MyCat);
void CheckStatus(CatState* MyCat);
#endif