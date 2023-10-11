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
ll arr[1002][1002], v[1002][1002];
ll res[1000000];
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll cnt;
void dfs(ll x, ll y, ll num) {
    v[x][y] = num;
    cnt++;
    for(ll i=0;i<4;i++) {
        ll nx = x+dx[i];
        ll ny = y+dy[i];
        if(arr[nx][ny]==0 && v[nx][ny]==0) dfs(nx, ny, num);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,n,m;
    cin>>n>>m;

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            char tmp;
            cin>>tmp;
            arr[i][j] = tmp-'0';
        }
    }
    for(i=0;i<=n+1;i++){
        arr[i][0] = 1;
        arr[i][m+1] = 1;
    }
    for(j=0;j<=m+1;j++) {
        arr[0][j] = 1;
        arr[n+1][j] = 1;
    }

    ll idx = 0;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(!v[i][j] && arr[i][j]==0) {
                idx++;
                cnt = 0;
                dfs(i, j, idx);
                res[idx] = cnt;
            }
        }
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(arr[i][j]==1) {
                ll tmp[5] = {0};
                for(k=0;k<4;k++) {
                    ll nx = i+dx[k];
                    ll ny = j+dy[k];
                    if(arr[nx][ny]==0) tmp[k] = v[nx][ny];
                }
                sort(tmp, tmp+4);
                for(k=0;k<4;k++) if(tmp[k]!=tmp[k+1]) arr[i][j] += res[tmp[k]]%10;
            }
        }
    }


    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) cout << arr[i][j]%10;
        cout <<'\n';
    }


    return 0;
}
