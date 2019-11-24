// luogu-judger-enable-o2
#include<stdio.h>
/*
	ʵ������֪��scanf+printf+O2c���ȿ���
*/
//using namespace std;

typedef unsigned int ll;//���Ρ�

#define maxn  (500000 + 10)

typedef struct node{
	int l;
	int r;
	ll sum;
} node; 
ll arr[maxn];
node tr[maxn*4];

/*������arrΪԭֵ�� rootΪ��ǰ�ڵ㣬 start/end Ϊ��ǰ����*/
void build_tree(node tree[], ll arr[], int root, int start, int end) {
	tree[root].l = start;
	tree[root].r = end;
	if(start == end) {
		tree[root].sum = arr[start];
		return;
	}
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	int mid = (start + end) /2;
	
	build_tree(tree, arr, left_child  , start, mid);//������ 
	build_tree(tree, arr, right_child , mid+1, end);//������ 
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//��¼�� 
}
/*���£� rootΪ��ǰ�ڵ㣬 start/endΪ�������䣬 kΪ�޸�ʱ���ϵ�ֵ 
*/
void update(node tree[], int root, int x, int k) {
    if(tree[root].l == tree[root].r && tree[root].l == x) {
        tree[root].sum += k;
        return;
    }
	if(tree[root].r<x || tree[root].l>x) {//���� 
		return;
	}
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	
	if(tree[left_child].l<=x)
		update(tree, left_child , x, k);
	if(tree[right_child].l<=x)
		update(tree, right_child, x, k);
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//����һ�� 
    return;
}
/*��ѯ�� rootΪ��ǰ�ڵ㣬 start/endΪ��ѯ����*/ 
ll query(node tree[], int root, int start, int end) {
	if(tree[root].r<start || tree[root].l>end) {//���� 
		return 0;
	}else if(tree[root].l>=start && tree[root].r<=end){
		return tree[root].sum;
	}
	ll ans = 0;
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	ans += query(tree, left_child , start, end);
	ans += query(tree, right_child, start, end);
	return ans;
}
int main() {
	/*ll arr[1000] = {1, 5, 4, 2, 3};
	build_tree(tr, arr, 0, 0, 4);
	update(tr, 0, 0, 1, 1);
		cout<<tr[i].sum<<endl;
	}
	cout<<endl<<query(tr, 0, 0, 3)<<endl;*/ 
	int n, m;
	scanf("%d%d", &n,&m);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	} 
	build_tree(tr, arr, 0, 0, n-1);
	int temp, x, y, k;
	ll ans = 0;
	for(int i=0; i<m; i++) {
		scanf("%d", &temp);
		if(temp == 1) {
			scanf("%d%d", &x, &k);
			update(tr, 0, x-1, k);//???��?????��????0~n-1??? 
		}
		if(temp == 2) {
			scanf("%d%d", &x, &y);
			ans = query(tr, 0, x-1, y-1);//??????? 
			printf("%d\n", ans);
		}
	}
	return 0;
}