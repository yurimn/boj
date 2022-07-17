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

class Matrix
{
public:
    Matrix(){
        Matrix(0,0);
    }
    Matrix(size_t row,size_t col):
        row(row),
        col(col),
        element(vector<vector<ll>>(row,vector<ll>(col))){}
    ~Matrix();
    void resize(size_t,size_t);
    void input();
    void print();
    Matrix add(const Matrix&);
    Matrix operator+(const Matrix&);

protected:
private:
    size_t row,col;
    vector<vector<ll>>element;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n,m;
    Matrix A;
    cin>>n>>m;
    Matrix B(n,m);
    A.resize(n,m);
    A.input(),B.input();
    (A+B).print();

    return 0;
}
Matrix::~Matrix(){
    element.clear();
}
void Matrix::resize(size_t row,size_t col){
    *this=Matrix(row,col);
    return;
}
void Matrix::input(){
    for(auto&k:element){
        for(auto &kk:k)cin>>kk;
    }
}
void Matrix::print(){
    for(auto&k:element){
        for(auto &kk:k)cout<<kk<<' ';
        cout<<'\n';
    }
}
Matrix Matrix::add(const Matrix&r){
    assert(row==r.row&&col==r.col);
    Matrix ret(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ret.element[i][j]=element[i][j]+r.element[i][j];
        }
    }
    return ret;
}
Matrix Matrix::operator+(const Matrix&r){
    return add(r);
}
