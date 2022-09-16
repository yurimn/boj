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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<int> cnt;
int c,n;

void dfs(int x, int y, vector<vector<char>> &a, vector<vector<int>> &b) {
    if(x<0||x>=n||y<0||y>=n||b[x][y]||a[x][y]=='0') return;
    if(!b[x][y] && a[x][y]=='1'){
        b[x][y] = 1;
        c++;
    }
    for(int i=0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        dfs(nx, ny, a, b);
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int i,j;
    cin>>n;
    vector<vector<char>> arr(n, vector<char> (n));
    vector<vector<int>> v(n, vector<int> (n));
    for(auto &a:arr){
        for(auto &aa:a) cin>>aa;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(!v[i][j]&& arr[i][j]=='1') {
                c = 0;
                dfs(i, j, arr, v);
                cnt.push_back(c);
            }
        }
    }

    sort(all(cnt));
    cout << cnt.size()<<'\n';
    for(auto cc:cnt){
        cout << cc << '\n';
    }


    return 0;
}
