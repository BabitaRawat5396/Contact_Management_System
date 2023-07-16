//------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------------------------
//----------------------------------------------------------------------------ADMIN_OPTIONS  F U N C T I O N  F I L E --------------------------------------------------------------------------------

//including header file
#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

/*
This function has return type of void, It provides the Options for admin
*/
void Admin_Options()
{
	//infinite loop
	while(1)
	{
		
		//variables for user choice 
		int choice;
		
		//menu for admin opeartions		
		printf("\n\t\t\t>[1] Update Details of Teacher.");
		printf("\n\t\t\t>[2] Update Details of Student.");
		printf("\n\t\t\t>[3] Search for Teacher.");
		printf("\n\t\t\t>[4] Delete The Details of Teacher.");
		printf("\n\t\t\t>[5] Insert The Details of New Teacher.");
		printf("\n\t\t\t>[6] Search For a Student.");
		printf("\n\t\t\t>[7] Delete the Details of Student.");
		printf("\n\t\t\t>[8] Insert the Details of New Student.\t");
		printf("\n\t\t\t>[0] EXIT\t");
		
		//asking user choice
		printf("\n\t\tEnter your Choice::\n\t");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case UPDATE_TEACHER:
				Update_Teacher();//calling update teacher function
				break;
				
			case UPDATE_STUDENT:
				Update_Student();//calling update Student function
				break;
			
			case SEARCH_TEACHER:
				Search_Teacher();//calling Search Teacher function
				break;
				
			case DELETE_TEACHER:	
				Delete_Teacher();//calling Delete teacher function
				break;
			
			case INSERT_TEACHER:
				Insert_Teacher();//calling insert teacher function
				break;
			
			case SEARCH_STUDENT:
				Search_Student();//calling Search Student function
				break;
				
			case DELETE_STUDENT:
				Delete_Student();//calling Delete Student function
				break;
				
			case INSERT_STUDENT:
				Insert_Student();//calling insert student function
				break;
				
			case EXIT_ADMIN:
				printf("\n\tThanks for visiting.........!!!!!!!!!!!");
				exit(0);//exiting from the application
				
			default:
				printf("\n\t\tYou Entered a Wrong Choice. select the correct one.");
			
		
		
	
		}//end of switch
	
	}//end of while loop
		
}//end of function
