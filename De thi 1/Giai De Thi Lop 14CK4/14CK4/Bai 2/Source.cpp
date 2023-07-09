/* 

TÌM KIẾM

có 3 loại thuật toán tìm kiếm

Có 2 loại:

- Tìm kiếm tuần tự (tuyến tính)
	+ Vét cạn
		=> xét tuần tự từ đầu tới cuối, gặp thì xuất ra rồi dừng lại, còn không thì chạy tới cuối cùng
	 1 2 3 4 5 6 7 8
	 x = 4
	 x = 10
	
	+ Lính canh
	1 2 3 4 5 x
	x = 6
- Tìm kiếm nhị phân
	Yêu cầu: Dãy số phải có 1 thứ tự nhất định
	tức là phải tăng dần hay giảm dần

	
	left = 0
	right = n - 1
	vòng lặp sẽ lặp trong khi left <= right
	mid = (left + right) / 2
	so sánh: x > a[mid] => left = mid + 1
	x < a[mid] => right = mid - 1
	x == a[mid] => trả về vị trí đã tìm thấy

	Nếu left > right => ko tìm thấy

	1 2 3 4 5 6 7 8 9 10

	x = 0

	lần 1:
	left = 0
	right = 9

	left <= right => mid = 4 => a[mid] = 5
	ta thấy x > a[mid] => left = mid + 1 = 5

	lần 2:
	left = 5
	right = 9

	left <= right => mid = 7 => a[mid] = 8
	ta thấy x == a[mid] => tồn tại tại vị trí mid


*/

#include <iostream>
using namespace std;

// tìm số x có trong mảng hay không
int TimKiemTuanTuVetCan(double a[], int n, double x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			return i; // vị trí tìm đc
		}
	}
	return -1; // không tìm thấy
}

int TimKiemTuanTuLinhCanh(double a[], int n, int x)
{
	a[n] = x; // đưa x vào đứng cuối mảng
	for(int i = 0; ; i++)
	{
		if(a[i] == x)
		{
			return i;
		}
	}
}

int TimKiemNhiPhan(double a[], int n, int x)
{
	int left = 0, right = n - 1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(x > a[mid])
		{
			left = mid + 1;
		}
		else if(x < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1; // không tìm thấy
}

int TimKiemNhiPhan_DeQuy(double a[], int n, int x, int left, int right)
{
	// dừng lại
	if(left > right)
	{
		return -1;
	}
	int mid = (left + right) / 2;
	if(x > a[mid])
	{
		return TimKiemNhiPhan_DeQuy(a, n, x, mid + 1, right);
	}
	else if(x < a[mid])
	{
		return TimKiemNhiPhan_DeQuy(a, n, x, left, mid - 1);
	}
	else
	{
		return mid;
	}
}

int main()
{
	double a[6] = {1, 2, 3, 4, 5};
	int n = 5;

	int x = 20;
	int vitri = TimKiemNhiPhan_DeQuy(a, n, x, 0, n - 1);
	if(vitri == -1)
	{
		cout << "\nKhong ton tai";
	}
	else
	{
		cout << "\nCo ton tai tai vi tri " << vitri;
	}

	system("pause");
	return 0;
}


