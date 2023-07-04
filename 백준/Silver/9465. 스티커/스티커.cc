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
    ll i,j,t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<ll>> v(2, vector<ll>(n));
        vector<vector<ll>> dp(2, vector<ll>(n));
        for(i=0;i<2;i++) {
            for(j=0;j<n;j++) {
                cin>>v[i][j];
            }
        }
        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        if(n>1) {
            dp[0][1] = v[1][0]+v[0][1];
            dp[1][1] = v[0][0]+v[1][1];
        }
        for(i=2;i<n;i++) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + v[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + v[1][i];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) <<'\n';
    }

    return 0;
}
