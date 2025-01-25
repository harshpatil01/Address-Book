# Address Book in C

This project implements a simple **Address Book** application in C that allows users to manage contact details efficiently. It is a menu-driven program where users can add, search, edit, delete, and list all contacts.

## Features
- **Add Contacts**: Store a contact's name, phone number, and email ID.
- **Search Contacts**: Find a contact by name, phone number, or email ID.
- **Edit Contacts**: Update a contact's information by selecting a search method.
- **Delete Contacts**: Remove a contact from the address book.
- **List All Contacts**: Display all saved contacts in a clean format.
- **File Persistence**: Save and load contacts from a file for data persistence.

## How It Works
1. **Add Contact**: Enter details like name, phone number, and email to save a contact.
2. **Search Contact**: Find a contact using the name, phone number, or email ID.
3. **Edit Contact**: Search for a contact and update the details.
4. **Delete Contact**: Locate a contact and remove it from the address book.
5. **List All Contacts**: Display all contacts stored in the address book.
6. **Exit**: Save the data to a file and exit the application.


1. **Clone the Repository:**

    ```bash
    git clone https://github.com/harshpatil01/Address-Book.git
    ```

2. **Compile the Code:**

    Navigate to the project directory and compile the C files:

    ```bash
    cd address-book
    gcc -o my_program main.c add_contact.c search_contact.c edit_contact.c delete_contact.c list_contacts.c
    ```

3. **Run the Program:**

    Execute the compiled program and provide the filename as a command-line argument:

    ```bash
    ./my_program address_book.txt
    ```

    Replace `address_book.txt` with your preferred filename.

4. **Follow the Menu Options:**

    Once the program is running, follow the on-screen menu options to interact with the address book.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests.

