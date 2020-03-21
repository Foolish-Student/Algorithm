//高精度乘法
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int m = 1e6;
string s1;//存储字符串1
string s2;//存储字符串2
int a[m];//乘数1
int b[m];//乘数2
int c[m];//存储结果
bool aa = true;//判断字符串1是否为负数
bool bb = true;//判断字符串2是否为负数
int main()
{
	//字符串处理
	cin >> s1 >> s2;
	//判断是否为负数,是负数就记录，去掉符号
	if (s1[0] == '-') {
		s1 = s1.substr(1);
	}
	else aa = false;
	if (s2[0] == '-') {
		s2 = s2.substr(1);
	}
	else bb = false;
	//乘数反转
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	//记录长度
	long long alen = s1.length();
	long long blen = s2.length();
	//处理乘数
	for (int i = 0; i < alen; i++) a[i] = s1[i]-'0';
	for (int i = 0; i < blen; i++) b[i] = s2[i]-'0';
	//记录进位
	int jw;
	//开始从相乘
	for (long long i = 0; i < alen; i++) {
		jw = 0;
		for (long long j = 0; j < blen; j++) {
			c[i + j] = c[i + j] + a[i] * b[j] + jw;//积等于  两个数的积加上进位加上自己
			jw = c[i + j] / 10;
			c[i + j] %= 10;
		}
		c[i + blen] = jw;//可能多一位
	}
	//去掉末尾多余的0
	long long clen = alen + blen;
	for (long long i = clen - 1; i >= 0; i--) {
		if (c[i] == 0&&clen>1) clen--; //如果遇到了不是0的数直接跳出循环,这个数还有可能是0
		else break;
	}
	//判断符号
	if (((aa == true && bb == false) || (aa == false && bb == true))&&(clen==1&&c[0])) cout << "-";
	//输出 从后往前输出
	for (long long i = clen - 1; i >= 0; i--) cout << c[i];
	return 0;
}