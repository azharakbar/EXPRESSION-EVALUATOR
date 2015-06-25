#include <iostream>
#include <string>
#include <process.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std ;

extern int para_match_test ( char expr[] ) ;
extern void space_remove ( char expr [] ) ;
extern double  evaluator ( char expr [] );

void main ()
{
	char expr[100] = "" , temp[100] = "" ;
	double result = 0.0 ;

	do
	{
		cout << "\n\n >> Enter The Mathematical Expression To Be Evaluated : ";
		cin.getline ( expr , 100 ) ;

		if ( !strcmp ( expr,"cnl") ) exit (0) ;

		//Enclosing The Entire Expression In ( )
		if ( expr[0] == '-' )
			strcpy ( temp , "(0" ) ;
		else
			strcpy ( temp , "(" ) ;
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

		result = evaluator ( expr ) ;

		cout << endl << " >> The Result = " << result ;
	}while (1) ;

	getchar();  
}