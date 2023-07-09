#include "DocGia.h"

// Định nghĩa.
void NhapThongTin1DocGia(char MaDocGia[], char HoTen[], char CMND[], int &NgaySinh, int &ThangSinh, int &NamSinh, int &GioiTinh, char Email[], char DiaChi[], int &NgayLapThe, int &ThangLapThe, int &NamLapThe, int &NgayHetHan, int &ThangHetHan, int &NamHetHan) // &: Tham chiếu giúp đồng nhất 2 địa chỉ với nhau.
{
	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao ma doc gia: ");
	gets(MaDocGia);

	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao ho ten: ");
	gets(HoTen);

	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao chung minh nhan dan: ");
	gets(CMND);

	printf("\n---------------- Nhap Thong Tin Ngay Sinh ----------------\n");

	printf("\nNhap vao ngay: ");
	scanf("%d", &NgaySinh); // &: Toán tử địa chỉ.

	printf("\nNhap vao thang: ");
	scanf("%d", &ThangSinh);

	printf("\nNhap vao nam: ");
	scanf("%d", &NamSinh);

	printf("\n----------------------------------------------------------\n");

	do{
		printf("\nGioi tinh (0: Nu, 1: Nam): ");
		scanf("%d", &GioiTinh);

		if(GioiTinh != 0 && GioiTinh != 1)
		{
			printf("\nGioi tinh khong hop le. Xin kiem tra lai !");
		}
	}while(GioiTinh != 0 && GioiTinh != 1);

	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao Email: ");
	gets(Email);

	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao dia chi: ");
	gets(DiaChi);

	
	printf("\n---------------- Nhap Thong Tin Ngay Lap The ----------------\n");

	printf("\nNhap vao ngay: ");
	scanf("%d", &NgayLapThe); // &: Toán tử địa chỉ.

	printf("\nNhap vao thang: ");
	scanf("%d", &ThangLapThe);

	printf("\nNhap vao nam: ");
	scanf("%d", &NamLapThe);

	printf("\n----------------------------------------------------------\n");

	// Thời hạn: 48 tháng.
	NgayHetHan = NgayLapThe;
	ThangHetHan = ThangLapThe;
	NamHetHan = NamLapThe + 4; 
}

void XuatThongTin1DocGia(char MaDocGia[], char HoTen[], char CMND[], int NgaySinh, int ThangSinh, int NamSinh, int GioiTinh, char Email[], char DiaChi[], int NgayLapThe, int ThangLapThe, int NamLapThe, int NgayHetHan, int ThangHetHan, int NamHetHan)
{
	printf("\nMa doc gia: %s", MaDocGia);
	printf("\nHo ten: %s", HoTen);
	printf("\nCMND: %s", CMND);
	printf("\nSinh ngay %d thang %d nam %d", NgaySinh, ThangSinh, NamSinh);
	if(GioiTinh == 0)
	{
		printf("\nGioi tinh: Nu");
	}
	else
	{
		printf("\nGioi tinh: Nam");
	}

	printf("\nEmail: %s", Email);
	printf("\nDia chi: %s", DiaChi);
	printf("\nLap the ngay %d thang %d nam %d", NgayLapThe, ThangLapThe, NamLapThe);
	printf("\nThe het han vao ngay %d thang %d nam %d", NgayHetHan, ThangHetHan, NamHetHan);
}
