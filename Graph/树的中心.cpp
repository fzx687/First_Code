#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int d1[N],d2[N];// the length of the longest and the second longest path in the subtree of x
int up[N];// the length of the longest path not in the subtree of x
int ans1 , ans2;// 可能有一个答案，也可能有两个答案
int mini = 1e9;
int n;
struct node{
    int to;
    int val;
};
vector<node> E[N];
void dfsd(int u,int fa){ // solve d1 and d2
    for (auto nxtn : E[u]){
        int v = nxtn.to;
        int w = nxtn.val;
        if(fa == v) continue;
        dfsd(v,u);
        if(d1[u] < d1[v] + w){
            d1[u] = d1[v] + w;
        }else if(d2[u] < d1[v] + w){
            d2[u] = d1[v] + w;
        }
    }
}
void dfsu(int u,int fa) {// solve up
    for (auto nxtn : E[u]){
        int v = nxtn.to;
        int w = nxtn.val;
        if(fa == v) continue;
        up[v] = up[u] + w;//directly up
        if(d1[v] + w != d1[u]){
            up[v] = max(up[v], d1[u] + w); // up to u and then down to another chain
        }else {
            up[v] = max(up[v], d2[u] + w);// the longest chain is coinident , so choose the second longest chain
        }
        dfsu(v,u);
    }
}
void GetTreeCenter() {  // 统计树的中心，记为x和y（若存在）
  dfsd(1, 0);
  dfsu(1, 0);
  for (int i = 1; i <= n; i++) {
    if (max(d1[i], up[i]) < mini) {  // 找到了当前max(len1[x],up[x])最小点
      mini = max(d1[i], up[i]);
      ans1 = i;
      ans2 = 0;
    } else if (max(d1[i], up[i]) == mini) {  // 另一个中心
      ans2 = i;
    }
  }
}
int main(){

    return 0;
}