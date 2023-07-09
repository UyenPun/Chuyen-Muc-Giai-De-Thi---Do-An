#include "DanhSachDocGia.h"

void NhapDanhSachDocGia(char MaDocGia[][10], char HoTen[][30], char CMND[][15], int NgaySinh[], int ThangSinh[], int NamSinh[], int GioiTinh[], char Email[][20], char DiaChi[][30], int NgayLapThe[], int ThangLapThe[], int NamLapThe[], int NgayHetHan[], int ThangHetHan[], int NamHetHan[], int SoLuongDocGia)
{
	for(int i = 0; i < SoLuongDocGia; i++)
	{
		printf("\n------------------- Nhap Thong Tin Doc Gia Thu %d -------------------\n", i + 1);
		NhapThongTin1DocGia(MaDocGia[i], HoTen[i], CMND[i], NgaySinh[i], ThangSinh[i], NamSinh[i], GioiTinh[i], Email[i], DiaChi[i], NgayLapThe[i], ThangLapThe[i], NamLapThe[i], NgayHetHan[i], ThangHetHan[i], NamHetHan[i]);		
	}
}

void XuatDanhSachDocGia(char MaDocGia[][10], char HoTen[][30], char CMND[][15], int NgaySinh[], int ThangSinh[], int NamSinh[], int GioiTinh[], char Email[][20], char DiaChi[][30], int NgayLapThe[], int ThangLapThe[], int NamLapThe[], int NgayHetHan[], int ThangHetHan[], int NamHetHan[], int SoLuongDocGia)
{
	for(int i = 0; i < SoLuongDocGia; i++)
	{
		printf("\n------------------- Xuat Thong Tin Doc Gia Thu %d -------------------\n", i + 1);
		XuatThongTin1DocGia(MaDocGia[i], HoTen[i], CMND[i], NgaySinh[i], ThangSinh[i], NamSinh[i], GioiTinh[i], Email[i], DiaChi[i], NgayLapThe[i], ThangLapThe[i], NamLapThe[i], NgayHetHan[i], ThangHetHan[i], NamHetHan[i]);		
	}
}



