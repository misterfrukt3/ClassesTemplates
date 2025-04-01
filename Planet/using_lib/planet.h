#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <fstream>

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
    int diameter_;
    int life_;
    int satellite_;
    static int counter;
    int id;

public:
    Planet();
    Planet(const char* planet, int diameter, int life, int satellite);
    Planet(const Planet& p);
    Planet& operator=(const Planet& other);
    ~Planet();


    friend std::istream& operator>>(std::istream& in, Planet& planet);
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    friend std::ifstream& operator>>(std::ifstream& fin, Planet& planet);
    friend std::ofstream& operator<<(std::ofstream& fout, const Planet& planet);


    bool operator<(const Planet& other) const;
    bool operator==(const Planet& other) const;


    const char* getPlanet() const;
    int getDiameter() const;
    int getLife() const;
    int getSatellite() const;
    int getId() const;

    static int getCounter();
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
