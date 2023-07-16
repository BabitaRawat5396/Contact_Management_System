//------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------
//------------------------------------TEACHER LOGIN  F U N C T I O N  F I L E --------------------------------------------------------------


#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

/*
This function has return type of void, It provides the plateform for teacher login by accepting mail id and password
*/
void Teacher_Login()
{
	//creating the varibale of teacher login structure
	struct Teacher_Login_Info teacher_login;
	
	//creating falg variable for validation and login_choice for storing the user choice
	int flag = 0, login_choice;
	
	//creating file pointer
	FILE *fptr;
	
	//variables for storing the teacher_id and password
	int Teacher_Id;
	char Password[20];
	
	//infinite loop
	while(1)
	{
		
		
		//Here user will input Teacher ID and after validation it will proceed for other inputs
		do
		{
			//Accepting the Teacher id 
			printf("\n\t\tEnter Teacher Id::\t");
			scanf("%d", &Teacher_Id);
			
			//validation of teacher id
			if(validate_id(Teacher_Id))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID ID...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
		
		
		flag =0;
		
		//Accepting the password from Admin
		printf("\n\t\tEnter Password::\t");
		scanf("%s", Password);
		
		//opening the file of admin details
		fptr = fopen("./DataBase/Teacher_Id_Password.txt", "r");
		
		//Accessing the elements from file and validating id or password
		
		while(fscanf(fptr,"%d%s",&teacher_login.Teacher_Id, teacher_login.Password)!= -1 )
		{
			
			//validating id and password
			if((teacher_login.Teacher_Id == Teacher_Id) && strcmp(teacher_login.Password,Password)==0)
			{
				flag = 1;
				break;
			}
		}
		
		//closing the file
		fclose(fptr);
		//if creadentials are not valid
		if(flag==0)
		{
			
			printf("\n\t\tYou enterd wrong Email_Id and Password.\n");
			printf("\n\t\t\t>[1]Do you want to login again?");
			printf("\n\t\t\t>[2]Do you want to exit");
			scanf("%d", &login_choice);
		
			//want to exit the application
			if(login_choice == 2)
			{
				printf("\n\t\tThanks for Visiting.\n");
				exit(0);
			}
			
		}//end of if
		else
		{
			break;
		}
	}//end of while
	printf("\n\t\tCongratulations, Please select one of the Operation::\n ");
	
	//after login we call the teacher options function for more options
	Teacher_Options(Teacher_Id);
	
	
}//end of teacher login function
