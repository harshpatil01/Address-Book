/*
Function to add the contact to the file passed as an argument by the user.
*/

#include "main.h"

int add_contact(char *fpc) {
    contacts cont;

    // Open the file in append mode
    // Declare variables
    FILE *fp;
    if ((fp = fopen(fpc, "ab")) == NULL) {
        // If it can't open a file, then print the error
        perror(fpc);
        exit(EXIT_FAILURE);
    }

    int validate;
    int checkphone = 0;
    int checkemail = 0;

    // Fetching the name from the user
    printf("Enter the name: ");
    scanf(" %[^\n]s", cont.name);

    // Fetching the phone no from the user
    printf("Enter phone no: ");
    scanf("%s", cont.phone);

    // Validate the phone no
    for (validate = 0; validate < strlen(cont.phone); validate++) {
        if (strlen(cont.phone) < 10 || cont.phone[validate] < '0' || cont.phone[validate] > '9') {
            checkphone = 1;
        }
    }

    // Fetching the email id from the user
    printf("Enter email id: ");
    scanf("%s", cont.emailid);

    // Validate email id to check if it contains at least one '@' and '.' character
    for (validate = 0; validate < strlen(cont.emailid); validate++) {
        if (cont.emailid[validate] == '@' || cont.emailid[validate] == '.') {
            checkemail++;
        }
    }

    // If either phone no or email id is invalid
    if (checkphone == 1 || checkemail < 2) {
        printf("It's an invalid phone no or email id\n");
        fclose(fp);
        return -1;
    }

    // Use fwrite to write the contact details to the file
    size_t added = fwrite(&cont, sizeof(cont), 1, fp);

    fclose(fp);

    if (added == 1) {
        printf("Contact details successfully added\n");
        return 1;
    } else {
        printf("Failed to add contact details\n");
        return -1;
    }
}
