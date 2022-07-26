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
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (!ndebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j, n;
    cin >>n;
    for(i = 0; i < n-1; i++) {
        if(i == 0) {
            for(j = 0; j< n; j++) cout <<"*";
            for(j = 0; j < n*2-3; j++) cout <<' ';
            for(j = 0; j< n; j++) cout <<"*";
        }
        else {
            for(j = 0; j < i; j++) cout <<' ';
            cout << '*';
            for(j = 0; j< n-2; j++) cout << ' ';
            cout <<'*';
            for(j = 0; j < 2*(n-i-1)-1; j++) cout <<' ';
            cout <<'*';
            for(j = 0; j< n-2; j++) cout << ' ';
            cout << '*';
        }
        cout << '\n';
    }
    for(i = 0; i < n-1; i++) cout << ' ';
    cout <<'*';
    for(i = 0; i < n-2; i++) cout<< ' ';
    cout <<'*';
    for(i = 0; i < n-2; i++) cout<< ' ';
    cout << '*'<< '\n';
    for(i = 0; i < n-1; i++) {
        if(i == n-2) {
            for(j = 0; j< n; j++) cout <<"*";
            for(j = 0; j < n*2-3; j++) cout <<' ';
            for(j = 0; j< n; j++) cout <<"*";
        }
        else {
            for(j = 0; j < n-i-2; j++) cout <<' ';
            cout << '*';
            for(j = 0; j< n-2; j++) cout << ' ';
            cout <<'*';
            for(j = 0; j < 2*i+1; j++) cout <<' ';
            cout <<'*';
            for(j = 0; j< n-2; j++) cout << ' ';
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
