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

string ans;
void f(ll s, ll k) {
    if(k == 0) return;
    ll K = 1;
    for(ll i=0;i<k-1;i++) K *= 3;
    for(ll i=0; i<K; i++) ans[s+K+i] = ' ';
    f(s, k-1);
    f(s+K*2, k-1);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll i,j;
    ll n;
    while(cin>>n) {
        ans = "";
        ll N = 1;
        for(ll i=0;i<n;i++) N *= 3;
        for(i=0;i<N;i++) ans +='-';
        f(0, n);
        cout <<ans << '\n';
    }

    return 0;
}
