//suv.h
//
//
#ifndef SUV_H_EXISTS
#define SUV_H_EXISTS


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "vehicle.h"

class SUV : public Vehicle {
	protected:
		int seatrows;

	public:
		SUV();
		SUV(std::string,std::string,int,std::string,std::string,int,int,std::string,int);
		~SUV();
		int getSeatRows();
		void setSeatRows(int);	
		void print();

};
#endif 
