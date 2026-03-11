#include <bits/stdc++.h>
using namespace std;

struct Phanso{
    int tuso;
    int mauso;

    // Ham UCLN
    // Dau vao: 2 so nguyen a, b
    // Dau ra : uoc chung lon nhat cua |a| va |b|
    // Chuc nang: dung __gcd() ket hop abs() de xu li so am
    int UCLN(int a,int b){
        return __gcd(abs(a),abs(b)); 
    }
    // Ham rutgon
    // Dau vao: tuso, mauso cua struct
    // Dau ra : khong co, thay doi truc tiep tuso va mauso
    // Chuc nang: chia tu va mau cho UCLN, dam bao mau luon duong
    void rutgon(){
        int g = UCLN(tuso,mauso); 
        tuso /= g;
        mauso /= g; 
        if(mauso < 0){
            tuso = -tuso; 
            mauso = -mauso;
        }
    }
    // Ham nhapps
    // Dau vao: nguoi dung nhap tu so va mau so tu ban phim
    // Dau ra : khong co, gan gia tri vao struct va rut gon lai
    // Chuc nang: vong lap kiem tra sai kieu du lieu va mau = 0
    void nhapps(){
        int t,m;
        do{
            cout<<"nhap gia tri cho tu so va mau so";
            cin>>t>>m;
            if(cin.fail()){ 
                cout<<"nhap sai dinh dang, yeu cau nhap lai"<<endl;
                cin.clear();
                cin.ignore(1000,'\n'); 
                continue;
            }
            if(cin.peek() == '.'){
                cout<<"sai kieu du lieu cua tu so va mau so, yeu cau nhap lai"<<endl;
                cin.ignore(1000,'\n');
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
    // Ham tong
    // Dau vao: phan so p2
    // Dau ra : phan so ket qua p1 + p2 da rut gon
    // Chuc nang: tinh (tuso*p2.mauso + p2.tuso*mauso) / (mauso*p2.mauso)
    Phanso tong(Phanso p2){
        Phanso res;
        res.tuso = tuso * p2.mauso + mauso * p2.tuso;
        res.mauso = mauso * p2.mauso;
        rutgon();
        return res;
    }
    // Ham hieu
    // Dau vao: phan so p2
    // Dau ra : phan so ket qua p1 - p2 da rut gon
    // Chuc nang: tinh (tuso*p2.mauso - p2.tuso*mauso) / (mauso*p2.mauso)
    Phanso hieu(Phanso p2){
        Phanso res;
        res.tuso = tuso * p2.mauso - mauso * p2.tuso;
        res.mauso = mauso * p2.mauso;
        rutgon();
        return res;
    }
    // Ham tich
    // Dau vao: phan so p2
    // Dau ra : phan so ket qua p1 * p2 da rut gon
    // Chuc nang: tinh (tuso*p2.tuso) / (mauso*p2.mauso)
    Phanso tich(Phanso p2){
        Phanso res;
        res.tuso = tuso * p2.tuso;
        res.mauso = mauso * p2.mauso;
        rutgon();
        return res;
    }
    // Ham thuong
    // Dau vao: phan so p2 (p2 khac 0)
    // Dau ra : phan so ket qua p1 / p2 da rut gon
    // Chuc nang: nhan p1 voi nghich dao cua p2, kiem tra p2 khac 0
    Phanso thuong(Phanso p2){
        Phanso res;
        res.tuso = tuso * p2.mauso;
        res.mauso = mauso * p2.tuso;
        rutgon();
        return res;
    }
    // Ham xuatps
    // Dau vao: khong co
    // Dau ra : in phan so dang "tuso/mauso" ra man hinh
    // Chuc nang: hien thi phan so, mau luon duong do rutgon() dam bao
    void xuatps(){
        cout<<tuso<<"/"<<mauso;
    }    
};

int main(){
    Phanso p1,p2;
    cout<<"nhap thong tin cho phan so 1:"<<endl;
    p1.nhapps();
    cout<<"nhap thong tin cho phan so 2:"<<endl;
    p2.nhapps();

    Phanso cong = p1.tong(p2);
    cout<<"tong giua 2 phan so la: ";
    cong.xuatps();
    cout<<endl;
    Phanso tru = p1.hieu(p2);
    cout<<"hieu giua 2 phan so la:";
    tru.xuatps();
    cout<<endl;
    Phanso nhan = p1.tich(p2);
    cout<<"tich giua 2 phan so la: ";
    nhan.xuatps();
    cout<<endl;
    Phanso chia = p1.thuong(p2);
    cout<<"thuong giua 2 phan so la: ";
    chia.xuatps();

}