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
    ll i,j,n,m,a,b;
    cin>>n>>m;
    vector<vector<ll>> p(n+1);
    vector<ll> v(n+1);
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    while(m--) {
        ll a, b;
        cin>>a>>b;
        v[b]++;
        p[a].push_back(b);
    }

    for(i=1;i<=n;i++) {
        if(v[i] == 0) pq.push(i);
    }

    while(!pq.empty()) {
        ll t = pq.top();
        pq.pop();
        cout<< t << ' ';
        for(auto pp:p[t]) {
            v[pp]--;
            if(v[pp]==0) pq.push(pp);
        }
    }


    return 0;
}
