#include "eletjatek.h"
#include "debugmalloc.h"
void vilag_frissites(int **vilag_jelen,int **vilag_jovo,int oszlop,int sor)
{
    //SZOMSZEDOK BEALLITASA
    int kornyezet_bal_felso=0;
    int kornyezet_bal_kozep=0;
    int kornyezet_bal_also=0;
    int kornyezet_kozep_felso=0;
    int kornyezet_kozep_also=0;
    int kornyezet_jobb_felso=0;
    int kornyezet_jobb_kozep=0;
    int kornyezet_jobb_also=0;

    for(int I=0;I<sor;I++)
    {
        for(int N=0;N<oszlop;N++)
        {
            kornyezet_bal_felso=0;
            kornyezet_bal_kozep=0;
            kornyezet_bal_also=0;
            kornyezet_kozep_felso=0;
            kornyezet_kozep_also=0;
            kornyezet_jobb_felso=0;
            kornyezet_jobb_kozep=0;
            kornyezet_jobb_also=0;
            //HATARON KIESES KORRIGALASA
            //BAL HATAR
            if(!(N-1<0))
            {
                kornyezet_bal_kozep=vilag_jelen[I][N-1];
                //FELSO HATAR
                if(!(I-1<0))
                {
                    kornyezet_bal_felso=vilag_jelen[I-1][N-1];
                    kornyezet_kozep_felso=vilag_jelen[I-1][N];
                }
                //ALSO HATAR
                if(!(I==sor-1))
                {
                    kornyezet_bal_also=vilag_jelen[I+1][N-1];
                    kornyezet_kozep_also=vilag_jelen[I+1][N];
                }
            }
            //JOBB HATAR
            //if(!(N+1>oszlop))
            if(!(N==oszlop-1))
            {
                kornyezet_jobb_kozep=vilag_jelen[I][N+1];
                //FELSO HATAR
                if(!(I-1<0))
                {
                    kornyezet_jobb_felso=vilag_jelen[I-1][N+1];
                    kornyezet_kozep_felso=vilag_jelen[I-1][N];
                }
                //ALSO HATAR
                if(!(I==sor-1))
                {
                    kornyezet_jobb_also=vilag_jelen[I+1][N+1];
                    kornyezet_kozep_also=vilag_jelen[I+1][N];
                }
            }
            //SZOMSZED SZAMLALAS
            int szomszed_db=0;
            if(kornyezet_kozep_felso==1)        szomszed_db++;
            if(kornyezet_bal_kozep==1)          szomszed_db++;
            if(kornyezet_jobb_kozep==1)         szomszed_db++;
            if(kornyezet_kozep_also==1)         szomszed_db++;
            if(kornyezet_bal_felso==1)          szomszed_db++;
            if(kornyezet_jobb_felso==1)         szomszed_db++;
            if(kornyezet_bal_also==1)           szomszed_db++;
            if(kornyezet_jobb_also==1)          szomszed_db++;

            //1.SZABALY
            if(vilag_jelen[I][N]==1)
            {
                if(szomszed_db==2||szomszed_db==3)
                {
                    vilag_jovo[I][N]=1;
                }
                //2.SZABALY
                else
                {
                    vilag_jovo[I][N]=0;
                }
            }
            //3.SZABALY
            else if(szomszed_db==3)
            {
                vilag_jovo[I][N]=1;
            }
        }
    }
}
