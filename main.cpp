#include "PLanetLib/planet.h"
#include <iostream>

void wait_for_continue() {
    char choice;
    std::cout << "Продолжить? (y/n): ";
    std::cin >> choice;
    if (choice == 'n' || choice == 'N') {
        exit(0); // Завершение программы
    }
}

int main(int argc, char* argv[]) {
    const int INITIAL_CAPACITY = 10;
    const char* file_name = "planets.txt";
    Planet* planets = new Planet[INITIAL_CAPACITY];
    int n_planet = 0;
    int capacity = INITIAL_CAPACITY;

    if (argc == 1) {
        while (true) {
            int choice = Planet::menu();
            switch (choice) {
                case READ_FROM_FILE: {
                    int result = Planet::read_db(file_name, planets, n_planet, capacity);
                    if (result > 0) {
                        std::cout << "Файл успешно прочитан. Загружено планет: " << result << std::endl;
                    } else if (result == 0) {
                        std::cout << "Файл пуст." << std::endl;
                    } else {
                        std::cout << "Ошибка чтения файла." << std::endl;
                    }
                    wait_for_continue();
                    break;
                }
                case WRITE_TO_FILE: {
                    int result = Planet::write_db(file_name, planets, n_planet);
                    if (result == 0) {
                        std::cout << "Данные успешно записаны в файл." << std::endl;
                    } else {
                        std::cout << "Ошибка записи в файл." << std::endl;
                    }
                    wait_for_continue();
                    break;
                }
                case EDIT_PLANET: {
                    if (n_planet == 0) {
                        std::cout << "Список планет пуст." << std::endl;
                    } else {
                        int index = Planet::find(planets, n_planet);
                        if (index >= 0) {
                            std::cin >> planets[index];
                            std::cout << "Данные планеты обновлены." << std::endl;
                        } else {
                            std::cout << "Планета не найдена." << std::endl;
                        }
                    }
                    wait_for_continue();
                    break;
                }
                case PRINT_BOOKS: {
                    if (n_planet == 0) {
                        std::cout << "Список планет пуст." << std::endl;
                    } else {
                        Planet::print_db(planets, n_planet);
                    }
                    wait_for_continue();
                    break;
                }
                case SORT_BY_DIAMETER: {
                    if (n_planet == 0) {
                        std::cout << "Список планет пуст." << std::endl;
                    } else {
                        Planet::sort_by_diameter(planets, n_planet);
                        std::cout << "Планеты отсортированы по диаметру." << std::endl;
                    }
                    wait_for_continue();
                    break;
                }
                case SORT_BY_NAME: {
                    if (n_planet == 0) {
                        std::cout << "Список планет пуст." << std::endl;
                    } else {
                        Planet::sort_by_name(planets, n_planet);
                        std::cout << "Планеты отсортированы по названию." << std::endl;
                    }
                    wait_for_continue();
                    break;
                }
                case ADD_BOOK: {
                    Planet::add_planet(planets, n_planet, capacity);
                    std::cout << "Планета добавлена." << std::endl;
                    wait_for_continue();
                    break;
                }
                case DELETE_BOOK: {
                    if (n_planet == 0) {
                        std::cout << "Список планет пуст." << std::endl;
                    } else {
                        int index = Planet::find(planets, n_planet);
                        if (index >= 0) {
                            Planet::delete_planet(planets, n_planet, index);
                            std::cout << "Планета удалена." << std::endl;
                        } else {
                            std::cout << "Планета не найдена." << std::endl;
                        }
                    }
                    wait_for_continue();
                    break;
                }
                case EXIT_PROGRAM:
                    delete[] planets;
                    return 0;
                default:
                    std::cout << "Неправильный выбор." << std::endl;
                    wait_for_continue();
                    break;
            }
        }
    } else if (argc > 1 && strcmp(argv[1], "d") == 0) {
        n_planet = Planet::read_db(file_name, planets, n_planet, capacity);
        Planet::print_db(planets, n_planet);
        std::cout << std::endl;

        Planet::add_planet(planets, n_planet, capacity);
        Planet::print_db(planets, n_planet);
        std::cout << std::endl;

        Planet::sort_by_name(planets, n_planet);
        Planet::print_db(planets, n_planet);
        std::cout << std::endl;

        Planet::delete_planet(planets, n_planet, 1);
        Planet::print_db(planets, n_planet);
    }

    delete[] planets;
    return 0;
}
