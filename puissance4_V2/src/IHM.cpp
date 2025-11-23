#include "IHM.h"

char getch() {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);         // lire config terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);       // désactiver mode canonique et echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // appliquer
    char c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaurer
    return c;
}

int IHM::choose_line()
{
    string touche;
    int choix = 0;
    touche = getch();
    if(touche=="z" || touche=="i") {choix = 10;};
    if(touche=="q" || touche=="j") {choix =-1;};
    if(touche=="d" || touche=="l") {choix =1;};

    return choix;
}



