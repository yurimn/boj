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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i =0;
    ll n;
    cin >> n;
    string st;
        getline(cin, st);
    for(i=0;i<n;i++) {
        string st;
        getline(cin, st);
        st+=' ';
        vector<string> str;
        while(st!="") {
            ll a = st.find(' ');
            str.push_back(st.substr(0,a));
            st.erase(0,a+1);
        }
        cout<<"Case #"<<i+1<<": ";

        for(auto it=str.rbegin();it!=str.rend();it++){
            cout<<*it<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
