#pragma once // Tác dụng tránh bị đụng độ thư viện, tức là những thư viện bị trùng thì biên dịch 1 lần.
#include <stdio.h>
#include <conio.h>
#include <string.h>

// Khai báo.
void NhapThongTin1DocGia(char MaDocGia[], char HoTen[], char CMND[], int &NgaySinh, int &ThangSinh, int &NamSinh, int &GioiTinh, char Email[], char DiaChi[], int &NgayLapThe, int &ThangLapThe, int &NamLapThe, int &NgayHetHan, int &ThangHetHan, int &NamHetHan);
void XuatThongTin1DocGia(char MaDocGia[], char HoTen[], char CMND[], int NgaySinh, int ThangSinh, int NamSinh, int GioiTinh, char Email[], char DiaChi[], int NgayLapThe, int ThangLapThe, int NamLapThe, int NgayHetHan, int ThangHetHan, int NamHetHan);
