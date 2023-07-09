/* 
Ta sẽ làm bài này theo dạng
xóa tất cả số lẻ có trong danh sách liên
kết đơn các số nguyên
*/
#include <iostream>
using namespace std;

/* 
quy trình thiết kế danh sách liên kết đơn
Bước 1: Khai báo cấu trúc dữ liệu
Bước 2: Khởi tạo danh sách liên kết đơn
Bước 3: Tạo Node trong danh sách liên kết đơn
Bước 4: Add Head/Add Tail
Bước 5: InPut
Bước 6: OutPut
Bước 7: Xử lý những yêu cầu
*/

/* Bước 1 */
struct Node
{
	int data;
	struct Node *pNext; // Con trỏ pNext tạo liên kết
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;
/* --------------------------------------------------- */

/* Bước 2 */
void INit(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

/* Bước 3 */
NODE *GetNode(int dulieu)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		cout << "\nMay tinh het bo nho nen khong khoi tao duoc";
		system("pause");
		return NULL;
	}
	p ->data = dulieu;
	p ->pNext = NULL;
	return p; // trả Node mới được tạo về
}

/* Bước 4 */
void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
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

/* Bước 5 */
void InPut(LIST &l)
{
	INit(l); // Khởi tạo danh sách.

	int n;
	cout << "\nNhap vao so luong data: ";
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int data;
		cout << "\nNhap vao data thu " << i << " la: ";
		cin >> data;

		NODE *p = GetNode(data);
		AddTail(l, p);
	}
}

// Bước 6
void OutPut(LIST l)
{
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		cout << p ->data << "   ";
	}
}

// giải phóng danh sách
void GiaiPhong(LIST &l)
{
	NODE *p; // Node phụ lưu trữ
	while(l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead ->pNext;
		delete p;
	}
}

void XoaDau(LIST &l)
{
	NODE *p = l.pHead;
	l.pHead = l.pHead ->pNext;
	delete p;
}

// Xóa Node nằm sau Node p
void XoaSauMotNode(LIST &l, NODE *p)
{
	for(NODE *u = l.pHead; u != NULL; u = u ->pNext)
	{
		if(u ->data == p ->data) // Xóa Node nằm sau u
		{
			NODE *g;
			g = u ->pNext;
			u ->pNext = g ->pNext;
			delete g;
			return;
		}
	}
}

void XoaTatCaSoLe(LIST &l)
{
	NODE *p = l.pHead; // Node trước Node sẽ xóa

	for(NODE *u = l.pHead ->pNext; u != NULL; u = u ->pNext)
	{
		if(u ->data % 2 != 0)
		{
			XoaSauMotNode(l, p);
			u = p; // lùi lại Node trước đó.
		}
		p = u; // gán p là Node trước u
	}
	if(l.pHead ->data % 2 != 0)
	{
		XoaDau(l);
	}
}

int main()
{
	LIST l;
	InPut(l);
	OutPut(l);

	//int data = 2;
	//NODE *p = GetNode(data);
	//cout << "\nXoa sau Mot Node\n";
	//XoaSauMotNode(l, p);
	//XoaDau(l);

	cout << "\nXoa tat ca so le\n";
	XoaTatCaSoLe(l);
	OutPut(l);

	GiaiPhong(l);

	system("pause");
	return 0;
}