#include <stdio.h>

int main()
{
	long int n = 0, left = 0, right = 0;
	char x;
	(void)scanf("%li %c", &n,&x);
	if (x == '(')
	{
		left++;
		long int i = 1;
		for (i; i<n; i++)
		{
    			(void)scanf(" %c", &x);
    			if ( x == '(')
    			{
    				left++;
    			}
    			if ( x == ')')
    			{
    				right++;
    			}
    		}
    		if (left == right)
    		{
    			printf("1");
    		}
    		else 
    		{
    			printf("0");
    		}
	}
	else
	{
   	     printf("0");
	}
	return 0;
}
