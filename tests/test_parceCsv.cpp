#include <iostream>
#include "csv.h"

int main() {
    TableData data = parseCsvNoHeaders("test.csv");

    if (!data.body.empty()) {
        std::cout << "Первая строка:\n";
        for (const auto& field : data.body[0]) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Файл пуст или не найден.\n";
    }

    return 0;
}
