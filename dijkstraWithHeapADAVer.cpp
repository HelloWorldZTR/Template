#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
const int MAXM = 500001;
const int INF  = 2147483647;

struct edge{
	int from;
	int to;
	int w;
	int next;
};
edge e[MAXM];

struct node{
	int w;
	int id;
	friend bool operator <(const node& a, const node& b) {
		return a.w>b.w;
	}
};

int cnt = 0;

int head[MAXN], vis[MAXN], m, n, s;

long long dis[MAXN];

void add(int from, int to, int w) {
	e[++cnt].from = from;
	e[cnt].to = to;
	e[cnt].w = w;
	e[cnt].next = head[from];
	head[from] = cnt;//head指from点的所有边 
}

priority_queue<node> q;
void dijkstra(int s) {
    for(int i=1;i<=n;i++) {
        dis[i]=INF;
    }
    dis[s]=0;//赋初值
    q.push((node){0,s});
    while(!q.empty()) {
        node x=q.top();
        q.pop();
        int u=x.id;
        if(vis[u])
			continue; 
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next) {
            int v=e[i].to;
            if(dis[v]>dis[u]+e[i].w) {
                dis[v]=dis[u]+e[i].w;
                q.push((node){dis[v],v});
            }
        }
    }
}
void printAns() {
	for(int i=1; i<=n; i++) {//从1开始 
		cout<<dis[i]<<" ";
	}
	cout<<endl;
}
int main() {
	cin>>n>>m>>s;
	int x, y, z;
	for(int i=0; i<m; i++) {
		cin>>x>>y>>z;
		add(x, y, z);
	}
	dijkstra(s);
	printAns();
	return 0;
}

