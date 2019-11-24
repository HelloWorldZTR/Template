#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;//arr size too small will cause RE(seg fault)

typedef unsigned long long ull;

struct Edge{
    int from;
    int to;
    ull w;
};

struct Node{
    int n;
    ull w;
    friend bool operator < (const Node& a, const Node& b) {
        return a.w>b.w;
    }
};

int n, m, s = 1;

ull dis[maxn+1];

vector<Edge> edges;
vector<int > head[maxn];

void addEdge(int from, int to, ull w) {
    edges.push_back((Edge){from, to, w});
    head[from].push_back(edges.size()-1);
}

priority_queue<Node> pq;
void dijsktra(int start) {
    for(int i=1; i<=n; i++) {
        dis[i] = 1e10;
    }
    dis[start] = 0;
    pq.push((Node){start, 0});
    while(!pq.empty()) {
        Node temp = pq.top();pq.pop();
        int n = temp.n;
        ull w = temp.w;
        if(w!=dis[n]) {
            continue;
        }
        for(int i=0; i<head[n].size(); i++) {
            Edge& now = edges[head[n][i]];
            if(dis[now.to]>dis[now.from]+now.w) {
                dis[now.to] = dis[now.from] + now.w;
                pq.push((Node){now.to, dis[now.to]});//it should update only at the time it needed
            }
        }
    }
}

void print_ans() {
   for(int i=1; i<=n; i++)  {
       cout<<dis[i]<<" ";
    }
   cout<<endl;
}

int main() {
    cin>>n>>m>>s;
    int from_, to_;
    ull w;
    for(int i=0; i<m; i++) {
        cin>>from_>>to_>>w;
        addEdge(from_, to_, w);
        //addEdge(to_, from_, w);
    }
    dijsktra(s);
    print_ans();
    return 0;
}
