//-----------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------
//------------------------------ADMIN_LOGIN  F U N C T I O N  F I L E -----------------------------------------


//including header file
#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


/*
This function has return type of void, It provides plateform to enter mail id and password also validate them
*/
void Admin_Login()
{
	// creating variable of admin login info structure
	struct Admin_Login_Info admin_login;
	
	//defining the int variable flag for validation and login_choice for selecting the choice
	int flag = 0, login_choice;
	
	//Creating the file pointer
	FILE *fptr;
	
	//creating strings for storing the user entered email id and passowrd
	char Email_Id[25], Password[20];
	

	//infinite loop
	while(1)
	{
		//Do While loop for entering valid email id
		do
		{
			//Accepting the Email id from Admin
			printf("\n\t\tEnter Email Id::\t");
			scanf("%s", Email_Id);	
			
			//validating the Gmail id
			if(Gmail_Validation(Email_Id))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID EMAIL ID...!!!!\n");
				flag = 0;
			}
			
		}while(flag==0);
		
		printf("\n");
		
		flag = 0;//resetting the flag variable
		
		
		//Accepting the password from Admin
		printf("\n\t\tEnter Password::\t");
		scanf("%s", Password);
		
		//opening the file of admin details
		fptr = fopen("./DataBase/Admin_Id_Password.txt", "r");
		
		//Accessing the elements from file and validating id or password
		while(fscanf(fptr,"%s%s",admin_login.Email_Id, admin_login.Password)!= -1 )
		{
			
			//validating the user eneterd email id and password
			if(strcmp(admin_login.Email_Id, Email_Id)==0 && strcmp(admin_login.Password,Password)==0)
			{
				flag = 1;
				break;
			}
		
		}//end of inner while loop
		
		
		//closing the file
		fclose(fptr);
		//for wrong creadentials
		if(flag==0)
		{
			//asking for using after entering the wrong credentials
			printf("\n\t\tYou enterd wrong Email_Id and Password.\n");
			printf("\n\t\t\t>[1]Do you want to login again?");
			printf("\n\t\t\t>[2]Do you want to leave this page");
			scanf("%d", &login_choice);
		
			//for exiting 
			if(login_choice == 2)
			{
				printf("\n\t\tThanks for Visiting.\n\n");
				exit(0);
			}
			
		}//end of if
		else
		{
			break;
		}
	
	}//end of outer while loop
	
	//after login we call the Admin_Options functions for more options
	printf("\n\t\tCongratulations, Please select one of the Operation:\n ");
	Admin_Options();
	
	
}//end of Admin_Login();





