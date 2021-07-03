#include<iostream>
#include<algorithm> 
#include<cstring>
#define inf 0x3f3f3f3f
#define MAX 10100
using namespace std;

int mp[MAX][MAX];//������űߵľ���
int vis[MAX];//�ж��Ƿ���ʹ�
int dis[MAX];//��ž��� 

void Dijkstra(int n){
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for(int i = 0; i < n; i++){
		int x = -1;//���û�п�ʼѰ������Ϊ-1 
		for(int j = 1; j <= n; j++){
			if(!vis[j] && (x == -1 || dis[x] > dis[j])) //Xû��Ŀ������һ���㡣�ٽ���Ѱ�Ҿ�����̵��Ǹ��� 
				x = j; 
		}
		vis[x] = 1;
		for(int j = 1; j <= n; j++){
			dis[j] = min(dis[j], dis[x] + mp[x][j]);//��չ�õ��ĵ������ܷ��ʵ�ľ��룬�ҳ���Сֵ 
		} 
	}
}

int main(){
	int n, m; //n�ڵ���� m���� 
	cin >> n >> m;
	memset(mp, 0x3f, sizeof(mp)); 
	while(m--){
		int a, b, c;//a��bΪ�ߣ�cΪ���� 
		cin >> a >> b >> c;
		mp[a][b] = c;
	}
	Dijkstra(n);
	cout << dis[n];
	return 0;
}
