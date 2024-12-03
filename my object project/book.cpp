#include "Book.h"

Book::Book(string title, string author, int pages)
    : title(title), author(author), pages(pages), isCheckedOut(false) {}

void Book::checkOut() {
    if (!isCheckedOut) {
        isCheckedOut = true;
    }
}

void Book::checkIn() {
    if (isCheckedOut) {
        isCheckedOut = false;
    }
}

string Book::to_string() const {
    return "Book Title: " + title + ", Author: " + author + 
           ", Pages: " + std::to_string(pages) + 
           ", Status: " + (isCheckedOut ? "Checked Out" : "Available");
}

bool Book::isAvailable() const {
    return !isCheckedOut;
}