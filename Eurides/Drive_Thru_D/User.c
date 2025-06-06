#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main()

{

//WINBASEAPI BOOL WINAPI GetUserNameA (LPSTR,PDWORD);

//WINBASEAPI BOOL WINAPI GetUserNameW(LPWSTR,PDWORD);

char acUserName[100];
DWORD nUserName = sizeof(acUserName);

if (GetUserName(acUserName, &nUserName)) {
printf("User name is %s\n",acUserName);

}

system("pause > nul");

return 0;
}

