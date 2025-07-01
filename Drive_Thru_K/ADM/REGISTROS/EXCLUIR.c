/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>


#define   TITULO   "Cardápio Lanches Web"
#define   TAMSTR   201

typedef   struct
{
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}
REGISTRO;

void excluirProduto(void) {
    int excluir;
    int find = 0;
    REGISTRO temp;
    FILE *Arq, *Temp;
/* SELECIONA O PRODUTO*/
    printf("\nDigite o código do produto que deseja excluir: ");
    scanf("%d", &excluir);
/* TENTA ABRIR O ARQUIVO*/
    Arq = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT", "r");
    if (Arq == NULL) {
        printf("Erro ao abrir PRODUTOS.DAT.\n");
        getch();
        return;
    }
/* CRIA UM ARQUIVO TEMPORÁRIO*/
    Temp = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\TEMP.DAT", "w");
    if (Temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(Arq);
        getch();
        return;
    }
/* ENCONTRA E EXCLUI O PRODUTO*/
    while (fread(&temp, sizeof(REGISTRO), 1, Arq) == 1) //enquanto fread for TRUE
	{
        if (temp.codprod != excluir) {
            fwrite(&temp, sizeof(REGISTRO), 1, Temp);  // Mantém registro
        } else {
            find = 1;  // find = TRUE (excluído)
        }
    }

    fclose(Arq);
    fclose(Temp);

    // Substitui o original
    remove("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT");
    rename("K:\\Drive_Thru_K\\ARQUIVOS\\TEMP.DAT", "E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT");

    if (find) //Se find for TRUE
        printf("\nProduto excluído com sucesso.\n");
    else
        printf("\nProduto não encontrado.\n");

    getch();
}

int main (void)
{
	setlocale(LC_ALL, "");
	system ("color 05");
	excluirProduto();
	getch();
	return 0;
}
