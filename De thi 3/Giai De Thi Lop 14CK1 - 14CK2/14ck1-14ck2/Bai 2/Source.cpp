#include <iostream>
using namespace std;

int demSoLuongChuSoLe_VongLap(int n)
{
	int dem = 0;
	while(n != 0)
	{
		int chuso = n % 10;
		n /= 10;
		if(chuso % 2 != 0)
		{
			dem++;
		}
	}
	return dem;
}

int demSoLuongChuSoLe(int n)
{
	// điều kiện dừng
	if(n == 0)
	{
		return 0;
	}

	// Bước đệ quy
	if((n % 10) % 2 != 0)
	{
		return 1 + demSoLuongChuSoLe(n / 10);
	}
	return demSoLuongChuSoLe(n / 10);
}

int DeQuyDuoi(int n, int dem = 0)
{
	if(n == 0)
	{
		return dem;
	}
	if((n % 10) % 2 != 0)
	{
		return DeQuyDuoi(n / 10, dem + 1);
	}
	return DeQuyDuoi(n / 10, dem);
}

int main()
{
	int n = 1234;
	int soluong = DeQuyDuoi(n); //demSoLuongChuSoLe(n); //demSoLuongChuSoLe_VongLap(n);
	cout << "\nSo luong chu so le = " << soluong;

	system("pause");
	return 0;
}