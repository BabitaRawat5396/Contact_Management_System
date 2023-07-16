#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

/*
This function has return type of void, It displays the menu for the login page
*/
void displayMenu()
{
	
	//variable for storing the choice from user
	int choice;
	//Displaying the menu bar with welcome message
	while(1)
	{
		printf("\n---------------------------C O N T A C T  M A N A G E M E N T  S Y S T E M--------------------------\n");
		printf("\n\t\t\t>[1] Login as Admin.");
		printf("\n\t\t\t>[2] Login as Teacher.");
		printf("\n\t\t\t>[3] Login as Student.");
		printf("\n\t\t\t>[0] EXIT.");
	
		//accepting the choice from user
	
	
		//falg variable for chaceking the choice validation
		int flag = 0;
		
		//asking user choice
		printf("\n\n\t\tEnter Your Choice::\t");
		scanf("%d", &choice);
	
	
		switch(choice)
		{
			case ADMIN_LOGIN:
				Admin_Login();//calling admin login fucntion
				break;
			case TEACHER_LOGIN:
				Teacher_Login();//calling teacher login function
				break;
			case STUDENT_LOGIN:
				Student_Login();//calling student login function
				break;
			case EXIT_MENU:
				printf("\n\t\tThanks for visiting");
				exit(0);
			default:
				flag = 1;
				printf("\n\t\tYou entered a wrong Choice.");
		}
		
		if(flag ==1)//asking for to choose again 
		{
			printf("\n\t\tWant to choose again:\n\t\t\t>[1] Yes \n\t\t\t>[2] No");
			scanf("%d", &choice);
			
			if(choice == 1)
			{
				continue;
			}
			else
			{
				printf("\n\t\tThanks for Visiting.\n");
				exit(0);//exiting from the application
			}
		}//end of if
	}//end of while	
}//end of display menu
