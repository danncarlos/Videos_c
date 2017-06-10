#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<locale.h>
#define clear;	system("cls");
#define flush;	fflush(stdin);
#define line;	puts("\n\n");
#define A	97
#define W	119
#define S	115	
#define D	100
	/*
		Mini Game interpretativo sobre hábito
	*/
	// 1º 35+20+12-7+4+7+9-32+24+1+4+21-14-2-7-19+4-2 = 58
	void local(void);
	void arrow(void);
	int gold = 0;
	int pk;
	int mat[10][10];
	int i, l, c, pk, x = 0, y = 0;
	
main(){
	srand(time(NULL));
	local();
	for(l=0;l<10;l++){
		for(c=0;c<10;c++){
			mat[l][c] = rand() % 99+2;
			{	//if's
				
				if(l == 0 & c == 0){
					mat[l][c] = 1;
				}
				if(l == 0 & c == 1){
					mat[l][c] = 35;
				}
				if(l == 1 & c == 1){
					mat[l][c] = 20;
				}
				if(l == 1 & c == 2){
					mat[l][c] = 12;
				}			
				if(l == 2 & c == 2){
					mat[l][c] = -7;
				}
				if(l == 2 & c == 3){
					mat[l][c] = 4;
				}	
				if(l == 3 & c == 3){
					mat[l][c] = 7;
				}
				if(l == 3 & c == 4){
					mat[l][c] = 9;
				}
				if(l == 4 & c == 4){
					mat[l][c] = -32;
				}
				if(l == 4 & c == 5){
					mat[l][c] = 24;
				}
				if(l == 5 & c == 5){
					mat[l][c] = 1;
				}			
				if(l == 5 & c == 6){
					mat[l][c] = 4;
				}			
				if(l == 6 & c == 6){
					mat[l][c] = 21;
				}
				if(l == 6 & c == 7){
					mat[l][c] = -14;
				}
				if(l == 7 & c == 7){
					mat[l][c] = -2;
				}			
				if(l == 7 & c == 8){
					mat[l][c] = -7;
				}			
				if(l == 8 & c == 8){
					mat[l][c] = -19;
				}			
				if(l == 8 & c == 9){
					mat[l][c] = 4;
				}			
				if(l == 9 & c == 9){
					mat[l][c] = -2;
				}
			}
			
			
		}
	}
	puts("Missão: Conclua a masmora utilizando sua mítica Rotina.");
	puts("Sua mítica rotina, tem como gatilho, sua vontade por gold, e sua rotina, consite\n"
	"em explorar novas masmorras diáriamente.");
	puts("\n\n");
	printf("Gatilho: Gold\n");
	printf("Rotina: Explorar novas Masmorras todos os dias\n");
	printf("Recompensa: Bem estar // Conhecer novos locais // Não Morrer preso em uma Masmorra\n");
	puts("Precione qualquer tecla para continuar...");
	getch();
	clear;
	
	for(;;){
	puts("1 - Indica sua posição");
	puts("Seu dever é proseguir como nossa Rotina");
	puts("Chegar no ponto mais distante da masmora, somando 58 de Gold NADA A MAIS ou a MENOS\n pois isso quebraria sua rotina");
	printf("Use: W - Cima, S - Baixo, A - Esquerda, D - Direita\n");
	puts("\n\n");
	printf("Start\n");
	printf(" v\n");
		for(l=0;l<10;l++){
			for(c=0;c<10;c++){
				printf("[%02i]", mat[l][c]);	
			}
			if(l == 9){
				printf(" < FIM");				
			}
			printf("\n");
		}
		printf("\nX: %i Y: %i \t\t Gold: %i\n", x, y, gold);
		arrow();
		clear;
		
	}
	getch();
	return 0;
}

arrow(){
	pk = _getch();
	if(pk == A){
		mat[x][y] = 0;
		y--;
		gold+=mat[x][y];
		mat[x][y] = 1;
		if(y>9 || x >9 || x<0 || y<0){
			puts("AHHH... Emboscada dos vampiros...");
			puts("Aparentemente você era saboroso demais para se torna um vampiro...\n"
			"De toda forma não conquistou seu objetivo");
			puts("Você não seguiu a rotina...");
			getch();
			exit(1);
		}
		
	}
	else if(pk == W){
		mat[x][y] = 0;
		x--;
		gold+=mat[x][y];
		mat[x][y] = 1;
		if(x>9 || y>9 || x<0 || y<0){
			puts("AHHH... Armadilhas...");
			puts("Você não seguiu a rotina...");
			getch();
			exit(1);
		}	
	}
	else if(pk == S){
		mat[x][y] = 0;
		x++;
		gold+=mat[x][y];
		mat[x][y] = 1;
		if(x>9 || y>9 || x<0 || y<0){
			puts("AHHH... Você caiu no buraco do tormento eterno...");
			puts("Sem rotina, sem recompensa pra você...");
			getch();
			exit(1);
		}
		if(x == 9 && y == 9 && gold == 58){
			clear;
			puts("Mais uma Masmorra concluida...");
			puts("Agora você está vivo, teve uma incrível aventura e ainda está 58(g) mais rico...");
			puts("Viu seguir rotinas pode lhe render ótimas recompensas ^^");			
			getch();
			exit(1);
		}
	}
	else if(pk == D){
		mat[x][y] = 0;
		y++;
		gold+=mat[x][y];
		mat[x][y] = 1;
		if(y>9 || x >9 || x<0 || y<0){
			puts("AHHH... Você encontrou um monstro terrível e foi morto...");
			puts("Você não seguiu a rotina...");		
			getch();
			exit(1);
		}
		if(x == 9 && y == 9 && gold == 58){
			clear;
			puts("Mais uma Masmorra concluida...");
			puts("Agora você está vivo, teve uma incrível aventura e ainda está 58(g) mais rico...");
			puts("Viu seguir rotinas pode lhe render ótimas recompensas ^^");
			getch();
			exit(1);
		}			
	}
}


void local(void){
	setlocale(LC_ALL, "Portuguese");
}
