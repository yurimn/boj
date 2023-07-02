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
vector<ll> v;
ll n, m;
void f(ll cnt, ll now, vector<ll> tmp, vector<ll> visit) {
    if(cnt == m) {
        for(auto t:tmp) cout << t << ' ';
        cout <<'\n';
        return;
    }
    for(ll i=0; i< n; i++) {
        if(i>0 && v[i] == v[i-1]) continue;
        vector<ll> ttmp = tmp;
        if(visit[i] == 0) continue;
        ttmp.push_back(v[i]);
        visit[i]--;
        f(cnt+1, i, ttmp, visit);
        visit[i]++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    for(i=0;i<n;i++) {
        ll k;
        cin>>k;
        v.push_back(k);
    }
    sort(all(v));
    vector<ll> visit(n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(v[i] == v[j]) visit[i]++;
        }
    }
    f(0, 0, {}, visit);

    return 0;
}
