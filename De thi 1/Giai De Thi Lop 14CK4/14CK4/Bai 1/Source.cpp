/* 
7 Bước để cấu hình danh sách liên kết đơn

Bước 1: Khai báo cấu trúc dữ liệu danh sách
Bước 2: Khởi tạo danh sách
Bước 3: Tạo Node
Bước 4: Viết hàm thêm đầu/thêm cuối danh sách
Bước 5: Viết hàm InPut
Bước 6: Viết hàm OutPut
Bước 7: Giải phóng bộ nhớ & xử lý ...
*/
#include <iostream>
using namespace std;

/* Bước 1: */
struct Node
{
	int data;
	struct Node *pNext; // giữ mối liên kết giữa Node này với Node kia
};
typedef struct Node NODE;

struct List
{
	NODE *pHead, *pTail;
};
typedef struct List LIST;
/* ---------------------------------------------- */

/* Bước 2 */
void INit(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

/* Bước 3 */
NODE *GetNode(int x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		cout << "\nKhong con bo nho de cap phat !";
		system("pause");
		return NULL;
	}
	p ->data = x;
	p ->pNext = NULL;
	return p;
}

/* Bước 4 */

void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		//cout << "Roi vao day ne";
		l.pHead = l.pTail = p;
	}
	else
	{
		p ->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail ->pNext = p;
		l.pTail = p;
	}
}

/* Bước 6 */
void InPut(LIST &l)
{
	INit(l); // Khởi tạo

	int n;
	cout << "\nNhap vao so luong can nhap: ";
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int data;
		cout << "\nNhap vao data thu " << i << " : ";
		cin >> data;

		NODE *p = GetNode(data);
		AddTail(l, p);
	}
}

/* Bước 7 */
void OutPut(LIST l)
{
	// for(int i = 0; i < n; i++)
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		cout << p ->data << "   ";
	}
}

/* Bước 8 */
void GiaiPhong(LIST &l)
{
	NODE *p;
	while(l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead ->pNext;
		delete p;
	}
}

void XoaCuoi(LIST &l)
{
	// nếu chỉ có 1 phần tử trong danh sách
	if(l.pHead ->pNext == NULL)
	{
		GiaiPhong(l);
	}
	else
	{
		NODE *p; // Node nằm trước đó
		for(NODE *u = l.pHead; u != NULL; u = u ->pNext)
		{
			if(u == l.pTail)
			{
				l.pTail = p;
				l.pTail ->pNext = NULL;
				delete u;
				return; // kết thúc luôn
			}
			if(u != NULL)
			{
				p = u;
			}
		}
	}
}

int main()
{
	LIST l;
	InPut(l);
	
	OutPut(l);

	int data_cuoi = l.pTail ->data;
	NODE *cuoi = GetNode(data_cuoi);

	XoaCuoi(l);

	AddHead(l, cuoi);

	cout << "\nDanh sach sau khi chuyen cuoi ve dau la\n";
	OutPut(l);

	GiaiPhong(l);

	system("pause");
	return 0;
}