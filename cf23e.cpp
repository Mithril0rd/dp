#include <cstdio>
#include <cstring>

const int MAX_N = 100007;

int n;
bool vis[MAX_N];
int end[MAX_N], ans[MAX_N];
int E[MAX_N], in[MAX_N];

void dfs(int u) {
	if (~end[u]) return ;
	if (vis[u]) {
		end[u] = u;
		return ;
	}
	vis[u] = true;
	dfs(E[u]);
	end[u] = end[E[u]];
}

int main() {
	scanf("%d", &n);
	memset(end, -1, sizeof end);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &E[i]);
		++in[E[i]];
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0) {
			dfs(i);
			ans[cnt++] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
			ans[cnt++] = i;
		}
	}
	if (cnt == 1 && end[ans[0]] == ans[0]) {
		puts("0");
	} else {
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++i) {
			printf("%d %d\n", end[ans[(i + 1) % cnt]], ans[i % cnt]);
		}
	}
	return 0;
}
