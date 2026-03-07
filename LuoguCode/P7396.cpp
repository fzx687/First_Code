#include <iostream>
#include <algorithm>
using namespace std;
constexpr int MAXN = 105;
constexpr int INF = 1e9;
int d[MAXN];
int f[400 * MAXN];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> d[i];
        }
        sort(d+1,d+n+1);
        double tmp;
        cin >> tmp;
        int m = (int)(tmp * 100.0);
        for (int i = 1; i <= m; i++) f[i] = INF;
        f[0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = d[i]; j <= m; j++){
                f[j] = min(f[j],f[j-d[i]] + 1);
            }
        }
        cout << f[m] << endl;
    }
    return 0;
}