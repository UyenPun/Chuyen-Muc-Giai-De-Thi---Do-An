#include <stdio.h>
#include <conio.h>

int DemSoLuongChuSo(FILE *FileIn)
{
	int dem = 0;

	// Nếu chưa đến cuối file thì vòng lặp sẽ tiếp tục lặp
	while(!feof(FileIn))
	{
		char c = fgetc(FileIn);
		//printf("\nc = %c", c);

		if(c >= '0' && c <= '9')
		{
			dem++;
		}
	}
	return dem;
}

int main()
{
	// Bước 1: Mở tập tin để đọc
	FILE *FileIn; // Khai báo
	FileIn = fopen("INPUT.txt", "r");

	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.txt");
		getch();
		return 0;
	}

	int soluong = DemSoLuongChuSo(FileIn);

	printf("\nSo luong chu so la: %d", soluong);

	// đóng tập tin lại
	fclose(FileIn);

	getch();
	return 0;
}