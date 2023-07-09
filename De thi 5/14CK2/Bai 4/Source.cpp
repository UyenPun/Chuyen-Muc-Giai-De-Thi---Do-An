/* 
Ý Tưởng:

B1: Tạo ra mảng 1 chiều chứa 10 phần tử khởi tạo mặc định là 0

B2: Xét duyệt mảng 2 chiều, tách ra từng chữ số của từng số bên trong ma
trận rồi tương ứng tại chỉ số đó bên mảng 1 chiều được ++ lên 1 đơn vị.

B3: Tìm Min trong mảng 1 chiều (Lưu ý: Chỉ xét các giá trị khác 0).

B4: Lấy Min tìm được xét lại từ đầu cho tới cuối của mảng 1 chiều, ở
vị trí nào có giá trị bằng với Min => chữ số (chỉ số) đó có số lần xuất hiện ít nhất.

*/

#include <stdio.h>
#include <conio.h>
#include <limits.h>
#define MAX 100

void TimCacChuSoXuatHienItNhat(int a[][3], int dong, int cot)
{
	// B1.
	int b[10] = {0};

	// B2.
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			int Temp = a[i][j]; // Tạo ra biến phụ rồi xử lý trên nó tránh làm thay đổi mảng.

			while(Temp != 0)
			{
				int ChuSo = Temp % 10; // Lấy ra chữ số ở cuối.
				Temp /= 10; // Loại bỏ chữ số vừa được lấy ra.

				b[ChuSo]++; // Tăng lên 1 đơn vị.
			}
		}
	}

	// B3
	int Min = INT_MAX; // Gán Min là phần tử đầu tiên của mảng.

	// Bắt đầu duyệt tiếp từ vị trí tiếp theo.
	for(int i = 0; i < 10; i++)
	{
		if(b[i] != 0 && b[i] < Min)
		{
			Min = b[i]; // Cập nhật lại Min.
		}
	}

	// B4.

	printf("\nCac chu so co so lan xuat hien it nhat la: ");

	// Duyệt lại mảng b.
	for(int i = 0; i < 10; i++)
	{
		if(b[i] == Min)
		{
			printf("%4d", i); // i tương ứng là chữ số xuất hiện ít nhất.
		}
	}
}

int main()
{
	int a[2][3] = {{126, 258, 374}, {45, 51, 60}};
	int dong = 2, cot = 3;

	TimCacChuSoXuatHienItNhat(a, dong, cot);

	/* 
	0: 1
	1: 2
	2: 2
	3: 1
	4: 2
	5: 3
	6: 2
	7: 1
	8: 1
	9: 0
	*/

	getch();
	return 0;
}