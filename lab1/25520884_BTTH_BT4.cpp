#include <bits/stdc++.h>
using namespace std;

struct Ngay
{
    int ngay;
    int thang;
    int nam;
    // Hàm khởi tạo giá trị mặc định cho ngày nếu chưa có input từ user hoặc user không cho 
    Ngay(){
        ngay = 1;
        thang = 1;
        nam = 2026;
    }
    // hàm namnhuan();
    // đàu vào: Lấy giá trị nam trong struct để so sánh
    // đàu ra: giá tri true hoặc false theo điều kiện
    // chức năng: Lấy input nam của user xem liệu năm đó có phải là năm nhuận không nếu thỏa hết điều kiện dưới, else trả về false
    // Là namnhuan nếu nam chia hết cho 400 hoặc nam chia hết cho 4 và không chia hết cho 100
    bool namnhuan(){
        return (nam % 400 == 0|| (nam % 4 == 0 && nam % 100 != 0));
    }
    // hàm ngaytrongthang()
    // đàu vào: Lấy dữ liệu theo từng tháng của user trong struct
    // đàu ra: Trả về số ngày tương ứng
    // chức năng: Xử lí đúng số ngày theo từng tháng và xét điêu kiện năm nhuận bên trong của tháng 2 
    int ngaytrongthang(){
        int ngayarr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool lanamnhuan = namnhuan();
        if(lanamnhuan && thang == 2){
            return 29;
        }
        return ngayarr[thang];
    }
    // hàm Nhapngay();
    // đàu vào: Nhập input cho ngay , thang, nam
    // đầu ra: không có, gán ngược lại giá trị bên trong struct
    void nhapngay(){
        int date,month,year;
        cout << "Thang 31 ngay : 1, 3, 5, 7, 8, 10, 12"<<endl;
        cout << "Thang 30 ngay : 4, 6, 9, 11"<<endl;
        cout << "Thang 2 : 28 ngay (khong nhuan) / 29 ngay (nhuan)"<<endl;
        // Cho phép người dùng có thể biết được cụ thể tháng đó có bao nhiêu ngày
        do{
            cin>>date>>month>>year;
            // Cho input để có thể lọc điều kiện dẽ hơn
            if(cin.fail()){
                // loi dinh dang kieu du lieu
                // tương tự như bài Phanso thì nếu gắp sai dữ liệu thì máy tính báo lỗi và xử lí các bước tiếp theo
                cout<<"loi dinh dang yeu cau nhap lai";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            if(year <= 0){
                cout<<"nam khong duoc phep am hoac bang 0";
                continue;
            }
            if(month < 1 || month > 12){
                cout<<"thang khong hop le";
                continue;
            }
            if(date < 1){
                cout<<"ngay khong hop le";
                continue;
            }
            nam = year;
            thang = month;
            // Check ngày tương ứng từng tháng thi ta phai cập nhật lại đúng tháng đó, năm đó vào trong struct
            // xem liệu ngày nhập có valid với tháng đó không
            if(ngaytrongthang() < date){
                cout<<"thang "<<month<<" co "<<ngaytrongthang()<<" ngay"<<endl;
                continue;
            }
            ngay = date;
            // nêu ok thì break 
            break;

        }while(true);
    }
    // Hàm ngaytieptheo();
    // đàu vào: Lấy dữ liệu từ struct hiện tại người dùng mới nhập vào
    // đàu ra: trả về giá trị ngày tiếp theo tương xứng
    // chức năng: Cộng cho từng ngày với 1, xử lí riêng trường hợp nếu vượt quá quy định và xử lí năm
    Ngay ngaytieptheo(){
        Ngay ketqua = *this;// Lấy và sao lưu dữ liệu gốc của ngày ban đàu mới vừa nhập chuyển sang ketqua
        ketqua.ngay++; // khúc này chỉ đang sửa dựa trên bản sao còn bản gốc ngày đầu vẫn giữ nguyên
        if(ketqua.ngay > ngaytrongthang()){
            ketqua.ngay = 1;
            ketqua.thang++;
        }
        if(ketqua.thang > 12){
            ketqua.thang = 1;
            ketqua.nam++;
        }
        return ketqua;
    }
    void xuatngay(){
        cout<<ngay<<"/"<<thang<<"/"<<nam;
    }
};

int main() {
    Ngay n1;
    cout<<"nhap ngay thang cho ngay 1"<<endl;
    n1.nhapngay();
    Ngay n2 = n1.ngaytieptheo();
    cout<<"ngay ke tiep la: ";
    n2.xuatngay();
    
    return 0;
}