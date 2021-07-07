//truck.h
//
//
#ifndef TRUCK_H_EXISTS
#define TRUCK_H_EXISTS


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "vehicle.h"

class Truck : public Vehicle {
	protected:
		std::string sidestep;//properties that seperate truck from vehicle
		std::string truckbed;

	public:
		Truck();
		Truck(std::string,std::string,int,std::string,std::string,int,int,std::string,std::string,std::string);
		~Truck();
		std::string getSideStep();
		std::string getTruckbed();
		void setSideStep(std::string);	
		void setTruckbed(std::string);
		void print();
};
#endif 
