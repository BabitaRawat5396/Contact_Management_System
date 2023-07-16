//---------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L------------------------------------
//----------------------------------------TEACHER_OPTIONS  F U N C T I O N  F I L E -----------------------------------------------------------


//includeing the header file
#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

/*
This function has return type of void, It provides the Options for teachers
*/


void Teacher_Options(int Teacher_Id)
{
	//variable n is for checking the class teacher if function returns value 2, simple teacher if functions return 1
	int n = Teacher_By_ID(Teacher_Id, 1);
	
	//falg for checking validation and choice for storing the choice of user
	int choice;
	
	//infinite loop
	while(1)
	{	
		//menu for Teacher opeartions
		printf("\n\t\t\t>[1] Search for a Teacher.");
		printf("\n\t\t\t>[2] Serach for Student.");
		
		//only for class teacher
		if(n == 2)
		{
			printf("\n\t\t\t>[3] Update The Details of Student.");//for class teacher
		}
		
		printf("\n\t\t\t>[0] Exit.");
	
		//asking for choice
		printf("\n\t\tEnter your Choice::\n\t");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case SEARCH_TEACHER_T:
				Search_Teacher();//calling search teacher
				return;
				
			case SEARCH_STUDENT_T:
				Search_Student();//callig search student
				return;
					
			case UPDATE_DETAILS_T://for class teacher
				Update_Student();//calling update student
				return;
				
			case EXIT_TEACHER:
				printf("\n\tThanks For Visiting\n");
				return;
					
			default:
				printf("\n\t\tYou Entered a Wrong Choice. Please select the correct one.");
				
					
		}//end of switch
		
		
	}//end of while
	
	
		
}//end of function




























