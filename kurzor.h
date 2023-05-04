#ifndef KURZOR_H
#define KURZOR_H
    typedef struct KurzorKoordinatai
    {
        int x;
        int y;
        struct KurzorKoordinatai *kovetkezo;
    }
    KurzorKoordinatai;
    void KurzorPozicioBeallitas(int,int);
    void KurzorElrejtes();
    void KurzorMutatas();
    void KurzorPozicioLekerdezes(int*,int*);
    KurzorKoordinatai *KurzorPoziciok_letrehozas(KurzorKoordinatai*,int,int);
    void KurzorPoziciok_hozzaad(KurzorKoordinatai*,int,int);
    int KurzorPoziciok_hossz(KurzorKoordinatai*);
    void KurzorPoziciok_torles(KurzorKoordinatai*);
	KurzorKoordinatai *KurzorPoziciok_Ndik_elem(KurzorKoordinatai*,int);
#endif
