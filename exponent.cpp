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

	// cout << "Incoming Expr Original = " << expr << endl ;
/*
	for ( int x = 0 ; expr[x] != '\0' ; ++x )
		cout << x << " = " << expr[x] << "    " ;*/

	// cout << "in enlongator" << endl ;

	int i = 0  , j = 0 , k = 0 ;

	while ( expr[i] != '\0' ){
		// cout << "Now Considering ---->> " << expr[i] << endl ;
		if ( expr[i] != '^' ){
			temp[indexForTemp++] = expr[i] ;
		} else {
			temp[indexForTemp] = '\0' ;
			// cout << "Temp = " << temp << endl ;
			end = i-1 ;
			j = i+1 ;
			raisePower = 0 ;
 			while ( isdigit(expr[j]) ){
				raisePower = (raisePower * 10) + (expr[j]-'0') ;
				++j ;
			}
			power_end = j ;
			// cout << "Power = " << raisePower <<  endl ;
			// cout << "Power_end = " << power_end << endl ;
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
				// cout << "Start = " << start << endl ;
				// cout << "End = " << end << endl ;

				strcpy ( base , "" ) ;
				k = 0 ;
				j = start ;
				while ( k <= end-start ){
					base[k++] = expr[j] ;
					++j ;
				}
				base[k] = '\0' ;
				cout << "Base = " << base << endl ;
				//start = j ;

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
				// cout << "Start = " << start << endl ;
				// cout << "End = " << end << endl ;				
				// cout << "Baee == " << base << endl ;
			}

			--raisePower ;
			// cout << "New Power = " << raisePower << endl ;

			for ( j = 1 ; j <= raisePower ; ++j ){
				// cout << "Here" << endl ;
				strcat ( temp , "*" ) ;
				strcat ( temp , base ) ;
			}
			indexForTemp = strlen(temp) ;
			i = power_end-1 ;
		}
		++i ;
	}

	cout << "DONE ----------   " << temp << endl ;
	strcpy ( expr , temp ) ;
}