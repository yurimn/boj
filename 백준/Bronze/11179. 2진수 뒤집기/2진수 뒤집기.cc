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
    ll n;
    string st, re;
    cin >> n;
    stringstream ss;
    vector<string> oc= {"000", "001", "010", "011", "100", "101", "110", "111"};
    ss << oct << n;
    ss >> st;
    for(char k:st) {
        re += oc[k-'0'];
    }
    re.erase(0, re.find('1'));
    re += "00";
    string rre;
    for(ll i = 0; i< re.size()-2; i+=3) {
        string str = re.substr(i, 3);
        reverse(all(str));
        rre += find(all(oc), str) - oc.begin() + '0';
    }
    reverse(all(rre));
    ss.clear();
    ss << rre;
    ss >> oct >> n;
    cout << n;
    return 0;
}
