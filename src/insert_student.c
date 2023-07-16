//------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------------------------
//----------------------------------------------------------------------------INSERT_STUDENT  F U N C T I O N  F I L E --------------------------------------------------------------------------------


#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//This Function doesn't return anything(it is of void type), it's work is to take input from user about the student's details and insert the data into Student personal details file.
// Also this function will take student login info and store it in the Student Login details file


void Insert_Student()
{
	//for clearing screen
	system("cls");

	
	FILE *file_ptr_details; //Declaring file pointer to the file which contains student details
	FILE *file_ptr_Login; //Declaring file pointer to the file containing Id, Password details of students
	
	//Declaring variable of student structure
	Student stud;
	
	char ch;
	int flag,i=0;
	int numberRead=0;
	
	//Opening the Student Personal details file
	file_ptr_details = fopen("./DataBase/Student_Contact_System_file.txt","a");
	
	
	//Opening Student Login details file
	file_ptr_Login = fopen("./DataBase/Student_Id_Password.txt","a");
	
	
	//Checking if File opened is AVAILABLE or NOT
	if(file_ptr_details == NULL)
	{
		printf("\n\n\tFile containing teacher's details is NOT AVAILABLE");
		exit(0);
	}
	
	if(file_ptr_Login == NULL)
	{
		printf("\n\n\tFile containing teacher's Login details is NOT AVAILABLE");
		exit(0);
	}
	
	
	
	//Accepting Students Details
	do
	{
		printf("\n\n\tEnter the Details of the Student :: %d",i+1);
		i++;
		printf("\n\n");
		
		//Here user will input rollno and after validation it will proceed for other inputs
		do
		{
			printf("\n\t\tEnter the Roll No : ");
			numberRead = scanf("%d",&stud.student_login.Roll_No);
			
			//while loop to ensure that entered value is an integer value
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tEnter the Roll No : ");
				numberRead = scanf("%d",&stud.student_login.Roll_No);
			}
				
			if(validate_id(stud.student_login.Roll_No))
				flag=1;
			else
			{
				printf("\n\t\tINVALID ROLLNO...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
			
		
		
		//Do While loop for entering valid Password
		do
		{
			//Accepting the password from Admin
			printf("\n\t\tEnter Password(Should contain one special character, lowercase charcter and uppercase character with digits):  ");
			
			scanf("%s",stud.student_login.Password);
		
			//validating the Gmail id
			if(Password_Validation(stud.student_login.Password))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID PASSWORD...!!!! Please check the format\n");
				flag = 0;
			}
			
		}while(flag==0);
		
		
		printf("\n\t\tFirst Name : ");
		scanf("%s",stud.details.First_Name);
		
		
		printf("\n\t\tLast Name : ");
		scanf("%s",stud.details.Last_Name);
		
		//Loop for entering only positive age 
		do
		{
			printf("\n\t\tAge : ");
			numberRead = scanf("%d",&stud.details.Age);
			
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tAge : ");
				numberRead = scanf("%d",&stud.details.Age);
			}
			
			if(stud.details.Age<2)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter age greater than 2.\n");
				flag=0;
				
			}
			else
			{
				flag=1;
			}
		}while(flag==0);
		
		
		//Do While loop for correct class number that is 1 to 12
		do
		{
			printf("\n\t\tClass : ");
			numberRead = scanf("%d",&stud.Class);
			
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tClass : ");
				numberRead = scanf("%d",&stud.Class);
			}
			
			if(stud.Class<0 || stud.Class>12)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter class between 1 to 12.\n");
				flag=0;
				
			}
			else
			{
				flag=1;
			}
		}while(flag==0);
		
		//Do While loop to check user has entered correct Alphabet for Gender
		do
		{
			printf("\n\t\tGender (M/F)or(m/f) : ");
			scanf(" %c",&stud.details.Gender);
		
			
			if(stud.details.Gender=='F' || stud.details.Gender=='M' || stud.details.Gender=='f' || stud.details.Gender=='m')
				flag=1;
			else
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter (F/M) or (f/m).\n");
				flag=0;
			}
		}while(flag==0);
		
		
		//Taking Date of birth as input and then validating it using dob_validate function
		do
		{
			printf("\n\t\tDate Of Birth (DD/MM/YYYY) : ");
			numberRead = scanf("%d/%d/%d",&stud.dob.day,&stud.dob.month,&stud.dob.year);
		
			while(numberRead !=3)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				
				printf("\n\t\tDate Of Birth (DD/MM/YYYY) : ");
				while(getchar()!='\n');
				numberRead = scanf("%d/%d/%d",&stud.dob.day,&stud.dob.month,&stud.dob.year);
			}
			
			if(dob_validate(stud.dob))
				flag=1;
			else
			{
				printf("\n\t\tINVALID Date OF Birth...!!!!\n\t\tPlease enter valid DOB.\n");
				flag=0;
			}
		}while(flag==0);
		
		
		
		printf("\n\t\tAddress : ");
		while(getchar()!='\n');
		fgets(stud.details.Address,50,stdin);
		stud.details.Address[strlen(stud.details.Address)-1] = '\0';
		
		printf("\n\t\tMothers Name : ");
		fgets(stud.Mothers_Name,20,stdin);
		stud.Mothers_Name[strlen(stud.Mothers_Name)-1] = '\0';
		
		printf("\n\t\tFathers Name : ");
		fgets(stud.Fathers_Name,20,stdin);
		stud.Fathers_Name[strlen(stud.Fathers_Name)-1] = '\0';
		
		
		//Do While loop for entering valid email id
		do
		{
			printf("\n\t\tParent Mail Id : ");
			fgets(stud.Parents_Mail,25,stdin);
			stud.Parents_Mail[strlen(stud.Parents_Mail)-1] = '\0';
				
			if(Gmail_Validation(stud.Parents_Mail))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID EMAIL ID...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
		
		//Do While loop for entering only 10 Digit mobile no.
		do
		{
			printf("\n\t\tParent Mobile No. : ");
			scanf("%ld",&stud.Parent_Mob_No);
		
			
			if(Mobile_Validation(stud.Parent_Mob_No))
			{
				
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter 10 digit mobile number.\n");
				flag =0;
			}
				
		}while(flag==0);
		
		
		//Asking user if he/she wants to continue or not
		printf("\n\t\tDo you want to continue(Y/N) : ");
		scanf(" %c",&ch);
		
		
		//Writing Student's Details in the file "Student_Contact_System_file.txt"
		fprintf(file_ptr_details,"%d,%s,%s,%d,%d,%c,%d/%d/%d,%s,%s,%s,%s,%ld\n",stud.student_login.Roll_No,stud.details.First_Name,stud.details.Last_Name,stud.details.Age,
			stud.Class,stud.details.Gender,stud.dob.day,stud.dob.month,stud.dob.year,stud.details.Address,
			stud.Mothers_Name,stud.Fathers_Name,stud.Parents_Mail,stud.Parent_Mob_No);
		
		
		//Writing Student's Details in the file "Student_Id_Password.txt"
		fprintf(file_ptr_Login,"%d\t%s\n",stud.student_login.Roll_No,stud.student_login.Password);
		
	}while(ch=='y' || ch=='Y');
	
	
	//Closing Files
	fclose(file_ptr_details); 
	fclose(file_ptr_Login);
	
	printf("\n\t\t....................D A T A    I N S E R T E D     S U C C E S S F U L L Y............................\n");
}



























