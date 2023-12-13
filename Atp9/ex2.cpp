#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct info
{
    char nom[200];
    char prenom[200];
    int age;
};

void remplir(struct info *player)
{
    printf("donner votre nom : ");
    scanf("%s",player->nom);

    printf("donner votre prenom : ");
    scanf("%s",player->prenom);

    printf("donner votre age : ");
    scanf("%d", &player->age);
}

const char* translate(int a){
    const char* res;
    if(a==0){
        res = "Pierre";
    }
    else if(a==1){
        res = "Papier";
    }
    else if(a==2){
        res = "Ciseaux";
    }
    return res;
}

const char* determiner_winner(int a,int b){
	const char* winner;
	if(a==0){
		if(b==0){
			winner="egalite";
		}
		else if(b==1){
			winner="l'ordinateur a gagner la manche";
		}
		else{
			winner="Bravo ! vous avez gagne";
		}
	}
	else if(a==1){
		if(b==0){
			winner="Bravo ! vous avez gagne";
		}
		else if(b==1){
			winner="egalite";
		}
		else{
			winner="l'ordinateur a gagner la manche";
		}
	}
	else{
		if(b==0){
			winner="l'ordinateur a gagner la manche";
		}
		else if(b==1){
			winner="Bravo ! vous avez gagne";
		}
		else{
			winner="egalite";
		}
	}
}

int main() {
    struct info joueur;
    remplir(&joueur);

    int m;
    printf("donner le nombre de manches : ");
    scanf("%d", &m);
    int stat[3];
    for(int i=0;i<3;i++){
    	stat[i]=0;
	}
	int choix_user;
	for(int i=0; i<m; i++){
        printf("-------------------------------------\n");
        printf("-------------- Manche %d --------------\n", i+1);
        printf("-------------------------------------\n");
        do{
        	printf("choisissez entre Pierre(0), Papier(1) et Ciseaux(2) : ");
        	scanf("%d", &choix_user);
		}while(!(0<=choix_user<=2));
        printf("%s %s a choisi : %s \n", joueur.prenom, joueur.nom, translate(choix_user));
		int choix_ordi = rand() % 3;
        printf("l'ordinateur a choisi : %s\n", translate(choix_ordi));
        printf("%s \n",determiner_winner(choix_user,choix_ordi));
        printf("-------------------------------------\n");
        
		if ((determiner_winner(choix_user,choix_ordi)) == "egalite"){
			stat[0]++;
		}
		else if ((determiner_winner(choix_user,choix_ordi)) == "Bravo ! vous avez gagne"){
			stat[1]++;
		}
		else if ((determiner_winner(choix_user,choix_ordi)) == "l'ordinateur a gagner la manche"){
			stat[2]++;
		}
    }
	printf("vous avez gagne %d fois \n",stat[1]);
	printf("l'ordinateur a gagne %d fois \n",stat[2]);
	printf("egalite %d fois \n",stat[0]);
}

