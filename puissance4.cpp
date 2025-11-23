/*
 * Fichier : puissance4.cpp
 * Auteur : Pierre BOUCKSON
 * Date : 16 Novembre 2025
 * Description : Implémentation du jeu de Puissance 4 en C++.
 */


#include <iostream>
#include <cstdlib>
#include <chrono> 
#include <thread>
#include <termios.h>
#include <unistd.h>
using namespace std;

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
		int update_buffer(int x, bool buffer_jeux[6][7]){
			for(int i=5;i>=0;--i){
				if(buffer_jeux[i][x] == 0){
					buffer[i][x]=1;
					return 0;
				}
			}
			return 0;
		}
		bool (&lire_buffer())[6][7] {
 		   return buffer;
		}
		bool check_victory()
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
		
					

		return 0;
		}



};

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

class IHM {
	private:


	public:
		int choose_line()
		{
			string touche;
			int choix = 0;
			touche = getch();
			if(touche=="z" || touche=="i") {choix = 10;};
			if(touche=="q" || touche=="j") {choix =-1;};
			if(touche=="d" || touche=="l") {choix =1;};

			return choix;
		}
};
class grille 
{
	private:
	
	public:
		void afficher_grille(bool buffer1[6][7], bool buffer2[6][7])
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
							if (buffer1[row][col])
								cout << "\x1b[31mO\x1b[0m";
							else if (buffer2[row][col])
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
		void afficher_choix(int choix, char cara)
		{
			cout << "    ********************    " << endl;
			cout << "    ***	             ***    " << endl;
			cout << "    *** PUISSANCE 4  ***    " << endl;
			cout << "    ***     by :     ***    " << endl;
			cout << "    *** Pierre       ***    " << endl;
			cout << "    ***     Bouckson ***    " << endl;
			cout << "    ***	             ***    " << endl;
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

};
int main()
{
	player player1;
	player player2;
	player jeux;
	grille my_grille;
	IHM my_ihm;
	int choix = 0;
	while(1)
	{
	system("clear");
	choix = 3;
	my_grille.afficher_choix(choix,'O');
	my_grille.afficher_grille(player1.lire_buffer(),player2.lire_buffer());
	while(choix < 10){
		choix += my_ihm.choose_line();
		if(choix < 0){choix=0;}
		if(choix > 6 && choix < 9){choix=6;}
		system("clear");
		my_grille.afficher_choix(choix,'O');
		my_grille.afficher_grille(player1.lire_buffer(), player2.lire_buffer());
	}
	player1.update_buffer(choix-10,jeux.lire_buffer());
	jeux.update_buffer(choix-10,jeux.lire_buffer());
	my_grille.afficher_grille(player1.lire_buffer(),player2.lire_buffer());
	if(player1.check_victory()){
		system("clear");
		my_grille.afficher_choix(0,'X');
		my_grille.afficher_grille(player1.lire_buffer(),player2.lire_buffer());
		cout << "\x1b[31m" <<"Player 1 WIN" << "\x1b[0m" << endl;
		while(1);
	}
	//Joueur 2
	system("clear");
	choix = 0;
	my_grille.afficher_choix(choix,'X');
	my_grille.afficher_grille(player1.lire_buffer(),player2.lire_buffer());
	while(choix < 10){
		choix += my_ihm.choose_line();
		if(choix < 0){choix=0;}
		if(choix > 6 && choix < 9){choix=6;}
		system("clear");
		my_grille.afficher_choix(choix,'X');
		my_grille.afficher_grille(player1.lire_buffer(), player2.lire_buffer());
	}
	player2.update_buffer(choix-10,jeux.lire_buffer());
	jeux.update_buffer(choix-10,jeux.lire_buffer());
	my_grille.afficher_grille(player1.lire_buffer(), player2.lire_buffer());
	if(player2.check_victory()){
		system("clear");
		my_grille.afficher_choix(0,'O');
		my_grille.afficher_grille(player1.lire_buffer(),player2.lire_buffer());
		cout << "\x1b[34m" <<"Player 2 WIN" << "\x1b[0m" << endl;
		while(1);
	}
	
	
	}	
}
