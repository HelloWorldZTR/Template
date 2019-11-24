#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 10010;

int father[maxn] ;

void init() {
	memset(father, -1, sizeof(father));
}

int find_father(int x) {
	if(father[x]==-1) {
		return x;
	}
	return father[x] = find_father(father[x]);
}

void union_(int x, int y) {
	int x_root = find_father(x);
	int y_root = find_father(y);
	if(x_root!=y_root)
		father[x_root] = y_root;
}
int main() {
	init();
	int m, n, x, y, z;
	int x_r=0, y_r=0;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>z>>x>>y;
		if(z==1)
			union_(x, y);
		else {
			x_r = find_father(x);
			y_r = find_father(y);
			if(x_r==y_r)
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
		}
	}
	return 0;
}

