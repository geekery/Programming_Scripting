#include <stdio.h>
#include <math.h>
main()
{
	int c, n, x, i, z = 0, k, q, y;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d", &n, &x);
		k = 0;
		for(i = x - 1; i >= 0; i--)
			z += pow(10, i);
		y = z;
		for( ; y < pow(10, x); y++)
		{	
			z = y;
			q = 1;
			while(z > 0)
			{
				q *= (z % 10);
				z /= 10;
			}
			if(q == n)
				k++;
		}
		printf("%d\n", k);
	}
}
		
