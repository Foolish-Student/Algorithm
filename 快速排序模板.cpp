//通用模板  讲解在 exercise 仓库 
#include<iostream>
using namespace std;
void quicksort(int*, int, int);
int main()
{
	int a[] = { 45,9984,21,45,326,4,86,47 };
	int len = sizeof(a) / sizeof(int);
	quicksort(a, 0, len - 1);
	cout << "排序后：";
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
void quicksort(int* a, int l, int r)
{
	if (l < r)
	{
		int temp = a[l], left = l, right = r;
		while (left < right)
		{
			while (left < right && a[right] >= temp)
				right--;
			if (left < right)
				a[left++] = a[right];
			while (left < right && a[left] < temp)
				left++;
			if (left < right)
				a[right--] = a[left];
		}
		a[left] = temp;
		quicksort(a, l, left - 1);
		quicksort(a, left + 1, r);
	}
}

