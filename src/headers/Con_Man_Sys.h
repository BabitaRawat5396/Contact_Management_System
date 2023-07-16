//-----------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L----------------------------
//--------------------------------------F U N C T I O N  H E A D E R  F I L E ------------------------------------------------



//including the standard library files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Macros for LOGIN 
#define ADMIN_LOGIN 1
#define TEACHER_LOGIN 2
#define STUDENT_LOGIN 3
#define EXIT_MENU 0



//Macros for switch case statements for ADMIN OPTIONS
#define UPDATE_TEACHER 1
#define UPDATE_STUDENT 2
#define SEARCH_TEACHER 3
#define DELETE_TEACHER 4
#define INSERT_TEACHER 5
#define SEARCH_STUDENT 6
#define DELETE_STUDENT 7
#define INSERT_STUDENT 8
#define EXIT_ADMIN 0

//Macros for switch case statements for TEACHER OPTIONS

#define SEARCH_TEACHER_T 1
#define SEARCH_STUDENT_T 2
#define UPDATE_DETAILS_T 3 //for class teacher
#define EXIT_TEACHER 0


//Macros for switch case statements for STUDENT OPTIONS
#define SEARCH_STUDENT_S 1
#define SEARCH_TEACHER_S 2
#define EXIT_STUDENT 0

//Macros for switch case statements for UPDATE

//macros for student Parameters
#define PARENT_MOB_NO	1
#define CLASS 		2
#define PARENT_MAIL_ID	3
#define MOTHER_NAME 	4
#define FATHER_NAME 	5
#define FIRST_NAME 	6
#define LAST_NAME 	7
#define GENDER 		8
#define AGE 		9
#define ADDRESS		10
#define D_O_B		11



//macros for teacher Parameters
#define MOB_NO_T	1
#define TEACHER_ID_T 	2
#define CLASS_ID_T 	3
#define MAIL_ID_T 	4
#define FIRST_NAME_T 	5
#define LAST_NAME_T 	6
#define GENDER_T	7
#define AGE_T 		8
#define D_O_B_T         9
#define ADDRESS_T	10




//admin related functions
void Admin_Login();
void Admin_Options();

//teacher related functions
void Teacher_Login();
void Teacher_Options(int);


//student related functions
void Student_Login();
void Student_Options();

//update related functions
void update_menu();
void Update_Student();
void Update_Teacher();


//functions for admin
void Update_Details();//for class teacher too
int Search_Teacher();
void Delete_Teacher();
void Insert_Teacher();


//student details manipulation function
int Search_Student();//for student, teacher, admin
void Delete_Student();//for admin and class teacher
void Insert_Student();//for admin and class teacher


//for display menu
void displayMenu();

//student serach related
int Student_By_Name(char[]);
int Student_By_ROLL(int);

//declaring function for search by name and id for teacher
int Teacher_By_Name(char[]);
int Teacher_By_ID(int, int);


//Validations Functions
int Gmail_Validation(char[]);
int validate_id(int);
int Mobile_Validation(long int);
int Password_Validation(char*);

