#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, m;

const int maxn = 510;
const int INF  = 0x3f3f3f3f;

int g[maxn][maxn], dis[maxn];

bool st[maxn];

int prim() {
  memset(dis, 0x3f, sizeof dis);
  memset(st, false, sizeof st);
  register int i, j, res = 0;
  for(i=0; i<n; i++) {
    register int t = -1;
    for(j=1; j<=n; j++) {
      if(!st[j] && (t==-1 || dis[t]>dis[j])) t = j;
    }
    if(i && dis[t] == INF)  return INF;
    st[t] = true;
    for(j=1; j<=n; j++) {
      if(!st[j]) {
         dis[j] = min(dis[j], g[t][j]);
      }
    }
    if(i) res += dis[t];
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  int u, v, w;
  memset(g, 0x3f, sizeof g);
  while(m--) {
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = g[v][u] = min(g[u][v], w);
  }
  int ans = prim();
  if(ans == INF)  puts("impossible");
  else  printf("%d\n", ans);
  return 0;
}
