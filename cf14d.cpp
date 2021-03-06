#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 205;

int dep, n, map[MAX_N][MAX_N];

int dfs(int u, int v) {
    int max1 = 0, max2 = 0, path_max = 0;
	for(int i = 1; i <= n; ++i){
        if(map[i][u] && i != v){
            int z = dfs(i, u);
            if(path_max < z) path_max = z;
            if(max1 < dep){
                max2 = max1;
                max1 = dep;
            } else if(max2 < dep) max2 = dep;
        }
    }
    if(path_max < max1 + max2) path_max = max2 + max1;
    dep = max1 + 1;
    return path_max;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		map[u][v] = map[v][u] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (map[i][j]) {
				int a = dfs(i, j);
				int b = dfs(j, i);
				ans = max(ans, a * b);
			}
		}
	}
    printf("%d\n", ans);
    return 0;
}
