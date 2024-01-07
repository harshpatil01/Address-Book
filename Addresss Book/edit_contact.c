/*
Function to edit the contacts when called from the main.c function.
User will be asked to enter the details accordingly.

*/


#include "main.h"

int edit_contact(char *fpc) {
    // Declare variables
    contacts cont, edit;
    // Open the file in read and write mode
    FILE *fp;
    if ((fp = fopen(fpc, "r+")) == NULL) {
        // If it can't open a file then print the error
        perror(fpc);
        exit(EXIT_FAILURE);
    }

    char editname[50];
    char editphone[11];
    char editemailid[50];

    printf("Choose your option-\n1. Edit by searching Name\n2. Edit by searching Phone No\n3. Edit by searching Email Id\n4. Go to Main Menu\n Enter your option: ");
    int option;
    scanf("%d", &option);

    int count = 0;
    char res;
    switch (option) {
        case 1:
            printf("Enter the Name which you want to edit: ");
            scanf("\n%[^\n]s", editname);

            while (fread(&cont, sizeof(cont), 1, fp) == 1) {
                if (!strcmp(editname, cont.name)) {
                    printf("Contact FOUND\n Name:%s\n Phone No: %s\n Email Id: %s\n", cont.name, cont.phone, cont.emailid);
                    printf("Enter the new name: ");
                    scanf("\n%[^\n]s", edit.name);

                    // ... (similar changes for phone and email)

                    // File Position indicator of fp being set to the start of the record
                    fseek(fp, -sizeof(cont), SEEK_CUR);
                    // Writing the edited contents into the file passed as the argument
                    fwrite(&edit, sizeof(cont), 1, fp);
                    // Increment count variable
                    count++;
                    break;
                }
            }
            break;
        case 2:
            // Similar changes for case 2 and case 3
            // ...
            break;
        case 3:
            // ...
            break;
        case 4:
            fclose(fp);
            return 3;
        default:
            printf("Invalid Option \n ");
            fclose(fp);
            return -1;
    }

    // Close the file
    fclose(fp);

    if (count) {
        printf("Contact details have been edited successfully \n");
        return 1;
    } else {
        printf("Data cannot be edited successfully \n");
        return -2;
    }
}
