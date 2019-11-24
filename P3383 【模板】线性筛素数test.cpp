#include<iostream>
#include<cstring>
/*
 *  线性筛（aka. 欧拉筛）
 * */
using namespace std;

const int maxn = 1000;

int prime[maxn], noprime[maxn];

int main() {
    int n;
//    cin>>n;
//
//    n = 100;
    cout<<"Please input n(<=1000)";
    cin>>n;
    cout<<endl;
    noprime[0] = noprime[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(noprime[i] == 0/*is prime*/) {
            prime[++prime[0]] = i;
        }
        for(int j = 1; j<=prime[0] && i*prime[j]<n; j++) {
            noprime[i*prime[j]] = 1;
            if(i%prime[j] == 0) {
                break;
            }
        }
    }
    cout<<"\t\t\tPrime number table (start from 1)"<<endl;
    for(int i =1; i<=n; i++) {
//        cout<<!noprime[i]<<"\t";
        if(!noprime[i]) {
            cout<<"Yes\t";
        }
        else {
            cout<<"--\t";
        }
        if(i%10 == 0) {
            cout<<endl;
        }
    }
    return 0;
}
