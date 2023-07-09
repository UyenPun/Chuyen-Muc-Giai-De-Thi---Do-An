/* 
vd: ta có số n = 30
30 : 2 = 15 dư 0
15 : 2 = 7 dư 1
7 : 2 = 3 dư 1
3 : 2 = 1 dư 1
1 : 2 = 0 dư 1

=> 30 => 11110

Điều kiện dừng: Khi n = 0
Bước đệ quy: Liên tục chia nguyên cho 2
DQ(30) --> DQ(15) --> DQ(7) --> DQ(3) --> DQ(1) --> DQ(0) --> END

*/

#include <iostream>
using namespace std;

void XuatHe2(long n)
{
	// Điều kiện dừng
	if(n == 0)
	{
		return;
	}
	XuatHe2(n / 2); // Bước đệ quy
	cout << n % 2;
}

int main()
{
	XuatHe2(30);

	system("pause");
	return 0;
}