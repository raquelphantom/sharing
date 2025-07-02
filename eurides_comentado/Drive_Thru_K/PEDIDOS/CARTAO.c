#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <locale.h>

#define TAMSTR 201
// Inicia a definição de uma estrutura para representar um registro de produto.
typedef struct {
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}REGISTRO;	REGISTRO r;

// Inicia a definição de uma estrutura para representar um item de pedido ou detalhes de pagamento.
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
void valida (void);


void abre (void)
{
	FILE * Arq;
	// Tenta abrir o arquivo "PEDIDO.DAT" e o resultado é atribuído a `Arq`.
	Arq = fopen ("K:\\Drive_Thru_K\\ARQUIVOS\\PEDIDO.DAT", "r");
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
	For = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\FORMA.DAT", "w");
    do
    {	system("cls");
    	abre();// Chama a função `abre()` para ler o último pedido e exibir seu total.
    	printf("\n==========================\n");
		printf("     TIPO DE CARTÃO: ");
		printf("\n--------------------------  \n");
		printf ("    1. DÉBITO\n");
		printf ("    2. CRÉDITO\n");
		printf ("    3. VALE REFEIÇÃO\n");
		printf ("    4. VALE ALIMENTAÇÃO\n");
		printf("\n==========================   ");
		printf("\nSUA ESCOLHA: "); 
		fflush (stdin); op=getche();// Lê um caractere digitado pelo usuário (exibindo-o na tela) e o armazena em `op`.
	}
	while ( op<'1' || op>'4' );
	
	printf ("\nTotal do Pedido:R$%.2f\n", p.total);
	
	switch (op)
	{
		case '1': system("cls"); printf("\n%s selecionado, Digite o Número do Cartão: ", "Débito"); 
			valida(); printf("\nDigite a senha do Cartão: "); senha(); gravar(); 
			fprintf(For,"Cartão Débito");break;
			
		case '2': system("cls"); printf("\n%s selecionado, Digite o Número do Cartão: ", "Crédito");
			valida(); printf("\nDigite a senha do Cartão: "); senha(); gravar(); 
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
	
	Pag = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\NUMERO.DAT", "a");
	if (Pag == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nErro)");
		getch();
		exit(0);
	}
	fprintf(Pag,"%s", p.cartao);
    fclose(Pag);
	
}

void valida (void)
{
	int ind;
	for (ind = 0; ind < 16; ) 
	{
	    fflush(stdin);
	    p.cartao[ind] = getche();
	
	    if (p.cartao[ind] >= '0' && p.cartao[ind] <= '9') {ind++;} // avança apenas se for número
		// Verifica se o caractere digitado está entre '0' e '9'. Se for um número, incrementa `ind` para avançar para a próxima posição.

		else {printf("\nDigite apenas números (0-9). Tente novamente: ");}
	}
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
