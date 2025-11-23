#include "jeux.h"

int jeux::update_buffer(int x, int id){
        for(int i=5;i>=0;--i){
                if(buffer[i][x] == 0){
                        buffer[i][x] = id;
                        return 0;
                }
        }
        return 0;
}

bool jeux::check_victory()
{
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
                                return 1;
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
                                return 1;
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
                                return 1;
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
                                return 1;
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
                                {return 1;}
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
                                {return 1;}
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
                                {return 1;}
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
                                {return 1;}
                        }
                }
        }
        return 0;
}


                        