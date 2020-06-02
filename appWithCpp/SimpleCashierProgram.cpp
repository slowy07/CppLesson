#include <iostream>
#include <string.h>
using namespace std;


void menu()
{
    cout<<"1. nasi goreng sambal pelangi"<<endl;
    cout<<"2. soto daging kerbau"<<endl;
    cout<<"3. ikan salmon bakar"<<endl;
    cout<<"4. udang tumis cabe hijau"<<endl;
}

double jumlah_pesanan(double harga, double jumlah_pesanan)
{
    return jumlah_pesanan * harga;
}
double kembalian(double hargaTotal,double uangKembalian)
{
    return hargaTotal - uangKembalian;
}


int main()
{
    char looping;
    int choice;
    double HargaMakanan,jumlah_pesananMakanan,sum,uangPelanggan,uangKembalianPelanggan;
    do
    {
        menu();
        switch (choice)
        {
        case 1:
            HargaMakanan = 15000;
            cout<<"harga per piring = Rp.15000"<<endl;
            cout<<"masukkan jumlah pesanan = "; cin>>jumlah_pesananMakanan;
            sum = jumlah_pesanan(HargaMakanan, jumlah_pesananMakanan);
            cout<<"harga yang harus dibayar Rp."<<sum<<endl;
            cout<<"masukkan uang pelanggan Rp = "; cin>>uangPelanggan;
            uangKembalianPelanggan = kembalian(sum, uangPelanggan);
            cout<<"kembalian Rp."<<uangKembalianPelanggan<<endl;
            break;
        case 2:
            HargaMakanan = 35000;
            cout<<"harga per piring = Rp.35000"<<endl;
            cout<<"masukkan jumlah pesanan = "; cin>>jumlah_pesananMakanan;
            sum = jumlah_pesanan(HargaMakanan, jumlah_pesananMakanan);
            cout<<"harga yang harus dibayar Rp."<<sum<<endl;
            break;
        case 3:
            HargaMakanan = 25000;
            cout<<"harga per piring = Rp.35000"<<endl;
            cout<<"masukkan jumlah pesanan = "; cin>>jumlah_pesananMakanan;
            sum = jumlah_pesanan(HargaMakanan, jumlah_pesananMakanan);
            cout<<"harga yang harus dibayar Rp."<<sum<<endl;
            cout<<"masukkan uang pelanggan Rp = "; cin>>uangPelanggan;
            uangKembalianPelanggan = kembalian(sum, uangPelanggan);
            cout<<"kembalian Rp."<<uangKembalianPelanggan<<endl;
            break;
        case 4:
            HargaMakanan = 15000;
            cout<<"harga per piring = Rp.15000"<<endl;
            cout<<"masukkan jumlah pesanan = "; cin>>jumlah_pesananMakanan;
            sum = jumlah_pesanan(HargaMakanan,jumlah_pesananMakanan);
            cout<<"harga yang harus dibayar Rp."<<sum<<endl;
            cout<<"masukkan uang pelanggan Rp = "; cin>>uangPelanggan;
            uangKembalianPelanggan = kembalian(sum, uangPelanggan);
            cout<<"kembalian Rp."<<uangKembalianPelanggan<<endl;
            break;
        default:
            cout<<"wrong choice";
            break;
        }
        cout<<"count ?? "; cin>>looping;
    }
    while(looping =='y' || looping =='Y');
    return 0;
}
