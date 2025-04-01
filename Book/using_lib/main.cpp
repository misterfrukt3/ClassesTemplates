#include "Book.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    const int INITIAL_CAPACITY = 10;
    Book* books = new Book[INITIAL_CAPACITY];
    int nBooks = 0, capacity = INITIAL_CAPACITY;
    char fileName[100];

    if (argc > 1 && strcmp(argv[1], "i") == 0) {
        while (true) {
            int choice = Book::menu();
            if (choice < 1 || choice > 9) {
                std::cout << "Ошибка: введите число от 1 до 9.\n";
                continue;
            }

            switch (static_cast<MenuOption>(choice)) {
                case READ_FROM_FILE:
                    std::cout << "Введите имя файла: ";
                    std::cin >> fileName;
                    if (Book::readDB(fileName, books, nBooks, capacity) == -1) {
                        std::cout << "Ошибка чтения файла.\n";
                    }
                    break;
                case WRITE_TO_FILE:
                    std::cout << "Введите имя файла: ";
                    std::cin >> fileName;
                    if (Book::writeDB(fileName, books, nBooks) == -1) {
                        std::cout << "Ошибка записи файла.\n";
                    }
                    break;
                case EDIT_BOOK:
                    if ((choice = Book::find(books, nBooks)) >= 0) {
                        std::cin >> books[choice];
                    } else {
                        std::cout << "Книга не найдена.\n";
                    }
                    break;
                case PRINT_BOOKS:
                    Book::printDB(books, nBooks);
                    break;
                case SORT_BY_AUTHOR:
                    Book::sortByAuthor(books, nBooks);
                    break;
                case SORT_BY_NAME:
                    Book::sortByName(books, nBooks);
                    break;
                case ADD_BOOK:
                    Book::addBook(books, nBooks, capacity);
                    break;
                case DELETE_BOOK:
                    if ((choice = Book::find(books, nBooks)) >= 0) {
                        Book::deleteBook(books, nBooks, choice);
                    } else {
                        std::cout << "Книга не найдена.\n";
                    }
                    break;
                case EXIT_PROGRAM:
                    delete[] books;
                    return 0;
                default:
                    break;
            }
        }
    } else {
        std::cout << "Используйте аргумент 'i' для интерактивного режима.\n";
    }

    delete[] books;
    return 0;
}
