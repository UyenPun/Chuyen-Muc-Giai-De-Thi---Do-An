#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

void NhapMang(int a[], int n);
int DemSoLuongChuSo(int n);
int TimSoCoNhieuChuSoNhat(int a[], int n);

// Nhập vào dãy số.
void NhapMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao so thu %d: ", i + 1);
		scanf("%d", &a[0]);
	}
}

// Hàm đếm số lượng chữ số của 1 số nguyên.
int DemSoLuongChuSo(int n)
{
	/* Cách 1 */
	//int dem = 0;

	//while(n != 0)
	//{
	//	n /= 10; // Loại bỏ đi chữ số ở cuối.
	//	dem++; // Tăng biến đếm lên.
	//}
	//return dem; // Trả về kết quả.

	// log cơ số 10 của 100 = 2
	// log cơ số 10 của 999 = 2.9999999

	// Cách 2.
	return n == 0 ? 1 : log10((double)abs(n)) + 1;
}

int TimSoCoNhieuChuSoNhat(int a[], int n)
{
	int idx = 0; // idx: Vị trí của số có nhiều chữ số nhất.
	int Max = DemSoLuongChuSo(a[0]); // Max: Tìm số lượng chữ số lớn nhất.
	
	// Duyệt từ phần tử tiếp theo.
	for(int i = 1; i < n; i++)
	{
		int SoLuong = DemSoLuongChuSo(a[i]);
		if(SoLuong > Max)
		{
			Max = SoLuong; // Cập nhật lại Max.
			idx = i; // Cập nhật lại idx.
		}
	}
	return a[idx]; // Trả về phần tử tại vị trí idx => có nhiều chữ số nhất.
}

int main()
{
	int a[] = {2, 234, 56, 8910, 1, 56, 7};
	int n = sizeof(a) / sizeof(a[0]);

	int Max = TimSoCoNhieuChuSoNhat(a, n);
	printf("\nSo co nhieu chu so nhat la: %d", Max);
	
	getch();
	return 0;
}