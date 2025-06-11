/*AdmProd.C*/

/* Controla as chamadas dos programas
	CADASTRA.c
	CONSULTA.c
	RETATORIO.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>



char menu (void)
{   char opc;
    do
    {	system("cls");
		printf ("\n 1. CADASTRAR");
		printf ("\n 2. CONSULTAR");
		printf ("\n 3. RELATORIO");
		printf ("\n 4. EXCLUIR PROD.");
		printf ("\n 0. ENCERRAR ");
		printf ("\n-----------------");
		printf ("\nSUA ESCOLHA: "); 
		fflush (stdin); opc=getche();
	}while ( opc<'0' || opc>'4' );
	return (opc);
}

void caso(char adm)
{
	switch (adm)
	{
		case '0' : exit (0); break;
		case '1' : system ("E:\\Drive_Thru_E\\ADM\\CADASTRO.exe"); break;
		case '2' : system ("E:\\Drive_Thru_E\\ADM\\CONSULTA.exe"); break;
		case '3' : system ("E:\\Drive_Thru_E\\ADM\\RELATORIO.exe"); break;
		case '4' : system ("E:\\Drive_Thru_E\\ADM\\EXCLUIR.exe"); break;
	}

}


int main ()
{
char adm;
setlocale(LC_ALL, "");
do
	{
		system ("color b5");
		adm = menu();/* oferece o menu*/
		caso(adm);
		/*chama a função que gerencia a opção selecionada */	
	}while (adm!='0');
	return 0;
}


