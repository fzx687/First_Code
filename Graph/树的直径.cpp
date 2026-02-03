#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n;
vector <int> E[N];
int d[N];
int furthest_point = 1;
int dfs(int id,int fa){
    for (int x:E[id]){
        if(x == fa) continue;
        d[x] = d[id] + 1;
        if(d[x] > d[furthest_point]){
            furthest_point = x;
        }
        dfs(x,id);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1,0);
    d[furthest_point] = 0;
    dfs(furthest_point,0);
    cout << d[furthest_point];
    return 0;
}