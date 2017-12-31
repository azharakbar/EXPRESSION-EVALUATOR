#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

extern double exponent_enlongator ( char expr[] ){
	char temp[10000] = "" , base[5000] = "" ;
	int raisePower = 0 , bracket = 0 , start = 0 , end = 0 , power = 0 , power_end = 0 ; 

	int indexForTemp = 0 ;
	strcpy ( temp , expr ) ;

	int i = 0  , j = 0 , k = 0 ;

	while ( expr[i] != '\0' ){
		if ( expr[i] != '^' ){
			temp[indexForTemp++] = expr[i] ;
		} else {
			temp[indexForTemp] = '\0' ;
			end = i-1 ;
			j = i+1 ;
			raisePower = 0 ;
 			while ( isdigit(expr[j]) ){
				raisePower = (raisePower * 10) + (expr[j]-'0') ;
				++j ;
			}
			power_end = j ;
			if ( expr[end] == ')' ){
				j = end ;
				bracket = 0 ;
				do{
					if ( expr[j] == ')' ){
						++bracket ;
					} else if ( expr[j] == '(' ){
						--bracket ;
					}
					--j ;
				}while(bracket) ;
				start = j+1 ;
				strcpy ( base , "" ) ;
				k = 0 ;
				j = start ;
				while ( k <= end-start ){
					base[k++] = expr[j] ;
					++j ;
				}
				base[k] = '\0' ;
			} else {
				j = end ;
				k = 0 ;
				while ( isdigit(expr[j] ) ){
					base[k++] = expr[j] ;
					--j ;
				}
				start = j-1 ;
				base[k] = '\0' ;
				strrev(base) ;
			}

			--raisePower ;
			if ( raisePower == -1 ){
				strcat ( temp , "*0+1" ) ;
			} else if ( raisePower == 0 ){
				strcat ( temp , "*1" ) ;
			} else {
				for ( j = 1 ; j <= raisePower ; ++j ){
					strcat ( temp , "*" ) ;
					strcat ( temp , base ) ;
				}
			}
			indexForTemp = strlen(temp) ;
			i = power_end-1 ;
		}
		++i ;
	}

	strcpy ( expr , temp ) ;
}