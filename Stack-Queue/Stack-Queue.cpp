#include <iostream>
using namespace std;
struct Dugum {
    int veri; //d���m�n say�sal de�eri
    Dugum* sonraki; //sonraki d���me i�aret�i
};
struct Kuyruk {
    Dugum* bas; //kuyru�un ba��ndaki eleman�n adresini tutar
    Dugum* son; //kuyru�un sonundaki eleman�n adresini tutar
    void olustur(); //ba�lang�� i�in gereken tan�mlar� i�erir
    void kapat(); //program bitiminde bellek iadesi yapar
    void ekle(int); //kuyru�a yeni veri ekler
    int cikar(); //kuyruktan s�radaki eleman� ��kar�r
    bool bosMu(); //kuyruk bo� mu kontrol eder
};
struct Yigin {
    Kuyruk k1, k2; //y���n i�in kullan�lacak kuyruk de�i�kenleri
    void olustur(); //ba�lang�� i�in gereken tan�mlar� i�erir
    void kapat(); //program bitiminde bellek iadesi yapar
    void ekle(int); //kuyru�a yeni veri ekler
    int cikar(); //kuyruktan s�radaki eleman� ��kar�r
    bool bosMu(); //kuyruk bo� mu kontrol eder
    int tepe(); //y���n�n tepesindeki eleman� okur
    void yazdir(); //y���n elemanlar�n� s�rayla ekrana yazar
};

int main()
{
    
}
void Kuyruk::olustur() {
    bas = NULL;
    son = NULL;
}
void Kuyruk::kapat() {
    Dugum* p;
    while (bas) {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
}
void Kuyruk::ekle(int yeni) {
    Dugum* newNode = new Dugum();
    newNode->veri = yeni;
    newNode->sonraki = NULL;
    if (bas == NULL) {
        bas = newNode;
        son = bas;
    }
    else {
        son->sonraki = newNode;
        son = newNode;
    }
}
int Kuyruk::cikar() {
    Dugum* ustDugum;
    int gecici;
    ustDugum = bas;
    bas = bas->sonraki;
    gecici = ustDugum->veri;
    delete ustDugum;
    return gecici;
}
bool Kuyruk::bosMu() {
    return bas == NULL;
}