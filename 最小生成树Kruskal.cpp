#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Edge {
  int u, v, dis;
  friend bool operator < (const Edge a, const Edge b) {
    return a.dis < b.dis;
  }
};

vector<Edge> vec;

void add(int u, int v, int w) {
  vec.push_back((Edge){u, v, w});
}

int n, m;

const int maxn = 1e5 + 100;

int fa[maxn];

int getFa(int n) {
  if(fa[n] == -1)   return n;
  else return fa[n] = getFa(fa[n]);
}

bool unionV(int u, int v) {
  int FaU = getFa(u);
  int FaV = getFa(v);
  if(FaU == FaV)  return false;
  else {
    fa[FaU] = FaV;
    return true;
  }
}

int main() {
  memset(fa, -1, sizeof fa);
  scanf("%d%d", &n, &m);
  register int i, u, v, w, times = 0;
  for(i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
  }
  sort(vec.begin(), vec.end());
  long long ans = 0;
  for(i=0; i<m; i++) {
    Edge &now = vec[i];
    if(unionV(now.u, now.v)) {
      ans += now.dis;
      times ++;
    }
  }
  if(times == n-1)
    printf("%lld\n", ans);
  else
    puts("impossible");
  return 0;
}
