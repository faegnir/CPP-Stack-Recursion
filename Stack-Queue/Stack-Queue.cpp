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

void yiginCikar(Yigin*);
void siraliEkle(Yigin*, int);
static int sayac = 0;

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

    for (int i = 0;i < sayac;i++)
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
    sayac = 0;
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
    sayac++;
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