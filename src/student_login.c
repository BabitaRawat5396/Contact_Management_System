//------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------------------------
//----------------------------------------------------------------------------STUDENT LOGIN  F U N C T I O N  F I L E --------------------------------------------------------------------------------

//including headr file
#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


/*
This function has return type of void, It provides the plateform to login as student by entering roll number and password
*/
void Student_Login()
{
	//creating variable for the student login info structure 
	struct Student_Login_Info student_login;
	
	//falg for validation, login choice for storing user choice
	int flag = 0, login_choice;
	
	//creating file pointer
	FILE *fptr;
	
	//variables for storing the creadentials 
	char Password[20];
	int Roll_No;
	
	while(1)
	{
		
		
		//Here user will input rollno and after validation it will proceed for other inputs
		do
		{
			//Accepting the Roll Number
			printf("\n\t\tEnter Roll Number::\t");
			scanf("%d", &Roll_No);
				
			//validating roll number
			if(validate_id(Roll_No))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID ROLLNO...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
		
		flag =0;//resetting 
		
		printf("\n");
		
		//Accepting the password from Admin
		printf("\n\t\tEnter Password::\t");
		scanf("%s", Password);
		
		//opening the file of admin details
		fptr = fopen("./DataBase/Student_Id_Password.txt", "r");
		
		
		//Accessing the elements from file and validating id or password	
		while(fscanf(fptr,"%d%s",&student_login.Roll_No, student_login.Password)!= -1 )
		{
			
			
			if((student_login.Roll_No == Roll_No) && strcmp(student_login.Password,Password)==0)
			{
				flag = 1;
				break;
			}
		}
		
		fclose(fptr);
		
		if(flag==0)
		{
			
			printf("\n\t\tYou enterd wrong Email_Id and Password.\n");
			printf("\n\t\t\t>[1]Do you want to login again?");
			printf("\n\t\t\t>[2]Do you want to leave this page");
			scanf("%d", &login_choice);
		
			if(login_choice == 2)
			{
				printf("\n\t\tThanks for Visiting.\n");
				exit(0);
			}
			
		}
		else
		{
			break;
		}
	}
	printf("\n\t\tCongratulations, Please select one of the Operation::\n ");
	Student_Options();
	
	
}
