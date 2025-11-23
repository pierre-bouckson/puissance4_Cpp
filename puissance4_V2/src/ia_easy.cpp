#include "ia_easy.h"

int ia_easy::check_V_in_1(int buffer[6][7])
{

    for(int k=0;k<7;k++)
    {
        for(int i=5;i>=0;--i){
                if(buffer[i][k] == 0){
                        buffer[i][k] = 1;
                        int q = i;
                        int cons_h = 0;
                        int cons_v = 0;
                        //Hozizontal O
                        for(int i=0;i<6;i++)
                        {
                                for(int j=0;j<7;j++){
                                        if(buffer[i][j] == 1){
                                                cons_h++;
                                        }else{cons_h=0;}
                                        if(cons_h==4){
                                                buffer[q][k] = 0;
                                                return k;
                                        }
                                }
                                cons_h = 0;
                        }
                        //Hozizontal X
                        for(int i=0;i<6;i++)
                        {
                                for(int j=0;j<7;j++){
                                        if(buffer[i][j] == 2){
                                                cons_h++;
                                        }else{cons_h=0;}
                                        if(cons_h==4){
                                                buffer[q][k] = 0;
                                                return k;
                                        }
                                }
                                cons_h = 0;
                        }
                        //Vertical O
                        for(int j=0;j<7;j++)
                        {
                                for(int i=0;i<6;i++){
                                        if(buffer[i][j] == 1){
                                                cons_v++;
                                        }else{cons_v=0;}
                                        if(cons_v==4){
                                                buffer[q][k] = 0;
                                                return k;
                                        }
                                }
                                cons_v = 0;
                        }
                        //Vertical X
                        for(int j=0;j<7;j++)
                        {
                                for(int i=0;i<6;i++){
                                        if(buffer[i][j] == 2){
                                                cons_v++;
                                        }else{cons_v=0;}
                                        if(cons_v==4){
                                                buffer[q][k] = 0;
                                                return k;
                                        }
                                }
                                cons_v = 0;
                        }
                        //Diagonal '/' O
                        for(int i=3;i<=6;i++)
                        {
                                for(int j=0;j<=7-4;j++){
                                        if(buffer[i][j]==1){
                                                if(buffer[i-1][j+1]==1 && buffer[i-2][j+2]==1
                                                && buffer[i-3][j+3]==1)
                                                {buffer[q][k] = 0;
                                                return k;}
                                        }
                                }
                        }
                        //Diagonal '/' X
                        for(int i=3;i<=6;i++)
                        {
                                for(int j=0;j<=7-4;j++){
                                        if(buffer[i][j]==2){
                                                if(buffer[i-1][j+1]==2 && buffer[i-2][j+2]==2
                                                && buffer[i-3][j+3]==2)
                                                {buffer[q][k] = 0;
                                                return k;}
                                        }
                                }
                        }
                        //Diagonal '\' O
                        for(int i=0;i<=6-4;i++)
                        {
                                for(int j=0;j<=7-4;j++){
                                        if(buffer[i][j]==1){
                                                if(buffer[i+1][j+1]==1 && buffer[i+2][j+2]==1
                                                && buffer[i+3][j+3]==1)
                                                {buffer[q][k] = 0;
                                                return k;}
                                        }
                                }
                        }
                        //Diagonal '\' X
                        for(int i=0;i<=6-4;i++)
                        {
                                for(int j=0;j<=7-4;j++){
                                        if(buffer[i][j]==2){
                                                if(buffer[i+1][j+1]==2 && buffer[i+2][j+2]==2
                                                && buffer[i+3][j+3]==2)
                                                {buffer[q][k] = 0;
                                                return k;}
                                        }
                                }
                        }
                        buffer[q][k] = 0;
                }
    }
    }
    srand(time(NULL));   // seed variable selon l’heure
    return int(rand()%3);

}