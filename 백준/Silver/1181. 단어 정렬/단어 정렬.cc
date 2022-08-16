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

int n;
vector<string> v;

bool compare(string &a, string &b) {
    if(a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}
int main()
{
    cin >> n;
    v.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v), compare);
    v.erase(unique(all(v)), v.end());
    for(string k:v){
        cout << k << '\n';
    }
}
