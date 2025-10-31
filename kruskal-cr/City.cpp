
#include "City.hpp"
std::string cityName(City c) {
    switch (c) {
        case SAN_JOSE: return "San Jose";
        case ALAJUELA: return "Alajuela";
        case CARTAGO: return "Cartago";
        case HEREDIA: return "Heredia";
        case LIMON: return "Limon";
        case PUNTARENAS: return "Puntarenas";
        default: return "Unknown";
    }
}
