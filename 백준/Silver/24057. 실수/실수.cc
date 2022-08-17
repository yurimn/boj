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
ll gcd(ll a, ll b, ll c) {return gcd(gcd(a, b),c);}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
class Num
{
public:
    ll a, b, c, d;

    Num operator+(const Num&)const;
    Num operator-(const Num&)const;
    Num operator*(const Num&)const;
    Num operator/(const Num&)const;
    void divgcd();

};

istream& operator>>(istream&is, Num&r){
    is >> r.a>>r.b>>r.c>>r.d;
    return is;
}
ostream& operator<<(ostream&os, const Num&r){
    os <<r.a<<' '<<r.b<<' '<<r.c<<' '<<r.d<<'\n';
    return os;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    Num A, B, r;
    cin>>A>>B;
    cout << A+B;
    cout << A-B;
    cout << A*B;
    cout << A/B;
    return 0;
}


Num Num::operator+(const Num&k)const{
    Num r;
    r.a = a*k.a;
    r.b = a*k.b+b*k.a;
    r.c = a*k.c+c*k.a;
    r.d = d;
    if(r.c==0) r.d=0;
    r.divgcd();
    return r;
}
Num Num::operator-(const Num&k)const{
    Num r;
    r.a = a*k.a;
    r.b = -a*k.b+b*k.a;
    r.c = -a*k.c+c*k.a;
    r.d = d;
    if(r.c==0) r.d=0;
    r.divgcd();
    return r;
}
Num Num::operator*(const Num&k)const{
    Num r;
    r.a = a*k.a;
    r.b = b*k.b+c*k.c*d;
    r.c = b*k.c+c*k.b;
    r.d = d;
    if(r.c==0) r.d=0;
    r.divgcd();
    return r;
}
Num Num::operator/(const Num&k)const{
    Num r,s;
    s.a=k.b*k.b-k.c*k.c*d;
    s.b=k.a*k.b;
    s.c=-k.a*k.c;
    s.d=d;
    if(s.c==0) s.d=0;

    r.a = a*s.a;
    r.b = b*s.b+c*s.c*d;
    r.c = b*s.c+c*s.b;
    r.d = d;
    if(r.c==0) r.d=0;
    r.divgcd();
    return r;
}
void Num::divgcd() {
    if(a<0){
        a*=-1,b*=-1,c*=-1;
    }
    ll d=gcd(a,abs(b),abs(c));
    a/=d;b/=d;c/=d;
}
