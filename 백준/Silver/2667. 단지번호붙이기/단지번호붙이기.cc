#include<bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int cnt;

void dfs(int x, int y, vector<vector<char>> &a, vector<vector<int>> &v) {
    v[x][y] = 1;
    for(int i=0;i<4;i++){
        int tmpx = x+dx[i];
        int tmpy = y+dy[i];
        if(v[tmpx][tmpy]==0 && a[tmpx][tmpy]=='1'){
            dfs(tmpx, tmpy, a, v);
        }
    }
    cnt++;
}

int main() {
    int n,i,j;
    cin>>n;

    vector<vector<char>> arr(n+2, vector<char> (n+2));
    vector<vector<int>> visit(n+2, vector<int> (n+2));
    vector<int> ans;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) cin>>arr[i][j];
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(arr[i][j]=='1' && !visit[i][j]){
                cnt = 0;
                dfs(i, j, arr, visit);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() <<'\n';
    for(i=0;i<ans.size();i++) cout << ans[i] << '\n';
}
