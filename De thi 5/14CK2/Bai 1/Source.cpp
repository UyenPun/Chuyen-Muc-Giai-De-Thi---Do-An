/* 
Giai pt: ax^4 + bx^2 + c = 0
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

void GiaiPhuongTrinh(double a, double b, double c)
{
	if(a == 0) // Phương trình sẽ có dạng: bx^2 + c = 0
	{
		if(b == 0) // Phương trình sẽ có dạng: c = 0
		{
			if(c == 0)
			{
				printf("\nPhuong trinh co vo so nghiem");
			}
			else
			{
				printf("\nPhuong trinh vo nghiem");
			}
		}
		else
		{
			double t; // t tượng trưng cho x^2

			t = -c / b;

			if(t < 0)
			{
				printf("\nPhuong trinh vo nghiem");
			}
			else
			{
				double x1 = sqrt(t);
				double x2 = -sqrt(t);

				printf("\nPhuong trinh co 2 nghiem phan biet:\nx1 = %lf\nx2 = %lf", x1, x2);
			}
		}
	}
	else
	{
		// ax^4 + bx^2 + c = 0

		double t; // t tượng trưng cho x^2 lúc này pt có dạng: at^2 + bt + c = 0

		double Denta = b * b - 4 * a * c;
		if(Denta < 0)
		{
			printf("\nPhuong trinh vo nghiem");
		}
		else if(Denta == 0)
		{
			t = -b / (2 * a); // Nghiệm kép.

			if(t < 0)
			{
				printf("\nPhuong trinh vo nghiem");
			}
			else
			{
				double x1 = sqrt(t);
				double x2 = -sqrt(t);

				printf("\nPhuong trinh co 2 nghiem phan biet:\nx1 = %lf\nx2 = %lf", x1, x2);
			}
		}
		else // Denta > 0
		{
			double t1 = (-b + sqrt(Denta)) / (2 * a);
			double t2 = (-b - sqrt(Denta)) / (2 * a);

			if(t1 < 0 && t2 < 0)
			{
				printf("\nPhuong trinh vo nghiem");
			}
			else
			{
				if(t1 >= 0)
				{
					double x1 = sqrt(t1);
					double x2 = -sqrt(t1);

					printf("\nPhuong trinh co nghiem:\nx1 = %lf\nx2 = %lf", x1, x2);
				}

				if(t2 >= 0)
				{
					double x3 = sqrt(t2);
					double x4 = -sqrt(t2);

					printf("\nPhuong trinh co nghiem:\nx3 = %lf\nx4 = %lf", x3, x4);
				}
			}
		}
	}
}

int main()
{
	double a = -2, b = 8, c = -8;

	GiaiPhuongTrinh(a, b, c);

	getch();
	return 0;
}