#include <ctype.h>
#include <string.h> 
#include <iostream>

using namespace std ;

extern void zero_plus_prepender ( char expr [] ){
	char temp[100] = "" ;
	int i = 0 , j = 0 ;
	for ( i = 0 ; expr[i] != '\0' ; ++i ){
		temp[j++] = expr[i] ;
		if ( i && expr[i] == '('){
			temp[j++] = '0' ;
			temp[j++] = '+' ;
		}
	}
	temp[j] = '\0' ;
	
	strcpy ( expr , temp ) ;	
}

extern void space_remove ( char expr [] )
{
	int i = 0 , j = 0 ;

	for ( i = 0 ; expr[i] != '\0' ; ++i ){
		if ( expr[i] == ' ' ){
			j = i ;
			while ( expr[j+1] != '\0' ){
				expr[j] = expr[j+1] ;
				++j ;
			}
			expr[j] = '\0' ;
			--i ;
		}
	}

	i = 0 ;

	for ( i = 0 ; expr[i] != '\0' ; ++i ){
		if ( expr[i] == '{' || expr[i] == '[' ) expr[i] = '(' ;
		else if ( expr[i] == '}' || expr[i] == ']' ) expr[i] = ')' ;
	}

	char temp[100] = "" ;
	j = 0 ;
	for ( i = 0 ; expr[i] != '\0' ; ++i ){
		temp[j++] = expr[i] ;

		if (  expr[i+1] != '\0' ){
			if ( expr[i] == ')' && isdigit(expr[i+1]) ){
				temp[j++] = '*' ;
			} else if ( ( expr[i+1] == '(' && isdigit(expr[i]) ) ){
				temp[j++] = '*' ;
			} else if ( ( expr[i] == ')' && expr[i+1] == '(' ) ) {
				temp[j++] = '*' ;
			}
		}
	}
	temp[j] = '\0' ;
	
	strcpy ( expr , temp ) ;
}