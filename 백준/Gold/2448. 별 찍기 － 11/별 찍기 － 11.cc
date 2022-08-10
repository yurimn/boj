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
void f(ll k, vector<vector<char>> &v, ll n) {
    if(k < 3) return;
    f(k/2, v, n);
    ll b = k/2;
    for(ll i=0; i< n/k; i++) {
        for(ll j= 0; j < (n/k)*2; j++) {
            for(ll x = 0; x < b; x++) {
                for(ll y = 0; y < 2*(b-x)-1; y++) {
                    v[i*k+b+x][j*k+x*2+1+y] = ' ';
                }
            }
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll i,j, n;
    cin >> n;
    vector<vector<char>> v(n, vector<char> (n*2, '*'));
    f(n, v, n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) cout << ' ';
        for(j = 0; j < i*2+1; j++) cout << v[i][j];
        for(j = 0; j < n-i-1; j++) cout << ' ';
        cout <<'\n';
    }

    return 0;
}

/*


*
* *
*****
*     *
* *   * *
***** *****
*           *
* *         * *
*****       *****
*     *     *     *
* *   * *   * *   * *
***** ***** ***** *****


*/

