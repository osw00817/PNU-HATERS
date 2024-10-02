#include <stdio.h>
#include <stdlib.h>

int *queue, front, rear, f_num, n_th;

void initqueue(void);
void enqueue(int X);
int dequeue(void);
int main(void)
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int cnt = 0, num;
		initqueue();
		scanf("%d %d", &f_num, &n_th);

		for (int j = 0; j < f_num; j++) {
			scanf("%d", &num);
			enqueue(num);
		}
		while (1) {
			int check = 0;
			for (int j = front + 1; j != rear; j = (j+1) % (f_num+1)) {
				if (queue[j] > queue[front]) {
					if (front == n_th) n_th = rear;
					enqueue(dequeue());
					check = 1;
					break;
				}
			}
			if (!check) {
				if (front == n_th) {
					printf("%d\n", cnt + 1);
					break;
				}
				dequeue();
				cnt++;
			}
		}
	}
	free(queue);
}

void initqueue(void)
{
	queue = malloc(sizeof(int) * (f_num + 1));
	front = 0;
	rear = 0;
}
void enqueue(int X)
{
	queue[rear] = X;
	rear = (rear + 1) % (f_num + 1);
}
int dequeue(void)
{
	int tmp = queue[front];
	front = (front + 1) % (f_num + 1);
	return tmp;
}
