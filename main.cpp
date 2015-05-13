#include <iostream>
#include <string>

using namespace std ;

extern int para_match_test ( char expr[] ) ;
extern void space_remove ( char expr [] ) ;

void main ()
{
	char expr[100] = "" ;

	cout << " >> Enter The Mathematical Expression To Be Evaluated : ";
	cin.getline ( expr , 100 ) ;

	//Enclosing The Entire Expression In ( )
	char temp[100] = "(";
	strcat ( temp , expr ) ;
	strcat ( temp , ")" ) ;
	strcpy ( expr , temp ) ;

	space_remove ( expr ) ;

	cout << endl << " >> The Updated Expression Is : " << expr ;

	if ( para_match_test ( expr ) )
		cout<<endl<<"MATCHING CORRECT";
	else
		cout<<endl<<"MATCHING INCORRECT";

	getchar();
}