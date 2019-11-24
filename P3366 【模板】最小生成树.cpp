#include<bits/stdc++.h>
using namespace std;

const int MAX_M    = 200010;
const int MAX_NODE =  5010;

struct s{
	int a;
	int b;
	int z;
} con[MAX_M];

int father[MAX_NODE]; 
bool vis[MAX_NODE];


bool cmp(s a, s b){
	return a.z<b.z;
}

int find_root(int x) {
	if(father[x]!=-1) {
		return father[x] = find_root(father[x]);
	}
	return x;
}

/*
*	1: success 
*	0: fail
*/
int union_(int x, int y) {
	int x_root = find_root(x);
	int y_root = find_root(y);
	if(x_root!=y_root) {
		father[y_root] = x_root;
		return 1;
	}
	return 0;
} 

int main() {
	memset(father, -1, sizeof(father));
	
	int m, n, x, y, z, ans = 0;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>x>>y>>z;
		con[i].a = x;
		con[i].b = y;
		con[i].z = z;
	}
	sort(con, con+m, cmp);
	for(int i=0; i<m; i++) {
		if(union_(con[i].a, con[i].b)) {
			vis[con[i].a] = true;
			vis[con[i].b] = true;
			ans += con[i].z;
		}
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			cout<<"orz"<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
