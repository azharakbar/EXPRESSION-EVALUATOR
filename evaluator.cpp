#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

int get_number ( char expr[] , int& i , int &result , int opcode )
{
	char temp[50] = "" ;
	int j = 0 ;

	while ( isdigit ( expr[i] ) )
		temp[j++] = expr[i++] ;

	temp[j] = '\0' ;

	if ( opcode == 1 )      result += atoi (temp) ;
	else if ( opcode == 2 ) result -= atoi (temp) ;
	else if ( opcode == 3 ) result *= atoi (temp) ;
	else if ( opcode == 4 ) result /= atoi (temp) ;
	else if ( !opcode )     result  = atoi (temp) ;

	cout << endl << " ** I AM INSIDE GETNUM FUNCTION ** ";
	cout << endl << " >> I UPDATED i as : "<< i ;
	cout << endl << " >> I UPDATED result as : " << result ;
	cout << endl << " >> I UPDATED opcode as : " << opcode ;
	getchar () ;

	return result ;

}

extern int evaluator ( char expr[] , int& i , int &result  )
{
	int opcode =  0 ;
	char op = NULL ;
	
	while ( expr[i] != ')' && expr[i] != '\0' )
	{
		cout << endl << " I AM INSIDE THE LOOP AND NOW expr["<<i<<"] = "<<expr[i] ;
		getchar (); 
		if ( expr[i] == '(' )
		{
			++i ;
			result = evaluator ( expr , i , result ) ;
			if ( expr[i+1] != ')' && expr[i+1] != '\0')
			{
				op = expr [i++] ;
				cout<<endl<< " I GOT THE OP = " <<op ;
			}
			else
				return result ;
		}

		if ( expr[i] != '(' )
		{
			result = get_number ( expr , i , result , opcode ) ;
			cout << endl << "value of i = " << i ;
			getchar () ;

			if ( expr[i+1] != ')' && expr[i+1] != '\0')
			{
				op = expr [i++] ;

				if ( op == '+' ) opcode = 1 ;
				else if ( op == '-' ) opcode = 2 ;
				else if ( op == '*' ) opcode = 3 ;
				else if ( op == '/' ) opcode = 4 ;
				else if ( op == NULL ) opcode = 0 ;
			}
			else
				return result ;
		}

	}
	
	return result ;
}