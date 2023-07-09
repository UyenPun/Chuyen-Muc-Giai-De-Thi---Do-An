#include <iostream>
using namespace std;

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		cin >> a[i];
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}

template <class sondeptrai>
void REALLOC(sondeptrai *&a, int NewSize, int OldSize)
{
	// Bước 1: Tạo mảng tạm có kích cỡ vừa đủ với mảng cũ
	sondeptrai *tam = new sondeptrai[OldSize];

	// Bước 2: Đổ dữ liệu từ mảng cũ sang mảng tạm
	for(int i = 0; i < OldSize; i++)
	{
		tam[i] = a[i];
	}

	// Bước 3: giải phóng mảng ban đầu & cấp lại mới
	delete[] a;
	a = new sondeptrai[NewSize];

	int Min = NewSize < OldSize ? NewSize : OldSize;

	// Bước 4: Đổ lại dữ liệu từ mảng tạm sang mảng a
	for(int i = 0; i < Min; i++)
	{
		a[i] = tam[i];
	}

	// Bước 5: Xóa mảng tạm
	delete[] tam;
}

// Xóa 1 phần tử tại 1 vị trí trong mảng
void XoaPhanTu(int *&a, int &n, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; // cập nhật lại số lượng.
	REALLOC<int>(a, n, n + 1); // realloc lại
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

	a = new int[n]; // cấp phát ra n phần tử

	NhapMang(a, n);
	XuatMang(a, n);

	cout << "\nXoa tat ca so le\n";
	XoaTatCaSoLe(a, n);
	XuatMang(a, n);

	/*cout << "\nXoa phan tu \n";
	XoaPhanTu(a, n, 2);
	XuatMang(a, n);*/

	//REALLOC(a, n - 1, n);

	
	//cout << "\nKet qua la: " << a[4];

	delete[] a; // giải phóng con trỏ

	system("pause");
	return 0;
}
