#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define capacity 1


typedef struct drink 
{
	char name[20];
	float price;
	int L;//多少L一瓶
	int num;//现在的数量
} drink;


typedef struct guanlixiton
{
	drink *date;//一共的饮料信息
	int count;//多少饮料
	int cap;//新增容量
}guanlixiton;
int jiance(const char* filename);
drink* ADD(guanlixiton* pc);
void DEL(guanlixiton* pc);
void SEARCH(guanlixiton* pc);
void ModifyDrink(guanlixiton* pc);
void SHOW(guanlixiton* pc);
void SORT(guanlixiton* pc);
void zhuzhuang1(guanlixiton* pc);
void zhuzhuang2(guanlixiton* pc);
