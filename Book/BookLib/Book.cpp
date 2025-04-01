#include "Book.h"

Book::Book() : book_(nullptr), author_(nullptr), words_(0), weight_(0) {}

Book::Book(const char* book, const char* author, int words, int weight) {
    book_ = new char[strlen(book) + 1];
    strcpy(book_, book);
    author_ = new char[strlen(author) + 1];
    strcpy(author_, author);
    words_ = words;
    weight_ = weight;
}

Book::Book(const Book &b) {
    book_ = new char[strlen(b.book_) + 1];
    strcpy(book_, b.book_);
    author_ = new char[strlen(b.author_) + 1];
    strcpy(author_, b.author_);
    words_ = b.words_;
    weight_ = b.weight_;
}

Book& Book::operator=(const Book &other) {
    if (this != &other) {
        delete[] book_;
        delete[] author_;
        book_ = new char[strlen(other.book_) + 1];
        strcpy(book_, other.book_);
        author_ = new char[strlen(other.author_) + 1];
        strcpy(author_, other.author_);
        words_ = other.words_;
        weight_ = other.weight_;
    }
    return *this;
}

Book::~Book() {
    delete[] book_;
    delete[] author_;
}

const char* Book::getBook() const {
    return book_;
}

const char* Book::getAuthor() const {
    return author_;
}

int Book::getWords() const {
    return words_;
}

int Book::getWeight() const {
    return weight_;
}

std::istream& operator>>(std::istream &in, Book &book) {
    char tempBook[100], tempAuthor[100];
    std::cout << "Введите название книги: ";
    in >> tempBook;
    std::cout << "Введите автора книги: ";
    in >> tempAuthor;
    std::cout << "Введите количество слов: ";
    in >> book.words_;
    std::cout << "Введите вес книги: ";
    in >> book.weight_;

    book.book_ = new char[strlen(tempBook) + 1];
    strcpy(book.book_, tempBook);
    book.author_ = new char[strlen(tempAuthor) + 1];
    strcpy(book.author_, tempAuthor);

    return in;
}

std::ostream& operator<<(std::ostream &os, const Book &book) {
    os << "Книга: " << book.book_ << ", Автор: " << book.author_
       << ", Слова: " << book.words_ << ", Вес: " << book.weight_;
    return os;
}

void Book::addBook(Book*& books, int &nBooks, int &capacity) {
    if (nBooks >= capacity) {
        capacity *= 2;
        Book* temp = new Book[capacity];
        for (int i = 0; i < nBooks; i++) {
            temp[i] = books[i];
        }
        delete[] books;
        books = temp;
    }
    std::cin >> books[nBooks];
    nBooks++;
}

void Book::deleteBook(Book* books, int &nBooks, int bookIndex) {
    if (bookIndex < 0 || bookIndex >= nBooks) return;
    for (int i = bookIndex; i < nBooks - 1; i++) {
        books[i] = books[i + 1];
    }
    nBooks--;
}

int Book::readDB(const char* fileName, Book*& books, int &nBooks, int &capacity) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << fileName << std::endl;
        return -1;
    }

    char tempBook[100], tempAuthor[100];
    int words, weight;

    while (file >> tempBook >> tempAuthor >> words >> weight) {
        if (nBooks >= capacity) {
            capacity *= 2;
            Book* temp = new Book[capacity];
            for (int i = 0; i < nBooks; i++) {
                temp[i] = books[i];
            }
            delete[] books;
            books = temp;
        }
        books[nBooks] = Book(tempBook, tempAuthor, words, weight);
        nBooks++;
    }
    file.close();
    return nBooks;
}

int Book::menu() {
    std::cout << "\nМеню:\n"
              << "1. Чтение из файла\n"
              << "2. Запись в файл\n"
              << "3. Редактировать книгу\n"
              << "4. Вывести книги\n"
              << "5. Сортировать по автору\n"
              << "6. Сортировать по названию\n"
              << "7. Добавить книгу\n"
              << "8. Удалить книгу\n"
              << "9. Выйти\n";
    int choice = 0;
    std::cin >> choice;
    return choice;
}

void Book::printDB(Book* books, int nBooks) {
    for (int i = 0; i < nBooks; i++) {
        std::cout << books[i] << std::endl;
    }
}

int Book::writeDB(const char* fileName, Book* books, int nBooks) {
    std::ofstream file(fileName);
    if (!file) return -1;
    for (int i = 0; i < nBooks; i++) {
        file << books[i] << std::endl;
    }
    file.close();
    return 0;
}

int Book::find(Book* books, int nBooks) {
    std::cout << "Введите название книги: ";
    char bookName[100];
    std::cin >> bookName;
    for (int i = 0; i < nBooks; i++) {
        if (strcmp(bookName, books[i].getBook()) == 0) {
            return i;
        }
    }
    return -1;
}

void Book::sortByAuthor(Book* books, int nBooks) {
    for (int i = 0; i < nBooks - 1; i++) {
        for (int j = i + 1; j < nBooks; j++) {
            if (strcmp(books[i].getAuthor(), books[j].getAuthor()) > 0) {
                std::swap(books[i], books[j]);
            }
        }
    }
}

void Book::sortByName(Book* books, int nBooks) {
    for (int i = 0; i < nBooks - 1; i++) {
        for (int j = i + 1; j < nBooks; j++) {
            if (strcmp(books[i].getBook(), books[j].getBook()) > 0) {
                std::swap(books[i], books[j]);
            }
        }
    }
}
