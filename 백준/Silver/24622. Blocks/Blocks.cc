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

vector<string> bl;
string st;
int f(ll idx, vector<ll> check) {
    if(idx == st.size()) return 1;
    ll i;
    for(i = 0; i < 4; i++) {
        if(bl[i].find(st[idx]) != string::npos && check[i] == 0) {
            check[i] = 1;
             if(f(idx+1, check)) return 1;
             check[i] = 0;
        }
    }
    if(i == 4) return 0;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin >> n;
    bl.resize(4);
    for(string &k:bl) cin >>k;
    for(i = 0 ; i< n; i++) {
        cin >> st;
        vector<ll> check(4);
        cout << (f(0, check)?"YES":"NO") << '\n';
    }


    return 0;
}
