#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1e5;

#define IDX(n) n-'a'

int son[maxn][26], cnt[maxn], idx;

void insert(char c[]) {
    int p = 0, len = strlen(c), i, now;
    for(i=0; i<len; i++) {
        now = IDX(c[i]);
        if(son[p][now]==0)  son[p][now] = ++idx;
        p = son[p][now];
    }
    cnt[p]++;
}

int query(char c[]) {
    int p = 0, len = strlen(c), i, now;
    for(i=0; i<len; i++) {
        now = IDX(c[i]);
        if(son[p][now]!=0)  p = son[p][now];
        else return 0;
    }
    return cnt[p];
}

char opt[2], str[maxn];

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s%s", &opt, &str);
        if(opt[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}