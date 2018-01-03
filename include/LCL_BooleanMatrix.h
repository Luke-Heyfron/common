#ifndef LCL_BOOLEAN_MATRIX_HEADER
#define LCL_BOOLEAN_MATRIX_HEADER

#include <iostream>
using namespace std;

#include <ostream>

template <int N, int M>
class LCL_BooleanMatrix {
    private:
        bool data[N][M];
        int _r = N;
        int _c = M;
    public:
    // Constructor
    LCL_BooleanMatrix();

    // Output
    void print(ostream& in_OS = cout) const;

    // Accessors
    bool operator()(int i, int j) const;
    bool& operator()(int i, int j);
    int r() const;
    int c() const;

    // Binary Operators
        // Addition
    LCL_BooleanMatrix operator+(const LCL_BooleanMatrix& in_Mat) const;
    LCL_BooleanMatrix& operator+=(const LCL_BooleanMatrix& in_Mat);
        // Multiplication
    LCL_BooleanMatrix operator*(const LCL_BooleanMatrix& in_Mat) const;
    LCL_BooleanMatrix& operator*=(const LCL_BooleanMatrix& in_Mat);
    //LCL_BooleanMatrix operator*(const bool)


    // Row Operators

    // Unary Operators
};

#endif // LCL_BOOLEAN_MATRIX_HEADER
