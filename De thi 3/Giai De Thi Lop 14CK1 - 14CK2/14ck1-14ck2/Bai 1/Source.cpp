#include <iostream>
using namespace std;

int demSoLuongTu(char * s)
{
	int length = strlen(s);
	int dem = 0;
	if(s[0] != ' ' && s[0] != '\0')
	{
		dem = 1;
	}

	for(int i = 0; i < length - 1; i++)
	{
		if(s[i] == ' ' && s[i + 1] != ' ')
		{
			dem++;
		}
	}
	return dem;
}

int main()
{
	char s[100];
	strcpy(s, "");
	int sotu = demSoLuongTu(s);
	cout << "\nSo tu = " << sotu;

	system("pause");
	return 0;
}