#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#define clear;	system("cls");
#define flush;	fflush(stdin);
#define line;	puts("\n\n");
#define solv; puts("\nPressione uma tecla para continuar");

/*
	Dannylo Carlos - 2216111572
	Natan Nascimento 2216111816
	Marcelo Souza 2216100928
	Vinicius Marcos 2216108448

*/

	void final(void);


	char assunto[30];
	char url[] = "start https://www.google.com.br/search?q=";
	char url2[] = "start https://pt.wikipedia.org/w/index.php?search=";
	char url2b[] = "&title=Especial:Pesquisar&fulltext=1&searchToken=9q5jyfgz3d3chjvyjxtf21zq5";
	int i;
	
main(){
	local();
	printf("Sobre qual assunto deseja aprender: ");
	flush;
	gets(assunto);
	strcat(url, assunto);
	strcat(url2, assunto);
	strcat(url2, url2b);
		
	clear;
	printf("Esta na hora de pesquisar sobre %s, após ter noção do que é\nvolte para continuar-mos...", assunto);
	line;
	puts("Dicas");
	printf("\n1 - Sinta-se a vontade para usar uma folha de papel, e tente explicar o tema na mesma...\n");
	printf("2 - Ao escrever, também fale em voz alta, como se estivesse dando uma aula.\n");
	solv; getch();
	system(url);
	clear;
	solv;
	getch();
	repeat:
	clear;
	printf("Entendeu todos os pontos sobre o assunto?!");
	printf("\n1 - Sim\n2 - Não\n");
	scanf("%i", &i);
	if(i == 1){
		final();
	}
	else{
		printf("Pesquisaremos novamente...\n");
		printf("Desta vez em mais de um motor de busca");
		solv;
		getch();
		system(url);
		system(url2);
		clear;
	}
	
	solv;
	getch();
	goto repeat;
}

final(){
	puts("Se chegamos aqui... significa que estamos no caminho certo...");
	puts("o segredo agora é repetir o processo, mas desta vez tente simplificar suas anotações, para uma mais fácil compreenção...");
	solv;
	getch();
	exit(1);
}

void local(void){
	setlocale(LC_ALL, "Portuguese");
}
