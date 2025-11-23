#include "player.h"

int player::update_buffer(int x, bool buffer_jeux[6][7]){
        for(int i=5;i>=0;--i){
                if(buffer_jeux[i][x] == 0){
                        buffer[i][x]=1;
                        return 0;
                }
        }
        return 0;
}
bool player::check_victory()
{
        int cons_h = 0;
        int cons_v = 0;
        //Hozizontal
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
        //Vertical
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
        //Diagonal '/'
        for(int i=3;i<6;i++)
        {
                for(int j=0;j<7-4;j++){
                        if(buffer[i][j]==1){
                                if(buffer[i-1][j+1]==1 && buffer[i-2][j+2]==1
                                && buffer[i-3][j+3]==1)
                                {return 1;}
                        }
                }
        }
        //Diagonal '\'
        for(int i=0;i<6-4;i++)
        {
                for(int j=0;j<7-4;j++){
                        if(buffer[i][j]==1){
                                if(buffer[i+1][j+1]==1 && buffer[i+2][j+2]==1
                                && buffer[i+3][j+3]==1)
                                {return 1;}
                        }
                }
        }
}


                        