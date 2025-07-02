/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>


/* CONSTANTES */
#define   TITULO   "Cardápio Lanches Web"
#define   TAMSTR   201
#define   NUM_PRODUTOS 10
 
 /* PROTÓTIPOS DE FUNÇÕES */
void capturaDados (void);
int contagemCod (void);
void gravarDados( void );
char menu (void);
void cadastroDefault (void);
void gerarRelatorio(void);


/* TIPOS PRÉ-DEFINIDOS */
typedef   struct
{
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}
REGISTRO;

/* VARIÁVEIS GLOBAIS */
REGISTRO vet[NUM_PRODUTOS] = {
    {1, "Hello, Burger!", 20.00},
    {2, "Ctrl+Grill", 25.00},
    {3, "MainBurger()", 27.00},
    {4, "VimBurguer", 30.00},
    {5, "Nano Fries", 12.00},
    {6, "Try Catchup()", 15.00},
    {7, "JSON do Céu", 25.00},
    {8, "GitShake ", 15.00},
    {9, "Cupcake++", 18.00},
    {10,"Array de Amendoim", 22.00},
};

REGISTRO 		r;




void capturaDados (void)
{
	r.codprod = contagemCod() +1; 
	printf ("\nDigite a descrição do produto: ");
	fflush(stdin); gets(r.descrprod);
	printf ("\nDigite o custo unitário do produto: ");
	fflush(stdin); scanf ("%f", &r.custoprod);
}

int contagemCod (void){
    FILE *Arq;
    REGISTRO temp;
    int Cod = 0; //Zera o Cod.Prod

    Arq = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT", "r");
    if (Arq == NULL) {
        return 0;  // Arquivo ainda não existe
    }
/* Calcula Cod. do Produto*/
    while (fread(&temp, sizeof(REGISTRO), 1, Arq) == 1) {
        if (Cod < temp.codprod ) {
            Cod = temp.codprod;
        	}
    }

    fclose(Arq);
    return Cod;

}

void gravarDados( void )
{
	FILE * Arq;
	/* Abre o arquivo */	
	Arq = fopen ("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT", "a");
	if (Arq == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nErro ao abrir PRODUTOS.DAT");
		printf ("\nRetorno de fopen = %p--->NULL", Arq);
		getch();
		exit(0);
	}
	else
	{
		printf ("\nPRODUTOS.DAT alocado em: %p", Arq);
		getch();
	}
	/* Grava o registro no arquivo PRODUTOS.DAT */
	fwrite ( &r, sizeof(r), 1, Arq );
	/* Fecha o arquivo */
	fclose(Arq);
	/* Informa que os dados foram gravados com sucesso */
	printf ("\nDados gravados com sucesso");
	getch();
	gerarRelatorio();
}


char menu (void)
{   char opc;
    do
    {	system("cls");
		printf ("\n%s\n", TITULO);
		printf ("\n 1. CADASTRAR");
		printf ("\n 2. CADASTRO DEFAULT");
		printf ("\n 0. ENCERRA ");
		printf ("\n------------");
		printf ("\nSUA ESCOLHA: "); 
		fflush (stdin); opc=getche();
	}while ( opc<'0' || opc>'2' );
	return (opc);
}

void gerencia(char opc)
{	switch (opc)
	{
		case '0': exit(0); break;
		case '1':
			{
				capturaDados();
    			gravarDados();	
			}
		break;
		case '2': cadastroDefault(); break;
	}
}

void cadastroDefault (void)
{
	FILE *Arq;
	int i;
	Arq = fopen ("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT" , "w");
	if ( Arq == NULL)
	{
		printf ("erro"); getch(); exit(0);
	}
	
    /* Grava os registros de uma só vez */ 
	fwrite (vet, sizeof(vet), 1, Arq);
	fclose(Arq);
	printf ("\nDados default cadastrados em PRODUTOS.DAT");
	getch();
	gerarRelatorio();
	
}

void gerarRelatorio(void)
{
    FILE *Arq, *Relat;
    REGISTRO temp_r; /* Variável local de REGISTRO*/

    Arq = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT", "r"); /* Lê o Produtos.Dat*/
    if (Arq == NULL)
    {
        printf("\nErro ao abrir PRODUTOS.DAT para relatorio. Nao ha dados.");
        getch();
        return; /* Return sem nada pq é void*/ 
    }

    Relat = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\RELATPRODUTOS.TXT", "w"); /* Sobrescreve o Relat.txt*/
    if (Relat == NULL)
    {
        printf("\nErro ao gerar RELATPRODUTOS.TXT");
        fclose(Arq);
        getch();
        exit(0);
    }

    fprintf(Relat, "\n%s\n", TITULO);
    fprintf(Relat, "\n--- RELATORIO DE PRODUTOS ---\n");
    fprintf(Relat, "\nCOD\tDESCRICAO               CUSTO");
    fprintf(Relat, "\n-------------------------------------------------\n");

    while (fread(&temp_r, sizeof(REGISTRO), 1, Arq) == 1)
    	/* fread: 1°-armazena em temp_r									Condição do while:
                  2°-um tamanho de um elemento do tipo registro			Enquanto fread for 
				  3°-lê 1 elemento por vez								igual a 1, Faça...
				  4°-de Arq
			Se fread for Verdadeiro, ele retorna 1*/
    {
        fprintf(Relat, "\n%3i\t%-21s\tR$%12.2f", temp_r.codprod, temp_r.descrprod, temp_r.custoprod);
    }

    fclose(Arq);
    fclose(Relat);
    printf("\nRelatorio RELATPRODUTOS.TXT gerado com sucesso.");
    getch();
}




int main()
{	char op;
	//setlocale(LC_ALL, "");
	setlocale(LC_ALL, "");
	do
	{
		system ("color 05");
		op = menu();
		gerencia (op);
	}
	while (op!='0');
	return 0;
}
