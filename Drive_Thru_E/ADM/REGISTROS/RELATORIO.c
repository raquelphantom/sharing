/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>


void Relat (void)
{
FILE  * Arq;
char  c;

/* lê O ARQUIVO TESTE.DAT */
Arq = fopen ("E:\\Drive_Thru_E\\ARQUIVOS\\RELATPRODUTOS.TXT" , "r") ;

/* TESTA SE O ARQUIVO FOI, DE FATO, ABERTO */
if (Arq == NULL)
{
	printf ("\nfopen não achou o arquivo RELATPRODUTOS.TXT");
	printf ("\nEndereço retornado por fopen: [%p]", Arq );
	getch();
	exit(0);
}
	
do
{
	/* LER O CONTÉUDO DO ARQUIVO E MOSTRAR NA TELA */
	c =	getc(Arq); /* Lê um caractere do arquivo */
		printf ("%c", c); /* Mostro o caractere lido na tela */
}
while ( !feof(Arq) );
	
	/* FECHA O ARQUIVO */	
fclose (Arq);
}
/* CORPO DO PROGRAMA */
int main()
{
	setlocale(LC_ALL, "");
	system ("color 05");
	system ("cls");
	Relat();
	getch();
	return 0;
}
