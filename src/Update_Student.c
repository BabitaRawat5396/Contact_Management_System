#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//function:: to upadte the contact using roll number
//return type:: void
//parameter : nothing
void Update_Student()
{
	   	system("cls");

	  //declarations
	  Student stud;
	  
	  int Roll_No,numberRead = 0;
	  
	  FILE *fptr=NULL;
	  node *head=NULL;
	  node* temp;
	  node *newnode=NULL;
	  
	  int flag1=0;
	  
	  //reading from file and loading all data in Linked List
	  fptr = fopen("./DataBase/Student_Contact_System_file.txt","r");
	   
	   
	   //loading data in structure
	   while( fscanf(fptr,"%d,%[^,],%[^,],%d,%d,%c,%d/%d/%d,%[^,],%[^,],%[^,],%[^,],%ld\n",&stud.Roll_No, stud.details.First_Name, stud.details.Last_Name, &stud.details.Age,&stud.Class, &stud.details.Gender, &stud.dob.day, &stud.dob.month, &stud.dob.year, stud.details.Address,stud.Mothers_Name, stud.Fathers_Name, stud.Parents_Mail, &stud.Parent_Mob_No) != -1)  //EOF=-1
	   {	   
	   	//creating new node using the data in structure	
	        newnode = create_St_Node(stud);
	        //adding new node to linked list
	        head = add_St_Node(head,newnode); 
	               
	   }//while ends
	   
	   fclose(fptr);
	   
	do
	{
		//old roll number from the file to update
		printf("\n\t\tEnter The Roll Number To search And Update:: ");	
		numberRead = scanf("%d", &Roll_No);
		
		//while loop to ensure that entered value is an integer value
		while(numberRead !=1)
		{
			printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
			while(getchar()!='\n');
			printf("\n\t\tEnter The Roll Number To search And Update:: ");	
			numberRead = scanf("%d", &Roll_No);
		}
		if(validate_id(Roll_No))
		{
			flag1=1;
		}
		else
		{
			printf("\n\t\tINVALID ROLLNO...!!!!\n");
			flag1 = 0;
		}
	}while(flag1==0); //do while ends
		
	   
	   head = Update_St_Data(head, Roll_No);
	   
	   
	   //purpose::update details:: reflect changes in linked list
	   //procedure::rewriting data from updated linked list to the same file
	   fptr = fopen("./DataBase/Student_Contact_System_file.txt","w");
	   
	   temp=head;
	   
	   while(temp!=NULL)
	   {
	   	//loading each entry/loop from LL to structure 
	   	stud.Parent_Mob_No = temp->Parent_Mob_No;
	   	stud.Class = temp->Class;
	   	strcpy(stud.Parents_Mail, temp->Parents_Mail);
	   	stud.Roll_No = temp->Roll_No;
	   	strcpy(stud.Mothers_Name, temp->Mothers_Name);
	   	strcpy(stud.Fathers_Name, temp->Fathers_Name);
	   	stud.dob.day = temp->dob.day;
	   	stud.dob.month = temp->dob.month;
	   	stud.dob.year = temp-> dob.year;
	   	strcpy(stud.details.First_Name, temp-> details.First_Name);
	   	strcpy(stud.details.Last_Name, temp->details.Last_Name);
	   	stud.details.Gender = temp->details.Gender;
	   	stud.details.Age = temp->details.Age;
	   	strcpy(stud.details.Address, temp-> details.Address);
	   	stud.student_login.Roll_No = temp-> student_login.Roll_No;
	   	
	        
	     
	//writeStudent function writes the data linewise into the file pointed by first parameter fptr, data is taken from second parameter stud 
	      write_Student(fptr,stud);
	      
	      temp = temp->next;
	   }//while ends here
	   
	  //to deallocate heap memory taken up by linked list
	   free_Student(head);
	   
	   fclose(fptr); //close file pointer
	   
}//end of update_student program

