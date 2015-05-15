#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

struct stack 
{
	int operand ;
	int opcode ;
};

stack A[100] ;
int top = -1 ;

extern int evaluator ( char expr[] )
{
	int result = 0 , i = 0 , opcode = 0 , temp = 0 ;

	while ( expr[i] != '\0' )
	{
		cout << endl << " NOW I AM DEALING WITH " << expr[i] ;
		if ( expr[i] >= 48 && expr[i] <= 57 )
		{
			cout << endl << " I AM IN CONDITION 1 " ;
			temp = ( temp *10 ) + ( (int)(expr[i]) - 48 ) ;
		}

		else if ( expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' )
		{
			cout << endl << " I AM IN CONDITION 2 " ;
			if ( !result )
				result = temp ;
			else
			{
				if ( opcode == 1 ) result += temp ;
				else if ( opcode == 2 ) result -= temp ;
				else if ( opcode == 3 ) result *= temp ;
				else if ( opcode == 4 ) result /= temp ;
			}

			temp = 0 ;
			if ( expr [i] == '+' ) opcode = 1 ;
			else if ( expr [i] == '-' ) opcode = 2 ;
			else if ( expr [i] == '*' ) opcode = 3 ;
			else if ( expr [i] == '/' ) opcode = 4 ;
		}

		else if ( expr[i] == '(' )
		{
			cout << endl << " I AM IN CONDITION 3 " ;
			if ( i && result )
			{
				cout << endl << " I AM PUSHING " ;
				A[++top].operand = result ;
				A[top].opcode = opcode ;
				result = temp = opcode = 0 ;
			}
		}

		else if ( expr[i] == ')' )
		{
			cout << endl << " I AM IN CONDITION 4 " ;
				if ( opcode == 1 ) result += temp ;
				else if ( opcode == 2 ) result -= temp ;
				else if ( opcode == 3 ) result = result * temp ;
				else if ( opcode == 4 ) result /= temp ;
				opcode = 0 ;
			if ( top != -1 )
			{
				cout << endl << " I AM POPPING " ;
				if ( A[top].opcode == 1 ) result += A[top--].operand ;
				else if ( A[top].opcode == 2 ) result -= A[top--].operand ;
				else if ( A[top].opcode == 3 ) result *= A[top--].operand ;
				else if ( A[top].opcode == 4 ) result /= A[top--].operand ;
			}
			temp = 0 ;
		}

		cout << endl << " AT THE END .... VALUE OF result = " << result << " AND temp = " << temp ; 

		getchar();
		++i ;
	}

	return result ;
}