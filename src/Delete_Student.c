//-----------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L----------------------------
//--------------------------------------DELETE STUDENT  F I L E ------------------------------------------------

#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

int fl =0;
//function to delete the student data from the data base
void Delete_Student()
{
	  //for clearing screen
	  	system("cls");

	  Student stud;
	  int numberRead=0;
	  
	  FILE *fptr=NULL;
	  node *head=NULL,*temp=NULL;
	  node *newnode=NULL;
	  
	  
	  //reading from file and loading all data in LinkedList
	  fptr = fopen("./DataBase/Student_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   while( fscanf(fptr,"%d,%[^,],%[^,],%d,%d,%c,%d/%d/%d,%[^,],%[^,],%[^,],%[^,],%ld\n",&stud.Roll_No, stud.details.First_Name, stud.details.Last_Name, &stud.details.Age,&stud.Class, &stud.details.Gender, &stud.dob.day, &stud.dob.month, &stud.dob.year, stud.details.Address,			stud.Mothers_Name, stud.Fathers_Name, stud.Parents_Mail, &stud.Parent_Mob_No) != -1)  //EOF=-1
	   {
	   	
	        newnode = create_St_Node(stud);
	        head = add_St_Node(head,newnode);        
	   }
	   
	
	  
	   
	 //  displayList(head);
	   fclose(fptr);
	   
	   int Roll;
	   int flag=0;
	   
	   //Here user will input rollno and after validation it will proceed for other inputs
		do
		{
			printf("\n\t\tEnter the Roll Number you want to delete::");
	   		numberRead = scanf("\t%d", &Roll);
	   		
	   		//while loop to ensure that entered value is an integer value
			while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tEnter the Roll Number you want to delete::");
				numberRead = scanf("\t%d", &Roll);
			}
			
			if(validate_id(Roll))
			{
				flag=1;
			}
			else
			{
				printf("\n\t\tINVALID ROLLNO...!!!!\n");
				flag = 0;
			}
		}while(flag==0);
			
	
	//calling delete function
	   head = Delete_St_Data(head, Roll);
	  if(fl == 1)
	  {
	  	printf("\nRecord DELETED.......!!!!!!!!!!!!!!!!\n");
	  }
	   //displayList(head);
	   //re-open file in "w" mode
	   
	   
	   fptr = fopen("./DataBase/Student_Contact_System_file.txt","w");
	   
	   //write all data from LL into the file inorder to reflect the changes
	   temp=head;
	   while(temp!=NULL)
	   {
	   	stud.Parent_Mob_No = temp->Parent_Mob_No;
	   	stud.Class = temp-> Class;
	   	strcpy(stud.Parents_Mail, temp->Parents_Mail);
	   	stud.Roll_No = temp->Roll_No;
	   	strcpy(stud.Mothers_Name, temp->Mothers_Name);
	   	strcpy(stud.Fathers_Name, temp->Fathers_Name);
	   	stud.dob.day = temp->dob.day;
	   	stud.dob.month = temp->dob.month;
	   	stud.dob.year = temp-> dob.year;
	   	strcpy(stud.details.First_Name, temp->details.First_Name);	   	
	   	strcpy(stud.details.Last_Name, temp->details.Last_Name);
	   	stud.details.Gender = temp->details.Gender;
	   	stud.details.Age = temp->details.Age;
	   	strcpy(stud.details.Address, temp-> details.Address);
	   	stud.student_login.Roll_No = temp-> student_login.Roll_No;
	        
	     
	      write_Student(fptr,stud);
	      
	      temp = temp->next;
	   }
	   free_Student(head);
	   
	   fclose(fptr);
}



//This function is to delete a particular student's data 
//Parameters taken are head node and the Roll_No


node* Delete_St_Data(node* head, int Roll_No)
{
	node* temp = head;
	node* tag = head;
	
        //check if the head is NULL
	if(temp==NULL)
	{
		printf("Data Not Exist.");
		return head;
	}
        //if the id in the LL matches with the given teacher ID, it frees that node
	if(head->Roll_No == Roll_No)
	{
		head = head->next;
		free(temp);
		return head;
	}
        //traversing till the node where the id matches with the given teacher ID
	while(temp!=NULL)
	{
		if(temp->Roll_No == Roll_No)
		{
			fl = 1;
			break;
		}
		tag = temp;
		temp = temp->next;
		
	}
        //if data not found
	if(fl == 0)
	{
		printf("Data Not Found..");
		return head;
	}
	if(temp->next == NULL)
	{
		tag->next = NULL;
		free(temp);
		return head;
	}
	node* temp2 = temp;
	
	tag->next = temp->next;
	
	free(temp2);
	
	return head;           //returning the updated LL
}