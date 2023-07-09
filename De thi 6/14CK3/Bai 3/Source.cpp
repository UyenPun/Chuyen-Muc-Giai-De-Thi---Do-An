#include <stdio.h>
#include <conio.h>

void XuLyYeuCau(int a[], int n)
{
	int dem = 0; // Khởi tạo ban đầu.
	int Tong = 0;

	// Duyệt hết mảng.
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0) // a[i] là số chẵn.
		{
			dem++; // Tăng biến đếm lên.
			Tong += a[i] * a[i]; // Tính tổng bình phương các số chẵn.
		}
	}

	printf("\nCo %d so chan trong mang", dem);
	printf("\nTong binh phuong cac so chan la: %d", Tong);
}

int main()
{
	int a[] = {1, 3, 5, 7};
	int n = sizeof(a) / sizeof(a[0]);

	XuLyYeuCau(a, n);

	getch();
	return 0;
}