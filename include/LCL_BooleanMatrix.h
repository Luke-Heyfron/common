#ifndef LCL_BOOLEAN_MATRIX_HEADER
#define LCL_BOOLEAN_MATRIX_HEADER

#include <iostream>
using namespace std;

#include <ostream>

// N and M are max number of rows and columns,respectively. Actual number of rows and columns _r and _c may be less.

template <int N, int M>
class LCL_BooleanMatrix {
    public:
        int r;  //Change these to type LCL_BoundedInt
        int c;
    private:
        bool data[N][M];
    public:
    // Constructor
    LCL_BooleanMatrix();
    LCL_BooleanMatrix(int in_r, int in_c);

    // Output
    void print(ostream& in_OS = cout) const;

    // Accessors
    bool operator()(int i, int j) const;
    bool& operator()(int i, int j);

    // Binary Operators
        // Addition
    LCL_BooleanMatrix operator+(const LCL_BooleanMatrix& in_Mat) const;
    LCL_BooleanMatrix& operator+=(const LCL_BooleanMatrix& in_Mat);
        // Multiplication
    //template <int P>
    LCL_BooleanMatrix operator*(const LCL_BooleanMatrix& in_Mat) const;
    LCL_BooleanMatrix& operator*=(const LCL_BooleanMatrix& in_Mat);


    // Row Operators

    // Unary Operators

};

// Constants

const int LCL_SMALL = 1E1;
const int LCL_MEDIUM = 1E2;
const int LCL_LARGE = 1E3;

#endif // LCL_BOOLEAN_MATRIX_HEADER
