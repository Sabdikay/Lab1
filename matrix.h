#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED


struct matrix {
    double **data;
    int rc;

};

int input();
matrix create(int n);
matrix createnew(int n);
void copymod(const matrix &inputmat, matrix &outputmat);
void display(const matrix &mat);
void free(matrix &mat);



#endif // MATRIX_H_INCLUDED
