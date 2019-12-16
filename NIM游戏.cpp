#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int res = 0, n;
        cin >> n;
        while(n--) {
            int x;
            cin >> x;
            res ^= x;
        }
        if(res) puts("Yes");
        else puts("No");
    }
    return 0;
}