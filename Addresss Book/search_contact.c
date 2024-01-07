/*
Function to search the contact . 
*/


#include "main.h"

int search_contact(char *fpc) {
    contacts cont;

    // Open the file in read mode
    FILE *fp;
    if ((fp = fopen(fpc, "rb")) == NULL) {
        // If it can't open a file, then print the error
        perror(fpc);
        exit(EXIT_FAILURE);
    }

    char searchname[50];
    char searchphone[11];
    char searchemailid[50];

    printf("Choose your option-\n1. Search by Name\n2. Search by Phone No\n3. Search by Email Id\n4. Go to Main Menu\nEnter your option: ");
    int option;
    scanf("%d", &option);

    int count = 0;
    switch (option) {
        case 1:
            printf("Enter a Name to search: ");
            scanf("\n%[^\n]s", searchname);
            while (fread(&cont, sizeof(cont), 1, fp) == 1) {
                if (!strcmp(searchname, cont.name)) {
                    printf("Contact Found\nName: %s\n Phone No: %s\n Email Id: %s\n", cont.name, cont.phone, cont.emailid);
                    count++;
                }
            }
            break;
        case 2:
            printf("Enter a Phone No to search: ");
            scanf("%s", searchphone);
            while (fread(&cont, sizeof(cont), 1, fp) == 1) {
                if (!strcmp(searchphone, cont.phone)) {
                    printf("Contact Found\n Name: %s\n Phone No: %s\n Email Id: %s\n", cont.name, cont.phone, cont.emailid);
                    count++;
                }
            }
            break;
        case 3:
            printf("Enter an Email ID to search: ");
            scanf("%s", searchemailid);
            while (fread(&cont, sizeof(cont), 1, fp) == 1) {
                if (!strcmp(searchemailid, cont.emailid)) {
                    printf("Contact Found\nName: %s\n Phone No: %s\n Email Id: %s\n", cont.name, cont.phone, cont.emailid);
                    count++;
                }
            }
            break;
        case 4:
            fclose(fp);
            return 3;
        default:
            printf("Invalid Option has been entered\n");
    }

    // Close the File
    fclose(fp);

    if (!count) {
        printf("Contact has not been found\n");
        return -2;
    } else if (count > 1) {
        printf("WARNING: Contacts with either the same Name, Phone No, or Email ID found\n");
    }

    return 1;
}

