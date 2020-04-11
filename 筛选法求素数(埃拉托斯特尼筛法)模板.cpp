//10000以内的素数
#include<iostream>
using namespace std;
void prime();
bool number[10005];
int main()
{
	prime();
	for (int i = 2; i <= 10000; i++)
	{
		if (!number[i])
			cout << i << " ";
	}
	return 0;
}
void prime()
{
	for (int i = 2; i <= 10000; i++)
	{
		if (!number[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				number[j] = true;
			}
		}	
	}
}
