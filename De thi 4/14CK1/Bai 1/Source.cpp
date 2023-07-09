/* 

Những tháng 31 ngày: 1, 3, 5, 7, 8, 10, 12
Những tháng 30 ngày: 4, 6, 9, 11

Riêng tháng 2 có 28 hoặc 29 ngày tùy thuộc vào năm
nhuận hay không nhuận
+ Năm nhuận: Có 29 ngày
+ Năm không nhuận: Có 28 ngày

Năm nhuận là năm thỏa 1 trong 2 điều sau:
1/ Chia hết cho 4 và không chia hết cho 100
2/ Chia hết cho 400

vd: Năm 2000 là năm nhuận (thỏa điều kiện 2)
Năm 2016 là năm nhuận (thỏa điều kiện 1)

*/

// Khai báo các thư viện.
#include <stdio.h>
#include <conio.h>

int tinhSoNgayTrongThang(int th, int nm);

// Hàm tính số ngày có trong tháng của năm đó.
int tinhSoNgayTrongThang(int th, int nm)
{
	if(th == 1 || th == 3 || th == 5 || th == 7 || th == 8 || th == 10 || th == 12)
	{
		return 31; // Có 31 ngày.
	}
	else if(th == 2) // Có thể có 28 hoặc 29 ngày.
	{
		if((nm % 4 == 0 && nm % 100 != 0) || nm % 400 == 0) // Năm nhuận.
		{
			return 29;
		}
		else // Không phải năm nhuận.
		{
			return 28;
		}
	}
	return 30;
}

int main()
{
	int th = 2, nm = 2016;

	int day = tinhSoNgayTrongThang(th, nm);
	printf("\nThang %d cua nam %d co %d ngay", th, nm, day);

	getch();
	return 0;
}