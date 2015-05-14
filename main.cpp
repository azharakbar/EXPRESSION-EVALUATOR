#include <iostream>
#include <string>
#include <process.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std ;

extern int para_match_test ( char expr[] ) ;
extern void space_remove ( char expr [] ) ;
extern int  evaluator ( char expr [] , int&  i , int& result );

void main ()
{
	char expr[100] = "" ;
	int result = 0 ;

	cout << " >> Enter The Mathematical Expression To Be Evaluated : ";
	cin.getline ( expr , 100 ) ;

	//Enclosing The Entire Expression In ( )
	char temp[100] = "(";
	strcat ( temp , expr ) ;
	strcat ( temp , ")" ) ;
	strcpy ( expr , temp ) ;

	space_remove ( expr ) ;

	if ( ! para_match_test ( expr ) )
	{
		cout<<endl<<"!! SORRY !! THE EXPRESSION IS INVALID !!" ;
		getchar () ;
		exit (0) ;
	}

	cout << endl << " >> The Updated Expression Is : " << expr ;

	cout << endl << " >> Each Character Details : " ;
	for ( int i = 0 ; expr [i] != '\0' ; ++i ) 
		cout << endl << "expr["<<i<<"] = " << expr[i] ;

	int j = 0 ;
	int opcode = 0 ;
	result = evaluator ( expr , j , result ) ;

	cout << endl << " >> The Result = " << result ;

	getchar();  
}