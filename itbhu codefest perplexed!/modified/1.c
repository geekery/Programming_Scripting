#include <stdio.h>
#include <math.h>
main()
{	
	int c,n,b;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d", &n, &b);
		printf("%d\n", n % (int) pow(2, b));
	}
}
