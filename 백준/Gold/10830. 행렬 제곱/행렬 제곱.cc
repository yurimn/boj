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
    Matrix();
    Matrix(size_t);
    Matrix(size_t,size_t);
    ~Matrix();
    void resize(size_t);
    void resize(size_t,size_t);
    istream& input(istream&);
    ostream& print(ostream&)const;
    Matrix add(const Matrix&)const;
    Matrix mul(const Matrix&)const;
    Matrix mod(const ll)const;
    Matrix powm(const ll,const ll)const;
    Matrix operator+(const Matrix&)const;
    Matrix operator+=(const Matrix&);
    Matrix operator*(const Matrix&)const;
    Matrix operator*=(const Matrix&);
    Matrix operator%(const ll&)const;
    Matrix operator%=(const ll&);

protected:
private:
    size_t row,col;
    vector<vector<ll>>element;
};

istream& operator>>(istream&l, Matrix&r){
    return r.input(l);
}
ostream& operator<<(ostream&l, const Matrix&r){
    return r.print(l);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n,m;
    Matrix A,B;
    cin>>n>>m;
    A.resize(n);
    cin>>A;
    cout<<A.powm(m,1000);
    return 0;
}
Matrix::Matrix(){
    *this=Matrix(0,0);
}
Matrix::Matrix(size_t row,size_t col):
    row(row),
    col(col),
    element(vector<vector<ll>>(row,vector<ll>(col))){}
Matrix::Matrix(size_t rowcol){
    *this=Matrix(rowcol,rowcol);
}

Matrix::~Matrix(){
    element.clear();
}
void Matrix::resize(size_t rowcol){
    *this=Matrix(rowcol);
    return;
}
void Matrix::resize(size_t row,size_t col){
    *this=Matrix(row,col);
    return;
}
istream& Matrix::input(istream&is){
    for(auto&k:element){
        for(auto &kk:k)is>>kk;
    }
    return is;
}
ostream& Matrix::print(ostream&os)const{
    for(auto&k:element){
        for(auto &kk:k)os<<kk<<' ';
        os<<'\n';
    }
    return os;
}
Matrix Matrix::add(const Matrix&r)const{
    assert(row==r.row&&col==r.col);
    Matrix ret(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ret.element[i][j]=element[i][j]+r.element[i][j];
        }
    }
    return ret;
}
Matrix Matrix::operator+(const Matrix&r)const{
    return add(r);
}
Matrix Matrix::operator+=(const Matrix&r){
    return *this=*this+r;
}
Matrix Matrix::mul(const Matrix&r)const{
    assert(col==r.row);
    Matrix ret(row,r.col);
    for(int i = 0; i< row; i++) {
        for(int j = 0; j< r.col; j++) {
            for(int k = 0; k < col; k++){
                ret.element[i][j] += element[i][k] * r.element[k][j];
            }
        }
    }

    return ret;
}
Matrix Matrix::operator*(const Matrix&r)const{
    return mul(r);
}
Matrix Matrix::operator*=(const Matrix&r){
    return *this=(*this)*r;
}

Matrix Matrix::mod(const ll r)const{
    Matrix ret=*this;
    for(auto&k:ret.element){
        for(auto&kk:k)kk%=r;
    }
    return ret;
}
Matrix Matrix::operator%(const ll&r)const{
    return mod(r);
}
Matrix Matrix::operator%=(const ll&r){
    return *this=*this%r;
}

Matrix Matrix::powm(const ll r,const ll _mod=1000) const{
    assert(row==col);
    Matrix ret(row,col);
    for(int i=0;i<row;i++)ret.element[i][i]=1;
    if(r==0)return ret;
    else{
        ret=powm(r>>1,_mod);
        ret*=ret;
        ret%=_mod;
        if(r&1)ret*=*this;
        return ret%_mod;
    }
}
