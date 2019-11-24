#include<iostream>
#include<cstring> 
/*
*	��˵������ʽǰ�������ᱬը 
*/
using namespace std;

const int INF = 2147483647;

int con[10010][10010], dis[10010], n, m, s, selected[10010];

void debug(){for(int i=1;i<=n;i++){cout<<dis[i]<<" ";}}

int dijk(int s) {
	for(int i=1; i<=n; i++) {//��ÿһ��������ɳ� 
		int min_ = INF;
		int nearest = -1;
		for(int j=1; j<=n; j++) {//�Ҿ��� i ����ǰ�㣩 ����Ĳ��ڼ����еĵ���� 
			if(selected[j]!=1 && con[i][j]<min_) {
				min_ = con[i][j];
				nearest = j;
			}
		}
		selected[nearest]  = 1;
		if(nearest!=-1) {		//�ٰ� ����ĵ� ��Ϊ�м�㣬 �����ɳ� 
			for(int j=1; j<=n; j++) {
				if(con[nearest][j] < 1e6) { //������ͨ�����ɳ� 
					if(dis[j]>dis[nearest]+con[nearest][j]) {//�ɳ� 
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
	for(int i=1; i<=n; i++) {//��dis[i] Ϊ i��ԭ��ľ��� 
		if(i==s) {
			dis[i] = 0;//�Լ����Լ��϶�Ϊ0 
		}else{
			dis[i] = con[s][i];
		}
	}
	selected[s] = 1;//ԭ�㱾���Ѿ����뼯�� 
	dijk(s);
	debug();
	return 0;
}

