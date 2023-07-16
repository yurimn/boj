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
    ll m = 1000000007;
    ll i,j,n;
    cin>>n;
    vector<ll> v(n), dp(n), cnt(n), li;
    vector<vector<ll>> l, vv;

    for(auto &vv:v) cin>>vv;

    l.push_back(vector<ll>());
    l[0].push_back(0);

    li.push_back(v[0]);

    for(i=1;i<n;i++) {
        ll top = li.size()-1;
        if(li[li.size()-1]<v[i]) {
            li.push_back(v[i]);
            l.push_back(vector<ll>());
            l[top+1].push_back(i);
        }
        else {
            ll tmp = lower_bound(all(li), v[i])-li.begin();
            li[tmp] = v[i];
            l[tmp].push_back(i);
        }
    }

    vv = l;
    for(i=0;i<vv.size();i++) {
        for(j=0;j<vv[i].size();j++) vv[i][j] = v[l[i][j]];
    }

    for(j=0;j<l[0].size();j++) cnt[l[0][j]] = 1;
    for(i=1;i<l.size();i++) {
        ll l_i_size = l[i].size();
        vector<ll> tmp(l[i-1].size());
        tmp[0] = cnt[l[i-1][0]];
        for(j=1;j<l[i-1].size();j++) {
            tmp[j] = tmp[j-1]+cnt[l[i-1][j]];
            tmp[j] %= m;
        }
        for(j=0;j<l_i_size;j++) {
            ll st = upper_bound(all(vv[i-1]), v[l[i][j]], greater<ll>())-vv[i-1].begin()-1;
            ll en = lower_bound(all(l[i-1]), l[i][j])-l[i-1].begin()-1;
            if(en == -1) continue;
            if(st==-1) {
                cnt[l[i][j]] = tmp[en];
            }
            else {
                cnt[l[i][j]] = tmp[en]-tmp[st];
                if(cnt[l[i][j]]<0) cnt[l[i][j]] += m;
            }
        }
    }

    ll rst = 0;
    for(j=0;j<l[l.size()-1].size();j++) {
        rst += cnt[l[l.size()-1][j]];
        rst %= m;
    }
    cout << l.size() << ' ' << rst%m;
    return 0;
}
