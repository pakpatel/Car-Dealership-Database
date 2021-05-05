//car.h
//
//
#ifndef CAR_H_EXISTS
#define CAR_H_EXISTS


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "vehicle.h"

class Car : public Vehicle {
	protected:
		std::string Spoiler;//slightly different then vehicle since it will have it's own properties

	public:
		Car();
		Car(std::string,std::string,int,std::string,std::string,int,int,std::string,std::string);
		~Car();
		std::string getSpoiler();
		void setSpoiler(std::string);	
		void print();	

};
#endif 
