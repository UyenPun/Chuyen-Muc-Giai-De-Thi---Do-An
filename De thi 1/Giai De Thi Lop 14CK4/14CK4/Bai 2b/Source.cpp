/* 
năm 1 vay 100 triệu

học 4 năm
sau đó đi làm 5 năm
vậy có nghĩa là sau 9 năm nó sẽ trả cả lãi lẫn gốc

V(0) = 100 triệu
V(1) = 102% của 100 triệu
V(2) = 102% của V(1)
V(3) = 102% của V(2)
...
V(9) = 102% của V(8)

V(n) = 102% của V(n - 1)
*/

#include <iostream>
using namespace std;

double TinhTienPhaiTra_DeQuyDuoi(double sotienvay, int sonamvay, int laisuat)
{
	if(sonamvay == 0)
	{
		return sotienvay;
	}
	return TinhTienPhaiTra_DeQuyDuoi(sotienvay * (1 + laisuat / 100.0), sonamvay - 1, laisuat);
}

double TinhTienPhaiTra_DeQuyThuong(double sotienvay, int sonamvay, int laisuat)
{
	if(sonamvay == 0)
	{
		return sotienvay;
	}
	return  (1 + (laisuat / 100.0)) * TinhTienPhaiTra_DeQuyThuong(sotienvay, sonamvay - 1, laisuat);
}

int main()
{
	int sotienvay = 100;
	int sonamvay = 9;
	int laisuat = 2;

	double sotienphaitra = TinhTienPhaiTra_DeQuyDuoi(sotienvay, sonamvay, laisuat);
	cout << "\nSo tien phai tra la: " << sotienphaitra;

	double sotien = TinhTienPhaiTra_DeQuyThuong(sotienvay, sonamvay, laisuat);
	cout << "\nso tien = " << sotien;

	system("pause");
	return 0;
}