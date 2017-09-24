#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y, R;
	scanf("%lf%lf", &x, &y);
	R = sin(x) + exp(2*y);
	printf("%.4lf\n", R);
	return 0;
}
