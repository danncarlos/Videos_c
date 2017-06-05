#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#define clear;	system("cls");
#define flush;	fflush(stdin);
#define line;	puts("\n\n");
#define MAX 100
/*
	Dannylo Carlos - 2216111572
	Natan Nascimento 2216111816
	Marcelo Souza 2216100928
	Vinicius Marcos 2216108448

*/
	int lerarq(void);
	char menu(void);
	void adicionar(void);
	void remover(void);
		
	struct x{
		char tarefa[45];
		int pomodori, status;
	};
	
	struct x all[MAX];

	int i, cont;
	char m, *token;

	FILE *fa, *novo;
		
main(){
	local();
			
	for(;;){
		puts("Pomodori's \t|\t Tarefa\n");
		cont = lerarq();
		switch(menu()){
			case '1':
				clear;				
				adicionar();
				break;
			case '2':
				clear;
				remover();
				break;
			case '0':
				puts("\tAte breve...");
				getch();
				exit(1);
				break;
			default:
				puts("\tOpção invalida tente novamente...");
				getch();
				clear;
		}			
	}
	
}

int lerarq(){// ler aquivo
	int conta = 0;
	int choice;
	fa = fopen("listadodia.dat", "r");
	if(fa == NULL){
		puts("\nErro na abertura de ferramentaspomodori.dat");
		puts("\nDeseja criar o arquivo? \n1 - Sim\n2 - Não");
		scanf("%i", &choice);
		if(choice == 1){
			fa = fopen("listadodia.dat", "w+");				
			fclose(fa);
		}
		else{
			getch();
			exit(1);
		}
	}// if verificação de erro	
	while(fgets(all[conta].tarefa, 50, fa) && fscanf(fa,"\n%i\n", &all[conta].pomodori) != EOF){
		all[conta].status = 1;
		printf("%i \t|\t %s\n", all[conta].pomodori, all[conta].tarefa);
		conta++;	
	}
	
	puts("\n");
	fclose(fa);
	return conta;		
}


char menu(){ // menu
	puts("\t-----Menu-----");
	puts("\t1 - Adicionar tarefa");
	puts("\t2 - Remover tarefa");	
	puts("\t0 - Sair");
	printf("\tOpção: ");
	scanf("%s", &m);
	return m;
}


adicionar(){
	char tarefa[50];
	int time;
	fa = fopen("listadodia.dat", "a+");
	for(;;){
		printf("\nDigite o nome da tarefa, ou '.' para finalizar: ");
		flush;
		gets(tarefa);
		strupr(tarefa);
		if(strcmp(tarefa,".") == 0){
			break;
		}
		printf("\nDigite quantos pomodoris serão necessários para concluir %s: ", tarefa);
		scanf("%i", &time);
		fprintf(fa,"%s\n%i\n", tarefa, time);
	}//
	fclose(fa);
	puts("\n...");
	clear;	
}


remover(){
	int id;
	printf("ID\t|Nome\n");
	for(i=0;i<cont;i++){
		printf("%i - %s", i, all[i].tarefa);
	}

	printf("Digite o ID a ser removido: ");
	scanf("%i", &id);
	for(i=0;i<cont;i++){
		if(id == i){
			printf("%s foi removida...", all[i].tarefa);
			all[i].status = 0;			
		}
	}	
	fa = fopen("listadodiaa.dat", "w");
	for(i=0;i<cont;i++){
		if(all[i].status == 1){
			fprintf(fa,"%s%i\n", all[i].tarefa, all[i].pomodori);
		}		
	}
	fclose(fa);
	remove("listadodia.dat");
	rename("listadodiaa.dat", "listadodia.dat");
	getch();
	clear;	

}


void local(void){
	setlocale(LC_ALL, "Portuguese");
}
