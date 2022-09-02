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
ll ans = 0;
void merge_sort(ll s, ll e, vector<ll> &v){
    if(s == e) return;
    vector<ll> tmp(e-s+2);
    ll m = (s+e)/2;
    merge_sort(s, m, v);
    merge_sort(m+1, e, v);

    ll p = s, q = m+1, i=0;
    while(p<=m && q<=e) {
        if(v[p] <= v[q]) tmp[i++] = v[p++];
        else ans+=m-p+1,tmp[i++] = v[q++];
    }
    while(p<=m) {
        tmp[i++] = v[p++];
    }
    while(q<=e) {
        tmp[i++] = v[q++];
    }
    for(i=s;i<=e;i++) v[i] = tmp[i-s];
//    for(auto vv:v) cout << vv << " ";
//    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n;
    cin>>n;
    vector<ll> v(n);
    for(auto &vv:v) cin>>vv;
    merge_sort(0,n-1, v);
    cout <<ans;

    return 0;
}
