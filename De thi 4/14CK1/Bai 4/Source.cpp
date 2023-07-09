#include <stdio.h>
#include <conio.h>

int laSoHoanHao(int n);
int TimViTriSHHDauTien(int a[], int n);
int timViTriSHHNhoNhat(int a[], int n);

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

// Hàm trả về vị trí của số hoàn hảo đầu tiên có trong mảng, nếu mảng không có số hoàn hảo thì trả về -1.
int TimViTriSHHDauTien(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(laSoHoanHao(a[i]) == 1) // a[i] là số hoàn hảo.
		{
			return i; // Trả về vị trí đầu tiên của số hoàn hảo.
		}
	}
	return -1; // Mảng không có số hoàn hảo.
}

int timViTriSHHNhoNhat(int a[], int n)
{
	int idx = TimViTriSHHDauTien(a, n); // Biến sẽ lưu vị trí của số hoàn hảo nhỏ nhất có trong mảng.

	if(idx == -1)
	{
		return -1; // Mảng không có số hoàn hảo.
	}

	// Nếu có số hoàn hảo thì xử lý tiếp ở đây.
	int Shh_Min = a[idx];

	for(int i = idx + 1; i < n; i++)
	{
		if(laSoHoanHao(a[i]) == 1) // a[i] là số hoàn hảo
		{
			if(a[i] < Shh_Min)
			{
				a[i] = Shh_Min; // Cập nhật lại Min.
				idx = i; // Cập nhật lại vị trí.
			}
		}
	}
	return idx; // Trả về vị trí của số hoàn hảo nhỏ nhất.
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 496, 8128, 28};
	int n = sizeof(a) / sizeof(a[0]);

	int Kq = timViTriSHHNhoNhat(a, n);
	if(Kq == -1)
	{
		printf("\nMang khong ton tai so hoan hao");
	}
	else
	{
		printf("\nSo hoan hao nho nhat nam tai vi tri: %d", Kq);
	}

	getch();
	return 0;
}