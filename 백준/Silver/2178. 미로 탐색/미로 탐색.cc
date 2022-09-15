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
int n,m;
class Data{
    public:
        Data();
        Data(int x, int y, int k) {
            this->x=x;
            this->y=y;
            this->k=k;
        }
        int x;
        int y;
        int k;
};
int main(){
    ///ios_base::sync_with_stdio(0);
    ///cin.tie(0);
    ll i,j;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<Data> q;


    cin>>n>>m;
    vector<vector<char>> v(n, vector<char> (m));
    vector<vector<char>> ch(n, vector<char> (m));
    for(auto &vv:v) {
        for(auto &vvv:vv) cin >> vvv;
    }

    Data d(0, 0, 1);
    q.push(d);
    while(!q.empty()){
        auto t = q.front();
        if(t.x==n-1&&t.y==m-1) {
            cout<<t.k;
            break;
        }
        ch[t.x][t.y] = t.k;
        for(int i=0;i<4;i++) {
            int tx = t.x+dx[i];
            int ty = t.y+dy[i];
            if(tx>=0&&ty>=0&&tx<n&&ty<m) {
                if(!ch[tx][ty] && v[tx][ty]=='1') {
                    Data tmp(tx, ty, t.k+1);
                    ch[tx][ty] = 1;
                    q.push(tmp);
                }
            }
        }
        q.pop();
    }
    return 0;
}
