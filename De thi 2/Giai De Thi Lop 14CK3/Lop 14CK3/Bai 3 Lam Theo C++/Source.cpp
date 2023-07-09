#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int DemSoLuongChuSo(ifstream &FileIn)
{
	int dem = 0;

	// Nếu chưa đến cuối file thì vòng lặp sẽ tiếp tục lặp
	while(!FileIn.eof())
	{
		string str;
		getline(FileIn, str);
		int length = str.length();

		for(int i = 0; i < length; i++)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				dem++;
			}
		}
	}
	return dem;
}

int main()
{
	// Bước 1: Mở tập tin để đọc
	ifstream FileIn; // Khai báo
	FileIn.open("INPUT.txt", ios_base::in);

	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.txt";
		system("pause");
		return 0;
	}

	int soluong = DemSoLuongChuSo(FileIn);

	cout << "\nSo chu so co trong tap tin van ban la: " << soluong;

	// đóng tập tin lại
	FileIn.close();

	system("pause");
	return 0;
}