#pragma once
#include <iostream>
#include <cstdlib>
#include <thread>
#include <termios.h>
#include <unistd.h>

using namespace std;



class IHM {
        public:
                int choose_line();
};
