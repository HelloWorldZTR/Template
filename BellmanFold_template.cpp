#include<iostream>
using namespace std;

const int INF = 2147483647;
const int MAXM = 500000;

int s, n, m;//总共n个点， m个边 

long long dist[MAXM], from[MAXM], to[MAXM], w[MAXM];

void BellmanFold(int start) {
	for(int i=1; i<=n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) {
			if(dist[to[j]] > dist[from[j]] + w[j]) {
				dist[to[j]] = dist[from[j]] + w[j];
			}
		}
	}
}

void printAns() {
	for(int i=1; i<=n; i++) {//从1开始 
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}

int main() {
	cin>>n>>m>>s;
	cout<<INF<<endl; 
	for(int i=0; i<m; i++) {
		cin>>from[i]>>to[i]>>w[i];
	} 
	BellmanFold(s);
	printAns();
	return 0;
}

