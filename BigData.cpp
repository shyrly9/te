#include <iostream>
#include <vector>
#include <chrono>
//Se crea clase BigData con vector 
class BigData {
public:
    BigData() {
        std::cout << "Constructor llamado" << std::endl;
        for (int i = 0; i < 1000000; i++) {
            data.push_back(i);
        }
    }

    BigData(const BigData& other) {
        std::cout << "Constructor de copia llamado" << std::endl;
        data = other.data;
    }
   //El constructor move mueven el vector de otro objeto 
    BigData(BigData&& other) noexcept {
        std::cout << "Constructor move llamado" << std::endl;
        data = std::move(other.data);
    }

    BigData& operator=(const BigData& other) {
        std::cout << "Operador de asignación llamado" << std::endl;
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    BigData& operator=(BigData&& other) noexcept {
        std::cout << "Operador de asignación move llamado" << std::endl;
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }

private:
    std::vector<int> data;
};
//Se crea 3 objetos BigData data1,BigData data2, BigData data3
//utilizando la funcion move
//Se mide el tiempo transcurrido utilizando la biblioteca <chrono>
int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    BigData data1;
    BigData data2 = data1;
    BigData data3 = std::move(data1);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Tiempo transcurrido: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " us" << std::endl;

    return 0;
}