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
    ll i,j,n,l,cnt;
    ll ptr1, ptr2;

    l = 4000000;
    cnt = 0;

    cin>>n;
    vector<ll> prime(l+1), v;

    prime[1] = 1;
    for(i=2;i<=l;i++) {
        if(!prime[i]) {
            for(j=2*i;j<=l;j+=i) prime[j] = 1;
        }
    }
    v.push_back(0);
    for(i=1;i<=l;i++) {
        if(!prime[i]) v.push_back(i);
    }
    for(i=1;i<v.size();i++) {
        v[i] += v[i-1];
    }
    ptr1 = 0;
    ptr2 = 1;
    while(ptr2<=v.size()) {
        ll num = v[ptr2]-v[ptr1];
        if(num>n) ptr1++;
        else if(num<n) ptr2++;
        else {
            cnt++;
            ptr1++;
        }
    }
    cout << cnt;

    return 0;
}
