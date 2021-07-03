/*
题目来源：算法基础（北京大学）
涉及：递归、动态规划
问题描述
    7
   3 8
  8 1 0
 2 7 4 4
4 5 2 6 5
    在上面的数字三角形中寻找一条从顶部到底部的路径，使得路径上所经过的数字之和最大。路径上的每一步
 都只能往左下或右下走。只需要求出这个最大和即可，不必给出具体路径。
    三角形的行数大于1小于等于100，数字为0-99
输入格式
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
要求输出最大和
*/

//解法1.递归、记忆优化

#include<iostream>
#include<algorithm>
using namespace std;
int maxnum[110][110];//存储三角形
int storage[100][100];//用来存储已经加号的数
int number(int, int, int);//递归调用
int main()
{
    int n;//层数
    cin >> n;
    //循环录入并赋初值
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> maxnum[i][j];
            storage[i][j] = -1;
        }
    }
    //调用并输出
    cout << number(1, 1, n) << endl;
    return 0;
}
int number(int i, int j, int n)
{
    //如果这个数存储过直接返回这个数
    if (storage[i][j] != -1)
        return storage[i][j];
    //如果到达最后一层直接返回
    if (i == n)
    {
        //赋值给他做存储
        storage[i][j] = maxnum[i][j];
        return storage[i][j];
    }
    else
    {
        //调用递归，去寻找她左下那个
        int x = number(i + 1, j, n);
        int y = number(i + 1, j + 1, n);//右下
        //找到最大值加上原来的值,并存储
        storage[i][j] = max(x, y) + maxnum[i][j];
    }
}

//解法2：动态优化
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;//行数
    int maxnum[110][110];//存储三角形
    int* storage;//用来存储数据
    cin >> n;
    //录入
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> maxnum[i][j];
        }
    }
    //最后一行的数据加完了就没用了 可以拿来存储
    storage = &maxnum[n][0];
    //从左下角往上找
    for (int i = n; i > 1; i--)
    {
        //从左往右两个为一组找出最大值
        for (int j = 1; j < i; j++)
        {
            //用最大值加上你上面的那个元素 存储到最后一行 以此类推
            storage[j] = max(storage[j], storage[j+1]) + maxnum[i - 1][j];
        }
    }
    //输出最大值
    cout << storage[1] << endl;
    return 0;
}
