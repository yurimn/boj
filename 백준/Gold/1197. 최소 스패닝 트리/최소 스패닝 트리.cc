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
bool cmp (pair<ll,ll> a, pair<ll,ll> b) {
    return a.second<b.second;
}

struct cmp2{
    bool operator()(pair<ll, ll>&a, pair<ll, ll>&b) {
      return a.second>b.second;
  }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,V,e;
    cin>>V>>e;
    vector<vector<pair<ll,ll>>> v(V+1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp2> pq;
    ll idx = 0;
    ll mini = 10000000;
    for(i=0;i<e;i++) {
        ll a, b, c;
        cin>>a>>b>>c;
        if(c<mini) {
            mini = c;
            idx = a;
        }
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    vector<ll> visit(V+1);
    ll val = 0;
    for(auto vv:v[1]) pq.push(vv);
    visit[1] = 1;
    ll cnt = 1;

    while(!pq.empty()) {
        pair<ll,ll> tmp = pq.top();
        while(!pq.empty() && visit[tmp.first]) {
            pq.pop();
            tmp = pq.top();
        }
        if(!pq.empty()) pq.pop();
        if(cnt == V) break;
        visit[tmp.first] = 1;
        val += tmp.second;
        cnt++;
        for(auto vv:v[tmp.first]) {
            if(!visit[vv.first]) pq.push(vv);
        }
    }
    cout << val;

    return 0;
}
