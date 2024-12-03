#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Book.h"
using namespace std;

TEST_CASE("Test can create and render a Book Object") {
    Book myBook("Moby-Dick", "Herman Melville", 635);
    CHECK(myBook.to_string() == "Book Title: Moby-Dick, Author: Herman Melville, Pages: 635, Status: Available");
}

TEST_CASE("Test check out functionality") {
    Book myBook("1984", "George Orwell", 328);
    myBook.checkOut();
    CHECK(myBook.to_string() == "Book Title: 1984, Author: George Orwell, Pages: 328, Statu: Checked Out"); // Typo in "Status"
}

TEST_CASE("Test check in functionality") {
    Book myBook("To Kill a Mockingbird", "Harper Lee", 281);
    myBook.checkOut();
    myBook.checkIn();
    CHECK(myBook.to_string() == "Book Title: To Kill a Mockingbird, Author: Harper Lee, Pages: 281, Status: Available");
}
