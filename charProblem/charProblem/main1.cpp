#include <stdio.h>
#include<stdlib.h>
int main() {
	char *str = "Hello World!";
	str = "I love C!";  //��ȷ
	*(str+3) = 'P';  //����
	puts(str);
	return 0;
}