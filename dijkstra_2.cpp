#include<iostream>
#include<cstring> 
/*
*	据说不用链式前向星做会爆炸 \
*		但还是炸了 
*/
using namespace std;

const int INF = 2147483647;

struct Edge{
	int next;
	int to;
	int w;
}edge[500010]; 


int dis[10010], n, m, s, head[10010], cnt;

bool selected[10010];

void debug(){for(int i=1;i<=n;i++){cout<<dis[i]<<" ";}}

void add(int from, int to, int value) {
	cnt++;
	edge[cnt].next = head[from];
	edge[cnt].to   = to;
	edge[cnt].w    = value;
	head[from] = cnt; 
}

int dijk(int s) {
	for(int i=1; i<=n; i++) {//对每一个点进行松弛 
		int min_ = INF;
		int nearest = -1;
		for(int j=head[i]; j!=0; j=edge[j].next) {//找距离 i （当前点） 最近的不在集合中的点加入 
			if(!selected[j] && edge[j].w<min_) {
				min_ = edge[j].w;
				nearest = j;
			}
		}
		selected[nearest]  = true;
		if(nearest!=-1) {		//再把 最近的点 作为中间点， 进行松弛 
			for(int j=head[nearest]; j!=0; j=edge[j].next) {
				//if(edge[j].to == ) { //必须连通才能松弛 
					if(dis[j]>dis[nearest]+edge[j].w) {//松弛 
						dis[j] = dis[nearest]+edge[j].w;
					}
				//} 
			}
		}
	}
}

int main() {
	memset(dis, INF, sizeof(dis));
	//memset(con, 1e6, sizeof(con));
	cin>>n>>m>>s;
	int start, end, value;
	for(int i=0; i<m; i++) {
		cin>>start>>end>>value;
		add(start, end, value);
	}
	for(int i=head[s]; i!=0; i=edge[i].next) {//设dis[i] 为 i到原点的距离 
		if(i==s) {
			dis[i] = 0;//自己连自己肯定为0 
		}else{
			dis[i] = edge[i].w;
		}
	}
	selected[s] = true;//原点本身已经加入集合 
	dijk(s);
	debug();
	return 0;
}

