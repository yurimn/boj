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
    cin>>n;
    vector<ll> v(n), dp(n), li;
    vector<vector<ll>> l;
    stack<ll> st;

    for(auto &vv:v) cin>>vv;
    dp[0] = 1;
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

    ll cp = 1000000010;
    cout << l.size() <<'\n';
    for(i=l.size()-1;i>=0;i--) {
        for(j=l[i].size()-1;j>=0;j--) {
            if(l[i][j] < cp) {
                st.push(v[l[i][j]]);
                cp = l[i][j];
                break;
            }
        }
    }
    while(!st.empty()) {
        cout << st.top() <<' ';
        st.pop();
    }

    return 0;
}
