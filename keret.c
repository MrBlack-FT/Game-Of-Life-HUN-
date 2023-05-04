#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"
int const oszlop=186;
int const koz=205;
int const koz_koz=206;
int const koz_fel=202;
int const koz_le=203;
int const keret_koz_jobb=185;
int const keret_koz_bal=204;
int const fejlec_jobb=187;
int const fejlec_bal=201;
int const lablec_jobb=188;
int const lablec_bal=200;
int const blokk=219;
void keret_tipusai()
{
    printf("[%d]:%c\n",koz,koz);
    printf("[%d]:%c\n",koz_koz,koz_koz);
    printf("[%d]:%c\n",koz_fel,koz_fel);
    printf("[%d]:%c\n",koz_le,koz_le);
    printf("[%d]:%c\n",keret_koz_jobb,keret_koz_jobb);
    printf("[%d]:%c\n",keret_koz_bal,keret_koz_bal);
    printf("[%d]:%c\n",oszlop,oszlop);
    printf("[%d]:%c\n",fejlec_jobb,fejlec_jobb);
    printf("[%d]:%c\n",fejlec_bal,fejlec_bal);
    printf("[%d]:%c\n",lablec_jobb,lablec_jobb);
    printf("[%d]:%c\n",lablec_bal,lablec_bal);
}
void keret_fejlec(int hossz)
{
    if(hossz<2)
    {
        return;
    }
    for(int I=0;I<hossz;I++)
    {
        if(I==0)
        {
            printf("%c",fejlec_bal);
        }
        else if(I==hossz-1)
        {
            printf("%c",fejlec_jobb);
        }
        else
        {
            printf("%c",koz);
        }
    }
    printf("\n");
}
void keret_torzs_ures(int hossz)
{
    if(hossz<2)
    {
        return;
    }
    for(int I=0;I<hossz;I++)
    {
        if(I==0)
        {
            printf("%c",oszlop);
        }
        else if(I==hossz-1)
        {
            printf("%c",oszlop);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}
void keret_lablec(int hossz)
{
    if(hossz<2)
    {
        return;
    }
    for(int I=0;I<hossz;I++)
    {
        if(I==0)
        {
            printf("%c",lablec_bal);
        }
        else if(I==hossz-1)
        {
            printf("%c",lablec_jobb);
        }
        else
        {
            printf("%c",koz);
        }
    }
    printf("\n");
}
void keret_torzs_statikus(int hossz,char szoveg[],char tipus)
{
    if(hossz<2)
    {
        return;
    }
    int szoveg_hossz=strlen(szoveg);
    if(szoveg_hossz>hossz-2)
    {
        printf(">>>>>A MEGADOTT SZOVEG NEM FERT BELE A TORZSBE!<<<<<\n");
        return;
    }
    int ures=(hossz-2-szoveg_hossz);
    int maradek=0;
    printf("%c",oszlop);
    switch(tipus)
    {
        case 'B':
            if(ures>1)
            {
                ures--;
                printf(" ");
            }
            for(int N=0;N<szoveg_hossz;N++)
            {
                printf("%c",szoveg[N]);
            }
            for(int N=0;N<ures;N++)
            {
                printf(" ");
            }
            break;
        case 'K':
            if(ures%2!=0)
            {
                maradek++;
            }
            for(int N=0;N<ures/2;N++)
            {
                printf(" ");
            }
            for(int N=0;N<szoveg_hossz;N++)
            {
                printf("%c",szoveg[N]);
            }
            for(int N=0;N<ures/2+maradek;N++)
            {
                printf(" ");
            }
            break;
        case 'J':
            if(ures>1)
            {
                ures--;
            }
            for(int N=0;N<ures;N++)
            {
                printf(" ");
            }
            for(int N=0;N<szoveg_hossz;N++)
            {
                printf("%c",szoveg[N]);
            }
            printf(" ");
            break;
        default:
            for(int N=0;N<szoveg_hossz;N++)
            {
                printf("%c",szoveg[N]);
            }
            for(int N=0;N<ures;N++)
            {
                printf(" ");
            }
            printf("%c\n",oszlop);
            printf("^^^^^ERVENYTELEN SZOVEG IGAZITAS!^^^^^\n");
            return;
    }
    printf("%c\n",oszlop);
}
void szovegdoboz_statikus(int hossz,char szoveg[],char tipus)
{
    if(hossz<2)
    {
        printf(">>>>>ERVENYTELEN SZOVEGDOBOZ!<<<<<\n");
        return;
    }
    keret_fejlec(hossz);
    keret_torzs_statikus(hossz,szoveg,tipus);
    keret_lablec(hossz);
}
void keret_torzs_vonal(int hossz)
{
    if(hossz<2)
    {
        return;
    }
    for(int I=0;I<hossz;I++)
    {
        if(I==0)
        {
            printf("%c",keret_koz_bal);
        }
        else if(I==hossz-1)
        {
            printf("%c",keret_koz_jobb);
        }
        else
        {
            printf("%c",koz);
        }
    }
    printf("\n");
}
void vonal(int hossz,char ujsor)
{
    if(ujsor!='I'&&ujsor!='N')
    {
        printf(">>>>>\"UJSOR\" ERTEKE ERVENYTELEN!<<<<<\n");
        return;
    }
    for(int I=0;I<hossz;I++)
    {
        printf("%c",koz);
    }
    if(ujsor=='I')
    {
        printf("\n");
    }
}
