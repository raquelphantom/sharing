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
#include <string.h> // Necessário para sprintf

char menu (void)
{
    char opc;
    do
    {
        system("cls");
        printf ("\n 1. CADASTRAR");
        printf ("\n 2. CONSULTAR");
        printf ("\n 3. RELATORIO");
        printf ("\n 0. ENCERRAR ");
        printf ("\n------------");
        printf ("\nSUA ESCOLHA: ");
        fflush (stdin); opc=getche();
    }while ( opc<'0' || opc>'3' );
    return (opc);
}

void caso(char adm)
{
    char comando[256]; // Buffer para construir o comando
    const char *caminho = "%USERPROFILE%\\Downloads\\Drive_Thru_D\\ADM\\"; // Caminho base universal
    /* const é uma variável que depois de inicializada é imutável*/

    switch (adm)
    {
        case '0' : exit (0); break;
        /* Escreve o Caminho até o .exe*/
        case '1' : sprintf(comando, "start %sCADASTRO.exe", caminho); system(comando); break;
        case '2' : sprintf(comando, "start %sCONSULTA.exe", caminho); system(comando); break;
        case '3' : sprintf(comando, "start %sRELATORIO.exe", caminho); system(comando); break;
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
