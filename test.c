#define _CRT_SECURE_NO_WARNINGS
#include"guanli.h"
void menu()
{
	printf("**********************************************************\n");
	printf("*********** 1:add                  2:del       ***********\n");
	printf("**********  3:search               4:modify      ********\n ");
	printf("**********  5:show                 6:sort          *******\n");
	printf("**********  7:保存                 8:名字-数量柱状图   ***\n");
	printf("*********   9:价格-数量柱状图      0:Exit      ***********\n");
}
enum choose
{
	Exit,
    add,
    del,
    search,
    modify,
    show,
	sort
};



int main()
{
	int num=jiance("txt.txt");        //检测有多少count,用于动态分配
	guanlixiton guan;
	guan.count = num;
	guan.date = (drink*)calloc(num,sizeof(drink));
	if (guan.date == NULL)
	{
		printf("文件不存在，将创建新文件\n");
		return 1;
	}
	//开辟内存 
	guan.cap = capacity;
	//每次运行，"r",文件信息区输入到内存中的 guan.date[i].name  guan.date[i].price   guan.date[i].L     guan.date[i].num
   LoadFromFile(&guan, "txt.txt",num);

	int input = 0;
	do
	{
		menu();
		printf("请选择");
		scanf("%d",&input);
		while (getchar() != '\n');
		switch (input)
		{
		case add:
			guan.date = ADD(&guan);
			break;
		case del:
			DEL(&guan);
			break;
		case search:
			SEARCH(&guan);
			break;
		case modify:
			ModifyDrink(&guan);
				break;
		case show:
			
			SHOW(&guan);
			break;
		case sort:
			SORT(&guan);
			break;
		case Exit:
			printf("退出饮料系统\n");
			break;
		case 7:
			SaveToFile(&guan, "txt.txt");
			printf("保存完成\n");
			break;
		case 8: 
			zhuzhuang1(&guan);
			break;
		case 9:
			zhuzhuang2(&guan);
			break;
		default:
			printf("请重新选择\n");
			break;
			//每次运行，"w",从内存输入文件信息输入到中的， 且文本换行，因为fprintf无自动换行功能
			
		}
	}while(input);
	free(guan.date);
	return 0;
}/*您的代码没有遇到scanf后接gets问题的原因是：

没有使用gets()函数

所有字符串输入都使用scanf("%s", ...)，而% s会跳过前导空白字符

程序逻辑设计合理，避免了混合输入类型的问题*/