#include <stdio.h> // Thư viện hỗ trợ xuất nhập chuẩn
#include <conio.h> // Thư viện hỗ trợ dừng màn hình

// Hàm nhập dữ liệu số nguyên n.
void NhapSoNguyen(int &n) // Lưu ý: Phải truyền tham chiếu vào.
{
	// lớn hơn 5 và nhỏ hơn 100 tức là [6, 99]
	// sai là khi nào ? => bé hơn hoặc bằng 5 hay lớn hơn hoặc bằng 100
	do{
		printf("\nNhap vao n (5 < n < 100): ");
		scanf("%d", &n); // &: Toán tử địa chỉ giúp xác định được địa chỉ của 1 biến trong bộ nhớ.
	
		if(n <= 5 || n >= 100)
		{
			printf("\nGia tri n khong hop le. Xin vui long kiem tra lai !");
		}
	}while(n <= 5 || n >= 100);
}

// Hàm xử lý tính toán.
int TinhS(int n) // Truyền tham trị.
{
	int Tong = 0;
	int Tich = 1;

	for(int i = 1; i <= n; i++)
	{
		Tich *= i; // Tích từ 1 tới i.
		Tong += Tich; // Cộng dồn các biến tích lại với nhau.
	}
	return Tong; // Trả về tổng.
}

// Hàm chính.
int main()
{
	int n;
	NhapSoNguyen(n);
	int S = TinhS(n);
	printf("\nS = %d", S);

	getch();
	return 0;
}