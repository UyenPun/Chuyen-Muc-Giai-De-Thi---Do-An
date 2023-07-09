/* 

Bài 1:
a. 
- Thực hiện việc tính tổng của S với các biến i chạy từ
1 và điều kiện là i < 2 * n, mỗi lần lặp lên 2 đơn vị (chạy
với các số i lẻ), mỗi lần thỏa thì cộng dồn kết quả:
i * (i + 1) / (i + 2)

b.

float S = 0;
int i = 1;

if(i < 2 * n)
{
	do{
		S += i * (i + 1) / (i + 2);
		i += 2;
	}while(i < 2 * n);
}

c.

<Khởi tạo>
while(<Điều kiện lặp>)
{
	<Xử lý>
	<Bước lặp>
}

<=>

I;
while(C)
{
	S;
	N;
}

*/

#include <stdio.h>

int main()
{
	return 0;
}