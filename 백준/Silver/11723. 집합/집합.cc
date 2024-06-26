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
    ll i,j,n;
    cin>>n;
    vector<bool> v(22);
    while(n--) {
        string q;
        int k;
        cin>>q;
        if(q == "all") {
            for(i=1;i<=20;i++) {
                v[i] = 1;
            }
        }
        else if(q == "empty") {
            for(i=1;i<=20;i++) {
                v[i] = 0;
            }
        }
        else {
            cin>>k;
            if(q == "add") {
                v[k] = 1;
            }
            else if(q == "remove") {
                v[k] = 0;
            }
            else if(q == "check") {
                if(v[k]) cout << 1 <<'\n';
                else cout << 0 <<'\n';
            }
            else if(q == "toggle") {
                v[k] = !v[k];
            }
        }
    }

    return 0;
}
