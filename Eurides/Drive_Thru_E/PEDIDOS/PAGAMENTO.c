#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h>

#define TAMSTR 201

typedef struct {
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}REGISTRO;	REGISTRO r;

typedef struct {
	REGISTRO r;
	int qtd;
	float total;
}
PRODUTO; 	PRODUTO p;

void abre (void);
void exclui (void);
char menu (void);
void pag (char opc);
void money (void);
void cartao (void);
void pix (void);


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
    printf ("\nTotal do Pedido:R$%.2f\n", p.total);
	}
	/* Fecha o arquivo */
	fclose(Arq);
	}

void exclui (void)
{
	
	
}

char menu (void)
{   char opc;
    do
    {	system("cls");
    	abre();
		printf ("\nEscolha a forma de Pagamento: \n");
		printf ("\n 1. DINHEIRO");
		printf ("\n 2. CARTÃO");
		printf ("\n 3. PIX");
		printf ("\n 0. CANCELAR ");
		printf ("\n------------");
		printf ("\nSUA ESCOLHA: "); 
		fflush (stdin); opc=getche();
	}
	while ( opc<'0' || opc>'3' );
	return (opc);
}


void pag(char opc)
{	switch (opc)
	{
		case '0': exit(0); break;
		case '1': money();	break;
		case '2': cartao(); break;
		case '3': pix(); break;
	}
}



void money (void)
{
	float valor;
	abre();
	do
	{
		printf("\nValor dado em Reais: R$ ");
		fflush(stdin); scanf("%f", &valor);
	
		if(valor < p.total)
		{
			p.total=p.total-valor;
			printf("\nFaltam R$%.2f", p.total);
		}else
		{
			if(valor > p.total)
			{
			valor=valor-p.total;
			printf("\nTroco de R$%.2f", valor);
			}
		}
	}while(valor > p.total);
}

void cartao (void)
{
	
	
	
}

void pix (void)
{
	
	
	
}






int main()
{
	setlocale(LC_ALL, "");
	char opc;
	
	opc= menu();// mostra cardápio lendo o prod.dat
	pag(opc);
	//comanda();//monta o pedido 
	printf("\nAgradecemos pela preferência!!!\nVolte sempre :)");
	return 0;
}
