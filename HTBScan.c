#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

//This program was designed for HTB and is heavily based off the
//nmapAutomater script
int intro();
//int flags(int argc, char *argv[]);
int makeDirectory(char *ipAddress);
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
    }

    makeDirectory(argv[1]);
    //makeDirectory(argv[1]);
}
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
  char newchar[50];
  char *path = "HTBscan/";
  strcpy(newchar, path);
  strcat(newchar, ipAddress);
  const char *new = newchar;
  //char *dirname = newchar;
  //printf(newchar);
  int directory;
  directory = mkdir(new, 0755);
  //printf("Created Directory %p", &ipAddress);
}
