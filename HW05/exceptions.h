#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

//In this header
//Holding exception classes..

namespace GtuObjects{

class CircleLessThanZero : public std::exception { //If a circle  gets a negative member data while setting a data or something  we will use this exception class.
public:
	const char * what() const throw (){
		return "This circle has negative data.";
	}
};

class RectLessThanZero : public std::exception { //If a rectangle gets a negative member data while setting a data or something  we will use this exception class.
public:
	const char * what() const throw(){
		return "This rectangle has a negative data.";
	}
};

class TriLessThanZero : public std::exception { //If a triangle  gets a negative member data while setting a data or something  we will use this exception class.
public:
	const char * what() const throw() {
		return "This triangle has a negative data.";
	}
};

class PolyLessThanZero : public std::exception { //If a polygon  gets a negative member data while setting a data or something  we will use this exception class.
public:
	const char * what() const throw() {
		return "This PolygonDyn has a negative data.";
	}
};

class OutOfBoundsException : public std::exception { // Using this exception for range checking.
public:
	const char * what() const throw(){
		return "Out of Range!!";
	}
};

class EmptyVectorException : public std::exception { // If someone sends a empty vector we will use this exception.
public:
	const char * what() const throw(){
		return "This vector is empty.";
	}
};

}

#endif