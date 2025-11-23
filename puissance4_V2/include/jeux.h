#pragma once

class jeux {
    private:
        int buffer[6][7] = {0};
    
    public:
        int update_buffer(int x, int id);
        int (&lire_buffer())[6][7] {
            return buffer;
        }
        bool check_victory();
};