#include <stdio.h>
#include <string.h>

int main(void) {
	char str[251];
	while (1) {
		int a, sum=0;
		fgets(str, 251, stdin);
		a = str[0];
		if (a == '#')
			return 0;
		else
			for (int i = 1; i < strlen(str); i++)
				if (a == str[i])
					sum += 1;
				else if (a == str[i] + 32)
					sum += 1;
		printf("%c %d\n",a,sum);
	}
}
