#include <iostream>
#include "Matrix.h"
#include "MatrixMultithreaded.h"

using namespace std;

typedef unsigned long NumberFormat;

#ifdef THREADS
typedef MatrixMultithreaded<NumberFormat> MatrixType;
#else
typedef Matrix<NumberFormat> MatrixType;
#endif

const unsigned int COL_NBR = 1000;
const unsigned int ROW_NBR = 1000;
const unsigned int INNER_NBR = 1000;

int main() {
    MatrixType a(INNER_NBR, COL_NBR);
    MatrixType b(ROW_NBR, INNER_NBR);

    // a.print();
    // b.print();

    auto result = a * b;
    //result->print();
    delete result;

    return 0;
}
