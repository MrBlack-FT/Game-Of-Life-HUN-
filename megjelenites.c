#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "megjelenites.h"
#include "keret.h"
#include "kurzor.h"

int COLORS[]={0, 17, 34, 51, 68, 85, 102, 119, 136, 153, 170, 187, 204, 221, 238, 256};
static unsigned short HATTERSZIN;
static unsigned short KIJELOLESSZIN;

void kepernyo_torles()
{
        system("cls||clear");
}
void keszito()
{
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    // 0 - 67 OSZLOP    => 67 OSZLOP
    // 0 - 33 SOR       => 33 SOR
    KurzorPozicioBeallitas((67-28)/2,(33-3)/2-1);
    HATTERSZIN=64;
    KIJELOLESSZIN=15;
    SetConsoleTextAttribute(konzolKezelo,HATTERSZIN);
    keret_fejlec(28);
    KurzorPozicioBeallitas((67-28)/2,(33-3)/2);
    HATTERSZIN=240;
    SetConsoleTextAttribute(konzolKezelo,HATTERSZIN);
    keret_torzs_statikus(28,"KESZITETTE: FEKETE TAMAS",'K');
    KurzorPozicioBeallitas((67-28)/2,(33-3)/2+1);
    HATTERSZIN=160;
    SetConsoleTextAttribute(konzolKezelo,HATTERSZIN);
    keret_lablec(28);
    SetConsoleTextAttribute(konzolKezelo,COLOR_DEFAULT);
}
void elkoszones()
{
    keret_fejlec(40);
    keret_torzs_statikus(40,"Viszontlatasra!",'K');
    keret_lablec(40);
    Sleep(2000);
}
void rajz_puffer_keret(int oszlop,int sor)
{
    keret_fejlec(7);
    keret_torzs_statikus(7,"VILAG",'K');
    printf("%c",204);
    vonal(5,'N');
    printf("%c",202);
    vonal(oszlop-6,'N');
    printf("%c\n",187);

    int koord_x,koord_y;
    KurzorPozicioLekerdezes(&koord_x,&koord_y);
    for(int I=koord_y;I<sor+3;I++)
    {
        printf("%c",186);
        KurzorPozicioBeallitas(koord_x,I+1);
    }
    KurzorPozicioBeallitas(koord_x+oszlop+1,koord_y);
    for(int I=koord_y;I<sor+3;I++)
    {
        printf("%c",186);
        KurzorPozicioBeallitas(koord_x+oszlop+1,I+1);
    }
    KurzorPozicioBeallitas(koord_x,koord_y+sor);
    printf("%c",204);
    vonal(15,'N');
    printf("%c",203);
    vonal(oszlop-16,'N');
    printf("%c\n",188);
    printf("%cIteracio:      %c\n",186,186);
    keret_lablec(17);
}
void vilag_megjelenites(int **vilag_jelen,int **vilag_jovo,int oszlop,int sor,int iteracio)
{
    KurzorPozicioBeallitas(0,0);
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            /*
            KurzorPozicioBeallitas(N+1,I+3);
            if(vilag_jelen[I][N]==1)
            {
                printf("%c",BLOCK);
            }
            else
            {
                printf(" ");
            }
            */
            if(vilag_jelen[I][N]!=vilag_jovo[I][N])
            {
                KurzorPozicioBeallitas(N+1,I+3);
                if(vilag_jovo[I][N]==1)
                {
                    printf("%c",BLOCK);
                }
                else
                {
                    printf(" ");
                }
            }
        }
    }
    KurzorPozicioBeallitas(10,sor+4);
    printf("%d",iteracio);
}
void rajz_ido_fps_hiba()
{
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    HATTERSZIN=79;
    SetConsoleTextAttribute(konzolKezelo,HATTERSZIN);
    keret_fejlec(40);
    keret_torzs_statikus(40,"FIGYELEM!",'K');
    keret_torzs_ures(40);
    keret_torzs_statikus(40,"NEM SIKERULT BETOLTENI AZ IDOT",'K');
    keret_torzs_statikus(40,"AZ FPS KISZAMITASAHOZ!",'K');
    keret_lablec(40);
    SetConsoleTextAttribute(konzolKezelo,COLOR_DEFAULT);
    Sleep(2500);
}
void puffer_torles(int **vilag_jelen,int oszlop,int sor)
{
    KurzorPozicioBeallitas(0,0);
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            KurzorPozicioBeallitas(N+1,I+3);
            if(vilag_jelen[I][N]==1)
                printf(" ");
        }
    }
}
