/*
Header file
contains all library files, macros and function prototypes 
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure Definition 
typedef struct Contact
{
	char name[50];
	char  phone[11];
	char emailid[50];
}contacts;

//Functions prototypes 
int add_contact(char * fpc);
int search_contact(char * fpc);
int edit_contact(char * fpc);
int delete_contact(char * fpc);
int list_contacts(char * fpc);
