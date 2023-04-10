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
ll r = 1000000007;

void f(ll n) {
    ll a=1,b=1,c=1,d=0;
    ll a1,b1,c1,d1;
    ll a2=1,b2=0,c2=0,d2=1;
    for(;n;n/=2) {
        if(n%2) {
            a1=(a2*a+b2*c)%r;
            b1=(a2*b+b2*d)%r;
            c1=(c2*a+d2*c)%r;
            d1=(c2*b+d2*d)%r;
            a2=a1;
            b2=b1;
            c2=c1;
            d2=d1;
        }
        if(n>1){
            a1=(a*a+b*c)%r;
            b1=(a*b+b*d)%r;
            c1=(c*a+d*c)%r;
            d1=(c*b+d*d)%r;
            a=a1;
            b=b1;
            c=c1;
            d=d1;
        }
    }
    cout << a2<<'\n';
}

int main(){

    ll i,j,k;
    cin>>k;
    f(k-1);

    return 0;
}
