#include "grille.h"

void grille::afficher_grille(int buffer1[6][7])
{
    cout << endl;
    for (int i = 0; i < 13; ++i) {
            if (i % 2 == 0) {
                    for (int j = 0; j < 29; ++j)
                            cout << (j % 4 == 0 ? "+" : "-");
            } else {
                    int row = i / 2;
                    for (int j = 0; j < 29; ++j) {
                            if (j % 4 == 2) {
                                    int col = j / 4;      // 0..6
                                    if (buffer1[row][col]==1)
                                            cout << "\x1b[31mO\x1b[0m";
                                    else if (buffer1[row][col]==2)
                                            cout << "\x1b[34mX\x1b[0m";
                                    else
                                            cout << " ";
                            } else if (j % 4 == 0) {
                                    cout << "|";
                            } else {
                                    cout << " ";
                            }
                    }
            }
            cout << endl;
    }
    cout << endl;
}

void grille::afficher_choix(int choix, char cara)
{
        cout << "    ********************    " << endl;
        cout << "    ***                     ***    " << endl;
        cout << "    *** PUISSANCE 4  ***    " << endl;
        cout << "    ***     by :     ***    " << endl;
        cout << "    *** Pierre       ***    " << endl;
        cout << "    ***     Bouckson ***    " << endl;
        cout << "    ***                     ***    " << endl;
        cout << "    ********************    " << endl;
        for(int i=0;i<29;i++){
                if(i==choix*4 + 2)
                {
                        if(cara == 'X'){
                                cout << "\x1b[34m" << "X" << "\x1b[0m" << endl;
                        }
                        if(cara == 'O'){
                                cout << "\x1b[31m" << "O" << "\x1b[0m" << endl;
                        }
                        for(int j=0;j<i;j++){cout << " ";}
                        cout << "|" << endl;
                        for(int j=0;j<i;j++){cout << " ";}
                        cout << "v" << endl;

                }
                else{cout << " ";}
        }
}