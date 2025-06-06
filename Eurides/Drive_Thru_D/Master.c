/*Master.C*/

/* Controla as chamadas dos programas
	Admprod.c
	Atendimento.c
*/
	/* Bibliotecas*/
	
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

/* Funções*/
char menu (void)
{
	char escolha; 
	do
	{
		system("cls");
		system ("color f3");
		printf("\n================");
		printf("\n     Master     ");
		printf("\n================");
		printf("\n1. AdmProd");
		printf("\n2. Atendimento");
		printf("\n0. Encerra    ");
		printf("\n================");
		printf("\nSua Escolha:  ");
		fflush (stdin); escolha = getche();
	}while (escolha<'0' || escolha >'2');
	return (escolha);
}
	
void gerencia(char algo)
{
	switch (algo)
	{
		case '0' : exit (0); break;
		case '1' : system ("AdmProd"); break;
		case '2' : system ("Atendimento"); break;
	}

}


int main ()
{
	char op;
	setlocale(LC_ALL, "");
	do
	{
		op = menu();/* oferece o menu*/
		gerencia(op);
		/*chama a função que gerencia a opção selecionada */	
	}while (op!='0');
	return 0;
}

