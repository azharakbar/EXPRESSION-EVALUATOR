#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

struct stack 
{
    double operand ;
    int opcode ;
};

stack A[100] ;
int top = -1 ;

extern double evaluator ( char expr[] )
{
    double result = 0 ,  temp = 0 ;
    int i = 0 , opcode = 0 , dec = -1 , j = 0 , ten = 1 ;

    while ( expr[i] != '\0' )
    {

        if ( (expr[i] >= 48 && expr[i] <= 57) )
        {
            if ( dec != -1 ) {  ++dec ; }
            temp = ( temp *10 ) + ( (int)(expr[i]) - 48 ) ;
        }
        
        else if ( expr[i] == '.' )
        {
            dec = 0 ;
        }

        else if ( expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' )
        {
            if ( dec != -1 )
            {
                ten = 1 ;
                for ( j = 1 ; j <= dec ; ++j )
                    ten = ten*10 ;
                temp = temp / ten ;
                dec = -1 ; 
            }
            
            if ( !result && opcode != 2 )
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
            if ( i && result )
            {
                A[++top].operand = result ;
                A[top].opcode = opcode ;
                result = temp = opcode = 0 ;
            }
        }

        else if ( expr[i] == ')' )
        {
                if ( dec != -1 )
                {
                    ten = 1 ;
                    for ( j = 1 ; j <= dec ; ++j )
                        ten = ten*10 ;
                    temp = temp / ten ;
                    dec = 0 ; 
                }
                if ( opcode == 1 ) result += temp ;
                else if ( opcode == 2 ) result -= temp ;
                else if ( opcode == 3 ) result = result * temp ;
                else if ( opcode == 4 ) result /= temp ;
                opcode = 0 ;

            if ( top != -1 )
            {
                if ( A[top].opcode == 1 ) result += A[top--].operand ;
				else if ( A[top].opcode == 2 ) result = A[top--].operand - result ;
                else if ( A[top].opcode == 3 ) result *= A[top--].operand ;
                else if ( A[top].opcode == 4 ) result = A[top--].operand / result ;
            }
            if ( !result ) result = temp ;
            temp = 0 ;
        }
        ++i ;
    }

    
    return result ;
}