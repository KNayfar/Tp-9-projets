#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];  // variable globale

void board_guide(){
	printf("7 | 8 | 9 \n");
	printf("----------\n");
	printf("4 | 5 | 6 \n");
	printf("----------\n");
	printf("1 | 2 | 3 \n");
}

void init_board(){
    board[0][0]=' ';board[0][1]=' ';board[0][2]=' ';
    board[1][0]=' ';board[1][1]=' ';board[1][2]=' ';
    board[2][0]=' ';board[2][1]=' ';board[2][2]=' ';
}

void print_board(){
	printf("%c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
	printf("----------\n");
	printf("%c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
	printf("----------\n");
	printf("%c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

int case_vide(int l, int c) {
    if (board[l][c] == ' ') {
        return 1;
    } else {
        return 0;
    }
}

void update_board_X(int i){
	if(i==1){
		board[2][0]='X';
	}
	if(i==2){
		board[2][1]='X';
	}
	if(i==3){
		board[2][2]='X';
	}
	if(i==4){
		board[1][0]='X';
	}
	if(i==5){
		board[1][1]='X';
	}
	if(i==6){
		board[1][2]='X';
	}
	if(i==7){
		board[0][0]='X';
	}
	if(i==8){
		board[0][1]='X';
	}
	if(i==9){
		board[0][2]='X';
	}
}
void update_board_O(int i){
	if(i==1){
		board[2][0]='O';
	}
	if(i==2){
		board[2][1]='O';
	}
	if(i==3){
		board[2][2]='O';
	}
	if(i==4){
		board[1][0]='O';
	}
	if(i==5){
		board[1][1]='O';
	}
	if(i==6){
		board[1][2]='O';
	}
	if(i==7){
		board[0][0]='O';
	}
	if(i==8){
		board[0][1]='O';
	}
	if(i==9){
		board[0][2]='O';
	}
}

int translate_ligne(int case_ordi){
	if( (case_ordi)==7 || (case_ordi)==8 || (case_ordi)==9 ){
		return 0;
	}
	else if ( (case_ordi)==4 || (case_ordi)==5 || (case_ordi)==6 ){
		return 1;
	}
	else if ( (case_ordi)==1 || (case_ordi)==2 || (case_ordi)==3 ){
		return 2;
	}
}
int translate_colone(int case_ordi){
	if( (case_ordi)==0 || (case_ordi)==4 || (case_ordi)==1 ){
		return 0;
	}
	else if ( (case_ordi)==8 || (case_ordi)==5 || (case_ordi)==2 ){
		return 1;
	}
	else if ( (case_ordi)==9 || (case_ordi)==6 || (case_ordi)==3 ){
		return 2;
	}
}

int check_win();
int check_loss();

int generate_move(int difficulty){
    if (difficulty == 1) {
        // Niveau facile : mouvement aléatoire
        return ((rand() % 9) + 1);
    } else if (difficulty == 2) {
        // Niveau intermédiaire : prévenir la victoire de l'adversaire si possible
        for (int i = 1; i <= 9; i++) {
            int l = translate_ligne(i);
            int c = translate_colone(i);
            if (case_vide(l, c)) {
                // Vérifier si l'adversaire gagnera en occupant cette case
                board[l][c] = 'O';
                if (check_loss()) {
                    board[l][c] = ' ';
                    return i;
                }
                board[l][c] = ' ';
            }
        }
        // Sinon, mouvement aléatoire
        return ((rand() % 9) + 1);
    } else if (difficulty == 3) {
        // Niveau difficile : bloquer la victoire de l'adversaire ou gagner si possible
        for (int i = 1; i <= 9; i++) {
            int l = translate_ligne(i);
            int c = translate_colone(i);
            if (case_vide(l, c)) {
                // Vérifier si l'ordinateur gagnerait en occupant cette case
                board[l][c] = 'X';
                if (check_win()) {
                    board[l][c] = ' ';
                    return i;
                }
                board[l][c] = ' ';
                // Vérifier si l'adversaire gagnerait en occupant cette case
                board[l][c] = 'O';
                if (check_loss()) {
                    board[l][c] = ' ';
                    return i;
                }
                board[l][c] = ' ';
            }
        }
        // Sinon, mouvement aléatoire
        return ((rand() % 9) + 1);
    }
    return ((rand() % 9) + 1); // Par défaut, mouvement aléatoire
}
	
int check_win(){
	
	if((board[0][0]=='X') && (board[0][1]=='X') && (board[0][2]=='X') ){
		return 1;
	}
	else if ((board[1][0]=='X') && (board[1][1]=='X') && (board[1][2]=='X') ){
		return 1;
	}
	else if ((board[2][0]=='X') && (board[2][1]=='X') && (board[2][2]=='X') ){
		return 1;
	}
	
	else if ((board[0][0]=='X') && (board[1][0]=='X') && (board[2][0]=='X') ){
		return 1;
	}
	else if ((board[0][1]=='X') && (board[1][1]=='X') && (board[2][1]=='X') ){
		return 1;
	}
	else if ((board[0][2]=='X') && (board[1][2]=='X') && (board[2][2]=='X') ){
		return 1;
	}
	
	else if ((board[0][0]=='X') && (board[1][1]=='X') && (board[2][2]=='X') ){
		return 1;
	}
	else if ((board[0][2]=='X') && (board[1][1]=='X') && (board[2][0]=='X') ){
		return 1;
	}
	
	else{
		return 0;
	}
}
int check_loss(){
	
	if((board[0][0]=='O') && (board[0][1]=='O') && (board[0][2]=='O') ){
		return 1;
	}
	else if ((board[1][0]=='O') && (board[1][1]=='O') && (board[1][2]=='O') ){
		return 1;
	}
	else if ((board[2][0]=='O') && (board[2][1]=='O') && (board[2][2]=='O') ){
		return 1;
	}
	
	else if ((board[0][0]=='O') && (board[1][0]=='O') && (board[2][0]=='O') ){
		return 1;
	}
	else if ((board[0][1]=='O') && (board[1][1]=='O') && (board[2][1]=='O') ){
		return 1;
	}
	else if ((board[0][2]=='O') && (board[1][2]=='O') && (board[2][2]=='O') ){
		return 1;
	}
	
	else if ((board[0][0]=='O') && (board[1][1]=='O') && (board[2][2]=='O') ){
		return 1;
	}
	else if ((board[0][2]=='O') && (board[1][1]=='O') && (board[2][0]=='O') ){
		return 1;
	}
	
	else{
		return 0;
	}
}

void restart();

void jeu(){
    init_board();
    int case_user, case_ordi,difficulte;
    printf("\nChoisissez le niveau de difficulte (1: Facile, 2: Intermediaire, 3: Difficile) : ");
    scanf("%d", &difficulte);
    int k;
	for(k=0; k<4; k++){
    	printf("\n choisir une case : ");
    	scanf("%d", &case_user);
    	update_board_X(case_user);
    	print_board();
    	int l,c;
		do{
    		case_ordi = generate_move(difficulte);
    		l = translate_ligne(case_ordi);
    		c = translate_colone(case_ordi);
		} while ((case_vide(l, c))==0);
		if(check_win()==1){
			printf("\nBravo ! vous avez gagne\n");
			restart();
			break;
		}
		printf("\nl'ordinateur a choisi la case N° %d \n\n", case_ordi);
		update_board_O(case_ordi);
		print_board();
		if(check_loss()==1){
			printf("\nl'ordinateur a gagner\n");
			restart();
			break;
		}
	}
	if(k==4){
		printf("\negalite\n");
		restart();
		}
}

void restart(){
	char restart[3]="";
		printf("\nest ce que vous voulez rejouer ? (oui/non) : ");fflush(stdin);
		gets(restart);
		if (strcmp(restart, "oui") == 0) {
        jeu();
        }
        else{
        	printf("ok :'(");
		}
}

int main() {
    printf("bienvenue au jeu Tic-tac-Toe\nvous pouvez choisir la case à occuper en tappant sur le 'numpad' de la façon suivante :\n\n");
	board_guide();
	jeu();
	return 0;
}

