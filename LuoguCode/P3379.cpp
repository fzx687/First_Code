#include <iostream>
#include <vector>
using namespace std;
constexpr int MAXN = 5e5 + 10;
vector<int> G[MAXN];
int fa[MAXN][31];
int dep[MAXN];
void dfs(int x,int f){
    fa[x][0] = f;
    dep[x] = dep[f] + 1;
    for (int i = 1; i < 31; i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for (auto &v:G[x]){
        if(v != f){
            dfs(v,x);
        }
    }
}
int lca(int x,int y){
    if (dep[x] > dep[y]) swap(x, y);
    int tmp = dep[y] - dep[x];
    for (int j = 0; tmp; ++j, tmp >>= 1)
        if (tmp & 1) y = fa[y][j];
    if (y == x) return y;
    for (int j = 30; j >= 0 && y != x; --j) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main(){
    int n,m,s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(s,0);
    for (int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << endl;
    }
    return 0;
}