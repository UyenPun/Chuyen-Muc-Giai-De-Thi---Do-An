#include <stdio.h>
#include <conio.h>
#define MAX 100

struct DaGiac
{
	int N; // Số đỉnh => cũng là số cạnh
	float a[MAX]; // Mảng chứa độ dài các cạnh.
};
typedef struct DaGiac DAGIAC;

float TinhChuVi(DAGIAC x)
{
	float Tong = 0;

	for(int i = 0; i < x.N; i++) // Chạy hết tất cả các cạnh đang có.
	{
		Tong += x.a[i]; // Cộng dồn vào độ dài của từng cạnh.
	}
	return Tong; // Trả kết quả về.
}

int main()
{
	DAGIAC x;

	x.N = 3; // Có 3 đỉnh => có 3 cạnh.
	x.a[0] = 1.3; // Độ dài cạnh 1.
	x.a[1] = 2.1; // Độ dài cạnh 2.
	x.a[2] = 3.5; // Độ dài cạnh 3.

	float ChuVi = TinhChuVi(x);
	printf("\nChu vi da giac = %f", ChuVi);

	getch();
	return 0;
}