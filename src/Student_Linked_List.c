#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//creating newnode for LL with data(values) fetched from file in formal paramter e

node* create_St_Node(Student st)
{
    node *newnode = (node*)malloc(sizeof(node));   
        
    newnode->Parent_Mob_No = st.Parent_Mob_No;
    newnode->Class = st.Class;
    strcpy(newnode->Parents_Mail, st.Parents_Mail);
    newnode->Roll_No = st.Roll_No;
    strcpy(newnode->Mothers_Name, st.Mothers_Name);
    strcpy(newnode->Fathers_Name, st.Fathers_Name);
    newnode->dob = st.dob;
    newnode->details = st.details;
   // newnode->student_login = st.student_login;
    
    newnode->next = NULL;
    
    return newnode;
}

/*adding node in LL containing emp_details
paramters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
node* add_St_Node(node *head,node *newnode)
{
    node *temp=head;
    //check if LL is empty
    if(head==NULL)
         head = newnode;
    else
    {
        while(temp->next!=NULL)
              temp = temp->next;
          
        temp->next = newnode; 
    }

   return head;
}





void free_Student(node* head)
{
	node* temp = head;
	if(temp == NULL)
	{
		free(temp);
		return;
		
	}
	while(temp!=  NULL)
	{
		node * tag= temp;
		temp = temp->next;
		free(tag);
		tag = NULL;
		
	}
	
	
}


//function:: writing each entry/loop from structure to file using fprintf
//parameter1:: file ptr pointing to data into the file
//parameter2:: structure to write data from
//return type:: void
void write_Student(FILE *fptr, Student stud)
{
	fprintf(fptr,"%d,%s,%s,%d,%d,%c,%d/%d/%d,%s,%s,%s,%s,%ld\n",stud.Roll_No, stud.details.First_Name, stud.details.Last_Name, stud.details.Age,
			stud.Class, stud.details.Gender, stud.dob.day, stud.dob.month, stud.dob.year, stud.details.Address,
			stud.Mothers_Name, stud.Fathers_Name, stud.Parents_Mail, stud.Parent_Mob_No);
}