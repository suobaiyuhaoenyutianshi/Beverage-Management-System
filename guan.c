#define _CRT_SECURE_NO_WARNINGS
#include"guanli.h"
static int findname(guanlixiton* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < (pc->count); i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
			return i;
	}
	return -1;
}
//显然这些comoare是没必要这么些，应该写个宏来代替的，之后改
static int compare_name(const void* e1, const void* e2)
{
	return strcmp(((drink*)e1)->name, ((drink*)e2)->name);
}
static int compare_price(const void* e1, const void* e2)
{
	float diff = ((drink*)e1)->price - ((drink*)e2)->price;

	if (diff > 0.0001f) return 1;       // e1 明显大于 e2
	else if (diff < -0.0001f) return -1;  // e1 明显小于 e2
	else return 0;                      // 在容差范围内
}
static int compare_num(const void* e1, const void* e2)
{
	return ((drink*)e1)->num - ((drink*)e2)->num;
}
static int compare_L(const void* e1, const void* e2)
{
	return ((drink*)e1)->L - ((drink*)e2)->L;
}
static void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;

	}

}
static void asort(void* base, int sz, int width, int (*comp)(const void* e1, const void* e2))//传的是drink date[100]的指针，类型是drink，不是guanlixito
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (comp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}

		}
		if (flag == 1)
		{
			break;
		}
	}

}//ch
drink* ADD(guanlixiton* pc)
{

	assert(pc);
	drink *p=realloc(pc->date, (sizeof(drink)) * (pc->count + pc->cap));
	if (p == NULL)
	{
		printf("文件不存在，将创建新文件\n");
		return;
	}
	printf("请输入名字>");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入每瓶的价格>");
	scanf("%f", &pc->date[pc->count].price);
	printf("请输入每瓶多少升>");
	scanf("%d", &pc->date[pc->count].L);
	printf("请输入现有数量>");
	scanf("%d", &pc->date[pc->count].num);
	pc->count++;
	printf("\n");
	printf("\n");
	printf("\n");
	return p;
}
void SHOW(guanlixiton* pc)
{
	assert(pc);
	printf("%-20s\t%-4s\t%-4s\t%-4s\n",
		" 名字", "价格", "升", "数量");
	for (int i = 0; i < (pc->count); i++)
	{
		printf("%-20s\t%-.2f\t%-4d\t%-4d\n",
			pc->date[i].name, pc->date[i].price, pc->date[i].L, pc->date[i].num);
	}
	printf("\n");
	printf("\n");
	printf("\n");
}
void SEARCH(guanlixiton* pc)
{
	char name[20] = { 0 };
	assert(pc);
	printf("请输入查找饮料的名字\n");
	scanf("%s", name);
	int pos = findname(pc, name);
	if (pos == -1)
	{
		printf("并没有该信息\n");
		return;
	}
	printf("已查询到\n");
	printf("%-20s\t%-4s\t%-4s\t%-4s\n", 
		" 名字", "价格", "升", "数量");
	printf("%-20s\t%-.2f\t%-4d\t%-4d\n",
		pc->date[pos].name, pc->date[pos].price, pc->date[pos].L, pc->date[pos].num);
	printf("\n");
	printf("\n");
	printf("\n");
}
void DEL(guanlixiton* pc)
{
	assert(pc);
	printf("请输入删除什么名字的饮料信息");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = findname(pc, name);
	if (pos == -1)
	{
		printf("并没有该信息\n");
		return;
	}
	printf("已查询到\n");
	printf("%-20s\t%-4s\t%-4s\t%-4s\n",
		" 名字", "价格", "升", "数量");
	printf("%-20s\t%-.2f\t%-4d\t%-4d\n",
		pc->date[pos].name, pc->date[pos].price, pc->date[pos].L, pc->date[pos].num);
	for (int i = pos; i < (pc->count) - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];

	}
	pc->count--;
	printf("已删除\n");

}
void ModifyDrink(guanlixiton* pc)
{
	assert(pc);
	printf("请输入修改饮料信息的名字");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = findname(pc, name);
	if (pos == -1)
	{
		printf("并没有该信息\n");
		return;
	}
	printf("已查询到\n");
	printf("%-20s\t%-4s\t%-4s\t%-4s\n",
		" 名字", "价格", "升", "数量");
	printf("%-20s\t%-.2f\t%-4d\t%-4d\n",
		pc->date[pos].name, pc->date[pos].price, pc->date[pos].L, pc->date[pos].num);
	printf("请修改名字>");
	scanf("%s", pc->date[pos].name);
	printf("请修改每瓶的价格>");
	scanf("%f", &pc->date[pos].price);
	printf("请修改每瓶多少升>");
	scanf("%d", &pc->date[pos].L);
	printf("请修改现有数量>");
	scanf("%d", &pc->date[pos].num);
	printf("修改完毕\n");
	printf("%-20s\t%-4s\t%-4s\t%-4s\n",
		" 名字", "价格", "升", "数量");
	printf("%-20s\t%-.2f\t%-4d\t%-4d\n", pc->date[pos].name, pc->date[pos].price, pc->date[pos].L, pc->date[pos].num);

}
void SORT(guanlixiton* pc)
{
	//价格排序
	//数量排序
	//升排序
	//名字排序
	assert(pc);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("**1:价格排序           2:数量排序     *************\n");
	printf("**3:按每多少升排序     4:名字排序    ***************\n");
	printf("请选择\n");
	int i = 0;
	scanf("%d", &i);
	switch (i)//传的是drink date[]的指针，类型是drink，不是guanlixito
	{
	case 1:
		asort(pc->date, pc->count, sizeof(drink), compare_price);
		break;
	case 2:
		asort(pc->date, pc->count, sizeof(drink), compare_num);
		break;
	case 3:
		asort(pc->date, pc->count, sizeof(drink), compare_L);
		break;
	case 4:
		asort(pc->date, pc->count, sizeof(drink), compare_name);
		break;
	default:
		printf("无该选项\n");
		break;
	}
	printf("\n");
	printf("\n");
	printf("\n");
}
void LoadFromFile(guanlixiton* pc, const char* filename,int count)
{
	assert(pc);
	FILE* pf = fopen(filename, "r");
	if (pf == NULL)
	{
		printf("文件不存在，将创建新文件\n");
		return;
	}
	int num = 0;
	while (num<count)
	{

		// 读取一行数据
		int result = fscanf(pf, "%19[^,],%f,%d,%d\n",
			pc->date[num].name,
			&pc->date[num].price,
			&pc->date[num].L,
			&pc->date[num].num);//自动换行

	  if (result != EOF&& result !=4 )
		{
			// 读取失败但还没到文件末尾，跳过这一行,佛则就卡住了
			char buffer[256];
			fgets(buffer, sizeof(buffer), pf);
			printf("警告：跳过格式错误的行\n");
		}
	  num++;
	}

	fclose(pf);
	printf("从文件加载了 %d 条记录\n", pc->count);
}
// 输入数据到文件
void SaveToFile(guanlixiton* pc, const char* filename)
{
	assert(pc);
	FILE* pf = fopen(filename, "w");
	if (pf == NULL)
	{
		perror("保存文件失败");
		return;
	}

	for (int i = 0; i < pc->count; i++)
	{
		fprintf(pf, "%s,%.2f,%d,%d\n",
			pc->date[i].name,
			pc->date[i].price,
			pc->date[i].L,
			pc->date[i].num);
	}

	fclose(pf);
	printf("已保存 %d 条记录到文件\n", pc->count);//没保存，是下次输入内存，在计算
}
void zhuzhuang1(guanlixiton* pc)
{
	assert(pc);
	printf("\n\n\n");
	int max_num = 0;
	for (int i = 0; i < (pc->count); i++)
	{
		if (pc->date[i].num > max_num)
			max_num = pc->date[i].num;
	}

	for (int row = max_num; row >= 1; row--)
	{
		for (int i = 0; i < (pc->count); i++)
		{
			if (pc->date[i].num >= row)
				printf("#######  ");
			else
			{
				printf("         ");
			}
			printf("     ");
		}
		printf("\n");

	}
	for (int i = 0; i < (pc->count); i++)
	{
		printf("%-8s      ", pc->date[i].name);
	}
	printf("\n");
	for (int i = 0; i < (pc->count); i++)
	{
		printf("  %-8d    ", pc->date[i].num); 
	}
	printf("\n");
}
int jiance(const char* filename)
{
	int count = 0;
	char line[256];
	FILE* pf = fopen(filename, "r");
	while (count < 100 && fgets(line, sizeof(line),pf) )//fgets自动换行  
		//它会一直读取，直到遇到以下情况之一：遇到换行符 \n（然后停止读取） 
		// // 达到指定的最大字符数（这里是 sizeof(line) - 1 = 255）  
		// 	遇到文件结束符 EOF  关键点：读取完当前行后，文件指针会自动定位到下一行的开头位
	{
		// 移除可能的换行符,strcspnNB
		line[strcspn(line, "\n")] = '\0';

		char temp_name[20];
		float temp_price;
		int temp_L, temp_num;
		//sscanf将字符以，为界，将字符转化%19[^,]等的类型
		if (sscanf(line, "%19[^,],%f,%d,%d",
			temp_name, &temp_price, &temp_L, &temp_num) == 4)
		{
			count++;
			printf("第%d行有效: %s\n", count, temp_name);
		}
		else 
		{
			printf("格式错误: %s\n", line);
		}
	}
	fclose(pf);
	printf("总计有效行数: %d\n", count);
	return count;
}
//用3及指针，创造关于饮料名称字符串的指针（即字符串的地址）的指针数组，，数组放指针，那么大小就不用多管了    里面还有个数组，目的使找对位置  
// 柱子的指针-字符串指针     指针数组套指针数组                           
void zhuzhuang2(guanlixiton* pc)
{
	assert(pc);
	printf("\n\n\n");
	float max = 0.0;

	// 找到最高价格
	for (int i = 0; i < (pc->count); i++)
	{
		if (max < (pc->date[i].price))
		{
			max = (pc->date[i].price);
		}
	}

	printf("请输入分组间距: ");
	float boundary = 0.0;
	scanf("%f", &boundary);

	int zhu_shu = (int)(max / boundary) + 1;

	// 分配存储数量的数组
	int* fenlei = (int*)calloc(zhu_shu, sizeof(int));
	if (fenlei == NULL)
	{
		printf("分配错误");
		return;
	}
	char** names = (char**)calloc(zhu_shu, sizeof(char*));
	if (names == NULL)
	{
		printf("分配错误");
		free(fenlei);
		return;
	}


	// 用于记录每个柱子的第几位饮料指针
	int* drink_count_per_column = (int*)calloc(zhu_shu, sizeof(int));
	// 用于创建级指针数组空间
	char*** drinks_per_column = (char***)calloc(zhu_shu, sizeof(char**));
	for (int i = 0; i < zhu_shu; i++)
	{
		drinks_per_column[i] = (char**)calloc(pc->count, sizeof(char*));
		drink_count_per_column[i] = 0;
	}

	// 遍历所有饮料，分配它们到对应的柱子
	for (int j = 0; j < pc->count; j++)
	{
		int group_index = (int)(pc->date[j].price / boundary);

		if (pc->date[j].price == boundary * (group_index + 1) && group_index > 0)
		{
			group_index--;
		}

		fenlei[group_index] += pc->date[j].num;
		drinks_per_column[group_index][drink_count_per_column[group_index]] = pc->date[j].name;
		drink_count_per_column[group_index]++;
	}

	printf("各柱子数量统计: ");
	for (int m = 0; m < zhu_shu; m++)
	{
		printf("%d   ", fenlei[m]);
	}
	printf("\n\n");

	int max2 = 0;
	for (int o = 0; o < zhu_shu; o++)
	{
		if (max2 < fenlei[o])
		{
			max2 = fenlei[o];
		}
	}

	printf("请输入每格代表的数量: ");
	int yihang = 0;
	scanf("%d", &yihang);

	for (int row = max2 / yihang; row >= 1; row--)
	{
		for (int i = 0; i < zhu_shu; i++)
		{
			if (fenlei[i] / yihang >= row)
				printf("#######  ");
			else
				printf("         ");
			printf("     ");
		}
		printf("\n");
	}

	for (int i = 0; i < zhu_shu; i++)
	{
		printf("  %-8d    ", fenlei[i]);
	}
	printf("\n");

	for (int f = 0; f < zhu_shu; f++)
	{
		float start_price = f * boundary;
		float end_price = (f + 1) * boundary;
		printf("%.2f_%.2f   ", start_price, end_price);
	}
	printf("\n");

	
	int max_drink_count = 0;
	for (int i = 0; i < zhu_shu; i++)
	{
		if (drink_count_per_column[i] > max_drink_count)
		{
			max_drink_count = drink_count_per_column[i];
		}
	}

	for (int row = 0; row < max_drink_count; row++)
	{
		for (int col = 0; col < zhu_shu; col++)
		{
			if (row < drink_count_per_column[col])
			{
				printf("%-15s", drinks_per_column[col][row]);
			}
			else
			{
				printf("%-15s", "");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < zhu_shu; i++)
	{
		free(names[i]);
		free(drinks_per_column[i]);
	}
	free(names);
	free(drinks_per_column);
	free(drink_count_per_column);
	free(fenlei);
}