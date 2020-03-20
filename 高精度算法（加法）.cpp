/*高精算法*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string addition(string, string);
int main()
{
	cout << addition("1000000000000000000000000000000000000000000000000000000000000000000000000000000000", "20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	return 0;
}
//加法
string addition(string a, string b)
{
	//先把字符串首位的0全部去掉
	a = a.substr(a.find_first_not_of('0'));
	b = b.substr(b.find_first_not_of('0'));
	//按位相加，为了好进位，把字符串反转一下
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	//用一个long long类型才存储长度
	long long alen = a.length();
	long long blen = b.length();
	long long anslen = max(alen, blen) + 10;//防止进位溢出
	//用一个新的字符串来存储答案
	string ans(anslen, '0');//初始化为0
	//把a字符串拷贝到ans字符串去
	for (int i = 0; i < alen; i++)
		ans[i] = a[i];
	int temp = 0;//用来进位
	//按位加
	for (int i = 0; i < anslen; i++)
	{
		if (i < blen)//如果i大于b的长度b就越界了
		{
			//两个数加一起在加上进位
			temp = (ans[i] - '0') + (b[i] - '0') + temp;
		}
		else
		{
			//如果长度大于b字符串直接忽略b
			temp = (ans[i] - '0') + temp;
		}
		//如果加一起大于0就进个位
		ans[i] = temp % 10 + '0';
		temp = temp / 10;
	}
	//结果已经从出来了但是是反的，把她翻转一下
	reverse(ans.begin(), ans.end());
	//去掉开头的0
	ans = ans.substr(ans.find_first_not_of('0'));
	//返回结果
	return ans;
}
