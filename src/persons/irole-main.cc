#include "persons.h"
#include <string>
#include <iostream>

int main(void){

    Cyclist c1("Jonathan Milan", 2000, "bahrain victorious", "c0a1b408");
    Director d1("Gorazd Stangelj", 1973, "bahrain victorious", "d0a1b005", 2012);
    Journalist j1("Manolo Lama", 1980, "ESPN");

    c1.SetComment("Hoy no he pedaleado cuesta abajo.");

    d1.SetComment("El equipo va a cobrar tras haber ganado la carrera.");

    j1.SetComment("c0a1b407", "Haig no ha aguantado hasta el final.");
    j1.SetComment("c0a1b408", "Milan prefiere bici electrica en pendientes.");
    j1.SetComment("c0a1b409", "Bauhaus no tiene suerte con las lesiones.");

    std::cout << "=== CICLISTA ===" << std::endl;
    std::cout << PrintComment(&c1) << std::endl;

    std::cout << "=== DIRECTOR ===" << std::endl;
    std::cout << PrintComment(&d1) << std::endl;

    std::cout << "=== PERIODISTA ===" << std::endl;
    std::cout << PrintComment(&j1) << std::endl;

    return 0;
}