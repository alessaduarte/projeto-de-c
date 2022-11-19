#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void tabuleiro (char local[3][3]) {
	system("cls");
	printf("\t %c | %c | %c \n", local[0][0], local[0][1], local[0][2]);
	printf("\t - - - - - \n");
	printf("\t %c | %c | %c \n", local[1][0], local[1][1], local[1][2]);
	printf("\t - - - - - \n");
	printf("\t %c | %c | %c \n", local[2][0], local[2][1], local[2][2]);
}
int main () {
	int i, j;
	int l, c;
	int vez;
	int cont_jogadas;
	char res;
	
	setlocale (LC_ALL, "Portuguese");
	
	char local[3][3] = {
		{'1', '2', '3'},
		{'1', '2', '3'},
		{'1', '2', '3'}, };
	
	do {
		cont_jogadas = 1;
		
		for (i = 0; i <= 2; i++) {
			for (j = 0; j <= 2; j++) {
				local[i][j] = ' '; 
			}
		}
		do {
			tabuleiro(local);
			
			if (vez%2==0) {
				printf("Jogador X \n");
			}
			else {
				printf("Jogador O \n");
			}
			
			printf("Digite a linha na qual a peça está localizada:");
			scanf("%i", &l);
			printf("Digite a coluna na qual a peça está localizada:");
			scanf("%i", &c);
			
			if (l < 1 || c < 1 || 1 > 3 || c > 3) {
				l = 0;
				c = 0;
			} else if (local[l - 1][c - 1] != ' ') {
				l = 0;
				c = 0;
			} else {
				if (vez%2 == 0) {
					local[l - 1][c - 1] = 'X';
				}
				else {
					local[l - 1][c - 1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			
			// Condições de Vitória X
			if (local[0][0]=='X' && local[0][1]=='X' && local[0][2]=='X') {
				cont_jogadas = 11;
			}
			if (local[1][0]=='X' && local[1][1]=='X' && local[1][2]=='X') {
				cont_jogadas = 11;
			}
			if (local[2][0]=='X' && local[2][1]=='X' && local[2][2]=='X') {
				cont_jogadas = 11;
			}
			if (local[0][0]=='X' && local[1][0]=='X' && local[2][0]=='X') {
				cont_jogadas = 11;
			}
			if (local[0][1]=='X' && local[1][1]=='X' && local[2][1]=='X') {
				cont_jogadas = 11;
			}
			if (local[0][2]=='X' && local[1][2]=='X' && local[2][2]=='X') {
				cont_jogadas = 11;
			}
			if (local[0][0]=='X' && local[1][1]=='X' && local[2][2]=='X') {
				cont_jogadas = 11;
			}
			if (local[0][2]=='X' && local[1][1]=='X' && local[2][0]=='X') {
				cont_jogadas = 11;
			}
			
			// Condições de Vitória O
			if (local[0][0]=='O' && local[0][1]=='O' && local[0][2]=='O') {
				cont_jogadas = 12;
			}
			if (local[1][0]=='O' && local[1][1]==')' && local[1][2]=='O') {
				cont_jogadas = 12;
			}
			if (local[2][0]=='O' && local[2][1]=='O' && local[2][2]=='O') {
				cont_jogadas = 12;
			}
			if (local[0][0]=='O' && local[1][0]=='O' && local[2][0]=='O') {
				cont_jogadas = 12;
			}
			if (local[0][1]=='O' && local[1][1]=='O' && local[2][1]=='O') {
				cont_jogadas = 12;
			}
			if (local[0][2]=='O' && local[1][2]=='O' && local[2][2]=='O') {
				cont_jogadas = 12;
			}
			if (local[0][0]=='O' && local[1][1]=='O' && local[2][2]=='O') {
				cont_jogadas = 12;
			}
			if (local[0][2]=='O' && local[1][1]=='O' && local[2][0]=='O') {
				cont_jogadas = 12;
			}
		} while(cont_jogadas <= 9);
		tabuleiro(local);
		
		if (cont_jogadas==10) {
			printf("Empate");
		}
		else if (cont_jogadas==11) {
			printf("O Jogador X venceu!\n");
		}
		else if (cont_jogadas==12) {
			printf("O Jogador O venceu!\n");
		}
		else {
			printf("Não foi possivel definir um vencedor.");
		}
		printf("Gostaria de iniciar um novo jogo? [S/N]");
		scanf("%s", &res);
	} while (res == 'S' || res == 's');
}

