#include<iostream>
using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    int year;
    Book* prev;
    Book* next;
};

class Library {
private:
    Book *start, *cur, *temp;

public:
    Library() {
        start = NULL;
    }

    void insertBook(string isbn, string title, string author, int year) {
        temp = new Book{isbn, title, author, year, NULL, NULL};

        if (start == NULL)
            start = temp;
        else {
            cur = start;
            while (cur->next != NULL)
                cur = cur->next;

            cur->next = temp;
            temp->prev = cur;
        }
        cout << "Book Inserted\n";
    }

    void searchBook(string key) {
        cur = start;
        while (cur != NULL) {
            if (cur->isbn == key || cur->title == key) {
                cout << "Found: " << cur->title << ", " << cur->author << ", " << cur->year << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Book Not Found\n";
    }

    
    void modifyBook(string isbn) {
        cur = start;
        while (cur != NULL) {
            if (cur->isbn == isbn) {
                cout << "New Title: ";
                cin >> cur->title;
                cout << "New Author: ";
                cin >> cur->author;
                cout << "New Year: ";
                cin >> cur->year;
                cout << "Record Updated\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Book Not Found\n";
    }

    void displayBooks() {
        if (start == NULL) {
            cout << "Library Empty\n";
            return;
        }

        cur = start;
        int count = 0;
        while (cur != NULL) {
            cout << cur->isbn << " | " << cur->title << " | "
                 << cur->author << " | " << cur->year << endl;
            cur = cur->next;
            count++;
        }
        cout << "Total Books: " << count << endl;
    }
};
int main() {
    Library lib;
    int ch, year;
    string isbn, title, author, key;

    do{
        cout << "\n1.Insert 2.Search 3.Modify 4.Display 5.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "ISBN: "; cin >> isbn;
            cout << "Title: "; cin >> title;
            cout << "Author: "; cin >> author;
            cout << "Year: "; cin >> year;
            lib.insertBook(isbn, title, author, year);
            break;

        case 2:
            cout << "Enter ISBN/Title: "; cin >> key;
            lib.searchBook(key);
            break;

        case 3:
            cout << "ISBN to modify: "; cin >> key;
            lib.modifyBook(key);
            break;

        case 4:
            lib.displayBooks();
            break;
        }

    } while (ch != 5);

    return 0;
}