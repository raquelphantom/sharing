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
	char cartao;
}PRODUTO; 	PRODUTO p;

void abre(void);
void cartao (void);
void senha (void);



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
	{
	printf("\n\nTotal do Pedido:R$%.2f\n",p.total);
	}
	/* Fecha o arquivo */
	fclose(Arq);
	}
	
	
void cartao (void)
{
	char op;
	int num[16+1];
	int ind;
    do
    {	system("cls");
    	abre();
		printf ("\nEscolha a forma de Pagamento: \n");
		printf ("\n 1. DÉBITO");
		printf ("\n 2. CRÉDITO");
		printf ("\n 3. VALE REFEIÇÃO");
		printf ("\n 4. VALE ALIMENTAÇÃO ");
		printf ("\n------------");
		printf ("\nSUA ESCOLHA: "); 
		fflush (stdin); op=getche();
	}
	while ( op<'1' || op>'4' );
	
	printf ("\nTotal do Pedido:R$%.2f\n", p.total);;
	
	switch (op)
	{
		case '1': system("cls"); printf("\n%s selecionado, Digite o Número do Cartão: ", "Débito"); 
			for (ind=0; ind<16; ind++){	fflush(stdin); num[ind]=getche();	} 
			printf("\nDigite a senha do Cartão: "); senha(); break;
			
		case '2': system("cls"); printf("\n%s selecionado, Digite o Número do Cartão: ", "Crédito");
			for (ind=0; ind<16; ind++){	fflush(stdin); num[ind]=getche();	} 
			printf("\nDigite a senha do Cartão: "); senha(); break;
			
		case '3': system("cls"); printf("\n%s selecionado, Insira ou Aproxiime o Cartão", "VR"); 
			sleep(5); break;
			
		case '4': system("cls"); printf("\n%s selecionado, Insira ou Aproxiime o Cartão", "VT");
			sleep(5); break;
	}
	
	
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

int main()
{
	char opc;

	setlocale(LC_ALL, "");
	system("cls");
	cartao();
	return 0;
}
