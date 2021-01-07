#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

const int MAX = 501;

int wei[MAX], visit[MAX], map[MAX][MAX];

int mind, cnt, maxt, n;

void init(int n) {
	int i, j;

	for (i = 0; i < n; ++i) {
		visit[i] = 0;
		for (j = 0; j < n; ++j) {
			map[i][j] = INT_MAX;
		}
	}
}

void dfs(int p, const int end, int dist, int weit) {
	if (p == end) {
		if (dist < mind) {
			cnt = 1;
			mind = dist;
			maxt = weit;
		}
		else if (dist == mind) {
			++cnt;
			if (maxt < weit) {
				maxt = weit;
			}
		}
		return;
	}

	int i;

	if (dist > mind)return;//这个地方不剪枝的话最后一个case过不去

	for (i = 0; i < n; ++i) {
		if (visit[i] == 0 && map[p][i] != INT_MAX) {
			visit[i] = 1;
			dfs(i, end, dist + map[p][i], weit + wei[i]);
			visit[i] = 0;
		}
	}

}

int main() {
	int m, st, end, x, y, d, i;
	mind = INT_MAX;
	cnt = 0;

	scanf("%d %d %d %d", &n, &m, &st, &end);
	init(n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &wei[i]);
	}
	while (m--) {
		scanf("%d %d %d", &x, &y, &d);
		if (map[x][y] > d) {
			map[x][y] = map[y][x] = d;
		}
	}
	dfs(st, end, 0, wei[st]);

	printf("%d %d\n", cnt, maxt);

	return 0;
}