#include "shape.h"

namespace GtuObjects{

//shape class comparison operator overloads..

bool Shape::operator==(const Shape &other) const{
	return (Area()==other.Area());
}
bool Shape::operator!=(const Shape &other) const{
	return !(Area()==other.Area());
}
bool Shape::operator>(const Shape &other) const{
	return (Area()>other.Area());
}
bool Shape::operator<(const Shape &other) const{
	return (Area()<other.Area());
}
bool Shape::operator>=(const Shape &other) const{
	if(Area()>other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}
}

bool Shape::operator<=(const Shape &other) const{
	if(Area()<other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator<<(std::ostream &output,const Shape &other){
	return other.draw(output);
}

}