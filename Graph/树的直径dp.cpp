#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+ 10;
int n;
vector<int> E[N];
int dp[N];
int ans;
void dfs(int u,int fa){
    for (int v : E[u]){
        if(v == fa) continue;
        dfs(v,u);
        ans = max(ans,dp[v] + dp[u] + 1);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1,0);
    cout << ans;
    return 0;
}