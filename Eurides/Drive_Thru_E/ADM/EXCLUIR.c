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

void excluirProduto(void) {
    int excluir;
    int find = 0;
    REGISTRO temp;
    FILE *Arq, *Temp;

    printf("\nDigite o código do produto que deseja excluir: ");
    scanf("%d", &excluir);

    Arq = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT", "r");
    if (Arq == NULL) {
        printf("Erro ao abrir PRODUTOS.DAT.\n");
        getch();
        return;
    }

    Temp = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\TEMP.DAT", "w");
    if (Temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(Arq);
        getch();
        return;
    }

    while (fread(&temp, sizeof(REGISTRO), 1, Arq) == 1) {
        if (temp.codprod != excluir) {
            fwrite(&temp, sizeof(REGISTRO), 1, Temp);  // Mantém registro
        } else {
            find = 1;  // Encontrado e pulado (excluído)
        }
    }

    fclose(Arq);
    fclose(Temp);

    // Substitui o original
    remove("E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT");
    rename("E:\\Drive_Thru_E\\ARQUIVOS\\TEMP.DAT", "E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT");

    if (find)
        printf("\nProduto com código %d excluído com sucesso.\n", find);
    else
        printf("\nProduto com código %d não encontrado.\n", find);

    getch();
}

int main (void)
{
	excluirProduto();
	setlocale(LC_ALL, "");
	system ("color d1");
	getch();
	return 0;
}
