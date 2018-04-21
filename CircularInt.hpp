#pragma once
#include<iostream>
#include<string>
using namespace std;
using std::ostream;
using std::to_string;

class CircularInt
{
  
public:
  int max;
  int min;
  int current;
  
  CircularInt(int, int);/*declaration for constructor*/
	CircularInt( const CircularInt& );/*declaration for copy constructor*/
	~CircularInt();/*destructor*/
	
             /*-----Add-----*/
	CircularInt operator+( int);
	CircularInt operator+(const CircularInt&);
	CircularInt& operator+=(int);
	CircularInt&  operator++();
	CircularInt  operator++(int);

	     /*-----Sub-----*/
  friend CircularInt operator-(const CircularInt& );
	friend CircularInt operator-( const int, const CircularInt&);
	CircularInt operator--();
	CircularInt& operator-=(int);

             /*-----Mult-----*/
	CircularInt &operator*=(const int);
	friend CircularInt operator * (int, CircularInt const &);
	
	     /*-----Div-----*/
	friend CircularInt operator/(const CircularInt&, const int );
	friend CircularInt operator / (CircularInt const &, CircularInt const &);
	friend CircularInt operator / (int , CircularInt const &);
        CircularInt operator/=(const int);
		
             /*-----Stream-----*/
	friend ostream& operator<<(ostream&, const CircularInt);
	friend istream& operator >> (istream & ,CircularInt &);
	
	     /*-----Comp-----*/
	CircularInt operator==(int);
	friend bool operator == (int const, CircularInt const &);
	friend bool operator != (int const, CircularInt const &);
	friend bool operator ==(CircularInt const &, int const );

	
};




		

	
	


  
