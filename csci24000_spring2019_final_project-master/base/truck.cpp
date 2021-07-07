//truck.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "truck.h"

Truck::Truck(): Vehicle(){ //constructor
		Truck::sidestep= "Yes";
		Truck::truckbed= "Yes";
	}


Truck::Truck(std::string make1,std::string model1,int year1,std::string color1,std::string bodystyle1,int price1,int mile1,std::string vin1,std::string ss1,std::string tb1) :Vehicle (make1,model1,year1,color1,bodystyle1,price1,mile1,vin1){//data
	Truck::sidestep=ss1;
	Truck::truckbed=tb1;
	}


Truck::~Truck(){ //destructor

	}


	std::string Truck::getSideStep(){
		return Truck::sidestep;
	}


	std::string Truck::getTruckbed(){
		return Truck::truckbed;
	}


	void Truck::setSideStep(std::string ss2){
		Truck::sidestep= ss2;
	}


	void Truck::setTruckbed(std::string tb2){
		Truck::truckbed= tb2;
	}

	void Truck::print()//new print
	{
		Vehicle::print();
		std::cout<<"Truck bed"<<Truck::truckbed<<std::endl;
		std::cout<<"Sidestep"<<Truck::sidestep<<std::endl;
		std::cout<<std::endl;
	}
