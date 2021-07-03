#include<iostream>
#include<algorithm> 
#include<cstring>
#define inf 0x3f3f3f3f
#define MAX 10100
using namespace std;

int mp[MAX][MAX];//用来存放边的距离
int vis[MAX];//判断是否访问过
int dis[MAX];//存放距离 

void Dijkstra(int n){
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for(int i = 0; i < n; i++){
		int x = -1;//如果没有开始寻找设置为-1 
		for(int j = 1; j <= n; j++){
			if(!vis[j] && (x == -1 || dis[x] > dis[j])) //X没有目标随便给一个点。再接着寻找距离最短的那个点 
				x = j; 
		}
		vis[x] = 1;
		for(int j = 1; j <= n; j++){
			dis[j] = min(dis[j], dis[x] + mp[x][j]);//拓展拿到的到到他能访问点的距离，找出最小值 
		} 
	}
}

int main(){
	int n, m; //n节点个数 m边数 
	cin >> n >> m;
	memset(mp, 0x3f, sizeof(mp)); 
	while(m--){
		int a, b, c;//a、b为边，c为距离 
		cin >> a >> b >> c;
		mp[a][b] = c;
	}
	Dijkstra(n);
	cout << dis[n];
	return 0;
}
