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
    ll i,j,n,s;
    cin>>n>>s;
    vector<ll> v(n);
    for(auto &vv:v) cin>>vv;
    ll sum = v[0];
    ll mini = 10000000;
    ll p1 = 0, p2 = 0;
    while(p1<n && p2<n) {
        if(sum<s) {
            if(p2<n) {
                p2++;
                sum += v[p2];
            }
            else break;
        }
        else {
            if(p2-p1+1 < mini) mini = p2-p1+1;
            sum -= v[p1];
            p1++;
        }
    }
    if(mini == 10000000) cout << 0;
    else cout << mini;


    return 0;
}



