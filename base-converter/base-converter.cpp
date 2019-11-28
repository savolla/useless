#include <iostream>

// recursive function that converts $x to base $base
void base_cnvt(long int x, int base)
{
	if (x <= 0)
		return;
	base_cnvt(x/base, base);
	std::cout << x%base;
}

// print base 2,3,4,5,6,7,8,9,10 of number 100
int main(void)
{
	for (int i=2; i<=10; ++i)
	{
		base_cnvt(100, i); std::cout << std::endl;
	}
	return 0;
}

