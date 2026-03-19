#include <bits/stdc++.h>
#include "Ngaythang.h"
#include "Ngaythang.cpp"
using namespace std;
int main(){
    Ngay N1; // tạo input cho ngày 1
    cout<<"nhap input cho ngay thang nam: ";
    N1.Nhap();
    Ngay res = N1.NgayThangNamTiepTheo();
    cout<<"Ngay tiep theo cho input la: ";
    res.Xuat();
    return 0;
}