/*
Function to delete the contact after the user has entered the contact which he wants to delete . The function is called from main.c .
*/


#include "main.h"

int delete_contact(char *fpc) {
    contacts cont;
    // Open the file in read mode
    FILE *fp, *ftemp;

    if ((fp = fopen(fpc, "rb")) == NULL) {
        // If it can't open a file, then print the error
        perror(fpc);
        exit(EXIT_FAILURE);
    }

    if ((ftemp = fopen("temp.txt", "wb")) == NULL) {
        // If it can't open a file, then print the error
        perror("temp.txt");
        exit(EXIT_FAILURE);
    }

    char deletename[50];
    char deletephone[11];
    char deleteemailid[50];

    printf("Choose your option-\n1. Delete by searching Name\n2. Delete by searching Phone No\n3. Delete by searching Email Id\n4. Go to Main Menu\n Enter your option: ");
    int option;
    scanf("%d", &option);

    int keepcount = 0;
    char res;

    switch (option) {
        case 1:
            printf("Enter the Name for which you want to delete the entire record: ");
            scanf("\n%[^\n]s", deletename);

            while (fread(&cont, sizeof(cont), 1, fp) == 1) {
                if (strcmp(deletename, cont.name) != 0) {
                    // Deleting the particular record
                    // Writing the name, phone, and the emailid to the file pointer pointed by ftemp from the original file i.e fp
                    fwrite(&cont, sizeof(cont), 1, ftemp);
                } else {
                    // Incrementing count variable by one
                    keepcount++;
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
            fclose(ftemp);
            return 3;
        default:
            printf("Invalid Option \n");
            fclose(fp);
            fclose(ftemp);
            return -1;
    }

    // Close the File fp
    fclose(fp);
    // Close the File ftemp
    fclose(ftemp);

    // int remove(const char *pathname)
    // remove() deletes a name from the filesystem.
    remove(fpc);
    rename("temp.txt", fpc);

    if (keepcount == 0) {
        printf("No specified contact details have been found\n");
        return -2;
    } else {
        printf("Contact details have been deleted successfully\n");
        return 1;
    }
}
