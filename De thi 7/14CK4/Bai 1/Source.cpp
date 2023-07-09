/* 
n = 0 => kết quả là: x^1/1!
n = 1 => kết quả là: x - x^3/(1! * 2 * 3)
n = 2 => kết quả là: x - x^3/3! + x^5/(3! * 4 * 5)
n = 3 => kết quả là: x - x^3/3! + x^5/5! - x^7/(5! * 6 * 7)
n = 4 => kết quả là: x - x^3/3! + x^5/5! - x^7/7! + x^9/(7! * 8 * 9)

n = k => kết quả là (k - 1) * x^2 / (2 * k * (2 * k + 1))
vd: n = 0 thì kết quả là: x^1/1!
n = 1 => x^1/1! * x^2/(2 * 3) = x * x^2/(2 * 3) => x^3/3!
n = 2 => x^3/3! * x^2/(4 * 5) = x^5/5!
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

double XuLy(double x, int n)
{
	double S = x; // S là kết quả sau cùng.
	double Temp = x; // Temp là biến trung gian giữa mỗi lần chuyển giao.

	for(int i = 1; i <= n; i++)
	{
		Temp = Temp * x * x / (2 * i * (2 * i + 1));
		S += pow(-1.0, i) * Temp;
	}
	return S;
}

int main()
{
	double x = 2;
	int n = 100;

	printf("\nS = %lf", XuLy(x, n));
	printf("\nSin(2.0) = %lf", sin(2.0));

	getch();
	return 0;
}