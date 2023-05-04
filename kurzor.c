#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "kurzor.h"
#include "debugmalloc.h"
void KurzorElrejtes()
{
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize=1;
    info.bVisible=FALSE;
    SetConsoleCursorInfo(konzolKezelo,&info);
}
void KurzorMutatas()
{
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize=20;
    info.bVisible=TRUE;
    SetConsoleCursorInfo(konzolKezelo,&info);
}
void KurzorPozicioBeallitas(int X,int Y)
{
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pozicio={X, Y};
    SetConsoleCursorPosition(konzolKezelo, Pozicio);
}
void KurzorPozicioLekerdezes(int *X,int *Y)
{
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(konzolKezelo,&info);
    COORD jelenlegi_pozicio=info.dwCursorPosition;
    *X=jelenlegi_pozicio.X;
    *Y=jelenlegi_pozicio.Y;
}
KurzorKoordinatai *KurzorPoziciok_letrehozas(KurzorKoordinatai *eleje,int X,int Y)
{
    KurzorKoordinatai *uj=(KurzorKoordinatai*)malloc(sizeof(KurzorKoordinatai));
    uj->kovetkezo=eleje;
    uj->x=X;
    uj->y=Y;
    uj->kovetkezo=NULL;
    return uj;
}
void KurzorPoziciok_hozzaad(KurzorKoordinatai *eleje,int X,int Y)
{
    KurzorKoordinatai *uj;
    uj=(KurzorKoordinatai*)malloc(sizeof(KurzorKoordinatai));
    uj->x=X;
    uj->y=Y;
    uj->kovetkezo=NULL;
    if (eleje==NULL)
    {
       eleje=uj;
    }
    else
    {
        KurzorKoordinatai *olvaso=eleje;
        while(olvaso->kovetkezo!=NULL)
        {
          olvaso=olvaso->kovetkezo;
        }
        olvaso->kovetkezo=uj;
    }
}
int KurzorPoziciok_hossz(KurzorKoordinatai *KurzorPoziciok)
{
    int db=0;
    for(KurzorKoordinatai *olvaso=KurzorPoziciok;olvaso!=NULL;olvaso=olvaso->kovetkezo)
    {
        db++;
    }
    return db;
}
void KurzorPoziciok_torles(KurzorKoordinatai *KurzorPoziciok)
{
        KurzorKoordinatai *torles=KurzorPoziciok;
        while(torles!=NULL)
        {
            KurzorKoordinatai *kovetkezo=torles->kovetkezo;
            free(torles);
            torles=kovetkezo;
        }
}
KurzorKoordinatai *KurzorPoziciok_Ndik_elem(KurzorKoordinatai *eleje,int N)
{
    int index=0;
    KurzorKoordinatai *olvaso=eleje;
    while(olvaso!=NULL)
    {
        if(index==N-1)
        {
            return olvaso;
        }
        olvaso=olvaso->kovetkezo;
        index++;
    }
    return NULL;
}
