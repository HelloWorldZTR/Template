#include<iostream>
#include<cstring> 
/*
*	��˵������ʽǰ�������ᱬը \
*		������ը�� 
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
	for(int i=1; i<=n; i++) {//��ÿһ��������ɳ� 
		int min_ = INF;
		int nearest = -1;
		for(int j=head[i]; j!=0; j=edge[j].next) {//�Ҿ��� i ����ǰ�㣩 ����Ĳ��ڼ����еĵ���� 
			if(!selected[j] && edge[j].w<min_) {
				min_ = edge[j].w;
				nearest = j;
			}
		}
		selected[nearest]  = true;
		if(nearest!=-1) {		//�ٰ� ����ĵ� ��Ϊ�м�㣬 �����ɳ� 
			for(int j=head[nearest]; j!=0; j=edge[j].next) {
				//if(edge[j].to == ) { //������ͨ�����ɳ� 
					if(dis[j]>dis[nearest]+edge[j].w) {//�ɳ� 
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
	for(int i=head[s]; i!=0; i=edge[i].next) {//��dis[i] Ϊ i��ԭ��ľ��� 
		if(i==s) {
			dis[i] = 0;//�Լ����Լ��϶�Ϊ0 
		}else{
			dis[i] = edge[i].w;
		}
	}
	selected[s] = true;//ԭ�㱾���Ѿ����뼯�� 
	dijk(s);
	debug();
	return 0;
}

