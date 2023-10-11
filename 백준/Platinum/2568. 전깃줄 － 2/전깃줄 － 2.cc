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
typedef struct line{
    ll a;
    ll b;
};
bool cmp(line x, line y){
    return x.a<y.a;
}
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll i,j,n;
    cin>>n;
    vector<line> vv(n);
    vector<ll> v(n);
    for(i=0;i<n;i++) {
        cin>>vv[i].a >> vv[i].b;
    }
    sort(all(vv), cmp);

    for(i=0;i<n;i++) v[i] = vv[i].b;

    vector<ll> l;
    vector<vector<ll>> arr(n+1);
    l.push_back(0);
    for(i=0;i<n;i++) {
        if(v[i]>l[l.size()-1]) {
            l.push_back(v[i]);
            arr[l.size()-1] = arr[l.size()-2];
            arr[l.size()-1].push_back(i);
        }
        else {
            ll tmp = lower_bound(all(l), v[i])-l.begin();
            if(l[tmp]>v[i]) {
                l[tmp] = v[i];
                ll ttmp = arr[tmp].size()-1;
                arr[tmp][ttmp] = i;
                for(ll k=0;k<ttmp;k++) arr[tmp][k] = arr[tmp-1][k];
            }
        }

    }
    cout << n-l.size()+1 <<'\n';
    vector<ll> check(n);

    for(auto aa:arr[l.size()-1]) check[aa] = 1;
    for(i=0;i<n;i++) if(!check[i]) cout << vv[i].a <<'\n';

    return 0;
}
