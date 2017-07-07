#include <stdio.h>

int main(int argc, char * argv[]) {
	
	int i, sum = 0;
	
	char track[] = "취약점"; 
	char name[] = "윤석찬";
	printf("[bob6][%s]sum_test[%s]\n", track, name);	
	
	for(i=0; i<=100; i++) {
		sum += i;
	}

	printf("%d\n", sum);

	return 0;

}
