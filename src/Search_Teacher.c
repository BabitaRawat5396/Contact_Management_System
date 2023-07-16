//-----------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L----------------------------
//--------------------------------------F U N C T I O N  H E A D E R  F I L E ------------------------------------------------

// including header file
#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

//defining function for searching teacher
int Search_Teacher() 
{
	system("cls");// clear screen 
	int ch;
	int val = 0;// input variable for choice 
	int numberRead = 0;
	
	do
	{	//menu for searching teacher with options
		printf("\n\n\t\tSELECT THE ONE FROM THE GIVEN OPTIONS::");
		printf("\n\t\t>[1]Search By Name.\
			\n\t\t>[2]Search By Teacher ID.\
			\n\t\t>[3]LOGOUT.");
		scanf("\n\t%d", &ch);// taking input for choice
	
		
		
		switch(ch)  //switch cases for menu
		{
			//  enclose each case within its own block using curly braces {}. This will create a new scope for the variables, allowing you to declare them within the specific case where they are needed.
			case 1: {
				char Name[20];
				printf("\n\t\tEnter The First Name::\t");
				scanf("%s", Name);
				val = Teacher_By_Name(Name);
				break;
			}				
			case 2:{
				int Teacher_ID,flag=0;
				
				
				//Here user will input Teacher ID and after validation it will proceed for other inputs
				do
				{
					printf("\n\t\tEnter Teacher ID::\t");
					numberRead = scanf("%d", &Teacher_ID);
					
					//while loop to ensure that entered value is an integer value
					while(numberRead !=1)
					{
						printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
						while(getchar()!='\n');
						printf("\n\t\tEnter Teacher ID::\t");
						numberRead = scanf("%d", &Teacher_ID);
					}
			
					if(validate_id(Teacher_ID))
					{
						flag=1;
					}
					else
					{
						printf("\n\t\tINVALID ID...!!!!\n");
						flag = 0;
					}
				}while(flag==0);
		
				val = Teacher_By_ID(Teacher_ID, 0);
				break;
			}
			case 3:
				printf("\n\tThanks for visiting........!!!!!!!!!!!");
				exit(0);
			default:
				printf("\n\t\tYou Entered a Wrong choice Please Select a Correct one.");
		}
	}while(ch!=0);
	
	return val;
}



