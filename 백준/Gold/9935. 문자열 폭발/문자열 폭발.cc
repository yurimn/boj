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
    ll i,j,cnt;
    cnt = 0;
    string s, e, r, tmp;
    stack<ll> st;
    cin>>s;
    cin>>e;
    for(i=0;i<s.size();i++) {
        auto idx = e.find(s[i]);
        if(idx==cnt || idx ==0) {
            st.push(idx);
            if(idx == cnt) cnt++;
            else if(idx == 0) cnt = 1;
            if(cnt == e.size()) {
                while(cnt>0) {
                    st.pop();
                    cnt--;
                }
                if(st.empty()) cnt = 0;
                else cnt = st.top()+1;
            }
        }
        else  {
            tmp = "";
            while(!st.empty()) {
                tmp += e[st.top()];
                st.pop();
            }
            cnt = 0;
            reverse(all(tmp));
            r += tmp;
            r += s[i];
        }
    }
    tmp = "";
    while(!st.empty()) {
        tmp += e[st.top()];
        st.pop();
    }
    reverse(all(tmp));
    r += tmp;

    if(r == "") cout << "FRULA";
    else cout << r;

    return 0;
}
