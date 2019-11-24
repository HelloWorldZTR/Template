#include<iostream>
/*
*	�������
*		����priority_queue 
*/
using namespace std;
typedef unsigned long long ll;

const int MAXN = 100010;

ll tr[MAXN];

void swap(ll tree[], int a, int b) {
	ll temp = tree[a];
	tree[a] = tree[b];
	tree[b] = temp;
}

void heapify(ll tree[], int n, int i) {
	int left_child  = 2 * i; 
	int right_child = 2 * i + 1;
	int max_ = i;
	if(left_child < n && tree[left_child] > tree[max_]) {
		max_ = left_child;
	}
	if(right_child < n && tree[right_child] > tree[max_]) {
		max_ = right_child;
	}
	if(max_!=i) {
		swap(tree, max_, i);
		heapify(tree, n, max_);
	}
}

void build_heap(ll arr[], int n) {
	int last_node = n - 1;
	int parent_la = (last_node - 1) / 2;
	for(int i=parent_la; i>=0; i--) {
		heapify(arr, n, i);
	}
}

void heap_sort(ll tree[], int n) {
	for(int i=n-1; i>=0; i--) {
		swap(tree, 0, i);
		heapify(tree, n, 0);
	}
}

int main() {
	int n;
	/*ll tr[] = {10, 4, 5, 3, 1};
	build_heap(tr, 5);
	heap_sort(tr, 5);
	for(int i=0; i<5; i++) {
		cout<<tr[i]<<endl;
	}*/
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>tr[i];
	}
	build_heap(tr, n);
	heap_sort(tr, n);
	for(int i=n-1; i>=0; i--) {
		cout<<tr[i]<<" ";
	}
	cout<<endl;
	return 0;
}

