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

void yiginCikar(Yigin*);
void siraliEkle(Yigin*, int);

int main()
{
    Yigin* st = new Yigin();

    cout << endl << "   Orjinal Yigin" << endl;
    st->olustur();
    st->ekle(3);
    st->ekle(1);
    st->ekle(7);
    st->ekle(4);
    st->ekle(8);
    st->yazdir();

    cout << endl <<"   ---yiginCikar fonksiyon cagrisi---" << endl;
    yiginCikar(st);
   
    cout << endl<< "   Sirali Yigin" << endl;
    siraliEkle(st, 3);
    siraliEkle(st, 1);
    siraliEkle(st, 7);
    siraliEkle(st, 4);
    siraliEkle(st, 8);
    st->yazdir();
    st->kapat();
}

void yiginCikar(Yigin* s) {
    if (s->bosMu())
        return;
    s->cikar();
    yiginCikar(s);
}
void siraliEkle(Yigin* s, int x)
{
    if (s->bosMu() or x > s->tepe()) {
        s->ekle(x);
        return;
    }
    int temp = s->cikar();
    siraliEkle(s, x);
    s->ekle(temp);
}

void Yigin::olustur() {
    k1.bas = NULL;
}
void Yigin::kapat(){
    Dugum* p;
    while (k1.bas) {
        p = k1.bas;
        k1.bas = k1.bas->sonraki;
        delete p;
    }
}
void Yigin::ekle(int x) {
    Kuyruk temp;
    k2.ekle(x);
    while (!k1.bosMu())
    {
        k2.ekle(k1.bas->veri);
        k1.cikar();
    }
    temp = k1;
    k1 = k2;
    k2 = temp;
}
int  Yigin::cikar() {
    Dugum* ustDugum;
    int gecici;
    ustDugum = k1.bas;
    k1.bas = k1.bas->sonraki;
    gecici = ustDugum->veri;
    delete ustDugum;
    return gecici;
}
bool Yigin::bosMu() {
    return k1.bas == NULL;
}
int  Yigin::tepe() {
    return k1.bas->veri;
}
void Yigin::yazdir() {
    Dugum* tara;
    tara = k1.bas;
    if (!tara) {
        cout << "Yigin bos" << endl;
        return;
    }
    cout << "   ";
    while (tara) {
        cout << tara->veri << " ";
        tara = tara->sonraki;
    }
    cout << endl;
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
    Dugum* newNode = new Dugum;
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
int  Kuyruk::cikar() {
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