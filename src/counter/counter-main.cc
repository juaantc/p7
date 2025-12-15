#include "counter.h"
#include <iostream>

int main(){
    
    std::cout << "=== PRUEBA DE LA CLASE COUNTER ===" << std::endl;

    Counter c(500, 0, 1000);
    std::cout << "1. Inicio c: " << c << " (Min: " << c.GetMin() << ", Max: " << c.GetMax() << ")" << std::endl;

    c++;
    std::cout << "2. c++ -> " << c << std::endl;
    ++c;
    std::cout << "3. ++c -> " << c << std::endl;

    c--;
    std::cout << "4. c-- -> " << c << std::endl;
    --c;
    std::cout << "5. --c -> " << c << std::endl;

    std::cout << "6. Suma (Counter + int): c + 2000..." << std::endl;
    c = c + 2000;
    std::cout << "      Resultado: " << c << " (Tope 1000)" <<std::endl;

    std::cout << "7. Suma (int + Counter): 10 + c..." << std::endl;
    c = 10 + c;
    std::cout << "      Resultado: " << c << " (Sigue en tope 1000)" <<std::endl;

    std::cout << "8. Resta (Counter - int): c - 2000..." << std::endl;
    c = c - 2000;
    std::cout << "      Resultado: " << c << " (Tope 0)" << std::endl;

    std::cout << "9. Resta (int - Counter): 100 - c..." << std::endl;
    c = 100 - c;
    std::cout << "      Resultado: " << c << " (Debería ser 100)" << std::endl;

    Counter d(50);
    std::cout << "10. Asignacion de objeto: c = d (donde d=50)..." << std::endl;
    c = d;
    std::cout << "      Valor de c: " << c << std::endl;

    std::cout << "11. Prueba de entrada (>>). Introduce un valor valido (0-1000): " << std::endl;
    if(std::cin >> c){
        std::cout << "      Valor introducido: " << c << std::endl;
    }

    std::cout << "----- PROGRAMA FINALIZADO -----";
    return 0;
}