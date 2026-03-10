#include <bits/stdc++.h>
using namespace std;

struct Phanso{
    int tuso;
    int mauso;

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
    bool bangnhau(Phanso p2){
        //Đầu vào: Phân số p2
        //Đầu ra: true nếu bằng nhau, false nếu khác
        //Chức năng: So sánh trực tiếp tuso và mauso sau khi đã rút gọn
        return tuso == p2.tuso && mauso == p2.mauso;
    }
    bool sosanh(Phanso p2){
        //Đầu vào: Phân số p2
        //Đầu ra: true nếu p1 > p2, false nếu p1 < p2
        //Chức năng: Nhân chéo tuso * p2.mauso so với mauso * p2.tuso
        int left = tuso * p2.mauso;
        int right = mauso * p2.tuso;
        if(left > right){
            return true;
        }
        else return false;
    }
    void xuatps(){
        // hàm xuatps
        // Đầu vao: Không có
        // đầu ra: in tuso/mauso ra màn hình output
        cout<<tuso<<"/"<<mauso;
    }    
};
int main(){
    Phanso p1,p2;
    cout<<"nhap thanh phan cho phan so p1"<<endl;
    p1.nhapps();
    cout<<"nhap thanh phan cho phan so p2:"<<endl;
    p2.nhapps();
    cout << "Ket qua: Phan so lon nhat la: ";

    if (p1.bangnhau(p2)) { 
        p1.xuatps();
        cout << " (hai phan so bang nhau)"<<endl;
    }
    else if (p1.sosanh(p2)) {
        p1.xuatps();
        cout<<endl;
    }
    else {
        p2.xuatps();
        cout <<endl;
    }
    return 0;
}
