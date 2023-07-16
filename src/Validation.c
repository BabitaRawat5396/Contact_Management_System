//------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L-------------------------------------------------------------
//--------------------------------------------------------------------------V A L I D A T I O N S  F U N C T I O N  F I L E ---------------------------------------------------------------------------


#include"Con_Man_Sys.h"
#include"Con_Man_Sys_Struct.h"


//--------------------------------------------ID VALIDATION---------------------------------------------------------
//This Function the id that has been passed to the function as an argument if it is valid otherwise it will return 0


//--------------------------------------------EMAIL ID VALIDATION--------------------------------------------
//This Function returns 1 if the Mail ID that has been passed to the function as an argument is valid otherwise it will return 0

int Gmail_Validation(char *str)
{
	char s[] = "@school.com";
	char s1[] = "@gmail.com";
	
	char *p = strstr(str, s);			//checked whether the string is present in given mail ID
	char *k = strstr(str,s1);
	
	if(p)
	{
		return 1;
	}
	if(k)
	{
		return 1;
	}
	
	return 0;
}


//--------------------------------------------MOBILE NO VALIDATION--------------------------------------------
//This Function is returns the count of the mobile number if count is 10 than it will return 1, otherwise it will return 0

int Mobile_Validation(long int mob_no)
{
	int count=0;
	
	while(mob_no!=0) //To check whether the number of digits is not equal to zero
	{
    // To check the count of the digits
		mob_no=mob_no/10;
		count++;
	}
	if(count==10)
		return 1;
	return 0;
}

//--------------------------------------------Date Of Birth VALIDATION--------------------------------------------
/*This Function is returns the 1 if year is in between 1900 to 2017 , month in between 1 to 12 and day in between 1 to 31 for partcular months 
like for 1,3,5,7,8,10 and 12th month days are 31 , 4,6,9,11th month have 30 days, 2 month have 28 and for leep year it has 29 
and this function will return 0 if non of the above follows 
*/
int dob_validate(DOB d)
{
    //check year
    if(d.year>=1900 && d.year<=2017) 
    {
        //check month
        if(d.month>=1 && d.month<=12)
        {
            //check days
            if((d.day>=1 && d.day<=31) && (d.month==1 || d.month==3 || d.month==5 || d.month==7 || d.month==8 || d.month==10 || d.month==12)) // To check months with 31 days
                return 1;
            else if((d.day>=1 && d.day<=30) && (d.month==4 || d.month==6 || d.month==9 || d.month==11)) // To check months with 30 days
                return 1;
            else if((d.day>=1 && d.day<=28) && (d.month==2)) //To check month with 28 days 
                return 1;
            else if(d.day==29 && d.month==2 && (d.year%400==0 ||(d.year%4==0 && d.year%100!=0))) //To check month with 29 days in a leapyear
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    	return 0;
}


int Password_Validation(char *pass)
{
	
        int i,number,special,capital,small;
        number=special=capital=small=0;
        
        for(i=0;pass[i]!='\0';i++)
        {
            if(pass[i]>='0' && pass[i]<='9')
            	number=1;
            if(pass[i]>='a' && pass[i]<='z')
            	small=1;
            if(pass[i]>='A' && pass[i]<='Z')
            	capital=1;
            if(pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='*')
            	special=1;
        }
        if(number==0 || special==0 || capital==0 || small==0)
        	return 0;
        else
        	return 1;


}


//function to validate the teacher id and roll number of student
int validate_id(int id)
{
	int arr[6];
	int count=0;
	int  n = id;
	
	//counting the number of digits
	while(n>0)
	{
		n = n/10;
		count++;
	}
	//vlidating the count of digits
	if(count != 6)
	{
		return 0;
	}
	
	//storing the digits for further vailadtion
	count = 0;
	while(id>0)
	{
		arr[count] = id%10;
		id = id/10;
		count++;
	}
	if(count == 6)
	{
		int y, n, m;
		n = arr[1]*10 + arr[0];
		m = arr[3]*10 + arr[2];
		y = arr[5]*10 + arr[4];
		if((y>=00 && y<=22) && (m>=01 && m<=12) && (n>=01 && n<=99))	//stored the numbers in variables and check for each condition
			return 1;
		else
			return 0;
		
	}
	else
	{
		return 0;
	}
}



