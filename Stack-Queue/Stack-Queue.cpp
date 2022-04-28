#include <iostream>
using namespace std;
struct Dugum {
    int veri; //düðümün sayýsal deðeri
    Dugum* sonraki; //sonraki düðüme iþaretçi
};
struct Kuyruk {
    Dugum* bas; //kuyruðun baþýndaki elemanýn adresini tutar
    Dugum* son; //kuyruðun sonundaki elemanýn adresini tutar
    void olustur(); //baþlangýç için gereken tanýmlarý içerir
    void kapat(); //program bitiminde bellek iadesi yapar
    void ekle(int); //kuyruða yeni veri ekler
    int cikar(); //kuyruktan sýradaki elemaný çýkarýr
    bool bosMu(); //kuyruk boþ mu kontrol eder
};
struct Yigin {
    Kuyruk k1, k2; //yýðýn için kullanýlacak kuyruk deðiþkenleri
    void olustur(); //baþlangýç için gereken tanýmlarý içerir
    void kapat(); //program bitiminde bellek iadesi yapar
    void ekle(int); //kuyruða yeni veri ekler
    int cikar(); //kuyruktan sýradaki elemaný çýkarýr
    bool bosMu(); //kuyruk boþ mu kontrol eder
    int tepe(); //yýðýnýn tepesindeki elemaný okur
    void yazdir(); //yýðýn elemanlarýný sýrayla ekrana yazar
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