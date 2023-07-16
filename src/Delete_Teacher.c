//-----------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L----------------------------
//--------------------------------------DELETE TEACHER FILE ------------------------------------------------

#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"

int flag = 0; // global variable for Delete_Teacher File

//function to delete the student data from the data base
void Delete_Teacher()
{
	  Teacher teacher;
	  int numberRead =0;
	  
	  
	  FILE *fptr=NULL;
	  nd *head=NULL,*temp=NULL;
	  nd *newnode=NULL;
	  
	
	  //reading from file and loading all data in LinkedList
	  fptr = fopen("./DataBase/Teacher_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   while( fscanf(fptr,"%d,%d,%[^,],%[^,],%d,%c,%d/%d/%d,%[^,],%[^,],%ld\n", &teacher.Teacher_Id, &teacher.Class_Id, teacher.details.First_Name, teacher.details.Last_Name,&teacher.details.Age, &teacher.details.Gender, &teacher.dob.day, &teacher.dob.month, &teacher.dob.year, teacher.details.Address,teacher.Email_Id, &teacher.Mob_No) != -1)  //EOF=-1
	   {
	   	
	        newnode = create_Tch_Node(teacher);
	        head = add_Tch_Node(head,newnode);     
	   }
	   
	   
	 //  displayList(head);
	   fclose(fptr);
	   
	  int id;
	  int flag1=0;
	  
	  //Here user will input Teacher ID and after validation it will proceed for other inputs
	do
	{
		printf("\n\t\tEnter the Teacher id that you want to delete::");
	  	numberRead = scanf("\t%d", &id);
		
		//while loop to ensure that entered value is an integer value
		while(numberRead !=1)
		{
			printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
			while(getchar()!='\n');
			printf("\n\t\tEnter the Teacher id that you want to delete::");
	  		numberRead = scanf("\t%d", &id);
		}
		if(validate_id(id))
		{
			flag1=1;
		}
		else
		{
			printf("\n\t\tINVALID ID...!!!!\n");
			flag1 = 0;
		}
	}while(flag1==0);
		
	  head = Delete_Tch_Data(head, id);
	  if(flag == 1)
	  {
	  	printf("\nRecord DELETED.......!!!!!!!!!!!!!!!!\n");
	  }
	 
	 //  displayList(head);
	   //re-open file in "w" mode
	   
	   
	   fptr = fopen("./DataBase/Teacher_Contact_System_file.txt","w");
	   
	   //write all data from LL into the file inorder to reflect the changes
	   temp=head;
	   while(temp!=NULL)
	   {
	   	
	   	teacher.Mob_No = temp->Mob_No;
	   	teacher.Teacher_Id = temp->Teacher_Id;
	   	teacher.Class_Id = temp->Class_Id;
	   	strcpy(teacher.Email_Id, temp->Email_Id);
	   	teacher.dob.day = temp->dob.day;
	   	teacher.dob.month = temp->dob.month;
	   	teacher.dob.year = temp->dob.year;
	   	strcpy(teacher.details.First_Name, temp->details.First_Name);
	   	strcpy(teacher.details.Last_Name, temp->details.Last_Name);
	   	teacher.details.Gender = temp->details.Gender;
	   	teacher.details.Age = temp->details.Age;
	   	strcpy(teacher.details.Address, temp->details.Address);
	   	teacher.teacher_login.Teacher_Id= temp->teacher_login.Teacher_Id;
	        
	     
	      write_Teacher(fptr,teacher);
	      
	      temp = temp->next;
	   }
	   
	   free_Teacher(head);
	   
	   fclose(fptr);
}



//This function is to delete a particular teacher's data 
//Parameters taken are head node and the teacher ID

nd* Delete_Tch_Data(nd* head, int Teacher_Id)
{
	nd* temp = head;
	nd* tag = head;
	
	//check if the head is NULL
	if(temp==NULL)
	{
		printf("Data Not Exist.");
		return head;
	}

	//if the id in the LL matches with the given teacher ID, it frees that node
	if(head->Teacher_Id == Teacher_Id)
	{
		head = head->next;
		free(temp);
		return head;
	}

	//traversing till the node where the id matches with the given teacher ID
	while(temp!=NULL)
	{
		if(temp->Teacher_Id == Teacher_Id)
		{
			flag = 1;
			break;
		}
		tag = temp;
		temp = temp->next;
		
	}

	//if data not found
	if(flag == 0)
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
	nd* temp2 = temp;
	
	tag->next = temp->next;
	
	free(temp2);
	
	return head;		//returning the updated LL
}

