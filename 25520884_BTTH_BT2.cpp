#include <bits/stdc++.h>
using namespace std;

struct Phanso{
    int tuso;
    int mauso;

    // Ham UCLN
    // Dau vao: 2 so nguyen a, b
    // Dau ra : uoc chung lon nhat cua |a| va |b|
    // Chuc nang: dung __gcd() ket hop abs() de xu li so am
    int UCLN(int a, int b){
        return __gcd(abs(a), abs(b));
        // ta lấy __gcd có sẵn trong thư viện <bits/stdc++.h>
        // sử dụng abs xử lí trường hợp nếu a hoặc b âm
    }

    // Ham rutgon
    // hàm rutgon(): rút gọn phân số về dạng tối giản 
    // đầu vào: Lấy tuso và mauso có trong hàm struct
    // đầu ra: Thay đỏi trực tiếp tuso và mauso
    // Chuc nang: chia tu va mau cho UCLN, dam bao mau luon duong
    void rutgon(){
        int g = UCLN(tuso, mauso);
        tuso  /= g;
        mauso /= g;
        if(mauso < 0){
            tuso  = -tuso;
            mauso = -mauso;
        }
    }

    // Ham nhapps
    // hàm nhập phân số 
    // đầu vào: user nhập tuso và mauso
    // đầu ra: gán giá trị ngược về struct và rút gọn laị
    // Chuc nang: vong lap kiem tra sai kieu du lieu va mau = 0
    void nhapps(){
        int t, m;
        do{
            cout << "Nhap tu so va mau so: ";
            cin >> t >> m;
            if(cin.fail()){
                cout << "Sai dinh dang, yeu cau nhap lai!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            if(m == 0){
                cout << "Mau khong duoc bang 0!" << endl;
                continue;
            }
            break;
        }while(true);
        tuso  = t;
        mauso = m;
        rutgon();
    }

    // Ham bangnhau
    // Dau vao: phan so p2
    // Dau ra : true neu p1 == p2, false neu khac
    // Chuc nang: so sanh truc tiep tuso va mauso sau khi da rut gon
    bool bangnhau(Phanso p2){
        return tuso == p2.tuso && mauso == p2.mauso;
    }

    // Ham sosanh
    // Dau vao: phan so p2
    // Dau ra : true neu p1 > p2, false neu p1 < p2
    // Chuc nang: nhan cheo (tuso * p2.mauso) voi (mauso * p2.tuso)
    bool sosanh(Phanso p2){
        long long left  = (long long)tuso  * p2.mauso;
        long long right = (long long)mauso * p2.tuso;
        return left > right;
    }

    // Ham xuatps
    // Đầu vao: Không có
    // đầu ra: in tuso/mauso ra màn hình output
    // Chuc nang: hien thi phan so, mau luon duong do rutgon() dam bao
    void xuatps(){
        cout << tuso << "/" << mauso;
    }
};

int main(){
    Phanso p1, p2;

    cout << "Nhap phan so p1:" << endl;
    p1.nhapps();
    cout << "Nhap phan so p2:" << endl;
    p2.nhapps();

    cout << "Ket qua: ";
    if(p1.bangnhau(p2)){
        cout << "Hai phan so bang nhau: ";
        p1.xuatps();
    }
    else if(p1.sosanh(p2)){
        cout << "Phan so lon nhat la: ";
        p1.xuatps();
    }
    else{
        cout << "Phan so lon nhat la: ";
        p2.xuatps();
    }
    cout << endl;
    return 0;
}