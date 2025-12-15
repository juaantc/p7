#include "catalog.h"
#include <iostream>

int main(){

    CyclistCatalog catalog;

    //1. Crear los ciclistas
    Cyclist c1{"Carlos Ramos", 1999, "BMW Pro Cycling Team", "d2a1x056"};
    Cyclist c2{"Mateu Lahoz", 1989, "BMW Pro Cycling Team", "d666b062"};
    Cyclist c3{"Mikel Oyarzabal", 2002, "Mercedes Pro Cycling Team", "d500b003"};
    Cyclist c4{"Isi Palazon", 2001, "Mercedes Pro Cycling Team", "d543b004"};

    std::cout << "Anadiendo ciclistas con operador << ..." << std::endl;

    //2. Usar el operador << en tandas (encadenamiento)
    catalog << c1 << c2;

    std::cout << "Anadidos los ciclistas c1 y c2. Tamano actual: " << catalog.Size() << std::endl;

    catalog << c3 << c4;

    std::cout << "Anadidos los ciclistas c3 y c4. Tamano final: " << catalog.Size() << std::endl;

    //3. Mostrar la tabla de ciclistas
    std::cout << "\n=== LISTADO DE CICLISTAS ===\n" << std::endl;

    std::vector <Cyclist> v = catalog.Data();

    //Recorro cyclist.csv con un bucle for

    for(const auto& c : v){
        std::cout << c.GetName() << " (" << c.GetBirthYear() << " ) - "
        << c.GetTeam() << " [" << c.GetCyclistId() << " ]" << std::endl;
    }

std::cout << "----- PROGRAMA FINALIZADO -----";
return 0;

}