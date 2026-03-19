#include <bits/stdc++.h>
#include "Ngaythang.h"
using namespace std;

// hàm xác định năm nhuận
bool namnhuan(int nam){
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}
// hàm xác định từng ngày theo tháng
int ngaytheothang(int thang,int nam){
    int ngayarr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(namnhuan(nam) && thang == 2){
        return 29;
    }
    return ngayarr[thang];
}
// hàm nhập
// Đầu vào: Người dùng nhập vào iNgay, iThang, iNam và đưa vào hàm class
// Output: không có, CHỉ có mục đích gán giá trị vào
// Chức năng: Hiển thị ngày nhập hợp lệ trước
//            Nhập lần lượt các input ngay thang nam
//            Kiểm tra input nhập vào có hợp lệ không
//            Yêu cầu nhập lại nếu lỗi
void Ngay::Nhap(){
    cout << "Thang 31 ngay : 1, 3, 5, 7, 8, 10, 12"<<endl;
    cout << "Thang 30 ngay : 4, 6, 9, 11"<<endl;
    cout<<"nhap ngay thang nam hien tai";
    do{ 
        string line; // Ở đây user sẽ cho 1 chuối trống trước 
        char extra; // tao them 1 ki tu để kiểm tra trường hợp cuối kí tự cỏn lỗi hay bị thừa input sai không
        getline(cin,line); // bắt đầu đọc hết chuỗi
        stringstream ss(line); // sử dụng stringstream để đọc từng từ trong chuỗi line

        if(!(ss>>iNgay>>iThang>>iNam) || ss >> extra){
            // điều kiện kiểm tra từng kí tự của stringstream giúp kiểm tra chuỗi line xem nó có thỏa điều kiện không
            // Nếu kiểm tra thỏa 3 số đầu thì nếu có input dư thì khi gặp 1 kí tự extra thì cho nó false 
            cout<<"input khong hop le(sai kiểu định dạng hoặc sai kiểu dữ liệu)"<<endl;
            cout<<"Nhap lai:";
            continue;
        }
        if(iNam < 0){
            cout<<"Nam khong hop le"<<endl;
            continue;
        }
        if(iThang <= 0 || iThang > 12){
            cout<<"thang khong hop le"<<endl;
            continue;
        }
        if(iNgay <= 0 || iNgay > 31){
            cout<<"ngay khong hop le";
            continue;
        }
        // xác định số ngày tối đa trong tháng đó, đảm bảo không vượt quá ngày theo tháng
        if(iNgay > ngaytheothang(iThang,iNam)){
            if(namnhuan(iNam) && iThang == 2){
                cout<<"Nam nhuan, thang 2 co 29 ngay"<<endl;
            }
            cout<<"thang "<<iThang<<" co toi da "<<ngaytheothang(iThang,iNam)<<" ngay"<<endl;
            continue; 
        }
        break; // Nếu thỏa hết thì break khỏi vòng lặp do while để bước sang cộng ngày tiếp theo

    }while(true);
}
// Hàm NgayThangNamTiepTheo()
// Đầu vào: Không có 
// Đẩu ra: Trả về kết quả của ngày tiếp theo 
// chức nang: Lấy dữ liệu từ ngày cũ thông qua biến con trỏ this lấy từ hàm gốc class ban đầu
//            Sau đó đem di cộng từng phần theo ngày tháng năm 
Ngay Ngay::NgayThangNamTiepTheo(){
    Ngay ketqua = *this; // tạo 1 hàm khởi tạo mói lấy class và lưu thông tin của ngày cũ
    ketqua.iNgay++; 
    if(ketqua.iNgay > ngaytheothang(ketqua.iThang,ketqua.iNam)){
        // điều kiện nếu ngày tiếp theo của ketqua vượt quá ngày theo tháng cho phép
        ketqua.iNgay = 1;
        ketqua.iThang++;
    }
    if(ketqua.iThang > 12){
        // điều kiện tháng vươt quá số quy định
        ketqua.iThang = 1;
        ketqua.iNam++;
    }
    return ketqua;
}
void Ngay::Xuat(){
    cout<<"ngay tiep theo la: "<<iNgay<<"/"<<iThang<<"/"<<iNam;
}