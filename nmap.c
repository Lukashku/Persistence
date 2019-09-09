#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int change(char *ipAddress){
  char path[30], ip[45];
  strcpy(path,"HTBScan/");
  strcpy(ip, ipAddress);
  strcat(path,ip);
  chdir(path);

}
int quickScan(char *ipAddress) {
  printf("Starting Quick Scan...\n");
  char ip[30], command[45];
  strcpy(command,"nmap --max-retries=1 -oN quick.nmap ");
  strcpy(ip, ipAddress);
  strcat(command, ip);
  system(command);
  return 0;
}
int basicScan(char *ipAddress) {
  printf("Starting Basic Scan...\n");
  char ip[30], command[45];
  strcpy(command,"nmap -sV -sC --max-retries=1 -oN basic.nmap ");
  strcpy(ip, ipAddress);
  strcat(command, ip);
  system(command);
  return 0;
}
int fullScan(char *ipAddress) {
  printf("Starting Full Scan...\n");
  char ip[30], command[45];
  strcpy(command,"nmap -sV -sC -p- --max-retries=1 -oN Full.nmap ");
  strcpy(ip, ipAddress);
  strcat(command, ip);
  system(command);
  return 0;
}
int vulnScan(char *ipAddress) {
  printf("Starting Vuln Scan...\n");
  char ip[30], command[45];
  strcpy(command,"nmap --script vuln --max-retries=1 -oN vuln.nmap ");
  strcpy(ip, ipAddress);
  strcat(command, ip);
  system(command);
  return 0;
}
