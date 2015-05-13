#include <iostream>
#include <string>

using namespace std ;

extern int para_match_test ( char expr[] ) ;

void main ()
{
	char expr[100] = "" ;

	cin.getline ( expr , 100 ) ;

	if ( para_match_test ( expr ) )
		cout<<endl<<"MATCHING CORRECT";
	else
		cout<<endl<<"MATCHING INCORRECT";

	getchar();
}