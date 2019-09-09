#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
//test
//This program was designed for HTB and is heavily based off the
//nmapAutomater script
/*int intro();*/
//int flags(int argc, char *argv[]);
/*int makeDirectory(char *ipAddress);*/
int choice(char *ipAddress);
int quickScan(char * ipAddress);
int basicScan(char * ipAddress);
int fullScan(char *ipAddress);
int vulnScan(char *ipAddress);
int change(char *ipAddress);
//int test();
int intro()
{
 printf(" _    _ _______ ____\n");
 printf("| |  | |__   __|  _ \\\n");
 printf("| |__| |  | |  | |_) |___  ___ __ _ _ __\n");
 printf("|  __  |  | |  |  _ </ __|/ __/ _` | '_ \\\n");
 printf("| |  | |  | |  | |_) \\__ \\ (_| (_| | | | |\n");
 printf("|_|  |_|  |_|  |____/|___/\\___\\__,_|_| |_|\n");
 printf("\n\t\t\tBy 3nt3r\n\n");

}

int makeDirectory(char *ipAddress) {
  	struct stat sb;
  	char ip[15], path[25];
  	strcpy(path, "HTBScan/");
  	if (stat(path, &sb) == -1) {
   		mkdir(path, 0755);
  	}
  	strcpy(ip, ipAddress);
  	strcat(path, ip);
  	int success = mkdir(path, 0755);
  	printf("Making directory %s, success: %d", path, success);

	  choice(ip);

}
int choice(char *ipAddress) {
	printf("\nPlease choose a scan:\n\n ");
	printf("{1} Quick Scan\n");
	printf("{2} Basic Scan\n");
	printf("{3} Full Scan\n");
	printf("{4} Vuln Scan\n");
	printf("{5} Recon Suggestions\n");
	printf("{6} All\n");
	printf("{0} Exit\n");

	int choices;
	printf(">>> ");
	scanf("%d", &choices);

  change(ipAddress);
	if (choices == 1) {
		quickScan(ipAddress);
	}
	else if (choices == 2){
    basicScan(ipAddress);
	}
	else if (choices == 3){
		fullScan(ipAddress);
	}
	else if (choices == 4) {
		vulnScan(ipAddress);
	}
	else if (choices == 5){
		//printf();
	}
	else if (choices == 6){
		quickScan(ipAddress);
    basicScan(ipAddress);
    fullScan(ipAddress);
    vulnScan(ipAddress);
	}
	else if (choices == 0){
		return 0;
	}
	else{
		printf("Invalid choice.");
		choice(ipAddress);
	}

}
int main(int argc, char *argv[])
{
    //flags(int argc, char *argv[]);
    if(argc == 2) {
      intro();
    }
    else if(argc > 2) {
      printf("Too many arguments supplied.\n");
    }
    else {
      printf("%s <ip address>\n",argv[0]);
      return 1;
    }

    makeDirectory(argv[1]);
    //makeDirectory(argv[1]);
}
