#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//function:: to upadte the contact using roll number
//return type:: void
//parameter : nothing
void Update_Teacher()
{
	system("cls");

	  //declarations
	  Teacher teacher;
	  
	  int Teacher_Id, ch,numberRead = 0;
	  FILE *fptr=NULL;
	  nd *head=NULL;
	  nd *newnode=NULL;
	  nd* temp;
	  int flag=0;
	  
	  //reading from file and loading all data in Linked List
	  fptr = fopen("./DataBase/Teacher_Contact_System_file.txt","r");
	   
	   	   
	   //loading data in structure
	   
	   while( fscanf(fptr,"%d,%d,%[^,],%[^,],%d,%c,%d/%d/%d,%[^,],%[^,],%ld\n", &teacher.Teacher_Id, &teacher.Class_Id, teacher.details.First_Name,teacher.details.Last_Name,&teacher.details.Age, &teacher.details.Gender, &teacher.dob.day, &teacher.dob.month, &teacher.dob.year,teacher.details.Address,teacher.Email_Id,&teacher.Mob_No) != -1)  //EOF=-1
	   {	  
	   	//creating new node using the data in structure	
	        newnode = create_Tch_Node(teacher);
	        //adding new node to linked list
	        head = add_Tch_Node(head,newnode);        
	   }
	   fclose(fptr);
	   
	   
	   
	   //Here user will input Teacher ID and after validation it will proceed for other inputs
		do
		{
			//old teacher id from the file to update
	   		printf("\n\t\tEnter Teacher ID To search And Update:: ");
	  	 	numberRead = scanf("%d", &Teacher_Id);
	   	
	   		while(numberRead !=1)
			{
				printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
				while(getchar()!='\n');
				printf("\n\t\tEnter Teacher ID To search And Update:: ");
	  		 	numberRead = scanf("%d", &Teacher_Id);
			}
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
		
		
	
		
	    //calling the function to update the details of the teacher   
	    head = Update_Tech_Data(head, Teacher_Id);
	    
	    
	   //purpose::update details:: reflect changes in linked list
	   //procedure::rewriting data from updated linked list to the same file
	   
	   fptr = fopen("./DataBase/Teacher_Contact_System_file.txt","w");
	   
	   temp=head;
	   
	   while(temp!=NULL)
	   {
	   	//loading each entry/loop from LL to structure 
	   	
	   	teacher.Mob_No = temp->Mob_No;
	   	teacher.Teacher_Id = temp-> Teacher_Id;
	   	teacher.Class_Id = temp-> Class_Id;	   	
	   	strcpy(teacher.Email_Id, temp->Email_Id);	   	
	   	strcpy(teacher.details.First_Name, temp-> details.First_Name);	   	
	   	strcpy(teacher.details.Last_Name, temp->details.Last_Name);
	   	teacher.details.Gender = temp->details.Gender;
	   	teacher.details.Age = temp->details.Age;
	   	teacher.dob.day = temp->dob.day;
	   	teacher.dob.month = temp->dob.month;
	   	teacher.dob.year = temp->dob.year;
	   	strcpy(teacher.details.Address, temp->details.Address);
	        
	//writeTeacher function writes the data linewise into the file pointed by first parameter fptr, data is taken from second parameter teacher
	        write_Teacher(fptr,teacher);
	      
	        temp = temp->next;
	   }//while ends here
	   
	   //TO FREE HEAP MEMORY USED BY LINKED LIST
	   free_Teacher(head);
	   
	   fclose(fptr); //TO close file//fptr no more points to data in file
	   
}//end of update_teacher program



nd* Update_Tech_Data(nd* head, int Teacher_Id)
{
	   
	   Teacher teacher;
	   
	   int ch;
	   int flag = 0,numberRead = 0, a = 0 ;
	   
	   nd* temp = head;
	   DOB dob;
	   
	   if(temp == NULL)
	   {
	   	printf("\n\n\t\tData Not Found::\n");
	   	return head;
	   }
	  
	  
	  //traversing the linkedlist
	 
	   while(temp != NULL)
	   {
	   	//comparing roll no if data matches the given roll no
	   	if(temp->Teacher_Id == Teacher_Id)
	   	{
	   			a = 1;

	   		
	   			printf("\n\t\tWhat Details you want to update?\n");
	   			printf("\n\t[1] Mobile Number:");
	   			printf("\n\t[2] Teacher ID:");
	   			printf("\n\t[3] Class Id:");
	   			printf("\n\t[4] Mail ID:");
	   			printf("\n\t[5] First Name:");
	   			printf("\n\t[6] Last Name:");
	   			printf("\n\t[7] Gender:");
	   			printf("\n\t[8] Age:");
	   			printf("\n\t[9] Date Of Birth:");
	   			printf("\n\t[10] Address:");
	   			
	   			printf("\n\nEnter Your Choice::");
	   			
	   			scanf("%d", &ch);//to choose the option
	   			
	   			//to update linked list with new data
	   			switch(ch)
	   			{
	   				
	   				//taking new data from user
	   				//replacing the old data with new in linked list
	   				case MOB_NO_T:{
						long int mob_no;
	   					
	   					//Validating Entered Mobile number that should be of 10 digit
						do
						{
							printf("\n\t\tEnter Mobile No. : ");
							scanf("%ld", &mob_no);
						
							
							if(Mobile_Validation(mob_no))
								flag=1;
							else
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter 10 digit mobile number.\n");
								flag=0;
							}
						}while(flag==0);
		
	   					temp->Mob_No = mob_no;//replacing old data by new data in linked list
	   					
	   					break;
					}
	   				case TEACHER_ID_T:{
						int t_id;
	   					
	   					//Here user will input Teacher ID and after validation it will proceed for other inputs
						do
						{
							printf("\n\tEnter new Teacher ID:");
							numberRead = scanf("%d", &t_id);
							
							while(numberRead !=1)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
								while(getchar()!='\n');
								printf("\n\tEnter new Teacher ID:");
								numberRead = scanf("%d", &t_id);
							
							}
							if(validate_id(t_id))
							{
								flag=1;
							}
							else
							{
								printf("\n\t\tINVALID ID...!!!!\n");
								flag = 0;
							}
						}while(flag==0);
	   					temp->Teacher_Id = t_id;//replacing old data by new data in linked list
	   						
	   					break;
					}
	   				
	   				case CLASS_ID_T:
	   					printf("\n\t\tEnter the Class Id (1 FOR CLASS TEACHERS, 0 For Teacher) : ");
	   					int c_id;
	   					scanf("%d", &c_id);
	   					temp->Class_Id = c_id;//replacing old data by new data in linked list	
	   					
	   					break;
	   					
	   				case MAIL_ID_T:{
						char mail[25];
	   					
	   					//Do While loop for entering valid email id
						do
						{
							printf("\n\tEnter new Personal Mail Id : ");
							scanf("%s", mail);
								
							if(Gmail_Validation(mail))
							{
								flag=1;
							}
							else
							{
								printf("\n\t\tINVALID EMAIL ID...!!!!\n");
								flag = 0;
							}
						}while(flag==0);
		
	   					strcpy(temp->Email_Id, mail);//replacing old data by new data in linked list
	   					
	   					break;
					} 					
	   				
	   				case FIRST_NAME_T:
	   					printf("\n\tEnter new Student First Name:");
	   					char first_name[25];
	   					scanf("%s", first_name);
	   					
	   					strcpy(temp->details.First_Name, first_name);//replacing old data by new data in linked list
	   					
	   					break;
	   					
	   				case LAST_NAME_T:
	   					printf("\n\tEnter new Student Last Name:");
	   					char last_name[25];
	   					scanf("%s", last_name);
	   					
	   					strcpy(temp->details.Last_Name , last_name);//replacing old data by new data in linked list
	   					
	   					break;
	   				
	   				
	   				case GENDER_T: {
						char Gender;
	   					
	   					do
						{
							printf("\n\tEnter Gender:");
	   					
	   						scanf(" %c", &Gender);
							
							if(Gender=='F' || Gender=='M' || Gender=='f' || Gender=='m')
								flag=1;
							else
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter (F/M) or (f/m).\n");
								flag=0;
							}
						}while(flag==0);
						
	   					temp->details.Gender  = Gender;//replacing old data by new data in linked list
	   					
	   					break;
					}
	   					
	   				case AGE_T:{
						int Age;
	   					
	   					//Loop for entering only positive age 
						do
						{
							printf("\n\tEnter new Age:");
	   						numberRead = scanf("%d", &Age);
							
							
							while(numberRead !=1)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
								while(getchar()!='\n');
								printf("\n\tEnter new Age:");
	   							numberRead = scanf("%d", &Age);
							}
							if(Age<20)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter age above 20.\n");
								flag=0;
								
							}
							else
							{
								flag=1;
							}
						}while(flag==0);
		
	   					temp->details.Age = Age;//replacing old data by new data in linked list
	   					
	   					break;
					}
	   					
	   				case D_O_B_T:
	   					
	   					
	   					//Validating Entered Date Of birth
						do
						{
							printf("\n\tEnter new Date Of Birth:(DD/MM/YYYY)::");
	   						numberRead = scanf("%d/%d/%d",&dob.day,&dob.month,&dob.year);
	   						
	   						
							while(numberRead !=3)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
								while(getchar()!='\n');
								printf("\n\tEnter new Date Of Birth:(DD/MM/YYYY)::");
	   							numberRead = scanf("%d/%d/%d",&dob.day,&dob.month,&dob.year);
	   						
							}
						
							if(dob_validate(dob))
								flag=1;
							else
							{
								printf("\n\t\tINVALID Date OF Birth...!!!!\n\t\tPlease enter valid DOB.\n");
								flag=0;
							}
						}while(flag==0);
		
	   					temp->dob.day = dob.day;
	   					temp->dob.month=dob.month;
	   					temp->dob.year = dob.year;
	   					//replacing old data by new data in linked list
	   					break;
	   					
	   				case ADDRESS_T: 
	   					printf("\n\tEnter new Address:");
	   					char Address[25];
	   					while(getchar()!='\n');
	   					fgets(Address, 25, stdin);
	   					Address[strlen(Address)-1] = '\0';
	   					strcpy(temp->details.Address, Address);//replacing old data by new data in linked list
	   					
	   					break;
	   					
	   				
	   				default:
	   					printf(" You Entered a Wrong Choice:: choose again::");
	   					
	   				
	   			}//switch cases ends here
		
	   	       
	   	}//if data matched ends here
	   
	   	temp = temp->next;
	   }//while temp!= null ends
	
	
	   if(a==1)
	   {
	   	printf("\n\tDetails have been Updated........!!!!!!!!!!!\n");
	   }
	   else
	   {
	   	printf("\n\t\tData not found..!!!!\n");
	   }
	   
	return head;
}

