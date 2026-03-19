#include <bits/stdc++.h>
using namespace std;
struct Phanso{
    int tuso;
    int mauso;
    Phanso(){
        tuso  =0;
        mauso =1;
        // hàm khởi tạo mặc định cho tử số và mẫu số
    }
    // hàm khởi tạo có tham số 
    // đầu vào: tu (tử số), mẫu số khác 0
    // đầu ra: không có(gán tuso,mauso và rutgon)
    Phanso(int tu,int mau){
        if(mau == 0){
            cout<<"mau khong dc bang 0";
            tuso = 0;
            mauso = 1;
            return;
        }
        tuso = tu;
        mauso = mau;
        rutgon();
    }
    // hàm UCLN: tìm ước chung lớn nhất của |a| và |b|
    // đầu vao: 2 số nguyên a,b;
    // đầu ra: UCLN(|a|,|b|)
    int UCLN(int a,int b){
        return __gcd(abs(a),abs(b)); 
        // ta lấy __gcd có sẵn trong thư viện <bits/stdc++.h>
        // sử dụng abs xử lí trường hợp nếu a hoặc b âm
    }
    // hàm rutgon(): rút gọn phân số về dạng tối giản 
    // đầu vào: Lấy tuso và mauso có trong hàm struct
    // đầu ra: Thay đỏi trực tiếp tuso và mauso 
    void rutgon(){
        int g = UCLN(tuso,mauso); 
        tuso /= g;
        mauso /= g; 
        if(mauso < 0){
            tuso = -tuso; 
            mauso = -mauso;
        }
    }
    // hàm nhập xuất phân số 
    // đầu vào: use nhập tuso và mauso
    // đầu ra: gán giá trị ngược về struct và rút gọn laị
    void nhapps(){
        int t,m;
        do{
            cout<<"nhap gia tri cho tu so va mau so";
            cin>>t>>m;
            if(cin.fail()){ 
                // cin.fail() để kiểm tra sai đinh dạng kiểu dữ liệu của tử và mẫu (nhập chuỗi, số thập phân)
                cout<<"nhap sai dinh dang, yeu cau nhap lai"<<endl;
                cin.clear();
                // su dung cin.clear() để tắt đi trạng thái fail của máy tinh giúp user nhập lại input
                cin.ignore(1000,'\n'); 
                // cin.ignore() xóa bộ nhớ đệm hay dữ liệu cũ 
                // tránh dữ liệu bị đè lên nhau 
                continue;
            }
            if(m == 0){
                cout<<"mau khong duoc bang khong"<<endl;
                continue;
            }
            break; 
        }while(true); 
        tuso = t; 
        mauso = m;
        rutgon(); 
    }
    // hàm xuatps
    // Đầu vao: Không có
    // đầu ra: in tuso/mauso ra màn hình output
    void xuatps(){
        cout<<tuso<<"/"<<mauso;
    }
};

int main(){
    Phanso p1;
    p1.nhapps();
    p1.xuatps();
    return 0;
}
