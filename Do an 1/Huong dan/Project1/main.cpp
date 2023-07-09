#include "DanhSachDocGia.h"
#define MAX 100

int main()
{
	int SoLuongDocGia;

	do{
		printf("\nNhap vao so luong doc gia: ");
		scanf("%d", &SoLuongDocGia);

		if(SoLuongDocGia < 0)
		{
			printf("\nSo luong doc gia khong hop le. Xin kiem tra lai !");
		}
	}while(SoLuongDocGia < 0);
	
	char MaDocGia[MAX][10], HoTen[MAX][30], CMND[MAX][15], Email[MAX][20], DiaChi[MAX][30];
	int NgaySinh[MAX], ThangSinh[MAX], NamSinh[MAX], GioiTinh[MAX], NgayLapThe[MAX], ThangLapThe[MAX], NamLapThe[MAX], NgayHetHan[MAX], ThangHetHan[MAX], NamHetHan[MAX];

	NhapDanhSachDocGia(MaDocGia, HoTen, CMND, NgaySinh, ThangSinh, NamSinh, GioiTinh, Email, DiaChi, NgayLapThe, ThangLapThe, NamLapThe, NgayHetHan, ThangHetHan, NamHetHan, SoLuongDocGia);
	XuatDanhSachDocGia(MaDocGia, HoTen, CMND, NgaySinh, ThangSinh, NamSinh, GioiTinh, Email, DiaChi, NgayLapThe, ThangLapThe, NamLapThe, NgayHetHan, ThangHetHan, NamHetHan, SoLuongDocGia);

	getch(); // Dừng màn hình.
	return 0;
}