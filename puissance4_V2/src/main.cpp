#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>

#include "IHM.h"
#include "grille.h"
#include "player.h"
#include "jeux.h"
#include "ia_easy.h"

int main()
{
	jeux my_jeux;
	grille my_grille;
	IHM my_ihm;
	ia_easy my_ia_easy;
	int choix = 0;
	while(1)
	{
		system("clear");
		choix = 3;
		my_grille.afficher_choix(choix,'O');
		my_grille.afficher_grille(my_jeux.lire_buffer());
		while(choix < 10){
				choix += my_ihm.choose_line();
				if(choix < 0){choix=0;}
				if(choix > 6 && choix < 9){choix=6;}
				system("clear");
				my_grille.afficher_choix(choix,'O');
				my_grille.afficher_grille(my_jeux.lire_buffer());
		}
		my_jeux.update_buffer(choix-10,1);
		my_grille.afficher_grille(my_jeux.lire_buffer());
		if(my_jeux.check_victory()){
				system("clear");
				my_grille.afficher_choix(0,'X');
				my_grille.afficher_grille(my_jeux.lire_buffer());
				cout << "\x1b[31m" <<"Player 1 WIN" << "\x1b[0m" << endl;
				while(1);
		}
		choix = my_ia_easy.check_V_in_1(my_jeux.lire_buffer());
		my_jeux.update_buffer(choix,2);
		if(my_jeux.check_victory()){
				system("clear");
				my_grille.afficher_choix(0,'X');
				my_grille.afficher_grille(my_jeux.lire_buffer());
				cout << "\x1b[31m" <<"Player 1 WIN" << "\x1b[0m" << endl;
				while(1);
		}


		
	}
}

/*int main()
{
	jeux my_jeux;
	grille my_grille;
	IHM my_ihm;
	int choix = 0;
	while(1)
	{
		system("clear");
		choix = 3;
		my_grille.afficher_choix(choix,'O');
		my_grille.afficher_grille(my_jeux.lire_buffer());
		while(choix < 10){
				choix += my_ihm.choose_line();
				if(choix < 0){choix=0;}
				if(choix > 6 && choix < 9){choix=6;}
				system("clear");
				my_grille.afficher_choix(choix,'O');
				my_grille.afficher_grille(my_jeux.lire_buffer());
		}
		my_jeux.update_buffer(choix-10,1);
		my_grille.afficher_grille(my_jeux.lire_buffer());
		if(my_jeux.check_victory()){
				system("clear");
				my_grille.afficher_choix(0,'X');
				my_grille.afficher_grille(my_jeux.lire_buffer());
				cout << "\x1b[31m" <<"Player 1 WIN" << "\x1b[0m" << endl;
				while(1);
		}
		//Joueur 2
		system("clear");
		choix = 3;
		my_grille.afficher_choix(choix,'X');
		my_grille.afficher_grille(my_jeux.lire_buffer());
		while(choix < 10){
				choix += my_ihm.choose_line();
				if(choix < 0){choix=0;}
				if(choix > 6 && choix < 9){choix=6;}
				system("clear");
				my_grille.afficher_choix(choix,'X');
				my_grille.afficher_grille(my_jeux.lire_buffer());
		}
		my_jeux.update_buffer(choix-10,2);
		my_grille.afficher_grille(my_jeux.lire_buffer());
		if(my_jeux.check_victory()){
				system("clear");
				my_grille.afficher_choix(0,'O');
				my_grille.afficher_grille(my_jeux.lire_buffer());
				cout << "\x1b[34m" <<"Player 2 WIN" << "\x1b[0m" << endl;
				while(1);
		}
	}
	return 0;
}
*/


