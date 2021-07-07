//van.h
//
//
#ifndef VAN_H_EXISTS
#define VAN_H_EXISTS


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "vehicle.h"

class Van : public Vehicle {
	protected:
		std::string slidingdoor;
		int seatrows;

	public:
		Van();
		Van(std::string,std::string,int,std::string,std::string,int,int,std::string,std::string,int);
		~Van();
		std::string getSlideDoor();
		int getSeatRows();
		void setSlideDoor(std::string);	
		void setSeatRows(int);
		void print();

};
#endif 