node* Update_St_Data(node* head, int Roll_No)
{
	int flag = 0;
	int flag1 = 0;
	
	int ch,numberRead =0;
	DOB dob;
	//creating a temporary node for traversal
	   node* temp = head;
	   if(temp == NULL)
	   {
	   	printf("\n\n\t\tData Not Found::\n");
	   	return head;
	   }
	  
	  
	  //traversing the linkedlist
	   while(temp!=NULL)
	   {
	   	//comparing roll no if data matches the given roll no
	   	if(temp->Roll_No == Roll_No)
	   	{//if data matches
	   	           		
	   		flag =1;
	   		
	   			printf("\n\t\tWhat Details you want to update?\n");
	   			printf("\n\t[1] Parent Mobile Number:");
	   			printf("\n\t[2] Class:");
	   			printf("\n\t[3] Parent Mail Id:");
	   			printf("\n\t[4] Mothers Name:");
	   			printf("\n\t[5] Fathers Name:");
	   			printf("\n\t[6] Student First Name:");
	   			printf("\n\t[7] Student Last Name:");
	   			printf("\n\t[8] Gender:");
	   			printf("\n\t[9] Age:");
	   			printf("\n\t[10] Address:");
	   			printf("\n\t[11] Date Of Birth:");
	   			
	   			printf("\n\nEnter Your Choice::");
	   			
	   			
	   			scanf("%d", &ch);//to choose the option
	   			
	   			//to update linked list with new data
	   			switch(ch)
	   			{
	   				
	   				//taking new data from user
	   				//replacing the old data with new in linked list
	   				case PARENT_MOB_NO:{
						long int mob_no;
	   					
	   					
	   					//Do While loop for entering only 10 Digit mobile no.
						do
						{
							printf("\n\tEnter Parent Mobile Number:");
							scanf("%ld", &mob_no);
						
							if(Mobile_Validation(mob_no))
							{
								
								flag1=1;
							}
							else
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter 10 digit mobile number.\n");
								flag1 =0;
							}
						}while(flag1==0);
		
		
	   					temp->Parent_Mob_No = mob_no; //replacing old data by new data in linked list
	   					
	   					break;
	   					
					}
	   					
	   				case CLASS:{
						int Class;
	   					
	   					//Do While loop for correct class number that is 1 to 12
						do
						{
							printf("\n\tEnter Class:");
	   						numberRead = scanf("%d", &Class);
							
							while(numberRead !=1)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
								while(getchar()!='\n');
								printf("\n\tEnter Class:");
	   							numberRead = scanf("%d", &Class);
							}
							
							
							if(Class<0 || Class>12)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter class between 1 to 12.\n");
								flag1=0;
								
							}
							else
							{
								flag1=1;
							}
						}while(flag1==0);
		
	   					temp->Class = Class;
	   					//replacing old data by new data in linked list
	   					break;
					}
	   						   				
	   				case PARENT_MAIL_ID:{
						char mail[25];
	   					
	   					//Do While loop for entering valid email id
						do
						{
							printf("\n\tEnter Parent Mail Id:");
	   						scanf("%s", mail);
								
							if(Gmail_Validation(mail))
							{
								flag1=1;
							}
							else
							{
								printf("\n\t\tINVALID EMAIL ID...!!!!\n");
								flag1 = 0;
							}
						}while(flag1==0);
						
	   					strcpy(temp->Parents_Mail, mail);//replacing old data by new data in linked list
	   					
	   					break;
	   						
	   				case MOTHER_NAME:
	   					printf("\n\tEnter Mothers Name:");
	   					char mothers_name[25];
	   					scanf("%s", mothers_name);	
	   					
	   					 strcpy(temp->Mothers_Name, mothers_name);//replacing old data by new data in linked list
	   					 
	   					 break;
					}
	   					   					
	   				case FATHER_NAME:
	   					printf("\n\tEnter Fathers Name:");
	   					char fathers_name[25];
	   					//while(getchar()!='\n');
	   					//fgets(fathers_name, 25, stdin);
	   					scanf("%s", fathers_name);	
	   					//fathers_name[strlen(fathers_name)-1] = '\0';   					
	   					strcpy(temp->Fathers_Name, fathers_name);//replacing old data by new data in linked list
	   					
	   					
	   					break;
	   				
	   				case FIRST_NAME:
	   					printf("\n\tEnter Student First Name:");
	   					char first_name[25];
	   					scanf("%s", first_name);
	   					
	   					strcpy(temp->details.First_Name, first_name);//replacing old data by new data in linked list
	   					
	   					break;;
	   					
	   				case LAST_NAME:
	   					printf("\n\tEnter Student Last Name:");
	   					char last_name[25];
	   					scanf("%s", last_name);
	   					
	   					strcpy(temp->details.Last_Name , last_name);//replacing old data by new data in linked list
	   					
	   					break;;
	   				
	   				
	   				case GENDER: {
						char Gender;
	   					
	   					
	   					//Do While loop to check user has entered correct Alphabet for Gender
						do
						{
							printf("\n\tEnter Gender:");
	   						scanf(" %c", &Gender);
							
							if(Gender=='F' || Gender=='M' || Gender=='f' || Gender=='m')
								flag1=1;
							else
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter (F/M) or (f/m).\n");
								flag1=0;
							}
						}while(flag1==0);
		
	   					temp->details.Gender  = Gender;//replacing old data by new data in linked list
	   					
	   					break;
					}
	   					
	   				case AGE:{
						int Age;
	   					//Loop for entering only positive age 
						do
						{
							printf("\n\tEnter Age:");
	   						numberRead = scanf("%d", &Age);
							
							while(numberRead !=1)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
								while(getchar()!='\n');
								printf("\n\tEnter Age:");
	   							numberRead = scanf("%d", &Age);
							}
							
							if(Age<2)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter postive age number.\n");
								flag1 = 0;
								
							}
							else
							{
								flag1 = 1;
							}
						}while(flag1==0);
		
	   					temp->details.Age = Age;//replacing old data by new data in linked list
	   					
	   					break;
					}
	   						   				
	   				case ADDRESS: 
	   					printf("\n\tEnter Address:");
	   					char Address[25];
	   					while(getchar()!='\n');
	   					fgets(Address, 25, stdin);
	   					Address[strlen(Address)-1] = '\0';
	   					strcpy(temp->details.Address, Address);//replacing old data by new data in linked list
	   					
	   					break;
	   				case D_O_B:
	   				
	   					
	   					//Validating Entered Date Of birth
						do
						{
							
							printf("\n\tEnter Date Of Birth:(DD/MM/YYYY)::");
	   						numberRead = scanf("%d/%d/%d",&dob.day,&dob.month,&dob.year);
	   						
	   						
							while(numberRead !=3)
							{
								printf("\n\t\tINVALID INPUT...!!!!\n\t\tPlease enter integer value");
								while(getchar()!='\n');
								
								printf("\n\tEnter Date Of Birth:(DD/MM/YYYY)::");
	   							numberRead = scanf("%d/%d/%d",&dob.day,&dob.month,&dob.year);
							}
			
						
							if(dob_validate(dob))
								flag1=1;
							else
							{
								printf("\n\t\tINVALID Date OF Birth...!!!!\n\t\tPlease enter valid DOB.\n");
								flag1=0;
							}
						}while(flag1==0);
		
	   					temp->dob.day = dob.day;
	   					temp->dob.month = dob.month;
	   					temp->dob.year = dob.year;
	   					//replacing old data by new data in linked list
	   					break;
	   				
	   				default:
	   					printf(" You Entered a Wrong Choice:: choose again::");
	   					
	   				
	   			}//switch cases ends here
	   	}//if data matched ends here
	   
	   	temp = temp->next;
	   }//while temp!= null ends
	   
	   if(flag == 0)
	   {
	   	printf("\n\t\tData Not Found..!!");
	   	printf("\n\t\tWant to Enter Again (1/0)::\t");
	   	int rl;
	   	scanf("%d", &rl);
	   	if(rl == 1)
	   	{
	   		Update_Student();
	   	}
	   	else
	   	{
	   		return head;
	   	}
	   }
	   else
	   {
	   	printf("\n\tDetails have been Updated........!!!!!!!!!!!");
	   }
	   
	   return head;
}



