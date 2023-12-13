#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verif_majus(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if ((!(isupper(ch[i]))) || (!((isalpha(ch[i]))))) {
            return 0;
        }
    }
    return 1;
}

void chiffrement_cesar(char ch[],int cle){
    //creation d'un tableau contien 2 fois l'alphabets
    char T[54];

    for (int i = 0; i < 26; i++) {
        T[i] = i + 65;
        T[i + 26] = i + 65;
    }

    // Modification du tableau selon la clé (décalage de 3 positions)
    for (int j = 0; j < cle; j++) {
        for (int i = 0; i < 53; i++) {
            T[i] = T[i + 1];
        }
    }

    //chiffrement de ch
    for(int i=0;i<strlen(ch);i++){
        ch[i] = T[ch[i] - 'A'];
    }
}

void dechiffrement_cesar(char ch[],int cle){
    char T[54];

    for (int i = 0; i < 26; i++) {
        T[i] = i + 65;
        T[i + 26] = i + 65;
    }

    // Modification du tableau selon la clé (décalage de 3 positions)
    for (int j = 0; j < cle; j++) {
        for (int i = 0; i < 53; i++) {
            T[i] = T[i + 1];
        }
    }

    //dechiffrement de ch
    for(int i=0;i<strlen(ch);i++){
        ch[i] = T[ch[i] + 'A'];
    }
}


int main() {
    char *ch = (char*)malloc(100 * sizeof(char));
    if (ch == NULL) {
        printf("Erreur d'allocation de m?moire");
        return 1;
    }

	//controle de saisie
	do{
		printf("Donnez une cha?ne majuscule : ");
    	gets(ch);fflush(stdin);
	}while(!(verif_majus(ch)));

    ch= (char*) realloc(ch,strlen(ch));
    if (ch == NULL) {
        printf("Erreur d'allocation de m?moire");
        return 1;
    }
	
	int cle;
	do{
		printf("Donnez un cle de chiffrement : ");
		scanf("%d",&cle);
	}while(!(1<cle<25));
	
    chiffrement_cesar(ch,cle);

	printf("Texte chiffre : %s \n",ch);

    dechiffrement_cesar(ch,cle);

    printf("Texte dechiffre : %s\n",ch);

	free(ch);

    return 0;
}

