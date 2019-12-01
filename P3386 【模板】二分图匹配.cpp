#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
const int maxm = 1000000 + 10;

struct Edge {
    int to, next;
    Edge(){}
    Edge(int _to, int _next) {
        to = _to, next = _next;
    }
};
int head[maxn], idx;
Edge edges[maxm];

void add(int u, int v) {
    edges[++idx] = Edge(v, head[u]);
    head[u] = idx;
}

void se(int u) {
    int i;
    for(i=head[u]; i!=0; i = edges[i].next) {
        cout<<edges[i].to<<endl;
    }
}

bool vis[maxn];int lpair[maxn];
bool find(int u) {
    register int i, now;
    for(i=head[u]; i; i=edges[i].next) {
        now = edges[i].to;
        if(!vis[now]) {
            vis[now] = true;
            if(lpair[now]==0 || find(lpair[now])) {
                lpair[now] = u;
                return true;
            }
        }
    }
    return false;
}

int n, m, e;

int main() {
    scanf("%d%d%d", &n, &m, &e);
    register int i, u, v;
    for(i=0; i<e; i++) {
        scanf("%d%d", &u, &v);
        if(u>n || v>m) continue;
        add(u, v);
    }
    se(1);
    register unsigned int cnt = 0;
    for(i=1; i<=n; i++) {
        memset(vis, 0, sizeof vis);
        if(find(i)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}