// defining function for searching teacher by teacher name by reading from file and validating
int Teacher_By_Name(char Name[])
{
	  Teacher teacher;
	  FILE *fptr=NULL;// firstly initialize file pointer to null value
	  nd *head=NULL; // firstly initialize head pointer to null value
	  nd *newnode=NULL;//firstly initialize file newnode pointer to null value
	  
	  
	  //reading from file and loading all data in LinkedList
	  fptr = fopen("./DataBase/Teacher_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   
	   while( fscanf(fptr,"%d,%d,%[^,],%[^,],%d,%c,%d/%d/%d,%[^,],%[^,],%ld\n", &teacher.Teacher_Id, &teacher.Class_Id, teacher.details.First_Name,teacher.details.Last_Name,&teacher.details.Age, &teacher.details.Gender, &teacher.dob.day, &teacher.dob.month, &teacher.dob.year,teacher.details.Address,teacher.Email_Id, &teacher.Mob_No) != -1)  //EOF=-1
	   {
	   	
	        newnode =  create_Tch_Node(teacher);// creating new  node 
	        head = add_Tch_Node(head,newnode);   // adding teacher node and assigning it to head          
	   }
	   fclose(fptr);//closing the file 
	   
	   
	   nd* temp = head; // assigning head node to temp node 
	   if(temp == NULL)
	   {
	   	return 0;
	   }
	   int count = 0;
	   
	   while(temp!=NULL)
	   {
	  	//validating teacher first name from file if true then printing teacher details
	   	if(strcmp(temp->details.First_Name, Name)==0)
	   	{
	   		count++;
	   		
	   		printf("\nTeachers Name with teacher id are below for more Information Search BY Teacher ID::\n");
	   		printf("\n\tTeacher ID \t : %d", temp->Teacher_Id);
	   		printf("\n\tclass Id \t : %d", temp->Class_Id);
	   		printf("\n\tFirst Name \t : %s", temp->details.First_Name);
	   		printf("\n\tLast Name \t : %s", temp->details.Last_Name);
	   		printf("\n\tAge \t\t : %d", temp->details.Age);
	   		printf("\n\tGender \t\t : %c", temp->details.Gender);
	   		printf("\n\tDate of Birth \t : %d/%d/%d", temp->dob.day, temp->dob.month, temp->dob.year);
	   		printf("\n\tAddress \t : %s", temp->details.Address);
	   		printf("\n\tEmail Id \t : %s", temp-> Email_Id);
	   		printf("\n\tMobile Number \t : %ld", temp->Mob_No);
	   		
	   	}
	   	
	   	temp = temp->next;//this will shift temp to next node 
	   }
	   
	   printf("\n\n\tTotal %d Records Found.", count);
	   free_Teacher(head);// deallocating memory 
	   return count;
}







// function for searching teacher by teacher ID by reading from file and validating
int Teacher_By_ID(int Teacher_ID, int num)
{
	  Teacher teacher;
	  FILE *fptr=NULL;// firstly initialize file pointer to null value
	  nd *head=NULL;
	  nd *newnode=NULL;
	  
	  
	  //reading from file and loading all data in LinkedList
	  fptr = fopen("./DataBase/Teacher_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   
	   while( fscanf(fptr,"%d,%d,%[^,],%[^,],%d,%c,%d/%d/%d,%[^,],%[^,],%ld\n", &teacher.Teacher_Id, &teacher.Class_Id, teacher.details.First_Name, teacher.details.Last_Name, &teacher.details.Age, &teacher.details.Gender, &teacher.dob.day, &teacher.dob.month, &teacher.dob.year,teacher.details.Address, teacher.Email_Id, &teacher.Mob_No) != -1)  //EOF=-1
	   {
	   	
	        newnode =  create_Tch_Node(teacher);// creating new node 
	        head = add_Tch_Node(head,newnode); // adding teacher node and assigning it to head         
	   }
	   fclose(fptr);//closing the file 
	   
	   
	   nd* temp = head;// assigning head node to temp node 
	   if(temp == NULL)
	   {
	   	return 0;
	   }
	  
	   
	   while(temp!=NULL)
	   {
	   	
	 	if(num == 1 && temp->Teacher_Id==Teacher_ID && temp->Class_Id == 1)
	 	{
	 		free_Teacher(head);
	 		return 2;
	 	}
	 	else if(num == 1 && temp->Teacher_Id==Teacher_ID && temp->Class_Id == 0)
	 	{
	 		free_Teacher(head);
	 		return 1;
	 	}
	 	//validating teacher id  from file if true then printing teacher details
	   	if(num == 0 && temp->Teacher_Id==Teacher_ID)
	   	{
	   		
	   		printf("\nTeachers details for provided teacher id ::\n");
	   		printf("\n\tTeacher ID \t : %d", temp->Teacher_Id);
	   		printf("\n\tclass Id \t : %d", temp->Class_Id);
	   		printf("\n\tFirst Name \t : %s", temp->details.First_Name);
	   		printf("\n\tLast Name \t : %s", temp->details.Last_Name);
	   		printf("\n\tAge \t\t : %d", temp->details.Age);
	   		printf("\n\tGender \t\t : %c", temp->details.Gender);
	   		printf("\n\tDate of Birth \t : %d/%d/%d", temp->dob.day, temp->dob.month, temp->dob.year);
	   		printf("\n\tAddress \t : %s", temp->details.Address);
	   		printf("\n\tEmail Id \t : %s", temp-> Email_Id);
	   		printf("\n\tMobile Number \t : %ld", temp->Mob_No);
	   		
	   		
	   		
	   	}
	   	
	   	temp = temp->next;//this will shift temp to next node 
	   }
	   
	 //  printf("\n\n\tTotal %d Records Found.", count);
	   free_Teacher(head);// deallocating 
	   return 0;
}