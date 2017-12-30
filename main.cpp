#include <iostream>
#include <string>
#include <process.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std ;

extern int para_match_test ( char expr[] ) ;
extern void space_remove ( char expr [] ) ;
extern void  zero_plus_prepender ( char expr [] );
extern double  evaluator ( char expr [] );
extern double  exponent_enlongator ( char expr [] );

void main ()
{
	char expr[10000] = "" , temp[10000] = "" , cresult[50] = "" ;
	double result = 0.0 ;

	do
	{
		cout << "\n\n >> Enter The Mathematical Expression To Be Evaluated : ";
		cin.getline ( expr , 100 ) ;

		if ( strstr ( expr,"cnl") ) exit (0) ;

		itoa ( result , cresult , 10 ) ;

		//Enclosing The Entire Expression In ( )
		if ( expr[0] == '+' || expr[0] == '-' || expr[0] == '/' || expr[0] == '*'  )
		{
			strcpy ( temp , "(" );
			strcat ( temp , cresult ) ;
		}
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
		}
		
		exponent_enlongator ( expr ) ;

		zero_plus_prepender ( expr ) ;

		result = evaluator ( expr ) ;

		cout << endl << " >> The Result = " << result ;
	}while (1) ;

	getchar();  
}