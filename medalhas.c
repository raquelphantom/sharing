#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int rank;
    char pais[5];
    int ouro,prata,bronze,total;
} 
QUADROMEDALHAS;

QUADROMEDALHAS oli[20] = {
    {1,"EUA",40 ,44, 42, 126},
    {2,"CHI",40,27,24,91},
    {3,"JAP",20,12,13,45},
    {4,"AUS",18,19,16,53},
    {5,"FRA",16,26,22,64},
    {6,"HOL",15,7,12,34},
    {7,"UK",14,22,29,65},
    {8,"KRS",13,9,10,32},
    {9,"ITA",12,13,15,40},
    {10,"ALE",12,13,8,33},
    {11,"NZL",10,7,3,20},
    {12,"CAN",9,7,11,27},
    {13,"UZB",8,2,3,13},
    {14,"HUN",6,7,6,19},
    {15,"SPA",5,4,9,18},
    {16,"SUE",4,4,3,11},
    {17,"QUE",4,2,5,11},
    {18,"NOR",4,1,3,8},
    {19,"IRL",4,0,3,7},
    {20,"BRA",3,7,10,20},
};
void mostra()
{
    int i;
    printf ("\n------------ RANKING -------------\n");
    for (i=0; i<20; i++)
       printf ("\n%i , %s , %i, %i, %i, %i\n",oli[i].rank, oli[i].pais, oli[i].ouro, oli[i].prata,oli[i].bronze,oli[i].total);
    printf ("\n-----------------------------------\n");
}

int main(){
    mostra();
    getch;
    return 0;
}
