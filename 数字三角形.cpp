/*
��Ŀ��Դ���㷨������������ѧ��
�漰���ݹ顢��̬�滮
��������
    7
   3 8
  8 1 0
 2 7 4 4
4 5 2 6 5
    �������������������Ѱ��һ���Ӷ������ײ���·����ʹ��·����������������֮�����·���ϵ�ÿһ��
 ��ֻ�������»������ߡ�ֻ��Ҫ���������ͼ��ɣ����ظ�������·����
    �����ε���������1С�ڵ���100������Ϊ0-99
�����ʽ
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Ҫ���������
*/

//�ⷨ1.�ݹ顢�����Ż�

#include<iostream>
#include<algorithm>
using namespace std;
int maxnum[110][110];//�洢������
int storage[100][100];//�����洢�Ѿ��Ӻŵ���
int number(int, int, int);//�ݹ����
int main()
{
    int n;//����
    cin >> n;
    //ѭ��¼�벢����ֵ
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> maxnum[i][j];
            storage[i][j] = -1;
        }
    }
    //���ò����
    cout << number(1, 1, n) << endl;
    return 0;
}
int number(int i, int j, int n)
{
    //���������洢��ֱ�ӷ��������
    if (storage[i][j] != -1)
        return storage[i][j];
    //����������һ��ֱ�ӷ���
    if (i == n)
    {
        //��ֵ�������洢
        storage[i][j] = maxnum[i][j];
        return storage[i][j];
    }
    else
    {
        //���õݹ飬ȥѰ���������Ǹ�
        int x = number(i + 1, j, n);
        int y = number(i + 1, j + 1, n);//����
        //�ҵ����ֵ����ԭ����ֵ,���洢
        storage[i][j] = max(x, y) + maxnum[i][j];
    }
}

//�ⷨ2����̬�Ż�
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;//����
    int maxnum[110][110];//�洢������
    int* storage;//�����洢����
    cin >> n;
    //¼��
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> maxnum[i][j];
        }
    }
    //���һ�е����ݼ����˾�û���� ���������洢
    storage = &maxnum[n][0];
    //�����½�������
    for (int i = n; i > 1; i--)
    {
        //������������Ϊһ���ҳ����ֵ
        for (int j = 1; j < i; j++)
        {
            //�����ֵ������������Ǹ�Ԫ�� �洢�����һ�� �Դ�����
            storage[j] = max(storage[j], storage[j+1]) + maxnum[i - 1][j];
        }
    }
    //������ֵ
    cout << storage[1] << endl;
    return 0;
}
