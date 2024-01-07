/*
Function to show all the contact details present in the file
called from main.c .
*/

#include "main.h"

int list_contacts(char *fpc) {
    contacts cont;

    // Open the file in read mode
    FILE *fp;
    if ((fp = fopen(fpc, "rb")) == NULL) {
        // If it can't open a file then print the error
        perror(fpc);
        exit(EXIT_FAILURE);
    }

    // Declaring contact count
    int contactcount = 1;

    printf("Contact details available \n");
    while (fread(&cont, sizeof(cont), 1, fp) == 1) {
        // Printing the list of contacts along with the details of the person
        printf("No of contacts %d\n Name: %s\n Phone No: %s\n Email Id: %s \n", contactcount, cont.name, cont.phone, cont.emailid);
        // Increment the contact count by one
        contactcount++;
    }

    if (contactcount == 1) {
        printf("No contacts in the file\n");
        fclose(fp);
        return -1;
    }

    // Close file
    fclose(fp);

    return 1;
}
