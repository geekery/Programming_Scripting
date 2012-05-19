/*
	Rovin Bhandari
	11/10/2011
	
	COINS
*/

#include <cstdio>
#include <map>
using std::map;

map<int, unsigned int> memo;	// memoization hash table consisting of number as hash-key and the number's equivalent max$ value as hash-value
map<int, unsigned int>::iterator i;
unsigned int beq;		// bytelandian equivalent; temporary variable to prevent one access to the hashmap per test-case
//int max;		// temporary variable to hold the maximum out of a number or its bytelandian equivalent

unsigned int max$(int x)
{
	if(x == 0)
		return 0;
	if((i = memo.find(x)) != memo.end())
		return i->second;
	else
	{
		return (memo[x] = ((x > (beq = max$(x >> 2) + max$(x / 3) + max$(x >> 1))) ? x : beq));	// will this line be faster than the 4 lines below it? Doesn't this line involve 2 accesses to the hash map while the lines below involves only 1?
		/*
		beq = max$(x >> 2) + max$(x / 3) + max$(x >> 1);
		max = (x > beq) ? x : beq;
		memo[x] = max;
		return max;
		*/
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) > 0)
		printf("%u\n", max$(n));
	return 0;
}
