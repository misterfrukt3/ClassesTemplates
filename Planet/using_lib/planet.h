#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <fstream>
#include <cstring>

enum MenuOption {
    READ_FROM_FILE = 1,
    WRITE_TO_FILE,
    EDIT_PLANET,
    PRINT_PLANETS,
    SORT_BY_DIAMETER,
    SORT_BY_NAME,
    ADD_PLANET,
    DELETE_PLANET,
    EXIT_PROGRAM
};

class Planet {
private:
    char* planet_;
    int diameter_, life_, satellite_;

public:
    Planet();
    Planet(const char* planet, int diameter, int life, int satellite);
    Planet(const Planet& p);
    Planet& operator=(const Planet& other);
    ~Planet();

    friend std::istream& operator>>(std::istream& in, Planet& planet);
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);

    const char* getPlanet() const;
    int getDiameter() const;
    int getLife() const;
    int getSatellite() const;

    void clear();

    static void add_planet(Planet*& planets, int& n_planet, int& capacity);
    static void delete_planet(Planet* planets, int& n_planet, int planet_index);
    static int read_db(const char* file_name, Planet*& planets, int& n_planet, int& capacity);
    static int menu();
    static void print_db(const Planet* planets, int n_planet);
    static int write_db(const char* file_name, const Planet* planets, int n_planet);
    static int find(const Planet* planets, int n_planet);
    static void sort_by_diameter(Planet* planets, int n_planet);
    static void sort_by_name(Planet* planets, int n_planet);
};

#endif // PLANET_H
