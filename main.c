#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "u_mount.h"
#include "start_term.h"


void 
print_menu()
{
	printf( "1. Mount device\n"
		   	"2. Unmount device\n"
			"3. Open mounted device in terminal\n"
			"4. Exit\n");
}

int 
get_choice()
{
	char choice[2];

	system("clear");
	print_menu();
	fgets(choice, 2, stdin);
	getchar();

	while(!isdigit(choice[0])) 
	{
		system("clear");
		print_menu();
		fgets(choice, 2, stdin);
		getchar();
		printf("The choice must be a number listed from above, please try again.\n");	
	}
	
 	return atoi(choice);
}

int 
main()
{
	int indicator, choice;

	indicator = 1;
	while(indicator)
	{
		choice = get_choice();
		switch(choice)
		{
			case 1:
				system("clear");
				mount(NULL);
				printf("DONE!\n");
				sleep(3);
				break;
			case 2:
				system("clear");
				umount(NULL);
				printf("DONE!\n");
				sleep(3);
				break;
			case 3:
				if(opened)
					start_terminal();
				else
					printf("There is no  devices mounted by this program.\n");
				break;
			case 4:
				indicator = 0;
				break;
			default: 
				indicator = 1;
		}
	}	
	printf("Goodbye!\n");
	exit(EXIT_SUCCESS);
}	
