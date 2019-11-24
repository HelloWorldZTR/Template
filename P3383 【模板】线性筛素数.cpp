#include<iostream>

//const int maxn = 100000005;//垃圾数组，耗我青春

using namespace std;

int n,  m;
int prime[1000000];//这里不用开大
bool noprime[100000005];//省空间
int main() {
    cin>>n>>m;
    //cout<<m;
    noprime[0] = noprime[1] = true;
    for(int i=2; i<=n; i++)
     {
        if(!noprime[i]) {
            prime[++prime[0]] = i;
        }
        for(int j=1; j<=prime[0] && prime[j]*i<=n; j++) {//prime[j]*i防越界
            noprime[i*prime[j]] = true;
            if(i%prime[j]==0)   break;
        }
    }

    int temp;
    for(int i=0; i<m; i++) {
        cin>>temp;
        if(noprime[temp] )  cout<<"No"<<endl;
        else    cout<<"Yes"<<endl;
    }
    return 0;
}