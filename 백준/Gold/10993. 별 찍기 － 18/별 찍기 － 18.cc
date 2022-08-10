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

void f(ll n, vector<vector<char>>&arr, ll x, ll y){
    ll i=0;
    if(n==0)return;
    for(i=0;i<(2<<n)-3;i++){
        arr[x][y+i]='*';
    }
    debug<<"TTT\n";
    for(i=0;i<(1<<n)-1;i++){
        arr[x+pow(-1,n)*i][y+i]=arr[x+pow(-1,n)*i][y+(2<<n)-4-i]='*';
        debug<<x-i<<' '<<y+i<<'\n';
        debug<<x-i<<' '<<y+(2<<n)-4-i<<'\n';
    }
    f(n-1,arr,x+pow(-1,n)*((1<<(n-1))-1),y+(1<<(n-1)));
}


int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<char>>arr((1<<n)-1,vector<char>((2<<n)-3, ' '));
    f(n,arr,((1<<n>>1)-1)*(1-pow(-1,n)),0);
    j=(2<<n)-3;
    i=((1<<n>>1)-1)*(1-pow(-1,n));
    while(0<=i&&i<(1<<n)-1){
        arr[i].resize(j--);
        i+=pow(-1,n);
    }
    for(auto&k:arr){
        for(auto&kk:k)cout<<kk;
        cout<<'\n';
    }
    return 0;
}
