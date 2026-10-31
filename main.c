#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    int maThuoc;
    char tenThuoc[50];
    int soLuong;
    float donGia;
} Thuoc;

int main() {
    Thuoc dsThuoc[MAX_SIZE];
    int soLuongThuoc = 0;
    int choice;

    do {
        printf("\n===== QUAN LY THUOC =====\n");
        printf("1. Them thuoc\n");
        printf("2. Hien thi danh sach thuoc\n");
        printf("3. Cap nhat thuoc theo ma\n");
        printf("4. Xoa thuoc theo ma\n");
        printf("5. Tim thuoc theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");

        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                if (soLuongThuoc >= MAX_SIZE) {
                    printf("Danh sach da day!\n");
                    break;
                }

                printf("Nhap ma thuoc: ");
                scanf("%d", dsThuoc[soLuongThuoc].maThuoc);

                int found = 0;

                for (int i = 0; i < soLuongThuoc; i++) {
                    if (strcmp(dsThuoc[i].maThuoc,
                               dsThuoc[soLuongThuoc].maThuoc) == 0) {
                        found = 1;
                        break;
                    }
                }

                if (found == 1) {
                    printf("Ma thuoc da ton tai!\n");
                    break;
                }

                printf("Nhap ten thuoc: ");
                scanf(" %49[^\n]", dsThuoc[soLuongThuoc].tenThuoc);

                do {
                    printf("Nhap so luong: ");
                    scanf("%d", &dsThuoc[soLuongThuoc].soLuong);

                    if (dsThuoc[soLuongThuoc].soLuong <= 0) {
                        printf("So luong phai lon hon 0!\n");
                    }
                } while (dsThuoc[soLuongThuoc].soLuong <= 0);

                do {
                    printf("Nhap don gia: ");
                    scanf("%f", &dsThuoc[soLuongThuoc].donGia);

                    if (dsThuoc[soLuongThuoc].donGia <= 0) {
                        printf("Don gia phai lon hon 0!\n");
                    }
                } while (dsThuoc[soLuongThuoc].donGia <= 0);

                soLuongThuoc++;

                printf("Them thuoc thanh cong!\n");
                break;
            }

            case 2: {
                if (soLuongThuoc == 0) {
                    printf("Danh sach rong!\n");
                    break;
                }

                printf("\n===== DANH SACH THUOC =====\n");

                for (int i = 0; i < soLuongThuoc; i++) {
                    printf("\nMa thuoc: %d", dsThuoc[i].maThuoc);
                    printf("\nTen thuoc: %s", dsThuoc[i].tenThuoc);
                    printf("\nSo luong: %d", dsThuoc[i].soLuong);
                    printf("\nDon gia: %.2f\n", dsThuoc[i].donGia);
                }

                break;
            }

            case 3: {
            	if (soLuongThuoc == 0) {
            		printf("Danh sach rong!\n");
            		break;
				}
                break;
            }

            case 4: {  
                break;
            }

            case 0:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

