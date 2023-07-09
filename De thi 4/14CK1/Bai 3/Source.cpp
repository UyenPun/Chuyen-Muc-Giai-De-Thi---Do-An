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

// Kiểm tra mảng toàn số hoàn hảo, nếu thỏa trả về 1, ngược lại trả về 0.
int laMangToanSoHoanHao(int a[], int n)
{
	// Vòng lặp for chạy từ đầu mảng tới cuối mảng.
	for(int i = 0; i < n; i++)
	{
		printf("\nOK"); // Để xét xem vòng lặp thực tế chạy bao nhiêu lần.
		if(laSoHoanHao(a[i]) == 0)
		{
			return 0; // Không thỏa toàn số hoàn hảo.
		}
	}
	return 1; // Toàn số hoàn hảo.
}

int main()
{
	int a[] = {6, 28, 496, 8128};
	int n = sizeof(a) / sizeof(a[0]); // 24 / 4 = 6

	int Kq = laMangToanSoHoanHao(a, n);
	if(Kq == 1)
	{
		printf("\nMang toan so hoan hao");
	}
	else
	{
		printf("\nMang khong phai toan so hoan hao");
	}

	getch();
	return 0;
}