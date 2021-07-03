/*
题目来源：算法基础（北京大学）
目的：熟练使用递归
问题描述
·一天早上，你起床的时候想“我编程序这么牛，为什么不能靠这个赚点小钱呢？”因此你决定编写一个小游戏。
·游戏在一个分割成w*h个正方格子的矩形板上进行。
·每个正方格子上可以有一张游戏卡片，当然也可以没有。
·当下面的情况满足时，认为两个游戏卡片之间有一条路径相连：
	·路径只包含水平或者竖直的直线段。
	·路径不能穿过别的游戏卡片。
	·但是允许路径临时的离开矩形板。
输入（1/2）
·输入包括多组数据：一个矩形板对应一组数据。
·第一行包括两个整数w和h（1<=2.h<=75），分别表示矩形板的宽度和长度。
·下面的h行，每行包括w个字符，表示矩形板上的游戏卡片分布情况：
	·使用'X'表示这个地方有一个游戏卡片。
	·使用空格表示这个地方没有一个游戏卡片。
输入（2/2）
·之后每行上包括4个整数：x1,y1,x2,y2(1<=x1,x2<=w,1<=y1,y2<=h)
·给出两个卡片在矩形板上的位置。注意：矩形板左上角的坐标时（1，1）。输入保证这两个游戏卡片所处的位置是不相同的。如果一行上有4个0，表示这组测试数据的结束。
·如果一行上给出w=h=0，那么表示所有的输入结束了。
输出
·对每一个矩形板，输出一行“Board#n:”，n是输入数据的编号
·对每一组需要测试的游戏卡片输出一行。这一行的开头是“Pair m:”，这里m是测试卡片的编号（对没有给矩形板，编号都从1开始）。
·如果可以相连，找到连接这两个卡片的所有路径中包括线段数最少的路径，输出“k segments.”k是找到的最优路径中包括的线段的数目。
·如果不能相连，输出“impossible.”。
·每组数据之后输出一个空行。
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void Search(int, int, int, int, int,int);//递归搜索
char square[75 + 2][75 + 2];//矩形格子
int w,h,countss;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//方向上下左右
bool make[75 + 2][75 + 2];//记录路径
int main()
{
	int x=0;//记录总次数
	//输入长和宽
	while (cin >> w >> h) 
	{
		//如果长和宽都等于0就直接结束循环
		if (w == 0 && h == 0)
			break;
		//初始化矩形格子
		memset(square, ' ', sizeof(square));
		//循环赋值，左上角的坐标是（1，1）
		for (int i = 1; i < h + 1; i++)
		{
			getchar();
			for (int j = 1; j < w + 1; j++)
			{
				square[i][j]=getchar();
			}
		}
		//输出总轮数
		cout << "Board# " << ++x << ":" << endl;
		int z = 0;//记录结果的次数
		int x, y, x2, y2;//起点和终点
		//输入起点和终点
		while (cin >> x >> y >> x2 >> y2)
		{
			//如果起点和终点都是（0，0），就跳出循环
			if(x == 0 && y == 0 && x2 == 0 && y2 == 0)
				break;
			//如果起或终点没有卡片直接跳循环
			if (square[y][x] == ' ' || square[y2][x2] == ' ')
			{
				cout << "impossible" << endl;
				break;
			}
			//把路径全部负fase,没走过fase走过true
			memset(make, false, sizeof(make));
			//给记录步骤一个不可能的值
			countss = 10000000;
			//调用函数，来进行搜索
			Search(x, y, x2, y2, 0, -1);
			//输出结果
			if (countss == 10000000)
				cout << "impossible" << endl;
			else
				cout << "Pair " << ++z << ":" << countss << " segments" << endl;
		}
	}
	return 0;
}
void Search(int x1, int y1, int x2, int y2, int scount, int f)
{
	//如果现在的步数大于之前的路径数就结束
	if (scount > countss)
		return;
	//判断是否到达终点
	if (x1 == x2 && y1 == y2)
	{
		//更新步数
		if (countss > scount)
			countss = scount;
		return;
	}
	//循环四种方向来搜索
	for (int i = 0; i < 4; i++)
	{
		//移动坐标
		int x = x1 + direction[i][0];
		int y = y1 + direction[i][1];
		//判断移动后的坐标是否越界,判断这个点是否走过,是否到达终点
		if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2) && (((square[y][x] == ' ') && (make[y][x] == false)) || ((x == x2) && (y == y2) && (square[y][x] == 'X'))))
		{
			//记录位置
			make[y][x] = true;
			//判断符号,不相等步数++
			if (f == i)
				Search(x, y, x2, y2, scount, i);	//调用递归继续搜索
			else
				Search(x, y, x2, y2, scount +1, i);
			//删除记录的位置，回溯
			make[y][x] = false;
		}
	}
}
