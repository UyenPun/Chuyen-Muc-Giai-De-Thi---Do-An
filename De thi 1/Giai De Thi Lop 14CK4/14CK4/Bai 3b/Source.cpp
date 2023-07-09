#include <iostream>
using namespace std;

void InSertionSort(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int x = a[i]; // đang xét x hiện tại
		int j;
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > x)
			{
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j + 1] = x;
	}
}

/* 

void InsertionSort(LIST &l)
{
	for(NODE *p = l.pHead ->pNext; p != NULL; p = p ->pNext)
	{
		int x = p ->data;
		NODE *q;
		for(q = p -> pRev; q != NULL; q = q ->pRev)
		{
			if(q ->data > x)
			{
				q ->pNext ->data = q ->data;
			}
			else
			{
				break;
			}
		}
		if(q != NULL)
		{
			q ->pNext ->data = x;
		}
		else
		{
			l.pHead -> data = x;
		}
		
	}
}

*/

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}

int main()
{
	int a[] = {5, -10, 20, 4, 69};
	int n = sizeof(a) / sizeof(a[0]);

	InSertionSort(a, n);
	XuatMang(a, n);


	system("pause");
	return 0;
}