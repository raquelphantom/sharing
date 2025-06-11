/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define   TITULO   "Teste com Drive Thru"
#define   TAMSTR   201

typedef   struct
{
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}
REGISTRO;

void lerDados (void)
{
	REGISTRO ler; 
	FILE * Arq;
	
	/* Abre o arquivo */	
	Arq = fopen ("E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT", "r");
	if (Arq == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nErro ao ler PRODUTOS.DAT");
		printf ("\nRetorno de fopen = %p--->NULL", Arq);
		getch();
		exit(0);
	}
	else
	{
		printf ("\nPRODUTOS.DAT aberto para leitura: %p", Arq);
		getch();
	}
	/* Procedimento de leitura dos dados */
	while ( !feof(Arq) ) //Enquanto não for EOF
	{
		/* Ler os dados */
		fread ( &ler, sizeof(ler), 1, Arq );
		/* Testa se leu EOF (end of file) */
		if ( !feof(Arq) )
		{	/* Mostrar na tela o conteúdo lido */
		    printf ("\n%3i\t%-21s\t\tR$%12.2f", ler.codprod, ler.descrprod, ler.custoprod);
	    }
	}
	/* Fecha o arquivo */
	fclose(Arq);
	getch();
}
/* CORPO DO PROGRAMA */
int main()
{
	setlocale(LC_ALL, "");
	system ("color e2");
	lerDados();
	return 0;
}
