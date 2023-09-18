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
ll POW(ll a, ll b){ll p=1;for(;b;b/=2,a=(a*a))if(b&1)p=(p*a);return p;}
ll f(ll x) {
    ll sum = 0;
    ll cnt= 0;
    if(x == 0) return 0;
    for(ll i=63;i>=0;i--) {
        if(x>>i&1) {
            cnt++;
            if(i==0) {
               sum += cnt;
            }
            else {
                if(cnt == 1) {
                    sum += i*POW(2, i-1)+1;
                }
                else {
                    sum += (cnt-1)*POW(2, i) + i*POW(2, i-1)+1;
                }

            }
           //cout << i << ' '<< sum <<'\n';
        }
    }
    return sum;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll a, b;
//    for(i=0;i<100;i++) {
//        cout << f(i) <<  ' '<< t(i) << '\n';
//    }
    cin>>a>>b;
    cout <<f(b)-f(a-1);

    return 0;
}
