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
    ll i,j;
    struct tm base={0},want={0};;
    base.tm_year=want.tm_year=2007-1900;
    base.tm_mon=1-1;
    base.tm_mday=1;
    cin>>want.tm_mon>>want.tm_mday;
    want.tm_mon-=1;
    cout<<vector<string>({"MON","TUE","WED","THU","FRI","SAT","SUN"})[(ll)difftime(mktime(&want),mktime(&base))/60/60/24%7];

    return 0;
}
