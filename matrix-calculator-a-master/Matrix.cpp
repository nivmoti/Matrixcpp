#include "Matrix.hpp"
namespace zich{
    Matrix::Matrix() {
    this->col=0;
    this->row=0;
    this->ve={{0},{0}};
    }
    Matrix::~Matrix(){};
    Matrix::Matrix(const vector<double> &ve,const int &row,const int &col)
    {this->col=0;
    this->row=0;
    this->ve={{0},{0}};
    }
    Matrix::Matrix(const Matrix &other)
     {this->col=0;
    this->row=0;
    this->ve={{0},{0}};
    }
    Matrix Matrix::operator*=(const Matrix &other){
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator*=(const int &num){
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator+=(const Matrix &other){
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator-=(const Matrix &other){
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator-()const{
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator-(const Matrix &other)const{
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator+(const Matrix &other)const{
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator*(const int &num)const{
        Matrix temp;
        return temp;
    }
    Matrix Matrix::operator*(const Matrix &other)const{
        Matrix temp;
        return temp;
    }
    Matrix& Matrix::operator=(const Matrix &other){
        return *this;
    }
    
    bool operator==(const Matrix& c1, const Matrix& c2){return true;}
    bool operator!=(const Matrix& c1, const Matrix& c2){return true;}
    bool operator>=(const Matrix& c1, const Matrix& c2){return true;}
    bool operator<=(const Matrix& c1, const Matrix& c2){return true;}
    bool operator>(const Matrix& c1, const Matrix& c2){return true;}
    bool operator<(const Matrix& c1, const Matrix& c2){return true;}

}