/* 
B1: Khai báo cấu trúc dữ liệu của danh sách
B2: Khởi tạo danh sách
B3: Tạo Node trong danh sách
B4: Thêm đầu/thêm cuối trong danh sách
B5: Viết hàm InPut
B6: Viết Hàm OutPut
B7: Giải phóng danh sách liên kết
*/

#include <iostream>
#include <string>
using namespace std;

/* 
Bước 1:
-------------------------------------------------
*/

struct KhachHang
{
	string MaSo, HoTen, DiaChi, SoDT, Email;
};
typedef struct KhachHang KHACHHANG;

struct Node
{
	KHACHHANG Data; // data đang chứa KHACHHANG
	struct Node *pNext; // con trỏ pNext tạo mối liên kết giữa các Node
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;
/* --------------------------------------------------------- */

// B2: Khởi tạo danh sách
void INit(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node
NODE *GetNode(KHACHHANG data)
{
	NODE *p = new NODE;

	// nếu hết bộ nhớ trong máy tính => không tạo ra được Node
	if(p == NULL)
	{
		return NULL;
	}
	p ->Data = data;
	p ->pNext = NULL; // tạo mối liên kết giữa Node này vs Node kia
	return p;
}

// Bước 4: Thêm Node p vào đầu danh sách
void AddHead(LIST &l, NODE *p)
{
	// Nếu danh sách rỗng
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else // danh sách đã có phần tử
	{
		p ->pNext = l.pHead; // tạo mối liên kết mới
		l.pHead = p; // cập nhật lại pHead
	}
}

void AddTail(LIST &l, NODE *p)
{
	// Nếu danh sách rỗng
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else // nếu danh sách đã có
	{
		l.pTail ->pNext = p; // tạo mối liên kết mới
		l.pTail = p; // cập nhật lại pTail
	}
}

void NhapKhachHang(KHACHHANG &kh)
{
	do{
		fflush(stdin); // Xóa bộ nhớ đệm
		cout << "\nNhap vao ma so: ";
		getline(cin, kh.MaSo);

		if(kh.MaSo.length() > 14)
		{
			cout << "\nMa so khong hop le. Xin kiem tra lai !";
		}
	}while(kh.MaSo.length() > 14);

	fflush(stdin); // Xóa bộ nhớ đệm
	cout << "\nNhap vao ho ten: ";
	getline(cin, kh.HoTen);

	fflush(stdin); // Xóa bộ nhớ đệm
	cout << "\nNhap vao dia chi: ";
	getline(cin, kh.DiaChi);

	fflush(stdin); // Xóa bộ nhớ đệm
	cout << "\nNhap vao so dien thoai: ";
	getline(cin, kh.SoDT);

	fflush(stdin); // Xóa bộ nhớ đệm
	cout << "\nNhap vao mail: ";
	getline(cin, kh.Email);
}

void XuatKhachHang(KHACHHANG kh)
{
	cout << "\nMa so: " << kh.MaSo;
	cout << "\nHo ten: " << kh.HoTen;
	cout << "\nDia chi: " << kh.DiaChi;
	cout << "\nSo dien thoai: " << kh.SoDT;
	cout << "\nEmail: " << kh.Email;
}

// Bước 5: Viết hàm InPut
void InPut(LIST &l)
{
	INit(l); // Khởi tạo danh sách ra.

	int n;
	cout << "\nBan muon nhap bao nhieu: ";
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		KHACHHANG data;
		NhapKhachHang(data);

		NODE *p = GetNode(data); // đóng data vào trong 1 cái Node
		//AddHead(l, p); // Thêm vào đầu
		AddTail(l, p); // thêm cuối
	}
}

// Bước 6: OutPut
void OutPut(LIST l)
{
	int dem = 1;
	// for(int i = 0; i < n; i++)
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		cout << "\n------- Thong Tin Khach Hang Thu " << dem++ << " ---------\n";
		XuatKhachHang(p ->Data);
	}
}

// Bước 7:
void GiaiPhongBoNho(LIST &l)
{
	NODE *p; // Node phụ sẽ tham gia
	
	// lặp liên tục cho đến khi danh sách rỗng thì thôi
	while(l.pHead != NULL)
	{
		p = l.pHead; // cho p trỏ tới pHead
		l.pHead = l.pHead ->pNext; // cập nhật lại pHead là Node kế tiếp
		delete p; // giải phóng p
	}
}

int main()
{
	LIST l;
	InPut(l);
	OutPut(l);

	GiaiPhongBoNho(l);
	//cout << "\nTail = \n";
	//XuatKhachHang(l.pTail ->Data);

	system("pause");
	return 0;
}