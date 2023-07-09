/* 

Một số n bất kỳ thì sẽ có các ước số nhỏ hơn nó nằm trong
phạm vi từ 1 --> n / 2

*/

#include <stdio.h>
#include <conio.h>

int laSoHoanHao(int n);

// Kiểm tra xem n có là số hoàn hảo, nếu có trả về 1, ngược lại trả về 0.
int laSoHoanHao(int n)
{
	int Tong = 0;

	for(int i = 1; i <= n / 2; i++)
	{
		if(n % i == 0) // i là ước số của n
		{
			Tong += i; // Tong = Tong + i;
		}
	}
	if(Tong == n)
	{
		return 1; // Là số hoàn hảo.
	}
	return 0; // Không phải là số hoàn hảo.
}

int main()
{
	int n = 6;

	int Kq = laSoHoanHao(n);

	if(Kq == 1)
	{
		printf("\nSo %d la so hoan hao", n);
	}
	else
	{
		printf("\nSo %d khong phai la so hoan hao", n);
	}

	getch();
	return 0;
}