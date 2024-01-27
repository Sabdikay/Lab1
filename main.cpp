#include <iostream>
#include "matrix.cpp"
#include "matrix.h"



int main() {
    while (true) {
        try {
            int n = input();
            matrix inputmat = create(n);
            matrix outputmat = createnew(n);

            copymod(inputmat, outputmat);

            std::cout << "\nDisplay before swap:\n";
            display(inputmat);

            std::cout << "\nDisplay after swap:\n";
            display(outputmat);

            free(inputmat);
            free(outputmat);

            break;
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
        catch (const std::bad_alloc& ex){
    std::cerr << "Not enough memory" << std::endl;
}

    }

    return 0;
}
