//-------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-----------------------------------
//-------------------------------------------------------STRUCUTRE HEADER FILE-------------------------------------------------------------------------------------



#include"Con_Man_Sys.h"


//structure for the admin login information
typedef struct Admin_Login_Info
{
	char Email_Id[25];
	char Password[20];
}admin_login;



//structure for the Teacher login information
typedef struct Teacher_Login_Info
{
	int Teacher_Id;
	char Password[20];
}teacher_login;



//structure for the Student login information
typedef struct Student_Login_Info
{
	int Roll_No;
	char Password[20];
}student_login;



//Structure for date of birth
typedef struct Date_of_Birth
{
	int day, month, year;
}DOB;



//structure for basic comman details of student_teacher and admin
typedef struct Basic_Details
{
	char First_Name[15];
	char Last_Name[15];
	char Gender;
	int Age;
	char Address[50];
}details;




//structure for teacher info
typedef struct Teacher
{
	unsigned long long int Mob_No;
	int Teacher_Id;
	int Class_Id;
	char Email_Id[25];	
	struct Date_of_Birth dob;
	struct Basic_Details details;
	struct Teacher_Login_Info teacher_login;
	
}Teacher;


//structure for student info
typedef struct Student
{
	long int Parent_Mob_No;
	int Class;
	char Parents_Mail[25];	
	int Roll_No;
	char Mothers_Name[20];
	char Fathers_Name[20];
	struct Date_of_Birth dob;
	struct Basic_Details details;
	struct Student_Login_Info student_login;
}Student;



//redefining the Student structure for linked list creation
typedef struct StudentLinkedList
{
	long int Parent_Mob_No;
	int Class;
	char Parents_Mail[25];	
	int Roll_No;
	char Mothers_Name[20];
	char Fathers_Name[20];
	char Parents_Name[20];
	struct Date_of_Birth dob;
	struct Basic_Details details;
	struct Student_Login_Info student_login;
  struct StudentLinkedList *next;
    
}node;//renaming the StudentLinedList as node


//redefining the Teacher structure for linked list creation
typedef struct TeacherLinkedList
{
	unsigned long long int Mob_No;
	int Teacher_Id;
	int Class_Id;
	char Email_Id[25];	
	struct Date_of_Birth dob;
	struct Basic_Details details;
	struct Teacher_Login_Info teacher_login;
	struct TeacherLinkedList *next;
	
}nd;




//functions dor manipulation of student linkedlist
node* create_St_Node(Student);
node* add_St_Node(node *,node *);
void Delete_Student();
node* Delete_St_Data(node* , int);
void write_Student(FILE *, Student);
node* Update_St_Data(node*, int);


//functions for teacher linkedlist manipulation
nd* create_Tch_Node(Teacher);
nd* add_Tch_Node(nd *,nd *);
void Delete_Teacher();
nd* Delete_Tch_Data(nd* , int);
void write_Teacher(FILE *, Teacher);
nd* Update_Tech_Data(nd*, int);

//functions to free the menoery occupied by teacher or student linkedlist
void free_Teacher(nd*);
void free_Student(node*);

//Validation for DOB
int dob_validate(DOB);