
#pragma once
#include <string>
enum City {
    SAN_JOSE = 0,
    ALAJUELA,
    CARTAGO,
    HEREDIA,
    LIMON,
    PUNTARENAS
};
const int CITY_COUNT = 6;
std::string cityName(City c);
