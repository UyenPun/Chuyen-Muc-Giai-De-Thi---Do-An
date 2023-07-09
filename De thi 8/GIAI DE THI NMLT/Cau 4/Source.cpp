#include <stdio.h>
#include <conio.h>
#define MAX 100

// Khai báo kiểu dữ liệu cấu trúc thông tin của 1 sinh viên.
// Câu a.
struct SinhVien
{
	char MaSo[10];
	char HoTen[30];
	int NamSinh;
	float DiemTrungBinh;
};
typedef struct SinhVien SINHVIEN;

// Câu b.
float TimDiemTrungBinhLonNhat(SINHVIEN sv[], int n)
{
	float DtbMax = sv[0].DiemTrungBinh; // Đặt Max là điểm trung bình của sinh viên đầu tiên trong danh sách.

	// Duyệt tiếp từ phần tử thứ 2 trong danh sách trở đi.
	for(int i = 1; i < n; i++)
	{
		if(sv[i].DiemTrungBinh > DtbMax)
		{
			DtbMax = sv[i].DiemTrungBinh;
		}
	}
	return DtbMax;
}

/* ================== Câu c ==================== */
void XuatThongTin1SinhVien(SINHVIEN sv)
{
	printf("\nMa so: %s", sv.MaSo);
	printf("\nHo ten: %s", sv.HoTen);
	printf("\nNam sinh: %d", sv.NamSinh);
	printf("\nDiem trung binh: %f", sv.DiemTrungBinh);
}

// Xuất danh sách các sinh viên có điểm trung bình < 5.0
void XuatDanhSachSinhVienThoaYeuCau(SINHVIEN sv[], int n)
{
	// Duyệt danh sách sinh viên.
	for(int i = 0; i < n; i++)
	{
		if(sv[i].DiemTrungBinh < 5)
		{
			XuatThongTin1SinhVien(sv[i]);
		}
	}
}
/* ======================================================= */

/* =============== Từ chỗ này trở xuống viết thêm để test ============== */
void NhapThongTin1SinhVien(SINHVIEN &sv)
{
	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nNhap vao ma so: ");
	gets(sv.MaSo);

	fflush(stdin);
	printf("\nNhap vao ho ten: ");
	gets(sv.HoTen);

	printf("\nNhap vao nam sinh: ");
	scanf("%d", &sv.NamSinh);

	printf("\nNhap vao diem trung binh: ");
	scanf("%f", &sv.DiemTrungBinh);
}

void NhapDanhSachSinhVien(SINHVIEN sv[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\n\n\t\t* Nhap Thong Tin Sinh Vien Thu %d *\n", i + 1);
		NhapThongTin1SinhVien(sv[i]);
	}
}

// Hàm chính.
int main()
{
	int n = 3; 
	SINHVIEN sv[MAX];

	NhapDanhSachSinhVien(sv, n);
	
	float DtbMax = TimDiemTrungBinhLonNhat(sv, n);
	printf("\nDiem trung binh lon nhat trong danh sach la: %f", DtbMax);
	printf("\nDanh sach cac sinh vien co diem trung binh < 5.0 la: \n");
	XuatDanhSachSinhVienThoaYeuCau(sv, n);

	getch();
	return 0;
}