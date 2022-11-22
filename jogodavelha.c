#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


// Função que chama o tabuleiro

void tabuleiro (char local[3][3]) {
	system("cls");
	printf(" 	      1   2   3\n");
	printf("\t    -------------\n");
	printf("\t 1  | %c | %c | %c |\n", local[0][0], local[0][1], local[0][2]);
	printf("\t    -------------\n");
	printf("\t 2  | %c | %c | %c |\n", local[1][0], local[1][1], local[1][2]);
	printf("\t    -------------\n");
	printf("\t 3  | %c | %c | %c |\n", local[2][0], local[2][1], local[2][2]);
	printf("\t    -------------\n");
}
int main () {
	int i, j;
	int l, c;
	int vez;
	int cont_jogadas;
	char res;
	char jogador1[50], jogador2[50];
	
	setlocale (LC_ALL, "Portuguese");
	
	// Nomes dos jogadores
	
	printf("Digite o nome do Jogador X: ");
	fgets(jogador1,50,stdin);
	printf("Digite o nome do Jogador O: ");
	fgets(jogador2,50,stdin);
	
	//Matriz que vai receber a função tabuleiro
	
	
	char local[3][3] = {
		{'1', '2', '3'},
		{'1', '2', '3'},
		{'1', '2', '3'}, };
	
	do {
		cont_jogadas = 1;
		
		//Entrada - ler os 9 caracteres e guardar na matriz local 3 x 3
		
		for (i = 0; i <= 2; i++) {
			for (j = 0; j <= 2; j++) {
				local[i][j] = ' '; 
			}
		}
		do {
			tabuleiro(local);
			
			// Mostra a vez do jogador
			
			if (vez%2==0) {
				printf("\nJogador X: %s\n",jogador1);
			}
			else {
				printf("\nJogador O: %s\n",jogador2);
			}
			
			printf("Digite a linha na qual a peça está localizada: ");
			scanf("%i", &l);
			printf("\nDigite a coluna na qual a peça está localizada: ");
			scanf("%i", &c);
			
			
			// Condições para uma jogada ser inválida 
			
			if (l < 1 || c < 1 || l > 3 || c > 3) {
				l = 0;
				c = 0;
			} else if (local[l - 1][c - 1] != ' ') {
				l = 0;
				c = 0;
			vez++;
			cont_jogadas++;
			
			// Jogadas válidas
			
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
			if (local[1][0]=='O' && local[1][1]=='O' && local[1][2]=='O') {
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
		
		// resultado do jogo
		
		if (cont_jogadas==10) {
			printf("\nEmpate");
		}
		else if (cont_jogadas==11) {
			printf("%sVenceu!\n",jogador1);
		}
		else if (cont_jogadas==12) {
			printf("%sVenceu!\n",jogador2);
		}
		else {
			printf("Não foi possivel definir um vencedor.");
		}
		printf("Gostaria de iniciar um novo jogo? [S/N]");
		scanf("%s", &res);
	} while (res == 's');
}
