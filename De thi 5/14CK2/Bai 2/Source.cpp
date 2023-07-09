/* 

Ý Tưởng:
Ta sẽ xét 1 phần tử tại 1 vị trí cụ thể trong mảng, rồi lấy
phần tử đó đi lần ngược về trước, nếu có bị trùng với bất kỳ 1
phần tử nào thì kết luận là phần tử đó đã bị trùng và không cần
xuất ra.

vd: 2 2 1 5 4 5 8 9

=> kết quả xuất: 2 1 5 4 8 9

*/

#include <stdio.h>
#include <conio.h>

void XuatCacGiaTriPhanBiet(int a[], int n);
void HoanVi(int &a, int &b);
void SapXepTang(int a[], int n);

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void SapXepTang(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}

void XuatCacGiaTriPhanBiet(int a[], int n)
{
	SapXepTang(a, n); // Sắp xếp mảng tăng dần.

	for(int i = 0; i < n; i++) // Duyệt hết mảng.
	{
		bool Check = true; // Đặt cờ hiệu mặc định thỏa.

		// Xét các số đứng trước nó xem nó có bị trùng hay không ?
		for(int j = i - 1; j >= 0; j--)
		{
			if(a[i] == a[j]) // Bị trùng.
			{
				Check = false; // Cập nhật lại cờ hiệu.
				break; // Thoát ra khỏi vòng lặp không cần phải duyệt tiếp về sau.
			}
		}

		// Xét biến cờ hiệu.
		if(Check == true)
		{
			printf("%4d", a[i]); // a[i] là phần tử phân biệt.
		}
	}
}

int main()
{
	int a[] = {2, 2, 1, 5, 4, 5, 8, 9};
	int n = sizeof(a) / sizeof(a[0]);

	XuatCacGiaTriPhanBiet(a, n);

	getch();
	return 0;
}