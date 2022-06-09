#include "stdafx.h"
#include <Windows.h>

/*
 * Author: @OsandaMalith
 * Website: https://osandamalith.com
 */

void check(int *pid) {
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	GetComputerName(computerName, &size);
	printf("[+] Computer Name: %s\n", computerName);

	TCHAR computerUserName[MAX_COMPUTERNAME_LENGTH + 1];
	size = sizeof computerUserName / sizeof *computerUserName;
	GetUserName(computerUserName, &size);
	printf("[+] Username: %s\n\n", computerUserName);

	int name = strlen((char *)(&computerName));
	int username = strlen((char *)(&computerUserName));

	int charName = *(char *)((int)&computerName);
	int charUser = *(char *)((int)&computerUserName);

	for (int i = 1; i < name; i++)
		charName += *(char *)(i + (int)&computerName);

	for (int i = 1; i < username; i++)
		charUser += *(char *)(i + (int)&computerUserName);
	
	int a = 9999 ^ *pid;
	int b = 2222 ^ charUser;
	int c = (a - b) ^ charName;

	printf("[~] Serial Key: %d-%d-%d\n\n",c,2222,9999);
	puts("[*] If the above doesn't work try this:\n");
	a = 9999 ^ *pid;
	b = 2222 ^ charUser;
	c = (a - b) ^ 0;

	printf("[~] Serial Key: %d-%d-%d\n\n", c, 2222, 9999);
}

int _tmain(int argc, _TCHAR* argv[]){
	puts("\t\t\t[~] caneacsu's CrackMe Keygen\n\t\t\t[~] Coded by @OsandaMalith");
	int pid = 0;
	printf("\n\n[?] Enter PID: ");
	scanf("%d", &pid);
	check(&pid);
	return 0;
}
