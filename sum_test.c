#include <stdio.h>
#include <stdlib.h>


// if OS is unix or linux, value OS has 1.

#ifdef __unix__
	# define OS 1
	# include <unistd.h>
	# include <termios.h>
	
	int getch(void)
	{
	    struct termios oldattr, newattr;
	    int ch;
	    tcgetattr( STDIN_FILENO, &oldattr );
	    newattr = oldattr;
	    newattr.c_lflag &= ~( ICANON | ECHO );
	    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	    ch = getchar();
	    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	    return ch;
	}
	
	
#elif __linux__
	# define OS 1
	# include <unistd.h>
	# include <termios.h>
	
	int getch(void)
	{
	    struct termios oldattr, newattr;
	    int ch;
	    tcgetattr( STDIN_FILENO, &oldattr );
	    newattr = oldattr;
	    newattr.c_lflag &= ~( ICANON | ECHO );
	    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	    ch = getchar();
	    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	    return ch;
	}

// if OS is windows, value OS has 2.
#elif defined _WIN32 
	# define OS 2
	# include <windows.h>
	# include <conio.h>
	
#endif

int clearScreen(void);
void sleepScreen(void);

int main(int argc, char * argv[]) {
	
	int i, sum = 0;
	
	char track[] = "취약점"; 
	char name[] = "윤석찬";
		
	
	clearScreen();
	
	
	// print my information
	printf("\n\t\t[bob6][%s]sum_test[%s]\n", track, name);
	printf("\n\n\n\t\tpress any key to get sum of 1 ~ 100\n");
	getch();
	
	
	clearScreen();
	
	
	for(i=0; i<=100; i++) {
		
		printf("\n\n\n\t\t%d%% loading.. ", i);
		sleepScreen();
		clearScreen();
		
		sum += i;
	}


	printf("\n\n\n\t\t\tThe sum (1 ~ 100) : %d\n\n\n\n\n", sum);

	return 0;

}


int clearScreen(void) {
	
	if (OS == 1) {	// OS == linux || OS == unix
		system("clear");
	} else if (OS == 2) {	// OS == windows
		system("cls");
	} else {
		printf("Sorry. My program doesn't support your OS.\n");
		return 1;
	}
	
}

void sleepScreen(void) {
	
	if (OS == 1) {
		usleep(5 * 1000);
	} else {
		Sleep(5);
	}
	
}



