/* BIBLIOTECAS */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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

REGISTRO vet[20] = {
    {1, "Big Mac", 22.62},
    {2, "Big Mac - Meal", 32.26},
    {3, "2 Cheeseburgers", 14.63},
    {4, "2 Cheeseburgers - Meal", 27.73},
    {5, "Quarter Pounder with Cheese", 21.49},
    {6, "Quarter Pounder with Cheese - Meal", 31.13},
    {7, "Double Quarter Pounder with Cheese", 27.16},
    {8, "Double Quarter Pounder with Cheese - Meal", 36.80},
    {9, "Bacon Habanero Ranch Quarter Pounder", 23.19},
    {10, "Bacon Habanero Ranch Quarter Pounder - Meal", 32.83},
    {11, "Deluxe Quarter Punder", 23.19},
    {12, "Deluxe Quarter Punder - Meal", 32.83},
    {13, "Bacon & Cheese Quarter Pounder", 23.19},
    {14, "Bacon & Cheese Quarter Pounder - Meal", 32.83},
    {15, "Filet-O-Fish", 21.49},
    {16, "Filet-O-Fish - Meal", 31.13},
    {17, "Double Filet-O-Fish", 26.59},
    {18, "Double Filet-O-Fish - Meal", 36.23},
    {19, "Double Cheeseburger", 9.02},
    {20, "Double Cheeseburger - Meal", 23.76},
};REGISTRO r;

void lerDados (void)
{
	FILE * Arq;
	/* Abre o arquivo */	
	Arq = fopen ("PRODUTOS.DAT", "r");
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
	while ( !feof(Arq) )
	{
		/* Ler os dados */
		fread ( &r, sizeof(r), 1, Arq );
		/* Testa se leu EOF (end of file) */
		if ( !feof(Arq) )
		{	/* Mostrar na tela o conteúdo lido */
		    printf ("\n%3i\t%-21s\t\tR$%12.2f", r.codprod, r.descrprod, r.custoprod);
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
