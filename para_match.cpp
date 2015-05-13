#define MAX 100

int is_opening ( char ch )
{
	if ( ch == '(' || ch == '[' || ch == '{' ) return 1 ;
	else									   return 0 ;
}

int is_closing ( char ch )
{
	if ( ch == ')' || ch == ']' || ch == '}' ) return 1 ;
	else									   return 0 ;
}

char counter ( char ch )
{
	if ( ch == ')' ) return '(' ;
	if ( ch == ']' ) return '[' ;
	if ( ch == '}' ) return '{' ;
}

int isempty ( int top )
{
	if ( top == -1 ) return 1 ;
	else 			 return 0 ;
}

void push ( char A[] , int *top , char data ) 
{
	A[++(*top)] = data ;
}

char pop ( char A[] , int *top )
{
	char data = A[*top] ;
	--(*top);
	return data ;
}

extern int para_match_test ( char expr[] )
{
		char ch ;
	
		int top = -1 , ctrl = -1 , i = 0 ;

		char A[MAX] ;

		while (( ch = expr[i++] ) != '\0' )
		{
			if ( is_opening (ch) ) 
			{
				push ( A , &top , ch ) ;
			}
		
			if ( is_closing (ch) )
			{
				if ( ! ( pop ( A , &top ) == counter ( ch ) ) )
				{
					return 0 ;
				}
			}
		}
	
		if ( isempty ( top ) ) return 1 ;
		else 				   return 0 ;
	
}