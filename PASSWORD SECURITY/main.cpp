//Password.cpp
//Auther   : oursharingciub
//Date     : September 26, 2014 Firday
//Email    : oursharingclub@163.com
//Tool     : Dev C++
//Language : C++

//Notice: Reference Mr. Jake Rodriguez Pomperada programming


#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>   //system(), Sleep( )
#include <time.h>


using namespace std;

const int PASSLEN= 7 ; //The length of password

string PassGet( void ); // Get the password
void Menu( void );   //The start menu


//******** main function **********
int main( void )
{
	Menu();

	getch();  //wait untill enter any key

	return 0;
}


//****** PassGet and menu function*****

string PassGet( void )
{
	char password[ PASSLEN ]= { '\0' };
	char letter;
	int loop;
	int len;
	string password2;

	len= 0;
	loop= 0;
	letter= '\0';

	while( letter!= '\r' )   //Caarrige return character
	{
	    letter= getch();

		if( letter== '\b' && password[ 0 ]== '\0' )
		{
		   loop= 0;
		   len= 0;
		}
		else
		{
			if( letter== '\b' && password[ 0 ]!= '\0' )  // \b :backspace
			{
			    cout<< "\b";
			    cout<< " ";
			    cout<< "\b";

			    loop--;
			    password[ loop ]= '\0';
			    len-- ;
			}
			else
			{
			    if( isprint( letter )!= 0 && loop< PASSLEN )
				{
			        password[ loop ]= tolower( letter );

			        cout<< "*";
				}
				loop++;
				if( loop<= PASSLEN )
				{
				   len++;
				}
			}
		}
	}

	//Convert Password from character
	loop= 0;
	password2= "";

	while( loop< len )
	{
	    password2= password2+ password[ loop ];

		loop++;
	}
	return password2;
}  //End of Passget function


void Menu( void )
{
	string password;

	//Get local time
	time_t date;
	date= time( NULL );

	cout<< "\n\n";

	char str[]= "********* PASSWORD SECURITY VERSION 2.0 **********";

	for( int i= 0; i< strlen( str ); i++ )
	{
		cout<< str[ i ];
		Sleep( 100 );  //wait 0.1 second
	}
	cout<< "\n\n";
	cout<< "\n\t\t Notice: Protect your Password.";
	cout<< "\n\n\t\t Enter Your Password: ";

	password= PassGet();

	if( password== "sharing" )
	{
		system( "cls" );

	    cout<< "\n\n\n\n";
		cout<< "\t\t Password Accepted.";
		cout<< "\n";
		cout<< "\n\n\t\t Thank You For Using this Software.";
		cout<< "\n\n\t\t Date : "<< ctime( &date );	   //show local time
	}
	else
	{
	   cout<< "\n\n";
	   cout<< "\n\t\tSorry...";
	   cout<< "\n\t\tPassword Denied!!!\n\n";

	   Sleep( 1000 );

	   cout<< "\n\n\t\tTry Again( Y ): ";

	   char ch;

	   cin>> ch;
	   if( toupper( ch )== 'Y' )
	   {
			system( "cls" );

		    Menu();
	   }
	   else
	   {
		    exit( 1 );
	   }
	}

	return ;
}   //End of Menu Function

