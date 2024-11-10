#include<stdio.h>
int graph[1001][1001] = { 0 };
int visited[1001] = { 0 };
int queue[1001];

void DFS(int n, int v) {
	visited[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (graph[v][i]==1 && !visited[i])
			DFS(n, i);
	}
}

void BFS(int n, int v) {
	int front = 0, rear = 1, pop;
	printf("%d ", v);
	visited[v] = 1;
	queue[0] = v;
	while (front < rear) {
		pop = queue[front++];
		for (int i = 1; i <= n; i++) {
			if (graph[pop][i] == 1 && !visited[i]) {
				printf("%d ", i);
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	int x, y;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	DFS(N, V);
	printf("\n");
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
	BFS(N, V);
	return 0;
}
