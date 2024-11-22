#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int geasan(int su, int gobhagi, int namerge) {
	if (gobhagi == 0)
		return 0;
	else if (gobhagi == 1) {
		return su;
	}
	else {
		int ans = geasan(su, gobhagi / 2, namerge);
		int result = (gobhagi % 2 == 1) ? (su * ((ans * ans) % namerge)) % namerge : (ans * ans) % namerge;
		return result;

	}
}

int main() {
	int su, gobhagi, namerge;
	scanf("%d %d %d", &su, &gobhagi, &namerge);
	printf("%d", geasan(su, gobhagi, namerge));
}