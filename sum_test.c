#include <stdio.h>

int main(int argc, char * argv[]) {
	
	int i, sum;
	
	for(i=0; i<=100; i++) {
		sum += i;
	}

	printf("%d\n", sum);

	return 0;

}
