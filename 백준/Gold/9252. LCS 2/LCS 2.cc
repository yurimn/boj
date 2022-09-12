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
    ll i,j;
    string a, b;
    cin >>a>>b;
    ll x = a.size();
    ll y = b.size();
    vector<vector<ll>> v(x+1, vector<ll> (y+1));
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(a[i-1] == b[j-1]) v[i][j] = max({v[i-1][j], v[i][j-1], v[i-1][j-1]+1});
            else v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    string s="";
    i = x;
    j = y;
    while(true) {
        while(j>=1 && v[i][j] == v[i][j-1]) j--;
        while(i>=1 && v[i][j] == v[i-1][j]) i--;
        if(i==0 || j ==0) break;
        s+=a[i-1];
        i--;
    }
//    cout << "  ";
//    for(i=0;i<y;i++) cout << b[i] <<' ';
//    cout <<'\n';
//    for(i=1;i<=x;i++) {
//        cout << a[i-1] << ' ';
//        for(j=1;j<=y;j++) {
//            cout << v[i][j] <<' ';
//        }
//        cout <<'\n';
//    }
    cout << v[x][y]<<'\n';
    for(i=v[x][y]-1;i>=0;i--)cout << s[i];


    return 0;
}
