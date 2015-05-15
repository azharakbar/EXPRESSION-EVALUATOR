extern void space_remove ( char expr [] )
{
	int i = 0 , j = 0 ;

	for ( i = 0 ; expr[i] != '\0' ; ++i )
	{
		if ( expr[i] == ' ' )
		{
			j = i ;
			while ( expr[j] != '\0' )
			{
				expr[j] = expr[j+1] ;
				++j ;
			}
		}
	}

	i = 0 ;

	for ( i = 0 ; expr[i] != '\0' ; ++i )
	{
		if ( expr[i] == '{' ) expr[i] = '(' ;
		else if ( expr[i] == '[' ) expr[i] = '(' ;
		else if ( expr[i] == '}' ) expr[i] = ')' ;
		else if ( expr[i] == ']' ) expr[i] = ')' ;
	}
}