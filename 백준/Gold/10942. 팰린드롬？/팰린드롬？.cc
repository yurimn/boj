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
    ll i,j,n,m,s,e;
    cin>>n;
    vector<ll> v(n);
    vector<vector<ll>> dp(n, vector<ll> (n));
    for(auto &vv:v) cin>>vv;

    for(i=0;i<n;i++) {
        dp[i][i] = 1;
        if(i<n-1 && v[i]==v[i+1]) dp[i][i+1] = 1;
    }
    for(i=1;i<n-1;i++) {
        for(j=1;j<=i;j++) {
            if(v[i-j]==v[i+j] && dp[i-j+1][i+j-1]) dp[i-j][i+j] = 1;
            if(i+j+1<n && v[i-j]==v[i+j+1] && dp[i-j+1][i+j]) dp[i-j][i+j+1] = 1;
        }
    }
//    for(i=0;i<n;i++) {
//        for(j=0;j<n;j++) cout << dp[i][j] <<' ';
//        cout <<'\n';
//    }
    cin>>m;
    for(i=0;i<m;i++) {
        cin>>s>>e;
        cout << dp[s-1][e-1] << '\n';
    }


    return 0;
}
