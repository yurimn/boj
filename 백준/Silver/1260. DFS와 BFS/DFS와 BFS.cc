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
void dfs(ll k, ll s, ll n, vector<vector<ll>> &v, vector<ll> &ch){
    if(s==n+1) return;
    ch[k] = 1;
    cout << k << ' ';
    for(ll i=1;i<=n;i++) {
        if(!ch[i] && v[k][i]) {
            dfs(i, s+1, n, v, ch);
        }
    }
}
void bfs(ll k, ll n, vector<vector<ll>> &v, vector<ll> &ch){
    queue<ll> q;
    q.push(k);
    ch[k] = 1;
    while(!q.empty()){
        cout << q.front() <<' ';
        for(ll i=1;i<=n;i++) {
            if(!ch[i] && v[q.front()][i]) {
                ch[i] = 1;
                q.push(i);
            }
        }
        q.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n,m,v,x,y;
    cin>>n>>m>>v;
    vector<vector<ll>> arr(n+1, vector<ll> (n+1));
    vector<ll> ch(n+1);

    while(m--) {
        cin>>x>>y;
        arr[x][y]=arr[y][x]=1;
    }
    dfs(v, 1, n, arr, ch);
    vector<ll> ch2(n+1);
    cout <<'\n';
    bfs(v, n, arr, ch2);
    return 0;
}
