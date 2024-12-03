#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;
    bool isCheckedOut;

public:
    Book(string title, string author, int pages);

    // Member functions
    void checkOut();
    void checkIn();
    string to_string() const;
    bool isAvailable() const;
};

#endif // BOOK_H