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
queue<pair<int,int>> q;
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int i,j,l,st;
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> v(n, vector<int> (n)), p(n, vector<int> (n)), pp(n);

    for(i=0;i<n;i++) {
        bool flag = true;

        for(j=0;j<i+1;j++) {
            if(i-j<0 || i+j >=n) break;
            if(s[i-j]!=s[i+j]) {
                flag = false;
                break;
            }
            p[i-j][i+j] = 1;
        }

        for(j=0;j<i+1;j++) {
            if(i-j<0 || i+j+1 >=n) break;
            if(s[i-j]!=s[i+j+1]) {
                flag = false;
                break;
            }
            p[i-j][i+j+1] = 1;
        }
    }
//    for(i=0;i<n;i++) {
//        for(j=0;j<n;j++) cout << p[i][j] <<' ';
//        cout <<'\n';
//    }

    vector<ll> dp(n);
    dp[0] = 1;
    for(j=0;j<n;j++) {
//        cout<< "j : " << j <<'\n';
        if(j) dp[j] = dp[j-1]+1;
        for(i=0;i<=j;i++) {
            if(p[i][j]) {
                if(i == 0) dp[j] = 1;
                else if(dp[i-1]+1<dp[j]) {
                    dp[j] = dp[i-1]+1;
//                    cout << i-1 <<' '<<dp[i-1] << ' '<< dp[j]<< '\n';
                }
            }
        }
    }
//    for(i=0;i<n;i++) cout <<s[i] <<' ';
//    cout << '\n';
//    for(i=0;i<n;i++) cout <<dp[i] <<' ';
//    cout << '\n';
    cout << dp[n-1];





    return 0;
}
