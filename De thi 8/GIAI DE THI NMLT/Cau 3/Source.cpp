#include <stdio.h>
#include <conio.h>
#define MAX 100

// Hàm nhập mảng các số nguyên.
// Câu a.
void NhapMang(int a[], int &n)
{
	do{
		printf("\nNhap vao n (5 < n < 100): ");
		scanf("%d", &n);

		if(n <= 5 || n >= 100)
		{
			printf("\nGia tri n khong hop le. Xin kiem tra lai !");
		}
	}while(n <= 5 || n >= 100); // Điều kiện sai - bị lặp lại.

	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

// Hàm xóa 1 phần tử tại 1 vị trí trong mảng.
// Câu b.
int XoaPhanTu(int a[], int &n, int ViTriXoa)
{
	if(ViTriXoa < 0 || ViTriXoa >= n)
	{
		return 0; // Không xóa.
	}
	for(int i = ViTriXoa; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--; // Giảm đi 1 đơn vị.
	return 1; // Xóa thành công.
}

// Câu d.
void XoaTatCaPhanTuAm(int a[], int &n)
{
	// Vòng lặp duyệt hết mảng.
	for(int i = 0; i < n; i++)
	{
		if(a[i] < 0) // âm
		{
			XoaPhanTu(a, n, i);
			i--; // Cập nhật lại vị trí cho các phần tử sau mỗi lần xóa.
		}
	}
}

// Hàm tìm kiếm 1 phần tử trong mảng.
// Câu c.
int TimKiemPhanTu(int a[], int n, int x)
{
	// Duyệt hết mảng.
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			return i; // Trả về vị trí đầu tiên tìm thấy.
		}
	}
	return -1; // Không tìm thấy.
}

// Hàm chính.
int main()
{
	int a[MAX], n; // Khai báo các biến.

	NhapMang(a, n);
	XuatMang(a, n);

	// Nhập k.
	//int k = 6; // Xóa tại vị trí 2.
	//int Kq = XoaPhanTu(a, n, k);
	//if(Kq == 1)
	//{
	//	printf("\nXoa thanh cong");
	//	printf("\nMang sau khi xoa la: ");
	//	XuatMang(a, n);
	//}
	//else
	//{
	//	printf("\nKhong xoa duoc !");
	//}

	/*XoaTatCaPhanTuAm(a, n);
	printf("\nMang sau khi xoa tat ca phan tu am la: ");
	XuatMang(a, n);*/

	int x = 5;
	int vt = TimKiemPhanTu(a, n, x);
	if(vt == -1)
	{
		printf("\nKhong tim thay phan tu x");
	}
	else
	{
		printf("\nPhan tu x tim thay dau tien tai vi tri: %d", vt);
	}

	getch();
	return 0;
}