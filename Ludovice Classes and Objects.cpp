#include <iostream>
#include <string>
#include <iomanip>

//Coded by Kristoffer Ludovice

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
	
	void setBook(string t, string a, int y)
	{
        title = t;
        author = a;
        year = y;
    }
	
    string getTitle()
	{
        return title;
    }

    string getAuthor()
	{
        return author;
    }

    int getYear()
	{
        return year;
    }

	void displayBook()
	{
        cout << setw(20) << left << title 
             << setw(20) << left << author 
             << setw(5)  << year << endl;
	}

};

class Library {
private:
    Book books[50];
    int bookCount; 

public:

    Library()
	{
		bookCount = 0;
	}

    void addBook(Book book)
	{
        if (bookCount < 50) 
		{
            books[bookCount] = book;
            bookCount++;
            cout << "Book added successfully!" << endl;
        } 
		else 
		{
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    void displayBooks() 
	{
        if (bookCount == 0) 
		{
            cout << "No books in the library." << endl;
        } 
		else 
		{
            cout << setw(20) << left << "Title"
                 << setw(20) << left << "Author"
                 << setw(5)  << "Year" << endl;
            for (int i = 0; i < bookCount; i++) {
                books[i].displayBook();
            }
        }
    }

    void searchBook(string title) 
	{
        for (int i = 0; i < bookCount; i++) 
		{
            if (books[i].getTitle() == title) 
			{
                cout << "Book found!" << endl;
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Year: " << books[i].getYear() << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice;

    do {
    	cout << "~-~-~-~-~-~-~-~-~-~-~\n";
    	cout << "     MY LIBRARY\n";
    	cout << "~-~-~-~-~-~-~-~-~-~-~\n\n";
        cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: 
			{
				cout << endl;
                string title, author;
                int year;
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                cin.ignore();
                Book newBook;
                newBook.setBook(title, author, year);
                library.addBook(newBook);
                cout << endl;
                system("pause");
                system("cls");
                break;
            }
            case 2:
            {
            	cout << endl;
                library.displayBooks();
                cout << endl;
                system("pause");
                system("cls");
                break;
            }
            case 3: 
			{
				cout << endl;
                string searchTitle;
                cout << "Enter a book to search: ";
                getline(cin, searchTitle);
                cout << endl;
                library.searchBook(searchTitle);
                cout << endl;
                system("pause");
                system("cls");
                break;
            }
            case 4:
            {
            	cout << endl;
                cout << "Exiting the system." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice, please try again.\n" << endl;
                system("pause");
                system("cls");
            }
        }
    } while (choice != 4);

    return 0;
}
