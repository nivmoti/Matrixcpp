#include "Matrix.hpp"

namespace zich{
    const int digitmin=48;
    const int digitmax = 57;
    Matrix::Matrix() {
    this->col=0;
    this->row=0;
    this->sum=0;
    this->ve={{0},{0}};
    }
    Matrix::~Matrix(){
     for (unsigned long i = 0; i < this->row; i++)
     {
         this->ve.at(i).clear();
         
     }
     this->ve.clear();
     

    }
    void Matrix::SetMatrix(const vector<double> &ve,const int &rows,const int &cols,Matrix& s) const{
        Matrix temp(ve,row,col);
        s.col=temp.col;
        s.row=temp.row;
        s.ve=temp.ve;
        s.sum=temp.sum;
    }
    Matrix::Matrix(const vector<double> &ve,const int &row,const int &col)
    {if(row<=0||col<=0){throw std::out_of_range("row and col annot be negative number");}
    this->col=col;
    this->row=row;
    if(col*row!=ve.size()){throw std::out_of_range("vector and size not match");}
    unsigned long k=0;
    for (int i = 0; i < row; i++)
    {
        vector<double> r;
        for (int j = 0; j < col; j++)
        {
            if(k>=ve.capacity()){
                r.push_back(0);
            }
            else{
            r.push_back(ve.at(k));
            this->sum+=ve.at(k);
            k++;
            }
        }
        this->ve.push_back(r);
        
    }
    this->CheckSum();
    
    }
    Matrix::Matrix(const Matrix &other)
     {this->col=other.col;
    this->row=other.row;
    this->ve=other.ve;
    this->sum=other.sum;
    }
    Matrix& Matrix::operator*=(const Matrix &other){
        // vector<double> t={0};
        // Matrix temp(t,this->col,other.row);
        //  for(unsigned long i=0;i<this->row;i++){
        //    for(unsigned long j=0;j<other.col;j++){
        //      for(unsigned long k =0;k<this->col;k++){
        //          temp.ve[i][j]+=this->ve[i][k]*other.ve[k][j];
        //      }
        //    }
        //  }
        
        // temp.CheckSum();
        *this=*this*other;
        return *this;
    }
    Matrix& Matrix::operator*=(const int &num){
         for(unsigned long i=0;i<this->row;i++){
           for(unsigned long j=0;j<this->col;j++){
             this->ve[i][j]*=num;
           }
         }
        
        this->CheckSum();
        return *this;
    }
    void Matrix::CheckSum(){
        double sum=0;
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                sum+=ve[i][j];
            }
            
        }
        
        this->sum=sum;
    }
    vector<int> Matrix::CheckInput(const string &str){
        stringstream os = stringstream(str);
        char ch=0;
        double x=0;
        int colthi=0;
        int colsave=0;
        int row=0;
        while (!os.eof()){
            os >> ch;
             if (ch != '[' || os.peek() < digitmin || os.peek() > digitmax)
        {
            throw invalid_argument("String is  not in the right format\n");
        }
        colthi=0;
        while (os.peek() != ']' && !os.eof())
        {
            
            os >> x;
            colthi++;
            if (colthi > colsave && colsave > 0)
            {
                throw invalid_argument("String is not  in the right format\n");
                
            }
            
        }
         if (colthi == 0)
        {
            throw invalid_argument("String is not in the right format\n");
        }
        if (colsave==0)
        {
            colsave = colthi;
        }
         if (colthi != colsave)
        {
            throw;
        }
        string check;
        os>>check;
         if (check != "],")
        {
            if (check=="]")
            {
                row++;
                break;
            }
            throw invalid_argument("String is not in the right format 3333\n");
        }
        row++;


        }
        
        return {colsave,row};
    }
    Matrix& Matrix::operator+=(const Matrix &other){
        if(this->row!=other.row||this->col!=other.col){throw std::out_of_range("not equal row or col");}
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                this->ve[i][j]=this->ve.at(i).at(j)+other.ve.at(i).at(j);
                 
            }
            
        }
        

        this->CheckSum();
        return *this;
    }
    Matrix& Matrix::operator-=(const Matrix &other){
       if(this->row!=other.row||this->col!=other.col){throw std::out_of_range("not equal row or col");}
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                this->ve[i][j]=this->ve.at(i).at(j)-other.ve.at(i).at(j);
                 
            }
            
        }

        this->CheckSum();
        return *this;
    }
    Matrix Matrix::operator-()const{
        Matrix temp(*this);
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                if(this->ve.at(i).at(j)!=0){
                  temp.ve[i][j]=this->ve.at(i).at(j)*-1;
                }
                 
            }
            
        }
        
        temp.CheckSum();
        return temp;
    }
    Matrix Matrix::operator-(const Matrix &other)const{
        if(this->row!=other.row||this->col!=other.col){throw std::out_of_range("not equal row or col");}
        Matrix temp(*this);
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                temp.ve[i][j]=this->ve.at(i).at(j)-other.ve.at(i).at(j);
                 
            }
            
        }

        temp.CheckSum();
        return temp;
    }
    Matrix Matrix::operator+(const Matrix &other)const{
        if(this->row!=other.row||this->col!=other.col){throw std::out_of_range("not equal row or col");}
        Matrix temp(*this);
        for (unsigned long i = 0; i < this->row; i++){
            for (unsigned long j = 0; j < this->col; j++){
                temp.ve[i][j]=this->ve[i][j]+other.ve[i][j];
                 
            }
            
        }
        temp.CheckSum();
        return temp;
    }
    Matrix Matrix::operator*(const int &num)const{
        Matrix temp(*this);
         for(unsigned long i=0;i<this->row;i++){
           for(unsigned long j=0;j<this->col;j++){
             temp.ve[i][j]=this->ve[i][j]*num;
           }
         }
        temp.CheckSum();
        return temp;
    }
    Matrix Matrix::operator*(const Matrix &other)const{
        if(this->col!=other.row){throw std::out_of_range("can't multiply");}
        vector<double> t((unsigned long)(this->row*other.col),0);
        Matrix temp(t,this->row,other.col);
         for(unsigned long i=0;i<this->row;i++){
           for(unsigned long j=0;j<other.col;j++){
             for(unsigned long k =0;k<this->col;k++){
                 temp.ve[i][j]+=this->ve[i][k]*other.ve[k][j];
             }
           }
         }
        temp.CheckSum();
        return temp;
    }
    Matrix& Matrix::operator=(const Matrix &other){
        this->col=other.col;
        this->row=other.row;
        this->ve=other.ve;
        this->CheckSum();
        return *this;
    }
    Matrix& Matrix::operator++(){
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                this->ve[i][j]=++this->ve[i][j];
            }
            
        }
        this->CheckSum();
        return *this;
        
    }
    Matrix& Matrix::operator--(){
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                --this->ve[i][j];
            }
            
        }
        this->CheckSum();
        
        return *this;
        
    }
    Matrix Matrix::operator--(int){
        Matrix temp(*this);
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                this->ve[i][j]--;
            }
            
        }
        this->CheckSum();
        
        return temp;
        
    }
    Matrix Matrix::operator++(int){
        Matrix temp(*this);
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->col; j++)
            {
                this->ve[i][j]++;
            }
            
        }
        this->CheckSum();
        
        return temp;
        
    }
    Matrix Matrix::operator+()const{
        return *this;
    }
    bool operator==(const Matrix& c1, const Matrix& c2){
        if(c1.row!=c2.row||c1.col!=c2.col){throw std::out_of_range("not equal row or col");}
        for (unsigned long i = 0; i < c1.row; i++)
        {
            for (unsigned long j = 0; j < c2.col; j++)
            {
                if(c1.ve.at(i).at(j)!=c2.ve.at(i).at(j)){return false;}
            }
            
        }
        
        return true;}
    bool operator!=(const Matrix& c1, const Matrix& c2){
        if(c1.row!=c2.row||c1.col!=c2.col){throw std::out_of_range("not equal row or col");}
        for (unsigned long i = 0; i < c1.row; i++)
        {
            for (unsigned long j = 0; j < c2.col; j++)
            {
                if(c1.ve.at(i).at(j)!=c2.ve.at(i).at(j)){return true;}
            }
            
        }
        return false;}
    bool operator>=(const Matrix& c1, const Matrix& c2){
    if(c1.row!=c2.row||c1.col!=c2.col){throw std::out_of_range("not equal row or col");}
    return c1.sum>=c2.sum;}
    bool operator<=(const Matrix& c1, const Matrix& c2){if(c1.row!=c2.row||c1.col!=c2.col){throw std::out_of_range("not equal row or col");}
    return c1.sum<=c2.sum;}
    bool operator>(const Matrix& c1, const Matrix& c2){if(c1.row!=c2.row||c1.col!=c2.col){throw std::out_of_range("not equal row or col");}
    return c1.sum>c2.sum;}
    bool operator<(const Matrix& c1, const Matrix& c2){if(c1.row!=c2.row||c1.col!=c2.col){throw std::out_of_range("not equal row or col");}
    return c1.sum<c2.sum;}
    istream& operator>>(istream& input, Matrix& source)
        {
            string vect;
            getline(input,vect);
            vector<int> size=source.CheckInput(vect);
            
            int countrow=0;
            int countcol=1;
            // string cols;
            // for (unsigned long i = 0; vect[i] != ']'; i++)
            // {
            //     cols=cols+vect[i];
              
            // }
            for (unsigned long i = 0; (i = vect.find(' ', i)) != std::string::npos; i++) {
             countcol++;
            }
            char ch = '[';
 
            for (unsigned long i = 0; (i = vect.find(ch, i)) != std::string::npos; i++) {
             countrow++;
            }
            std::replace( vect.begin(), vect.end(), ',', ' ');
            std::replace( vect.begin(), vect.end(), '[', ' ');
            std::replace( vect.begin(), vect.end(), ']', ' ');
            std::istringstream stm(vect) ;    
            // read the  numbers into a vector
            std::vector<double> numbers ;
            double n =0;
            while( stm >> n ) {numbers.push_back(n);}
            cout<<size.at(0)<<endl;
            cout<<size.at(1)<<endl;
            Matrix temp(numbers,size.at(1),size.at(0));
            // source.SetMatrix(numbers,countrow,countcol,source);

            source=temp;
            
            
            return input;
            
            }    
    

}