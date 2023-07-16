//------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------------------------
//----------------------------------------------------------------------------STUDENT_OPTIONS  F U N C T I O N  F I L E --------------------------------------------------------------------------------



#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

/*
This function has return type of void, It provides the Options for students
*/

void Student_Options()
{
	//infinite loop
	while(1)
	{
		//variable for validation and user choice
		int choice;
	
		//menu for admin opeartions	
		printf("\n\t\tSelect the option::\n\t");
		printf("\n\t\t\t1. Search for student");
		printf("\n\t\t\t2. Search for Teacher");
		printf("\n\t\t\t0. Exit");
		
		printf("\n\t\tEnter The Choice::\t");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case SEARCH_STUDENT_S:
				Search_Student();//calling serach student
				break;
				
			case SEARCH_TEACHER_S:
				Search_Teacher();//calling search teacher function
				break;
			
			case EXIT_STUDENT:
				printf("\n\tThanks For Visiting.\n");
				exit(0);
				
			default:
				printf("\n\t\tYou Entered a Wrong Choice. Please select the correct one.");
				
				
	
		}//end of switch
		
	}//end of while
	
	
		
}//end of function




























