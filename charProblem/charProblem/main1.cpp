#include <stdio.h>
#include<stdlib.h>
int main() {
	char *str = "Hello World!";
	str = "I love C!";  //ÕıÈ·
	*(str+3) = 'P';  //´íÎó
	puts(str);
	return 0;
}