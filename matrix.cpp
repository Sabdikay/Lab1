#include <iostream>
#include <limits>
#include"matrix.h"




int input() {
    int n;
    while (true) {
        std::cout << "Enter n :\n";
        if (!(std::cin >> n)) {
            if (std::cin.eof()) {
                std::cout << "EOF detected. Exiting...\n";
                throw std::runtime_error("EOF detected");
            }
            std::cout << "Please enter a number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (n <= 0) {
            std::cout << "Error: Please enter a positive number for n.\n";
        } else {
            return n;
        }
    }
}

matrix create(int n) {
    matrix mat;
    try {
        mat.data = new double*[n];
        mat.rc = n;
        for (int i = 0; i < n; ++i) {
            mat.data[i] = new double[n];
        }

        std::cout << "Input the elements:\n";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                while (!(std::cin >> mat.data[i][j])) {
                    if (std::cin.eof()) {
                        std::cout << "EOF detected. Cleaning up...\n";
                        throw std::runtime_error("EOF detected");
                    }
                    std::cout << "Please enter a valid number\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                mat.data[j][i] = mat.data[i][j];
            }
        }
    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation failed. Exiting...\n";
        throw;
    }
    return mat;
}

matrix createnew(int n) {
    matrix mat;
    try {
        mat.data = new double*[n];
        mat.rc = n;
        for (int i = 0; i < n; ++i) {
            mat.data[i] = new double[n];
        }
    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation failed. Exiting...\n";
        throw;
    }
    return mat;
}

void copymod(const matrix &inputmat, matrix &outputmat) {
    int s = inputmat.rc;

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            outputmat.data[i][j] = inputmat.data[i][j];
        }

        double minvalue = outputmat.data[i][0];
        double maxvalue = outputmat.data[i][0];
        int minIndices[s];
        int maxIndices[s];
        int minCount = 0;
        int maxCount = 0;

        for (int j = 0; j < s; j++) {
            if (outputmat.data[i][j] < minvalue) {
                minvalue = outputmat.data[i][j];
                minCount = 0;
                minIndices[minCount++] = j;
            } else if (outputmat.data[i][j] == minvalue) {
                minIndices[minCount++] = j;
            }

            if (outputmat.data[i][j] > maxvalue) {
                maxvalue = outputmat.data[i][j];
                maxCount = 0;
                maxIndices[maxCount++] = j;
            } else if (outputmat.data[i][j] == maxvalue) {
                maxIndices[maxCount++] = j;
            }
        }

        for (int k = 0; k < minCount; k++) {
            for (int l = 0; l < maxCount; l++) {
                double temp = outputmat.data[i][minIndices[k]];
        outputmat.data[i][minIndices[k]] = outputmat.data[i][maxIndices[l]];
        outputmat.data[i][maxIndices[l]] = temp;
    }
}
}
}

void free(matrix &mat) {
    for (int i = 0; i < mat.rc; ++i) {
        delete[] mat.data[i];
    }
    delete[] mat.data;
}

void display(const matrix &mat) {
    for (int i = 0; i < mat.rc; i++) {
        for (int j = 0; j < mat.rc; j++) {
            std::cout << mat.data[i][j] << " ";
        }
        std::cout << "\n";
    }
}
