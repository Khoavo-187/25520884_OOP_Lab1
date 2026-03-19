#include <bits/stdc++.h>
using namespace std;

struct Hocsinh{
    string hoten;
    double toan;
    double van;

    // Hàm khởi tạo giá trị mặc định
    // Đầu vào: Không có
    // Đầu ra: không có
    // Chức năng: Khởi tạo giá trị mặc định cho học sinh nếu không có input
    Hocsinh(){
        hoten = "";
        toan  = 0.0;
        van   = 0.0;
    }
    // ham kiemtrahoten
    // đâu vào: Hàm lấy input từ hàm nhapthongtin của ho tên học sinh 
    // đầu ra: Trả về true hoặc false nếu thỏa các điều kiện dưới
    // chức năng: Hàm kiểm tra tên chir chứa các kí tụ không phải là số
    bool kiemtraHoTen(string s){
    if(s.empty()) return false;
        for(char c : s){
            // Kiểm tra từng kí tự trong chuỗi s
            if(c >= '0' && c <= '9'){
                // xác nhận nếu có bất kì kí tự nào là số
                return false;
            }
        }   
        return true;
    }
    // Hàm nhapthongtin
    // Đầu vào: User nhập họ tên, điểm toán và văn cho 1 học sinh
    // Đầu ra: Không có, lấy input từ user gán vào giá trị của struct trong bảng
    // CHức năng: Nhập thông tin cho 1 học sinh, loại bỏ trường họp nếu tên có số hoặc input không hợp lệ
    void nhapthongtin(){
        // Đối với phần nhập thông tin này thì các kiểu dữ liệu trong struct là khác nhau thì minh phải có it nhất 2 vòng lặp do while để dễ kiểm soát input
        string ten;
        double t, v;

        // Chức năng: Ta sử dụng hàm cin.ignore() vì khi ta nhập input getline và bấm enter thì kí tụ '\n' sẽ bị kẹt lại trong bộ nhớ đệm
        // Nên khi ta muốn nhập input mới thì phải ignore bộ nhớ đệm cũ , bỏ qua '\n' để có thể nhập được input hợp lệ
        cin.ignore();
        do{
            cout << "Nhap ho ten hoc sinh: ";
            getline(cin, ten);
            if(cin.fail()){
                cout << "Sai kieu du lieu, nhap lai!" << endl;
                cin.clear(); // tương tự như Phanso thì phải tắt trạng thái fail để nhập cái mới
                cin.ignore(1000, '\n');
                continue;
            }
            // sau khi nhập họ tên thì biến ten sẽ được check lại bằng hàm kiemtra xem có thỏa điều kiện không
            if(!kiemtraHoTen(ten)){
                cout << "Ho ten khong hop le, nhap lai!" << endl;
                continue;
            }
            break;
        }while(true);

        // Nhập điểm toán và văn
        do{
            cout << "Nhap diem toan (0 - 10): ";
            cin >> t;
            cout << "Nhap diem van (0 - 10): ";
            cin >> v;
            if(cin.fail()){
                cout << "Sai kieu du lieu, nhap lai!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            // Điểm toán và văn phải nằm trong khoảng từ 0 - 10
            if(t < 0.0 || t > 10.0){
                cout << "Diem toan phai tu 0 den 10, nhap lai!" << endl;
                continue;
            }
            if(v < 0.0 || v > 10.0){
                cout << "Diem van phai tu 0 den 10, nhap lai!" << endl;
                continue;
            }
            break;
        }while(true);
        hoten = ten;
        toan  = t;
        van   = v;
    }

    // hàm diemtrungbinh
    // Đầu vào: toán, văn của struct
    // Đầu ra : điểm trung bình kiểu double
    // chức năng: tính trung bình cộng của điểm toán và văn
    double diemtrungbinh(){
        return (toan + van) / 2.0;
    }

    // hàm xuatthongtin
    // Đầu vào: Không có
    // Đầu ra: In thông tin của học sinh 
    // Chức năng: Xuất ra thông tin họ và tên, điểm toán , văn và điểm trung bình của học sinh
    void xuatthongtin(){
        cout << "Ho va ten     : " << hoten << endl;
        cout << "Diem toan     : " << toan  << endl;
        cout << "Diem van      : " << van   << endl;
        cout << "Diem trung binh: " << diemtrungbinh() << endl;
    }
};

int main(){
    Hocsinh hs;
    cout << "Nhap thong tin hoc sinh:" << endl;
    hs.nhapthongtin();
    cout << "\nThong tin hoc sinh:" << endl;
    hs.xuatthongtin();
    return 0;
}