#include<stdio.h>
#include<stdlib.h>

int compare(void *a,void *b) {
	return *(int*)a - *(int*)b;
}
int main(){
	int N = 0;
	int people = 0, sum = 0;
	scanf("%d", &N);
	int* time = malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++){
		scanf("%d", &time[i]);
	}
	qsort(time, N, sizeof(int), compare);

	for (int i = 0; i < N; i++){
		people += time[i];
		sum += people;
	}
	
	printf("%d", sum);
	free(time);
	return 0;
}
