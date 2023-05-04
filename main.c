#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//#include <strsafe.h>          //StringCchCopyA fugvenyhez, de a debugmalloc miatt nem lehet!
#include <conio.h>
#include "ftfunctions.h"
#include "kurzor.h"
#include "keret.h"
#include "megjelenites.h"
#include "eletjatek.h"
#include "debugmalloc.h"

#define ESC 27
#define ENTER 13

void Inicializalas(char *cim_sztring)
{
    kepernyo_torles();
    srand(time(0));

    CONSOLE_FONT_INFOEX info;
    info.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE konzolKezelo = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(konzolKezelo,0,&info);
    info.FontWeight=100;    //100-1000
    info.dwFontSize.X=4;    //4-16
    info.dwFontSize.Y=4;    //4-16
    lstrcpyW(info.FaceName,L"Lucida Console");
    //StringCchCopyA(info.FaceName,sizeof(info.FaceName),"Lucida Console");
    SetCurrentConsoleFontEx(konzolKezelo,false,&info);

    HWND ablak=GetConsoleWindow();
    DWORD FELBONTAS_SZELESSEG = GetSystemMetrics(SM_CXSCREEN);
    DWORD FELBONTAS_MAGASSAG = GetSystemMetrics(SM_CYSCREEN);
    int ABLAK_SZELESSEG=1600;
    int ABLAK_MAGASSAG=900;
    if(FELBONTAS_SZELESSEG<ABLAK_SZELESSEG&&FELBONTAS_MAGASSAG<ABLAK_MAGASSAG)
    {
        ABLAK_SZELESSEG=640;
        ABLAK_MAGASSAG=480;
    }
    MoveWindow(ablak, (FELBONTAS_SZELESSEG/2-ABLAK_SZELESSEG/2), (FELBONTAS_MAGASSAG/2-ABLAK_MAGASSAG/2), ABLAK_SZELESSEG, ABLAK_MAGASSAG, TRUE);
    SetWindowLong(ablak, GWL_STYLE, GetWindowLong(ablak, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    SetConsoleTitle(cim_sztring);

    Sleep(10);
}

int main()
{
    while(1)
    {
        printf("Nyomj Entert a Kezdeshez!\n");
        printf("Kilepeshez nyomd meg az ESC-et!\n");
        if(getch()==ENTER)
        {
            kepernyo_torles();
            break;
        }
        else if(getch()==ESC)
        {
            return 0;
        }
    }

    char cim_sztring[64];
    sprintf(cim_sztring,"Elet Jatek");

    Inicializalas(cim_sztring);

    //!FPS SZAMLALO INICIALIZALAS!
    time_t now;
    struct tm *tm;
    now=time(0);
    if ((tm=localtime(&now))==NULL)
    {
        rajz_ido_fps_hiba();
        kepernyo_torles();
    }
    double msp_elozo=tm->tm_sec;
    double msp_jelenlegi=tm->tm_sec;
    int kepkockak=0;
    double fps;
    //!FPS SZAMLALO INICIALIZALAS VEGE!

    KurzorElrejtes();
    HANDLE konzolKezelo=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(konzolKezelo,COLOR_DEFAULT);

    int OSZLOP=750;     //150-750
    int SOR=200;         //40-200
    int **vilag_jelen=int_dinamikus2dtomb(OSZLOP,SOR);
    int **vilag_jovo=int_dinamikus2dtomb(OSZLOP,SOR);

    int iteracio=0;

    rajz_puffer_keret(OSZLOP,SOR);
    vilag_megjelenites(vilag_jelen,vilag_jovo,OSZLOP,SOR,iteracio);
    printf("\n\nKilepeshez nyomd meg az ESC-et!\n");

    int_dinamikus2dtomb_random(vilag_jelen,OSZLOP,SOR);

    bool b_vm=true;
    bool b_pt=false;

    //MAIN LOOP
    while(1)
    {
        if(!kbhit())
        {
            vilag_frissites(vilag_jelen,vilag_jovo,OSZLOP,SOR);
            if(b_vm)
            {
                vilag_megjelenites(vilag_jelen,vilag_jovo,OSZLOP,SOR,iteracio);
                b_pt=false;
            }
            else if(!b_pt)
            {
                puffer_torles(vilag_jelen,OSZLOP,SOR);
                b_pt=true;
            }
            //!FPS SZAMLALO - ENNEK EGY KULON THREAD-EN KENE MENNIE!
            now=time(0);
            tm=localtime(&now);
            msp_jelenlegi=tm->tm_sec;
            if((msp_jelenlegi-msp_elozo)>1.0||kepkockak==0)
            {
                fps=(double)kepkockak/(msp_jelenlegi-msp_elozo);
                sprintf(cim_sztring,"Elet Jatek - FPS:%.2f",fps);
                SetConsoleTitle(cim_sztring);
                msp_elozo=msp_jelenlegi;
                kepkockak=0;
            }
            kepkockak++;
            //!FPS SZAMLALO VEGE

            iteracio++;

            int **vilag_ideiglenes=vilag_jelen;
            vilag_jelen=vilag_jovo;
            vilag_jovo=vilag_ideiglenes;

            int_dinamikus2dtomb_tisztitas(vilag_jovo,OSZLOP,SOR);
        }
        else if(getch()==ESC||iteracio==999999)
            break;
        else if(getch()=='t')
        {
            if(b_vm)
                b_vm=false;
            else
                b_vm=true;
        }
    }

    int_dinamikus2dtomb_torles(vilag_jelen,OSZLOP,SOR);
    int_dinamikus2dtomb_torles(vilag_jovo,OSZLOP,SOR);

    SetConsoleTextAttribute(konzolKezelo,COLOR_DEFAULT);
    KurzorPozicioBeallitas(0,SOR+7);
    return 0;
}
