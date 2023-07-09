#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

// Xóa 1 phần tử tại 1 vị trí trong mảng
void XoaPhanTu(int *&a, int &n, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; // cập nhật lại số lượng.
	realloc(a, n * sizeof(int));
}
// 3 5 6 8
void XoaTatCaSoLe(int *&a, int &n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0)
		{
			XoaPhanTu(a, n, i);
			i--; // cập nhật lại chỉ số
		}
	}
}

int main()
{
	int n = 5;

	// cấp phát bộ nhớ cho con trỏ mảng
	int *a; // khai báo con trỏ

	a = (int *)realloc(0, n * sizeof(int)); // cấp phát ra n phần tử

	NhapMang(a, n);
	XuatMang(a, n);

	printf("\nXoa tat ca so le la\n");
	XoaTatCaSoLe(a, n);
	XuatMang(a, n);

	free(a); // giải phóng con trỏ

	system("pause");
	return 0;
}