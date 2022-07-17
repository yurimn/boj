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
    cin >> n;
    if(n==0){
        cout<<0;
        return 0;
    }
    vector<pair<struct tm,ll>>arr(n);
    vector<long double>p(n);
    for(i = 0; i <n ;i++) {
        char x;
        struct tm tmp;
        cin>>tmp.tm_year>>x>>tmp.tm_mon>>x>>tmp.tm_mday
            >>tmp.tm_hour>>x>>tmp.tm_min>>x>>tmp.tm_sec>>arr[i].second;
        tmp.tm_year -= 1900;
        tmp.tm_mon -= 1;
        arr[i].first=tmp;
    }
    for(i=0;i<n;i++){
        p[i]=max(pow(0.9,n-1-i),
                 pow(0.5,(difftime(mktime(&arr[n-1].first),mktime(&arr[i].first)))/(365*24*60*60)));
    }
    long double u=0,d=0;
    for(i=0;i<n;i++){
        d+=p[i];
        u+=p[i]*arr[i].second;
    }
    cout<<round(u/d);


    return 0;
}
