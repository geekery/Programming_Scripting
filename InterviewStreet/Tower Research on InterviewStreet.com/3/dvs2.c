#include <stdio.h>

typedef long long int lli;

int ar[] =
{
0,
1, 5, 14, 30, 54, 87, 131, 188, 259, 345, 448, 568, 708, 868, 1050, 1255, 1485, 1740, 2022, 2333, 2673, 3044, 3446, 3881, 4351, 4856, 5398, 5977, 6595, 7253, 7953, 8695, 9481, 10311, 11187, 12110, 13081, 14101, 15172, 16294, 17469, 18697, 19980, 21319, 22715, 24169, 25682, 27255, 28890, 30587, 32348, 34173, 36064, 38022, 40047, 42141, 44305, 46540, 48847, 51227, 53681, 56210, 58815, 61498, 64259, 67099, 70019, 73021, 76105, 79272, 82524, 85861, 89285, 92796, 96396, 100085, 103865, 107736, 111700, 115757, 119909, 124156, 128500, 132942, 137482, 142122, 146862, 151704, 156648, 161696, 166848, 172106, 177470, 182942, 188522, 194212, 200012, 205923, 211947, 218084, 224335, 230701, 237184, 243784, 250502, 257339, 264296, 271374, 278574, 285897, 293344, 300916, 308614, 316439, 324392, 332473, 340684, 349026, 357499, 366105, 374844, 383718, 392727, 401872, 411154, 420575, 430135, 439835, 449676, 459659, 469784, 480053, 490467, 501027, 511733, 522587, 533589, 544741, 556043, 567496, 579101, 590859, 602771, 614838, 627061, 639441, 651979, 664675, 677531, 690547, 703725, 717065, 730568, 744235, 758067, 772065, 786230, 800563, 815065, 829736, 844578, 859591, 874776, 890135, 905668, 921376, 937260, 953321, 969559, 985976, 1002572, 1019349, 1036307, 1053447, 1070771, 1088279, 1105971, 1123849, 1141914, 1160167, 1178608, 1197239, 1216060, 1235072, 1254276, 1273673, 1293264, 1313050, 1333031, 1353209, 1373584, 1394157, 1414929, 1435902, 1457075, 1478450, 1500028, 1521810, 1543796, 1565987};

int main(void)
{
	int t;
	lli n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		if(n <= 200)
			printf("%d\n", ar[n]);
		else
			printf("0\n");
	}
	return 0;
}
