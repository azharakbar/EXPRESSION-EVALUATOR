#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

struct stack {
    double operand ;
    int opcode ;
};

stack A[100] ;
int top = -1 ;

int getOperand ( char expr[] , int &from ){
    int operandValue = 0 ;

    while ( isdigit(expr[from]) ){
        if ( (expr[from] >= 48 && expr[from] <= 57) ){
            operandValue = ( operandValue *10 ) + ( (int)(expr[from]) - 48 ) ;
        }
        ++from ;
    }
    --from ;
    return operandValue ;
}

bool isOperator ( char opr ){
    return (( opr == '+' ) || ( opr == '-' ) || ( opr == '*' ) || ( opr == '/' ))?true:false ;
}

int setOpCode ( char opr ){
    if ( opr == '+' )
        return 1 ;
    else if ( opr == '-' )
        return 2 ;
    else if ( opr == '*' )
        return 3 ;
    else if ( opr == '/' )
        return 4 ;
    else
        return -1 ;
}

double performOperation ( int operand1 , int operand2 , int opcode ){

    double result = 0 ;
    if ( opcode == 1 ){
        result = operand1 + operand2 ;
    } else if ( opcode == 2 ){
        result = operand1 - operand2 ;
    } else if ( opcode == 3 ){
        result = operand1 * operand2 ;
    } else if ( opcode == 4 ){
        result = operand1 / operand2 ;
    }

    return result ;
}

extern double evaluator ( char expr[] , int &from )
{
    double result = 0 ,  temp = 0 ;
    int i = 0 , opcode = 0 , dec = -1 , j = 0 , ten = 1 ;
    bool readOnce = false ;
    ++from ;
    while ( expr[from] != '\0' ){
        if ( expr[from] == '(' ){
            if ( !opcode ){
                result = evaluator ( expr , from ) ;
            } else if ( opcode == 1 ){
                result += evaluator ( expr , from ) ;
            } else if ( opcode == 2 ){
                result -= evaluator ( expr , from ) ;
            } else if ( opcode == 3 ){
                result *= evaluator ( expr , from ) ;
            } else if ( opcode == 4 ){
                result /= evaluator ( expr , from ) ;
            }
        } else if ( isdigit(expr[from]) ){
            temp = getOperand ( expr , from ) ;
            if ( !result && !readOnce ){
                result = temp ;
                readOnce = true ;
            }
            if ( opcode ){
                readOnce = true ;
                result = performOperation ( result , temp , opcode ) ;
            }
        } else if ( isOperator(expr[from]) ){
            opcode = setOpCode ( expr[from] ) ;
        } else if ( expr[from] == ')' ){
            return result ;
        }
        ++from ;
    }

    return result ;
}