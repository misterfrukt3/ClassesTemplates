#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <cstring>

enum MenuOption {
    READ_FROM_FILE = 1,
    WRITE_TO_FILE = 2,
    EDIT_BOOK,
    PRINT_BOOKS,
    SORT_BY_AUTHOR,
    SORT_BY_NAME,
    ADD_BOOK,
    DELETE_BOOK,
    EXIT_PROGRAM
};

class Book {
private:
    char* book_;
    char* author_;
    int words_;
    int weight_;
public:
    Book();
    Book(const char* book, const char* author, int words, int weight);
    Book(const Book &b);
    Book& operator=(const Book &other);
    ~Book();

    // Геттеры
    const char* getBook() const;
    const char* getAuthor() const;
    int getWords() const;
    int getWeight() const;

    // Друзья для перегрузки операторов ввода/вывода
    friend std::istream& operator>>(std::istream &in, Book &book);
    friend std::ostream& operator<<(std::ostream &os, const Book &book);

    // Статические методы для работы с базой книг
    static void addBook(Book*& books, int &nBooks, int &capacity);
    static void deleteBook(Book* books, int &nBooks, int bookIndex);
    static int readDB(const char* fileName, Book*& books, int &nBooks, int &capacity);
    static int menu();
    static void printDB(Book* books, int nBooks);
    static int writeDB(const char* fileName, Book* books, int nBooks);
    static int find(Book* books, int nBooks);
    static void sortByAuthor(Book* books, int nBooks);
    static void sortByName(Book* books, int nBooks);
};

#endif // BOOK_H
