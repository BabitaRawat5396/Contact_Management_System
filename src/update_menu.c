#include "Con_Man_Sys.h"
#include "Con_Man_Sys_Struct.h"

//menu for the admin update function
void update_menu()
{
	//for storing user choice
	int choice;
	
	printf("\t\t\t[1]Update Student Details\n\
		\t\t[2]Update Teacher Details\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case UPDATE_TEACHER: 
			Update_Teacher();//call update teacher
			break;
		case UPDATE_STUDENT: 
			Update_Student();//call update student function
			break;
	}
	
	return;
}
	
	
