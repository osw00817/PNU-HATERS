/*2차원 배열 동적 메모리 할당, 줄 6개 각각 마다 stack을 2차원 배열로 따로 만들고
각 줄 6개에 해당하는 top 배열도 만들어줌, 행은 6, 열은 플렛의 수
push 와 pop 이 진행될 때마다 count 증가*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int **stack, top[6] = {-1, -1, -1, -1, -1, -1}, cnt = 0;

void push(int string, int flat);
void pop(int string);

int main(void)
{
	int N, P, string, flat, tmp;
	scanf("%d %d", &N, &P);

	stack = (int**)malloc(sizeof(int*) * 6);

	for (int i = 0; i < 6; i++) {
		stack[i] = (int*)malloc(sizeof(int) * P); //플렛의 크기만큼 열의 크기 결정
	}

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &string, &flat);
		tmp = stack[string - 1][top[string - 1]];
		if (flat > tmp) push(string, flat); //입력되는 플렛이 해당 스텍의 top 보다 크면 push
		else if (flat < tmp) {
			while (stack[string - 1][top[string - 1]] > flat) pop(string);
			if (stack[string - 1][top[string - 1]] < flat) push(string, flat); //pop 을 한후 입력된 플렛 값보다 작으면 push 같으면 pass
		}
		else continue; //같을 땐 pass
	}
	printf("%d", cnt);
}

void push(int string, int flat)
{
	stack[string - 1][++top[string - 1]] = flat; //배열 인덱스를 0부터 5로 할당했기 때문에 string -1 해야함
	cnt++;
}

void pop(int string)
{
	--top[string - 1];
	cnt++;
}
