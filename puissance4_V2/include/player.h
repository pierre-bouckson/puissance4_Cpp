#pragma once
#include "player.h"


class player {
        private:
                bool buffer[6][7] = {
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0}};


        public:
                int update_buffer(int x, bool buffer_jeux[6][7]);
                bool (&lire_buffer())[6][7] {
                   return buffer;
                }
                bool check_victory();
};
                