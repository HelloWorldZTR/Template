#include<iostream>
#include<cstring> 
/*
*	据说不用链式前向星做会爆炸 
*/
using namespace std;

const int INF = 2147483647;

int con[10010][10010], dis[10010], n, m, s, selected[10010];

void debug(){for(int i=1;i<=n;i++){cout<<dis[i]<<" ";}}

int dijk(int s) {
	for(int i=1; i<=n; i++) {//对每一个点进行松弛 
		int min_ = INF;
		int nearest = -1;
		for(int j=1; j<=n; j++) {//找距离 i （当前点） 最近的不在集合中的点加入 
			if(selected[j]!=1 && con[i][j]<min_) {
				min_ = con[i][j];
				nearest = j;
			}
		}
		selected[nearest]  = 1;
		if(nearest!=-1) {		//再把 最近的点 作为中间点， 进行松弛 
			for(int j=1; j<=n; j++) {
				if(con[nearest][j] < 1e6) { //必须连通才能松弛 
					if(dis[j]>dis[nearest]+con[nearest][j]) {//松弛 
						dis[j] = dis[nearest]+con[nearest][j];
					}
				} 
			}
		}
	}
}

int main() {
	memset(dis, INF, sizeof(dis));
	memset(con, 1e6, sizeof(con));
	cin>>n>>m>>s;
	int start, end, value;
	for(int i=0; i<m; i++) {
		cin>>start>>end>>value;
		con[start][end] = value;
	}
	for(int i=1; i<=n; i++) {//设dis[i] 为 i到原点的距离 
		if(i==s) {
			dis[i] = 0;//自己连自己肯定为0 
		}else{
			dis[i] = con[s][i];
		}
	}
	selected[s] = 1;//原点本身已经加入集合 
	dijk(s);
	debug();
	return 0;
}

