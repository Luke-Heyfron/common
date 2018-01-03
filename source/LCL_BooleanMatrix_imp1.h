#include "LCL_BooleanMatrix.h"

#include <iostream>
using namespace std;

#include <ostream>

#include "LCL_ConsoleOut.h"
using namespace LCL_ConsoleOut;

template <int N, int M>
LCL_BooleanMatrix<N,M>::LCL_BooleanMatrix() {
    for(int i = 0; i < _r; i++) {
        for(int j = 0; j < _c; j++) {
            data[i][j]=0;
        }
    }
}

template <int N, int M>
bool LCL_BooleanMatrix<N,M>::operator()(int i ,int j) const {
    bool out = 0;
    if((i>=0) && (i<_r) && (j>=0)&&(j<_c)) {
        out = data[i][j];
    } else {
        error("Index out of bounds.", "operator()", "LCL_BooleanMatrix");
    }
    return out;
}

template <int N, int M>
bool& LCL_BooleanMatrix<N,M>::operator()(int i ,int j) {
    if((i>=0) && (i<_r) && (j>=0)&&(j<_c)) {
        return data[i][j];
    } else {
        error("Index out of bounds.", "operator()", "LCL_BooleanMatrix");
        bool dummy = 0;
        return dummy;
    }
}

template <int N, int M>
int LCL_BooleanMatrix<N,M>::r() const {
    return _r;
}

template <int N, int M>
int LCL_BooleanMatrix<N,M>::c() const {
    return _c;
}

template <int N, int M>
void LCL_BooleanMatrix<N,M>::print(ostream& in_OS) const {
    for(int i = 0; i < _r; i++) {
        for(int j = 0; j < _c; j++) {
            in_OS << data[i][j] << " ";
        }
        in_OS << endl;
    }
}

template <int N, int M>
LCL_BooleanMatrix<N,M> LCL_BooleanMatrix<N,M>::operator+(const LCL_BooleanMatrix& in_Mat) const {
    LCL_BooleanMatrix<N,M> out;

    // Output only defined if operand dimensions match.
    if((_r==in_Mat.r())&&(_c==in_Mat.c())) {
        for(int i = 0; i < _r; i++) {
            for(int j = 0; j < _c; j++) {
                out(i,j) = operator()(i,j)^in_Mat(i,j);
            }
        }
    } else {
        LCL_ConsoleOut::warning("Operand dimensions must match.", "operator+", "LCL_BooleanMatrix");
    }

    return out;
}

template <int N, int M>
LCL_BooleanMatrix<N,M>& LCL_BooleanMatrix<N,M>::operator+=(const LCL_BooleanMatrix& in_Mat) {
    if((_r==in_Mat.r())&&(_c==in_Mat.c())) {
        for(int i = 0; i < _r; i++) {
            for(int j = 0; j < _c; j++) {
                operator()(i,j) ^= in_Mat(i,j);
            }
        }
    } else {
        LCL_ConsoleOut::warning("Operand dimensions must match.", "operator+=", "LCL_BooleanMatrix");
    }

    return (*this);
}
