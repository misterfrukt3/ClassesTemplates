#include "planet.h"
#include <iostream>
#include <fstream>
#include <cstring>


int Planet::counter = 0;


Planet::Planet() : planet_(new char[1]), diameter_(0), life_(0), satellite_(0) {
    planet_[0] = '\0';
    id = ++counter;
    std::cout << "Создание ID " << id << std::endl;
}

Planet::Planet(const char* planet, int diameter, int life, int satellite) {
    planet_ = new char[strlen(planet) + 1];
    strcpy(planet_, planet);
    diameter_ = diameter;
    life_ = life;
    satellite_ = satellite;
    id = ++counter;
    std::cout << "Создание ID " << id << std::endl;
}

Planet::Planet(const Planet& p) {
    planet_ = new char[strlen(p.planet_) + 1];
    strcpy(planet_, p.planet_);
    diameter_ = p.diameter_;
    life_ = p.life_;
    satellite_ = p.satellite_;
    id = ++counter;
    std::cout << "Копирование ID " << id << " из ID " << p.id << std::endl;
}


Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        delete[] planet_;
        planet_ = new char[strlen(other.planet_) + 1];
        strcpy(planet_, other.planet_);
        diameter_ = other.diameter_;
        life_ = other.life_;
        satellite_ = other.satellite_;
    }
    std::cout << "Присваивание ID " << id << " <- ID " << other.id << std::endl;
    return *this;
}


Planet::~Planet() {
    std::cout << "Удаление ID " << id << std::endl;
    delete[] planet_;
}

std::istream& operator>>(std::istream& in, Planet& planet) {
    char temp_name[100];
    std::cout << "Введите название планеты: ";
    in >> temp_name;
    planet = Planet(temp_name, 0, 0, 0);
    std::cout << "Введите диаметр: ";
    in >> planet.diameter_;
    std::cout << "Есть ли жизнь (1/0): ";
    in >> planet.life_;
    std::cout << "Введите количество спутников: ";
    in >> planet.satellite_;
    return in;
}

std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << "ID " << planet.id << ": "
       << "Планета: " << planet.planet_
       << ", Диаметр: " << planet.diameter_
       << ", Жизнь: " << (planet.life_ ? "Да" : "Нет")
       << ", Спутники: " << planet.satellite_;
    return os;
}

std::ifstream& operator>>(std::ifstream& fin, Planet& planet) {
    char temp_name[100];
    fin >> temp_name;
    planet = Planet(temp_name, 0, 0, 0);
    fin >> planet.diameter_ >> planet.life_ >> planet.satellite_;
    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Planet& planet) {
    fout << planet.planet_ << " "
         << planet.diameter_ << " "
         << planet.life_ << " "
         << planet.satellite_;
    return fout;
}


bool Planet::operator<(const Planet& other) const {
    return diameter_ < other.diameter_;
}

bool Planet::operator==(const Planet& other) const {
    return strcmp(planet_, other.planet_) == 0;
}

// Геттеры
const char* Planet::getPlanet() const { return planet_; }
int Planet::getDiameter() const { return diameter_; }
int Planet::getLife() const { return life_; }
int Planet::getSatellite() const { return satellite_; }
int Planet::getId() const { return id; }

// Статические методы
int Planet::getCounter() { return counter; }

void Planet::add_planet(Planet*& planets, int& n_planet, int& capacity) {
    if (n_planet >= capacity) {
        int new_capacity = capacity * 2;
        Planet* new_planets = new Planet[new_capacity];
        for (int i = 0; i < n_planet; i++) {
            new_planets[i] = planets[i];
        }
        delete[] planets;
        planets = new_planets;
        capacity = new_capacity;
    }
    Planet new_planet;
    std::cin >> new_planet;
    planets[n_planet] = new_planet;
    n_planet++;
}

void Planet::delete_planet(Planet* planets, int& n_planet, int planet_index) {
    if (planet_index < 0 || planet_index >= n_planet) return;
    for (int i = planet_index; i < n_planet - 1; i++) {
        planets[i] = planets[i + 1];
    }
    n_planet--;
}

int Planet::read_db(const char* file_name, Planet*& planets, int& n_planet, int& capacity) {
    char name[100];
    int diameter = 0, life = 0, satellite = 0;
    n_planet = 0;
    std::ifstream file(file_name);
    if (file) {
        while (file >> name >> diameter >> life >> satellite) {
            if (n_planet >= capacity) {
                int new_capacity = capacity * 2;
                Planet* new_planets = new Planet[new_capacity];
                for (int i = 0; i < n_planet; i++) {
                    new_planets[i] = planets[i];
                }
                delete[] planets;
                planets = new_planets;
                capacity = new_capacity;
            }
            planets[n_planet] = Planet(name, diameter, life, satellite);
            n_planet++;
        }
    } else {
        std::cerr << "Ошибка открытия файла " << file_name << std::endl;
    }
    return n_planet;
}

void Planet::print_db(const Planet* planets, int n_planet) {
    for (int i = 0; i < n_planet; i++) {
        std::cout << planets[i] << std::endl;
    }
}

int Planet::write_db(const char* file_name, const Planet* planets, int n_planet) {
    std::ofstream file(file_name);
    if (file) {
        for (int i = 0; i < n_planet; i++) {
            file << planets[i].getPlanet() << " "
                 << planets[i].getDiameter() << " "
                 << planets[i].getLife() << " "
                 << planets[i].getSatellite() << std::endl;
        }
    } else {
        std::cerr << "Ошибка открытия файла " << file_name << std::endl;
        return -1;
    }
    return 0;
}

int Planet::menu() {
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Прочитать планеты из файла" << std::endl;
    std::cout << "2. Записать планеты в файл" << std::endl;
    std::cout << "3. Изменить данные планеты" << std::endl;
    std::cout << "4. Вывести планеты на экран" << std::endl;
    std::cout << "5. Отсортировать планеты по диаметру" << std::endl;
    std::cout << "6. Отсортировать планеты по названию" << std::endl;
    std::cout << "7. Добавить планету" << std::endl;
    std::cout << "8. Удалить планету" << std::endl;
    std::cout << "9. Выйти" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
}

int Planet::find(const Planet* planets, int n_planet) {
    char name[100];
    std::cout << "Введите название планеты: ";
    std::cin >> name;
    for (int i = 0; i < n_planet; i++) {
        if (strcmp(planets[i].getPlanet(), name) == 0) {
            return i;
        }
    }
    return -1;
}

void Planet::sort_by_diameter(Planet* planets, int n_planet) {
    for (int i = 0; i < n_planet - 1; i++) {
        for (int j = i + 1; j < n_planet; j++) {
            if (planets[i].getDiameter() < planets[j].getDiameter()) {
                Planet temp = planets[i];
                planets[i] = planets[j];
                planets[j] = temp;
            }
        }
    }
}

void Planet::sort_by_name(Planet* planets, int n_planet) {
    for (int i = 0; i < n_planet - 1; i++) {
        for (int j = i + 1; j < n_planet; j++) {
            if (strcmp(planets[i].getPlanet(), planets[j].getPlanet()) > 0) {
                Planet temp = planets[i];
                planets[i] = planets[j];
                planets[j] = temp;
            }
        }
    }
}
