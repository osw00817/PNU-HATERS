#include <stdio.h>
#include <stdlib.h>
#define MAX 500
//Building structure : time to build, pre_building number, pre_building count
typedef struct Building {
	int time;
	int pre_b_number[MAX];
	int link_ls_len;
}Building;

int memo[MAX] = {0};
Building** B_list;
int total_time(Building* B, int number);

int main(void)
{
	int N, tmp;
	scanf("%d", &N);

	B_list = malloc(N * sizeof(*Building)); //  array to store building

	for (int i = 0; i < N; i++) {
		B_list[i] = malloc(sizeof(Building));

		scanf("%d", &tmp);
		B_list[i]->time = tmp;

		int idx = 0;
		while (1) {
			scanf("%d", &tmp);
			if (tmp == -1) break;
			B_list[i]->link_ls[idx++] = tmp; // store pre_building number
		}
		B_list[i]->link_ls_len = idx;
	}

	for (int j = 0; j < N; j++) {
		printf("%d\n", total_time(B_list[j]), j+1);
	}
	for (int j = 0; j < N; j++) free(B_list[j]);
	free(B_list);
}

//calculate total time to build
int total_time(Building* B, int number)
{
	// if there is no  pre_B, then return the time.
	if (B->link_ls_len == 0) {
		memo[number] = B->time;
		return B->time;
	}
	//to find max time between pre_B time
	int max = 0;
	int tmp;
	for (int i = 0; i < link_ls_len; i++) {
		//if there is no preB time in memo, store new calculated time in memo
		int preB = B->pre_b_number[i];
		if (memo[preB] == 0) {
			memo[preB] = total_time(B_list[preB - 1], preB);
		}
		tmp = memo[preB];

		if (tmp > max) max = tmp;
	}
	
	return max + B->time;
}
