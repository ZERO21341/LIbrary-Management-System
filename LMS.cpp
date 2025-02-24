#include <iostream>
#include <vector>
using namespace std;

class Books {
public:
    string title;
    string author;
    int ReleaseDate;
    string Genre;
    double rating;

    Books(string title, string author, int ReleaseDate, string Genre, double rating) {
        this->title = title;
        this->author = author;
        this->ReleaseDate = ReleaseDate;
        this->Genre = Genre;
        this->rating = rating;
    }

    void display() {
        cout << "**************************************" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Release Date: " << ReleaseDate << endl;
        cout << "Genre: " << Genre << endl;
        cout << "Rating: " << rating << endl;
        cout << "**************************************" << endl;
    }
};

int main() {
    
    int choice;
    vector<Books> bookCollection;
    do {
        cout << "Menu:"<<endl;;
        cout << "1. Add a Book"<<endl;
        cout << "2. Remove a Book"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
              
                string title, author, Genre;
                int ReleaseDate;
                double rating;

                cout << "Enter Book Title: ";
                getline(cin, title);

                cout << "Enter Book Author: ";
                getline(cin, author);

                cout << "Enter Publication Date: ";
                cin >> ReleaseDate;
                cin.ignore();

                cout << "Enter Genre: ";
                getline(cin, Genre);

                cout << "Enter Rating: ";
                cin >> rating;
                cin.ignore();

                bookCollection.push_back(Books(title, author, ReleaseDate, Genre, rating));
                cout << "Book added successfully!\n";
                break;
            }

            case 2: {
                if (bookCollection.empty()) {
                    cout << "No books available to remove.\n";
                    break;
                }

                int removeIndex;
                cout << "Enter the Book ID to remove (1 to " << bookCollection.size() << "): ";
                cin >> removeIndex;
                cin.ignore();

                if (removeIndex < 1 || removeIndex > bookCollection.size()) {
                    cout << "Invalid Book ID!\n";
                } else {
                    bookCollection.erase(bookCollection.begin() + (removeIndex - 1));
                    cout << "Book removed successfully!\n";
                }
                break;
            }

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
