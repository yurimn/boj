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

void f(vector<ll> v, vector<ll> &s, ll sum, ll i, ll n) {
    sum += v[i];
    s.push_back(sum);
    for(ll j=i+1; j<n; j++) f(v, s, sum, j, n);
}
void ff(vector<ll> v, vector<ll> &s, ll n) {
    for(ll i=0;i<n;i++) f(v, s, 0, i, n);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n,m;
    ll cnt = 0;

    cin>>n>>m;
    vector<ll> v1(n/2), v2(n-n/2);
    vector<ll> s1, s2;

    for(i=0;i<n/2;i++) cin>>v1[i];
    for(i=0;i<n-n/2;i++) cin>>v2[i];

    ff(v1, s1, n/2);
    ff(v2, s2, n-n/2);

    sort(all(s1));
    sort(all(s2));

    if(n==1) {
        if(m == v2[0]) cout << 1;
        else cout << 0;
        return 0;
    }

    ll l1 = s1.size(), l2 = s2.size();
    for(i=0;i<l1;i++) if(s1[i]==m) cnt++;
    for(i=0;i<l2;i++) if(s2[i]==m) cnt++;

    ll p1=0, p2=l2-1;

    while(true) {
        if(s1[p1]+s2[p2] == m) {
            ll tmp1 = s1[p1], tmp2 = s2[p2];
            ll pp1 = p1, pp2 = p2;

            while(p1<l1 && tmp1 == s1[p1]) p1++;
            while(p2<l2 && tmp2 == s2[p2]) p2--;
            cnt += (p1-pp1)*(pp2-p2);
        }
        else if(s1[p1]+s2[p2]>m) p2--;
        else p1++;
        if(p2==-1 || p1 == l1) break;
    }
    cout <<cnt;

    return 0;
}
