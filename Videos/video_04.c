#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#define clear;	system("cls");
#define flush;	fflush(stdin);
#define line;	puts("\n\n");
#define MAX 30
/*
	Dannylo Carlos - 2216111572
	Natan Nascimento 2216111816
	Marcelo Souza 2216100928
	Vinicius Marcos 2216108448

*/
	struct x{
		char tafera[25];
		int lvl;
	};
	struct x all[MAX];
	struct x temp;
	
	int i;
	
main(){
	local();
	for(i=0;i<MAX;i++){
		printf("Digite suas tarefas do dia, ou '.' para finalizar: ");
		flush;
		gets(all[i].tafera);
		if(strcmp(all[i].tafera, ".") == 0){
			break;
		}
		printf("Qual a prioridade dessa tarefa,\nsendo (1 - baixo, 2 - alto, 0 - sem prioridade): ");
		scanf("%i", &all[i].lvl);
		if(all[i].lvl < 0){
			all[i].lvl = 0;
		}
		else if(all[i].lvl > 2){
			all[i].lvl = 2;
		}
	}
	clear;
	puts("----------------------------------------------");
	puts("OBRIGAÇÕES PARA HOJE");
	for(i=0;i<MAX;i++){
		if(all[i].lvl == 2){
			printf("%s\n", all[i].tafera, all[i].lvl);				
		}	
	}
	getch();
	return 0;
}

