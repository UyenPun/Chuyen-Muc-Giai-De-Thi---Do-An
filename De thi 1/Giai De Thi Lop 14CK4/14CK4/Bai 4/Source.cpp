#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream FileIn;
	FileIn.open("Mang_1chieu.txt", ios_base::in);

	// kiểm tra XEM FILE CÓ TỒN TẠI HAY KHÔNG ?
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin Mang_1chieu.txt";
		system("pause");
		return 0;
	}

	int n;
	FileIn >> n;
	
	int *a = new int[n];

	int tong = 0;
	for(int i = 0; i < n; i++)
	{
		FileIn >> a[i];
		tong += a[i];
	}

	FileIn.close();

	ofstream FileOut;
	FileOut.open("Tong_mang.txt", ios_base::out);

	FileOut << tong;

	FileOut.close();

	delete[] a;

	system("pause");
	return 0;
}