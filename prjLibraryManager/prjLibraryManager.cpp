// prjLibraryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int yearPublished;
    int numPages;
};

void displayBooks(Book libraryBooks[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << libraryBooks[i].title << endl;
        cout << "Author: " << libraryBooks[i].author << endl;
        cout << "Year Published: " << libraryBooks[i].yearPublished << endl;
        cout << "Number of Pages: " << libraryBooks[i].numPages << endl;
        cout << endl;
    }
}

void updateBookInfo(Book& book) {
    cout << "Enter the Author (" << book.author << "): ";
    getline(cin, book.author);

    cout << "Enter the Year Published (" << book.yearPublished << "): ";
    cin >> book.yearPublished;

    cout << "Enter the Number of Pages (" << book.numPages << "): ";
    cin >> book.numPages;

    cin.ignore(); // clear the input buffer
}

int main() {
    // Define the array of structs (libraryBooks) within main
    Book libraryBooks[4] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 180},
        {"To Kill a Mockingbird", "Unknown", 2021, 1},
        {"1984", "George Orwell", 1949, 328},
        {"The Catcher in the Rye", "J.D. Salinger", 1951, 277}
    };

    // Display initial book information
    displayBooks(libraryBooks, 4);

    // Prompt the user to update a book
    int id;
    cout << "Enter the ID of the book you would like to update (1-4): ";
    cin >> id;
    cin.ignore(); // clear the input buffer

    if (id < 1 || id > 4) {
        cout << "Book not in the library." << endl;
    }
    else {
        // Show the current book details before updating
        cout << id << ". " << libraryBooks[id - 1].title << endl;

        // Update the book's information
        updateBookInfo(libraryBooks[id - 1]);

        // Ask if the user wants to save changes
        char save;
        cout << "Save these changes? (Y/N): ";
        cin >> save;

        if (save == 'Y' || save == 'y') {
            // Display updated book information
            cout << "\nUpdated book information:\n";
            displayBooks(libraryBooks, 4);
        }
        else {
            cout << "Changes not saved." << endl;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
