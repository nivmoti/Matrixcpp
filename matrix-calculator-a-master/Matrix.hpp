#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;
namespace zich
{
    class Matrix
    {
    private:
        vector<vector<double>> ve;
        int row,col;
    public:
        Matrix();
        Matrix (const vector<double> &ve,const int &rows,const int &cols);
        Matrix(const Matrix &other);
        ~Matrix ();
        Matrix& operator=(const Matrix &other );
        Matrix  operator -()const;
        Matrix  operator -(const Matrix &other)const;
        Matrix  operator +(const Matrix &other)const ;
        Matrix  operator*(const Matrix &other)const;
        Matrix  operator*(const int &num)const;
        friend std::ostream &operator<<(std::ostream &os, const Matrix &m) {
         return os;
          }
        friend  Matrix operator *(const int & num,const Matrix &m)
        {
          return (m*num);
        }
        friend Matrix operator +(const int &num,const Matrix &t)
        {
          return (num+t);
        }
        Matrix operator*=(const Matrix &other);
        Matrix operator*=(const int &num);
        Matrix operator+=(const Matrix &other);
        Matrix operator-=(const Matrix &other);
        bool operator!() const{return true;}
        friend bool operator==(const Matrix& c1, const Matrix& c2);
        friend bool operator!=(const Matrix& c1, const Matrix& c2);
        friend bool operator>(const Matrix& c1, const Matrix& c2);
        friend bool operator>=(const Matrix& c1, const Matrix& c2);
        friend bool operator<=(const Matrix& c1, const Matrix& c2);
        friend bool operator<(const Matrix& c1, const Matrix& c2);
        friend std::istream& operator>> (std::istream& input , Matrix& c);
        Matrix& operator++(){Matrix temp;
        return *this;}
        Matrix& operator++(int flag){Matrix temp;
        return *this;}
         Matrix& operator--(){Matrix temp;
        return *this;}
        Matrix& operator--(int flag){Matrix temp;
        return *this;}

    };
    
    
    
} // namespace zich