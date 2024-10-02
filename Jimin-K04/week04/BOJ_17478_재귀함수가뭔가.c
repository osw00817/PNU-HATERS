#include <stdio.h>

char say[4][130] = { "\"재귀함수가 뭔가요?\"",
					"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
					"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
					"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" }; //배열 선언
char ans[3][65] = { "\"재귀함수가 뭔가요?\"\n", "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", "라고 답변하였지."}; //마지막에 줄바꿈이 되면 안되므로 문자열 자체에서 줄바꿈 처리

void Space(int space);
void RF(int N, int space);
int main(void)
{
	int N;
	scanf("%d", &N);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	RF(N, 0);
}

void RF(int N, int space) //space * 4 가 언더바 수임, space 는 무조건 0부터 시작
{
	if (N == 0) {
		for (int i = 0; i < 3; i++) {
			Space(space); // 언더바 출력
			printf("%s", ans[i]);
		}
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			Space(space);
			printf("%s\n", say[i]);
		}
		RF(N - 1, space + 1);
		printf("\n");// 라고 답변하였지 의 마지막 줄바꿈을 없에기 위해 먼저 줄바꿈을 해줌
		Space(space);
		printf("라고 답변하였지.");
	}
}

void Space(int space) //언더바 출력하는 함수
{
	for (int j = 0; j < space * 4; j++) printf("_");
}
