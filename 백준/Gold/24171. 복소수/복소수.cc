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
    Num() {
        a=b=c=d=0;
    }
    Num(ll aa, ll bb, ll cc, ll dd) {
        a=aa,b=bb,c=cc,d=dd;
    }

    Num operator+(const Num&)const;
    Num operator-(const Num&)const;
    Num operator*(const Num&)const;
    Num operator/(const Num&)const;
    void divgcd();

};

class Complex
{
public:
    Num x, y;

    Complex operator+(const Complex&)const;
    Complex operator-(const Complex&)const;
    Complex operator*(const Complex&)const;
    Complex operator/(const Complex&)const;
    void makezero();
};

istream& operator>>(istream&is, Complex&r){
    is >> r.x.a>>r.x.b>>r.x.c>>r.x.d>>r.y.a>>r.y.b>>r.y.c>>r.y.d;
    return is;
}
ostream& operator<<(ostream&os, const Complex&r){
    os <<r.x.a<<' '<<r.x.b<<' '<<r.x.c<<' '<<r.x.d<<' ';
    os <<r.y.a<<' '<<r.y.b<<' '<<r.y.c<<' '<<r.y.d<<'\n';
    return os;
}
ostream& operator<<(ostream&os, const Num&r){
    os <<r.a<<' '<<r.b<<' '<<r.c<<' '<<r.d<<' ';
    return os;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    Complex A, B, R;
    cin>>A>>B;
    R = A+B;
    R.makezero();
    cout << R;

    R = A-B;
    R.makezero();
    cout << R;

    R = A*B;
    R.makezero();
    cout << R;

    R = A/B;
    R.makezero();
    cout << R;
    return 0;
}


Num Num::operator+(const Num&k)const{
    Num r;
    r.a = a*k.a;
    r.b = a*k.b+b*k.a;
    r.c = a*k.c+c*k.a;
    r.d = d;
    r.divgcd();
    return r;
}
Num Num::operator-(const Num&k)const{
    Num r;
    r.a = a*k.a;
    r.b = -a*k.b+b*k.a;
    r.c = -a*k.c+c*k.a;
    r.d = d;
    r.divgcd();
    return r;
}
Num Num::operator*(const Num&k)const{
    Num r;
    r.a = a*k.a;
    r.b = b*k.b+c*k.c*d;
    r.c = b*k.c+c*k.b;
    r.d = d;
    r.divgcd();
    return r;
}
Num Num::operator/(const Num&k)const{
    Num r,s;
    s.a=k.b*k.b-k.c*k.c*d;
    s.b=k.a*k.b;
    s.c=-k.a*k.c;
    s.d=d;

    r.a = a*s.a;
    r.b = b*s.b+c*s.c*d;
    r.c = b*s.c+c*s.b;
    r.d = d;
    r.divgcd();
    return r;
}
void Num::divgcd() {
    ll gd = gcd(a,b,c);
    if(gd*a<0) gd*=-1;
    if(gd==0) gd=a;
    a /=gd;
    b /=gd;
    c /=gd;
}
Complex Complex::operator+(const Complex&k)const{
    Complex r;
    r.x = k.x+x;
    r.y = k.y+y;
    return r;
}
Complex Complex::operator-(const Complex&k)const{
    Complex r;
    r.x = x-k.x;
    r.y = y-k.y;
    return r;
}
Complex Complex::operator*(const Complex&k)const{
    Complex r;
    r.x = (k.x*x)-(k.y*y);
    r.y = (k.x*y)+(k.y*x);
    return r;
}
Complex Complex::operator/(const Complex&k)const{
    Complex r, conj, t;
    Complex u, d;

    Num m_one(1, -1, 0, x.d);
    conj.x=k.x;
    conj.y= k.y*m_one;
    t.x=x,t.y=y;

    u = t*conj;
    d = k*conj;

    r.x = u.x/d.x, r.y=u.y/d.x;
    return r;
}
void Complex::makezero() {
    if(x.c==0) x.d =0;
    if(y.c==0) y.d =0;
    x.divgcd();
    y.divgcd();
}
