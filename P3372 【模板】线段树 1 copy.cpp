#include <iostream>
using namespace std;

struct Node {
	long long sum;
	int l;
	int r;
	int lazy;
//	bool uped = false;
};
const int maxn = 1e5;
long long numbers[maxn + 10000];
Node tree[maxn<<2];

void buildTree(int now, int start, int end) {
	//cout<<start<<", "<<end<<endl;
	tree[now].l = start;
	tree[now].r = end;
	if(start == end) {
		tree[now].sum = numbers[start];
		return;
	}
	int lchild = now << 1;//now * 2
	int rchild = (now << 1) + 1;//now * 2 + 1
	int mid = (start + end) >> 1;
	buildTree(lchild, start, mid);
	buildTree(rchild, mid+1, end);
	tree[now].sum = tree[lchild].sum + tree[rchild].sum;
}

void pushDown(int now) {
	//if(now.lazy == 0)	return;
	if(tree[now].lazy!=0) {
		int lchild = (now<<1);
		int rchild = (now<<1) + 1;
		int v = tree[now].lazy;
		tree[now].lazy = 0;
		tree[lchild].sum += v * (tree[lchild].r - tree[lchild].l + 1);
		tree[rchild].sum += v * (tree[rchild].r - tree[rchild].l + 1);
		tree[lchild].lazy += v;
		tree[rchild].lazy += v;
	}
}

void updateTree(int now, int start, int end, int v) {
	if(tree[now].r < start)	return;
	if(tree[now].l > end  )	return;
	if(tree[now].l >= start && tree[now].r <= end) {
		tree[now].sum  += (tree[now].r - tree[now].l + 1) * v;
		tree[now].lazy += v;
		return ;
	}
	if(tree[now].lazy != 0)	pushDown(now);
	int lchild = (now<<1);
	int rchild = (now<<1) + 1;
	//int mid = (start + end) >> 1;
	updateTree(lchild, start, end, v);
	updateTree(rchild, start, end, v);
	tree[now].sum = tree[lchild].sum + tree[rchild].sum;
}

long long queryTree(int now, int start, int end) {
	/*DEBUG
	cerr<<"now at n="<<now<<" from ("<< tree[now].l << " ,"  << tree[now].r<<")"<<"start = "<<start<<"end = "<<end<<endl;
	cerr<<"value = "<<tree[now].sum<<endl;
	*/
	/*出界*/
	if(tree[now].r < start)	return 0;
	if(tree[now].l > end  )	return 0;
	/*返回区间和*/
	if(start<=tree[now].l && tree[now].r<=end)	return tree[now].sum;
	/*需要处理*/
	if(tree[now].lazy != 0)	pushDown (now);
	int lchild = (now<<1);
	int rchild = (now<<1) + 1;
	//int mid = (start + end) >> 1;
	return queryTree (lchild, start, end) + queryTree (rchild, start, end);
}

void dfs(int n) {
	if(tree[n].sum!=0) {
		cerr<<"now at n="<<n<<" from ("<< tree[n].l << " ,"  << tree[n].r<<")"<<endl;
		cerr<<"value = "<<tree[n].sum<<"  lazy = "<<tree[n].lazy<<endl;
		dfs(n<<1);
		dfs((n<<1)+1);
	}
}

int main() {
	//freopen("out.txt", "w", stderr);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int i, options, x, y, k;
	for(i=1; i<=n; i++) {//死因：：n，m写反
		cin>>numbers[i];
	}
	buildTree(1, 1, m);
	//dfs(1);
	for(i=0; i<m; i++) {
		cin >> options;
		if(options == 1) {
			cin >> x >> y >> k;
			updateTree (1, x, y, k);
		}
		else if(options == 2) {
			cin >> x >> y;
			cout << queryTree (1, x, y) << endl;
		}
		else {
			cerr << "Error! Unkown option" << endl;
		}
	}
	return 0;
}
