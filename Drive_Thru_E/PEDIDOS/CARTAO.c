#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <locale.h>

#define TAMSTR 201

typedef struct {
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}REGISTRO;	REGISTRO r;

typedef struct {
	REGISTRO r;
	int codped;
	int qtd;
	float total;
	float parcial;
	char cartao[16+1];
	char paga[30];
}PRODUTO; 	PRODUTO p;

void abre(void);
void cartao (void);
void senha (void);
void gravar (void);


void abre (void)
{
	FILE * Arq;
	
	Arq = fopen ("E:\\Drive_Thru_E\\ARQUIVOS\\PEDIDO.DAT", "r");
	if (Arq == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nPedido não encontrado :(\nPedimos perdão pela inconveniência)");
		getch();
		exit(0);
	}
	
	while (fread(&p, sizeof(p), 1, Arq) == 1) 
	{}
	printf("==========================\n");
	printf("Total do Pedido:R$%.2f\n",p.total);
	printf("==========================\n");
	/* Fecha o arquivo */
	fclose(Arq);
	}
	
	
void cartao (void)
{
	char op;
	int ind;
	FILE *For;
	For = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FORMA.DAT", "w");
    do
    {	system("cls");
    	abre();
    	printf("\n==========================\n");
		printf("     TIPO DE CARTÃO: ");
		printf("\n--------------------------  \n");
		printf ("    1. DÉBITO\n");
		printf ("    2. CRÉDITO\n");
		printf ("    3. VALE REFEIÇÃO\n");
		printf ("    4. VALE ALIMENTAÇÃO\n");
		printf("\n==========================   ");
		printf("\nSUA ESCOLHA: "); 
		fflush (stdin); op=getche();
	}
	while ( op<'1' || op>'4' );
	
	printf ("\nTotal do Pedido:R$%.2f\n", p.total);
	
	switch (op)
	{
		case '1': system("cls"); printf("\n%s selecionado, Digite o Número do Cartão: ", "Débito"); 
			for (ind=0; ind<16; ind++){	fflush(stdin); p.cartao[ind]=getche();	} 
			printf("\nDigite a senha do Cartão: "); senha(); gravar(); 
			fprintf(For,"Cartão Débito");break;
			
		case '2': system("cls"); printf("\n%s selecionado, Digite o Número do Cartão: ", "Crédito");
			for (ind=0; ind<16; ind++){	fflush(stdin); p.cartao[ind]=getche();	} 
			printf("\nDigite a senha do Cartão: "); senha(); gravar(); 
			fprintf(For,"Cartão Crédito");break;
			
		case '3': system("cls"); printf("\n%s selecionado, Insira ou Aproxime o Cartão", "VR"); 
			sleep(5); fprintf(For,"Vale Refeição");break;
			
		case '4': system("cls"); printf("\n%s selecionado, Insira ou Aproxime o Cartão", "VA");
			sleep(5); fprintf(For,"Vale Alimentação");break;
	}
	fclose(For);
	
}
void senha (void)
{
	int i;
	char pass[5];
for(i=0; i<4 ; i++)
{
	fflush(stdin);
	pass[i] = getch();
	printf ("*");
}

}

void gravar (void)
{
	FILE *Pag;
	
	Pag = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\NUMERO.DAT", "a");
	if (Pag == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nErro)");
		getch();
		exit(0);
	}
	fprintf(Pag,"%s", p.cartao);
    fclose(Pag);
	
}

int main()
{
	char opc;

	setlocale(LC_ALL, "");
	system ("color 0a	");
	system("cls");
	cartao();
	return 0;
}
