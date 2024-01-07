/*
TITLE      :Address Book
DESCRIPTION:  Main Function
AUTHOR     :
DATE       :
*/

/*
Main function
*/

#include "main.h"

int main(int argc, char *argv[]) {
    // If a file is passed as an argument
    if (argc == 2) {
        printf("ADDRESS BOOK\n");
        char res;
        do {
            // Storing the file passed as the argument (the file address) will be in the character pointer fpc
            char *fpc = argv[1];
            // Displaying the user options
            printf("Select options:\n1. Add a contact\n2. Search a contact\n3. Edit a contact\n4. Delete a contact\n5. List all contacts\n6. Exit application\n");

            // Waiting for the user to respond
            printf("Enter your option: ");
            int option;
            scanf("%d", &option);

            int result;

            switch (option) {
                case 1:
                    add_contact(fpc);
                    break;
                case 2:
                    search_contact(fpc);
                    break;
                case 3:
                    edit_contact(fpc);
                    break;
                case 4:
                    delete_contact(fpc);
                    break;
                case 5:
                    list_contacts(fpc);
                    break;
                case 6:
                    exit(0); // Corrected the exit code to 0
                    break;
                default:
                    printf("Invalid Option \n");
                    break;
            }

            // Clear the input buffer before reading the next character
            while (getchar() != '\n');

            printf("Do you want to continue? Yes or No\n ");
            scanf("%c", &res);
        } while (res == 'Y' || res == 'y');

        return 0;
    } else {
        printf("Usage: %s filename\n", argv[0]);
        printf("The number of arguments passed is invalid\n");
        exit(1);
    }
}
