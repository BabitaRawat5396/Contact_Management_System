//-----------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L----------------------------
//--------------------------------------F U N C T I O N  H E A D E R  F I L E ------------------------------------------------

// including header file
#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

//defining function for searching student 
int Search_Student()
{
	system("cls");// clear screen 

	int ch, val = 0;// input variable for choice 
	int numberRead = 0;
	
	
	do
	{	//menu for searching student
		printf("\n\n\n\tSELECT THE ONE FROM THE GIVEN OPTIONS : ");
		printf("\n\t>[1] Search By Name.\
			\n\t>[2] Search By Roll Number.\
			\n\t>[3] Show Menu Again.\
			\n\t>[4]LOGOUT.");
		scanf("%d", &ch);// taking input for choice
	
		
		
		switch(ch)
		{
			case 1: {
				char Name[20];
				printf("\n\tEnter The First Name :\t");
				scanf("%s", Name);
				
				//calling serach by name function
				val = Student_By_Name(Name);
				break;
			}
			case 2:{
				int Roll_No,flag=0;
				//Here user will input rollno and after validation it will proceed for other inputs
				do
				{
					printf("\n\tEnter the Roll Number :\t");
					numberRead = scanf("%d", &Roll_No);
					
					//while loop to ensure that entered value is an integer value
					while(numberRead !=1)
					{
						printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
						while(getchar()!='\n');
						printf("\n\tEnter the Roll Number :\t");
						numberRead = scanf("%d", &Roll_No);
					}
			
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
		
				//serach by roll number function call
				val = Student_By_ROLL(Roll_No);
				break;
			}
				
			case 3: 
				return 0;
			case 4:
				printf("\n\tThanks for visiting........!!!!!!!!!!!");
				exit(0);
			default:
				printf("\n\tYou have Entered a Wrong choice ...!!!!!!\n\tPlease Select a Correct one.");
		}
	}while(ch!=0);
	
	return val;
}
// function defination for search by name
int Student_By_Name(char Name[])
{
	  Student stud;
	  FILE *fptr=NULL; // file firstly initialize file pointer to null value
	  node *head=NULL;
	  node *newnode=NULL;
	  
	  
	  //reading from file and loading all data in LinkedList
	  fptr = fopen("./DataBase/Student_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   while( fscanf(fptr,"%d,%[^,],%[^,],%d,%d,%c,%d/%d/%d,%[^,],%[^,],%[^,],%[^,],%ld\n",&stud.Roll_No, stud.details.First_Name, stud.details.Last_Name, &stud.details.Age,
			&stud.Class, &stud.details.Gender, &stud.dob.day, &stud.dob.month, &stud.dob.year, stud.details.Address,
			stud.Mothers_Name, stud.Fathers_Name, stud.Parents_Mail, &stud.Parent_Mob_No) != -1)  //EOF=-1
	   {
	        newnode = create_St_Node(stud); // creating new node 
	        head = add_St_Node(head,newnode); // adding student node and assigning it to head       
	   }
	   fclose(fptr);
	   
	   
	   node* temp = head; // assigning head node to temp node 
	   if(temp == NULL)
	   {
	   	return 0;
	   }
	   
	   int count = 0;
	   
	   while(temp!=NULL)
	   {
	   	//validating student name from file and if data matches then printing details of student  
	   	if(strcmp(temp->details.First_Name, Name)==0)
	   	{
	   		count++;
	   		
	   		printf("\n\tStudents details for the provided name::");
	   		printf("\n\tStudent Roll Number \t : %d", temp->Roll_No);
	   		printf("\n\tStudent First Name \t : %s", temp->details.First_Name);
	   		printf("\n\tStudent Last Name \t : %s", temp->details.Last_Name);
	   		printf("\n\tAge \t\t\t : %d", temp->details.Age);
	   		printf("\n\tClass\t\t\t : %d", temp->Class);
	   		printf("\n\tGender \t\t\t : %c", temp->details.Gender);
	   		printf("\n\tDate of Birth:\t\t : %d/%d/%d", temp->dob.day, temp->dob.month, temp->dob.year);
	   		printf("\n\tAddress \t\t : %s", temp->details.Address);
	   		printf("\n\tMothers Name \t\t : %s", temp->Mothers_Name);
	   		printf("\n\tFathers Name \t\t : %s", temp->Fathers_Name);
	   		printf("\n\tParent Mail Id \t\t : %s", temp->Parents_Mail);
	   		printf("\n\tParent Mobile Number \t : %ld", temp->Parent_Mob_No);
	   		printf("\n");
	   		
	   	}
	   	
	   	temp = temp->next;//this will shift temp to next node 
	   }
	   
	   printf("\n\n\tTotal %d Records Found.", count);
	   
	   free_Student( head);//deallocating memory 
	   return count;
}

