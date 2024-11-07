#include<stdio.h>
#define MAX 501
int main() {
	int N,t,num;
	//time이랑 res는 시간 저장, pre는 i번째에서 전에 지어야할 건물이 몇개 있는지
	int time[MAX] = { 0 }, res[MAX] = { 0 }, pre[MAX] = { 0 };
	//graph[i][j]는 i번째 건물이 j번째 건물에서 필요한지
	int graph[MAX][MAX] = { 0 }, que[MAX];
	int front = 0, rear = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N;i++) {
		scanf("%d", &t);
		time[i] = res[i] = t;
		while (1) {
			scanf("%d", &num);
			if (num == -1) break;
			graph[num][i] = 1;
			pre[i]++;
		}
		if (pre[i] == 0)
			que[rear++] = i;
	}
	while (front < rear) {
		int idx = que[front++];
		for (int j = 1; j <= N; j++) {
			if (graph[idx][j] == 1) {
				res[j] = (res[j] > res[idx] + time[j]) ? res[j] : res[idx] + time[j];
				if (--pre[j] == 0)
					que[rear++] = j;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", res[i]);
	return 0;
}
