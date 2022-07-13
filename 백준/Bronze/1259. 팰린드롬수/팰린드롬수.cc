#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

int n;
int num[10];
int main() {
    while(true) {
        cin >> n;
        if(n == 0) return 0;
        int l = 0;
        while(true) {
            num[l++] = n%10;
            n /= 10;
            if(n == 0) break;
        }
        int i;
        for(i = 0; i < l/2; i++) {
            if(num[i] != num[l-i-1]) {
                cout << "no" << "\n";
                break;
            }
        }
        if(i == l/2) cout << "yes" << "\n";
    }
}
