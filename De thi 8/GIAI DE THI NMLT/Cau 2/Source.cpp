#include <stdio.h>
#include <conio.h>
#include <string.h> // Thư viện hỗ trợ chuỗi C

// Hàm kiểm tra tính đối xứng của chuỗi.
// Chỉ cần ghi hàm này là được rồi.
int KiemTraDoiXung(char *str)
{
	int DoDai = strlen(str); // Lấy độ dài của chuỗi str.

	for(int i = 0; i < DoDai / 2; i++)
	{
		if(str[i] != str[DoDai - 1 - i])
		{
			return 0; // Không đối xứng.
		}
	}
	return 1; // Chuỗi đối xứng.
}

int main()
{
	char str[30];
	strcpy(str, "abcdcba");

	int KiemTra = KiemTraDoiXung(str);
	if(KiemTra == 1)
	{
		printf("\nChuoi doi xung !");
	}
	else
	{
		printf("\nChuoi khong doi xung !");
	}

	getch();
	return 0;
}

