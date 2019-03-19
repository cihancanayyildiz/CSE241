#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

//Exception class for our exceptions.

class UnsupportedOperationException : public std::exception{
public:
	const char * what() const throw (){
		return "Remove function is unsopported for this hierarchy.";
	}
};


class NoElementException : public std::exception{
public:
	const char * what() const throw (){
		return "There is no element next.";
	}
};

class NoSuchElementException : public std::exception{
public:
	const char * what() const throw (){
		return "List is empty.";
	}
};


#endif