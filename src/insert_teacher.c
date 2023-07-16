//------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------------------------
//----------------------------------------------------------------------------INSERT_TEACHER  F U N C T I O N  F I L E --------------------------------------------------------------------------------


#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//This Function doesn't return anything(it is of void type), it's work is to take input from user about the teacher's details and insert the data into teacher personal details file.
// Also this function will take input for teacher login info and store it in teacher Login details file

void Insert_Teacher()
{
	//for clearing terminal's screen 
	system("cls");

	
	
	FILE *file_ptr_details; //Declaring file pointer to the file which contains teacher's details
	FILE *file_ptr_Login; //Declaring file pointer to the file containing Id, Password details of teacher
	
	//Declaring variable of Teacher structure
	Teacher teacher;
	
	int flag=0,i=0;
	char ch;
	int numberRead=0;
	
	
	//Opening the Teacher details file
	file_ptr_details = fopen("./DataBase/Teacher_Contact_System_file.txt","a");
	
	
	//Opening Teachers Login details file
	file_ptr_Login = fopen("./DataBase/Teacher_Id_Password.txt","a");
	
	
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
	
	
	//Accepting Teacher's Details
	do
	{
		printf("\n\n\tEnter the Details of the Teacher ::\n\n");
		i++;
		
		
		//Here user will input Teacher ID and after validation it will proceed for other inputs
		do
		{
			printf("\n\t\tEnter the Teacher Id : ");
			numberRead = scanf("%d",&teacher.Teacher_Id);
			
			
			teacher.teacher_login.Teacher_Id = teacher.Teacher_Id;			
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tEnter the Teacher Id : ");
				numberRead = scanf("%d",&teacher.Teacher_Id);
			}
			
			int a = Teacher_By_ID(teacher.Teacher_Id, 1);
			
			if(a!=0)
			{
				printf("\n\t\tId already exists\n");
				flag =0;
			}
			else if(validate_id(teacher.Teacher_Id))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID ID...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
		
		
		
		//Do While loop for entering valid Password
		do
		{
			//Accepting the password from Admin
			printf("\n\t\tEnter Password : ");
			scanf("%s",teacher.teacher_login.Password);
		
			//validating the Gmail id
			if(Password_Validation(teacher.teacher_login.Password))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID PASSWORD...!!!!\n");
				flag = 0;
			}
			
		}while(flag==0);
		
		//Loop for entering only positive age 
		do
		{
			printf("\n\t\tEnter the Class Id (1 FOR CLASS TEACHERS, 0 For Teacher) : ");
			numberRead = scanf("%d",&teacher.Class_Id);
			
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tEnter the Class Id (1 FOR CLASS TEACHERS, 0 For Teacher) : ");
				numberRead = scanf("%d",&teacher.Class_Id);
			}
			if(teacher.Class_Id==0 || teacher.Class_Id==1)
				flag=1;
			else
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter (1/0) only\n");
				flag=0;
			}
		}while(flag==0);
		
		
		printf("\n\t\tFirst Name : ");
		scanf("%s",teacher.details.First_Name);
		
		
		printf("\n\t\tLast Name : ");
		scanf("%s",teacher.details.Last_Name);
		
		//Loop for entering only positive age 
		do
		{
			printf("\n\t\tAge : ");
			numberRead = scanf("%d",&teacher.details.Age);
			
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tAge : ");
				numberRead = scanf("%d",&teacher.details.Age);
			}
			if(teacher.details.Age<20)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter age above 20.\n");
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
			printf("\n\t\tGender (M/F) : ");
			scanf(" %c",&teacher.details.Gender);
		
			
			if(teacher.details.Gender=='F' || teacher.details.Gender=='M' || teacher.details.Gender=='f' || teacher.details.Gender=='m')
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
			numberRead = scanf("%d/%d/%d",&teacher.dob.day,&teacher.dob.month,&teacher.dob.year);
			
			
			while(numberRead !=3)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				
				printf("\n\t\tDate Of Birth (DD/MM/YYYY) : ");
				while(getchar()!='\n');
				numberRead = scanf("%d/%d/%d",&teacher.dob.day,&teacher.dob.month,&teacher.dob.year);
			}
			if(dob_validate(teacher.dob))
				flag=1;
			else
			{
				flag=0;
				printf("\n\t\tINVALID Date OF Birth...!!!!\n\t\tPlease enter valid DOB.\n");
				
			}
		}while(flag==0);
		
		
		printf("\n\t\tAddress : ");
		while(getchar()!='\n');
		fgets(teacher.details.Address,50,stdin);
		teacher.details.Address[strlen(teacher.details.Address)-1] = '\0';
		
		//Do While loop for entering valid email id
		do
		{
			printf("\n\t\tPersonal Mail Id : ");
			fgets(teacher.Email_Id,25,stdin);
			teacher.Email_Id[strlen(teacher.Email_Id)-1] = '\0';
				
			if(Gmail_Validation(teacher.Email_Id))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID EMAIL ID...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
		
		//Validating Entered Mobile number that should be of 10 digit
		do
		{
			printf("\n\t\tMobile No. : "); // not more than 10 values
			scanf("%ld",&teacher.Mob_No);
		
			
			if(Mobile_Validation(teacher.Mob_No))
				flag=1;
			else
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter 10 digit mobile number.\n");
				flag=0;
			}
		}while(flag==0);
		
		//Asking user if he/she wants to continue or not
		printf("\n\t\tDo you want to continue(Y/N) : ");
		scanf(" %c",&ch);
		
		
		//Writing Teacher's Details in the file "Teacher_Contact_System_file.txt"
		fprintf(file_ptr_details,"%d,%d,%s,%s,%d,%c,%d/%d/%d,%s,%s,%ld\n", teacher.Teacher_Id, teacher.Class_Id, teacher.details.First_Name, teacher.details.Last_Name, teacher.details.Age, teacher.details.Gender, teacher.dob.day, teacher.dob.month, teacher.dob.year, teacher.details.Address, teacher.Email_Id,teacher.Mob_No);
			
			
		//Writing Teacher's Login Details in the file "Teacher_Id_Password.txt"
		fprintf(file_ptr_Login,"%d %s\n",teacher.teacher_login.Teacher_Id,teacher.teacher_login.Password);
	}while(ch=='y' || ch=='Y');
	
	
	fclose(file_ptr_details);   // Closing teacher details file
	
	fclose(file_ptr_Login);     // Closing Login details file
	
	
	printf("\n\t\t....................D A T A    I N S E R T E D     S U C C E S S F U L L Y............................\n");
}

























