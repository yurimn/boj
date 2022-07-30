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
    ll i,j,n;
    cin >>n;
    if(n == 1) {
        cout << '*';
        return 0;
    }
    ll nn = 4*n-3;
    vector<vector<char>> v(nn+2, vector<char> (nn, ' '));
    ll x = 0, y = nn-1;
    ll num = 0;
    for(i = nn; i >= 3; i-=2) {
        if(i != nn){
            for(j = 0; j < i; j++) v[x--][y] = '*';
        }
        for(j = 0; j < i; j++) v[x][y--] = '*';
        x++, y++;
        if(i!= nn) i-=2;
        for(j = 0; j < i; j++) v[x++][y] = '*';
        for(j = 0; j < i; j++) v[x][y++] = '*';
        x--, y--;
    }
    for(i = 0; i < nn+2; i++) {
        if(i == 1) {
            cout << '*' <<'\n';
        }
        else {
            for(j = 0; j<nn; j++) cout << v[i][j];
            cout << '\n';

        }
    }

    return 0;
}
