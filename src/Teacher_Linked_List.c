#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//purpose:: creating newnode for LL with data(values) fetched from file in formal parameter te
//parameter:: structure Teacher te
//return type:: node pointer of teacher linked list
nd* create_Tch_Node(Teacher te)
{
    nd *newnode = (nd*)malloc(sizeof(nd));   
        
    newnode->Mob_No= te.Mob_No;
    newnode->Teacher_Id = te.Teacher_Id;
    newnode->Class_Id= te.Class_Id;
    strcpy(newnode->Email_Id, te.Email_Id);
    newnode->dob = te.dob;
    newnode->details = te.details;
    //newnode->teacher_login = te.teacher_login;
    
    newnode->next = NULL;
    
    return newnode;
}


/*adding node in LL containing teacher details
parameter1:: *head pointing to 1st node of LL,
parameter2:: *newnode containing new record fetched from file*/
nd* add_Tch_Node(nd *head,nd *newnode)
{
    nd *temp=head;
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

//function:: writing each entry/loop from structure to file using fprintf
//parameter1:: file ptr pointing to data into the file
//parameter2:: structure to write data from
//return type:: void
void write_Teacher(FILE *fptr, Teacher teacher)
{
	fprintf(fptr,"%d,%d,%s,%s,%d,%c,%d/%d/%d,%s,%s,%ld\n", teacher.Teacher_Id, teacher.Class_Id, teacher.details.First_Name, teacher.details.Last_Name, teacher.details.Age,teacher.details.Gender,teacher.dob.day,teacher.dob.month,teacher.dob.year,teacher.details.Address,			teacher.Email_Id,teacher.Mob_No);
}





//purpose:: deallocating memory function to remove the dynamic memory 
//parameter:: node pointer head
//return type:: void 
void free_Teacher(nd* head)
{
	nd* temp = head;
	if(temp == NULL)
	{
		free(temp);
		return;
		
	}
	while(temp!=  NULL)
	{
		nd* tag= temp;
		temp = temp->next;
		free(tag);
		tag = NULL;
		
	}
	
	
}



















