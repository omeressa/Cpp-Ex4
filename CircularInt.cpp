#include <iostream>
#include <string>
#include "CircularInt.hpp"


CircularInt::CircularInt(int min, int max){
	this->min = min;
	this->max = max;
	this->current = min;
}

/*---Copy constructor---*/
CircularInt::CircularInt(const CircularInt& other) :min(other.min), max(other.max), current(other.current){}

/*---distructor---*/
CircularInt::~CircularInt(){}

/*-----Add operators-----*/
CircularInt CircularInt::operator+( int num){
  		current += num;
	if (current > max) {
		current = (current) % max;
	}
	return CircularInt(*this);
}
CircularInt CircularInt::operator+(const CircularInt& other){
	CircularInt temp(other);
	temp.current += other.current;
	if (temp.current >temp.max)
		temp.current = (temp.current) % (max);
	return temp;
}
CircularInt& CircularInt::operator+=(int num){

	num %= (max - min + 1);
	if (current + num > max) {
		current = (current + num) % max;
	}
	else {
		this->current += num;
	}
	return(*this);
}
CircularInt & CircularInt::operator++(){
	this->current += 1;
	return (*this);
}

CircularInt CircularInt::operator++(int ){
	CircularInt temp(*this);
	++(*this);
	return *this;
}

/*-----Sub operators-----*/
	CircularInt operator-( const int sub, CircularInt const & obj){
	CircularInt temp(obj);
	 temp.current=sub -temp.current  ;
	 while(temp.current<temp.min)
		 temp.current+=12;
	return temp;
}
CircularInt operator-(const CircularInt& other ){
 	CircularInt temp(other);
	temp.current = (temp.max - temp.current);
	return temp;
}

CircularInt CircularInt::operator--(){
	if (this->current == this->min)
		this->current = this->max;
	else this->current -= 1;
	return *this;
}


/**
 * the method i used here for adding is from a helping function
 * "normalization" from another person on gihub :
 * https://github.com/neorus616/CircularInt/blob/master/CircularInt.cpp
*/
CircularInt& CircularInt::operator-=(int num){
	num %= (max - min + 1);
	if (current - num < min) {
		num -= current;
		current = max - num;
	}
	else {
		current -= num;
	}
	return *this;
}

  /*-----Mult operators-----*/
CircularInt& CircularInt::operator*=(const int num){
		this->current = current*num % (max - min + 1);
		return *this;
}

CircularInt operator * (int num, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	res.current=res.current*num;
	res.current=res.current%(obj.max-obj.min+1);
		if(res.current>obj.max)
		res.current -= (obj.max-obj.min+1);
	if(res.current < obj.min)
		res.current += (obj.max-obj.min+1);
		return res;
}

 /*-----Div operators-----*/
 CircularInt operator/(const CircularInt& other, const int num){
	CircularInt temp(other);
	temp /= num;
	return temp;
}
CircularInt CircularInt::operator/=(const int num){

	int temp = current%num;

	if (temp != 0)
		throw string("There is no number x in {1,12} such that x*" + to_string(num) + "=" + to_string(this->current));
	else{
		current = current / num;
}
	return *this;
}
CircularInt operator / (CircularInt const & a, CircularInt const & b){
	if(a.max != b.max || a.min != b.min)
		throw "The objects have different cycles";
	else {
		CircularInt res {a.min, a.max};
        if(a.current % b.current == 0)
            res.current = a.current / b.current;
        else
            throw "\"There is no number x in {"+to_string(a.min)+","+to_string(a.max)+"} such that x*"+to_string(a.current)+"="+to_string(b.current)+"\" ";
		return res;
	}
}

CircularInt operator / (int x, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	x = x % obj.max;
	res.current = x;
	if(res.current % obj.current == 0)
		res.current /= obj.current;
	else
		throw "\"There is no number x in {"+to_string(obj.min)+","+to_string(obj.max)+"} such that x*"+to_string(x)+"="+to_string(obj.current)+"\" ";
	return res;
}


  /*-----Comp operator-----*/
CircularInt  CircularInt::operator==(int num){

	if (num - current < min) {
		current = max-(current - num);
	}
	else {
		current = num-current;
	}
	return *this;
}

bool operator != (int num, CircularInt const & other){
    return !(num == other.current);
}
bool operator == (int const num, CircularInt const & other){
    return num == other.current;
}
bool operator == (CircularInt const & obj, int const num){
    return obj.current == num;
}

  /*-----Stream operator-----*/
ostream & operator<<(ostream & o, const CircularInt time){
	o << time.current;
	return o;
}
/*
istream& operator >> (istream & is, CircularInt& circ){
		cin >> circ.min >> circ.max;
		circ.current = circ.min;
	}
	*/
	
	