//  definating function  for searching student  by name
int Student_By_ROLL(int roll)
{
	  Student stud;//student  structure declaration 
	  FILE *fptr=NULL; // firstly initialize file pointer to null value
	  node *head=NULL;// firstly initialize head pointer to null value
	  node *newnode=NULL;// firstly initialize newnode pointer to null value
	  
	  
	  //reading from file and loading all data in LinkedList
	  fptr = fopen("./DataBase/Student_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   while( fscanf(fptr,"%d,%[^,],%[^,],%d,%d,%c,%d/%d/%d,%[^,],%[^,],%[^,],%[^,],%ld\n",&stud.Roll_No, stud.details.First_Name, stud.details.Last_Name, &stud.details.Age,&stud.Class, &stud.details.Gender, &stud.dob.day, &stud.dob.month, &stud.dob.year, stud.details.Address,
stud.Mothers_Name, stud.Fathers_Name, stud.Parents_Mail, &stud.Parent_Mob_No) != -1)  //EOF=-1
	   
	   {
	   	
	        newnode = create_St_Node(stud); // creating new node 
	        head = add_St_Node(head,newnode); //adding student node and assigning to head        
	   }
	   fclose(fptr); //closing file
	   
	   
	   node* temp = head;//assigning head node to temp node 
	   if(temp == NULL)
	   {
	   	return 0;
	   }
	 
	   while(temp!=NULL)
	   {
	   	//validating  roll number  from file if data found true then printing all details of student 
	   	if(temp->Roll_No == roll)
	   	{
	   		
	   		
	   		printf("\n\tStudents details for provided Roll Number::");
	   		printf("\n\tStudent Roll Number \t : %d", temp->Roll_No);
	   		printf("\n\tStudent First Name \t : %s", temp->details.First_Name);
	   		printf("\n\tStudent Last Name \t : %s", temp->details.Last_Name);
	   		printf("\n\tAge \t\t\t : %d", temp->details.Age);
	   		printf("\n\tClass\t\t\t : %d", temp->Class);
	   		printf("\n\tGender \t\t\t : %c", temp->details.Gender);
	   		printf("\n\tDate of Birth:\t\t : %d/%d/%d", temp->dob.day, temp->dob.month, temp->dob.year);
	   		printf("\n\tAddress \t\t : %s", temp->details.Address);
	   		printf("\n\tMothers Name \t\t : %s", temp->Mothers_Name);
	   		printf("\n\tFathers Name \t\t : %s", temp->Fathers_Name);
	   		printf("\n\tParent Mail Id \t\t : %s", temp->Parents_Mail);
	   		printf("\n\tParent Mobile Number \t : %ld", temp->Parent_Mob_No);
	   		printf("\n");		
	   		
	   	}
	   	
	   	temp = temp->next;//this will shift temp to next node 
	   }
	//   printf("\n\n\tTotal %d Records Found.", count);
	   free_Student( head);// deallocating memory 
	   return 0;
}
