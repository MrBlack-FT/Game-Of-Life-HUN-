#include "ftfunctions.h"
#include "debugmalloc.h"
char **char_dinamikus2dtomb(int oszlop,int sor)
{
    char **tomb=(char**)malloc(oszlop*sor*sizeof(char));
    for(int I=0;I<sor;I++)
    {
        tomb[I]=(char*)malloc(oszlop*sizeof(char));
    }
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            tomb[I][N]='\0';
        }
    }
    return tomb;
}
void char_dinamikus2dtomb_torles(char **tomb,int oszlop,int sor)
{
    for(int I=0;I<sor;I++)
    {
        free(tomb[I]);
    }
    free(tomb);
}
void char_dinamikus2dtomb_random(char **tomb,int oszlop,int sor)
{
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            tomb[I][N]=(char)(rand()%223+32);
        }
    }
}
void char_dinamikus2dtomb_tisztitas(char **tomb,int oszlop,int sor)
{
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            tomb[I][N]='\0';
            //tomb[I][N]=BLOCK;
        }
    }
}
int **int_dinamikus2dtomb(int oszlop,int sor)
{
    int **tomb=(int**)malloc(oszlop*sor*sizeof(int));
    for(int I=0;I<sor;I++)
    {
        tomb[I]=(int*)malloc(oszlop*sizeof(int));
    }
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            tomb[I][N]=0;
        }
    }
    return tomb;
}
void int_dinamikus2dtomb_torles(int **tomb,int oszlop,int sor)
{
    for(int I=0;I<sor;I++)
    {
        free(tomb[I]);
    }
    free(tomb);
}
void int_dinamikus2dtomb_tisztitas(int **tomb,int oszlop,int sor)
{
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            tomb[I][N]=0;
        }
    }
}
void int_dinamikus2dtomb_random(int **tomb,int oszlop,int sor)
{
    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            tomb[I][N]=rand()%+2;
        }
    }
}
