//suv.cpp
//
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "suv.h"


SUV::SUV(): Vehicle(){//constructor
	SUV::seatrows= 2;
	}

SUV::SUV(std::string make1,std::string model1,int year1,std::string color1,std::string bodystyle1,int price1,int mile1,std::string vin1,int sr1) :Vehicle (make1,model1,year1,color1,bodystyle1,price1,mile1,vin1){//data

	SUV::seatrows=sr1;
	}


SUV::~SUV(){//destructor
	
	}


	int SUV::getSeatRows(){
		return SUV::seatrows;
	}


	void SUV::setSeatRows(int ss2){
		SUV::seatrows=ss2;
	}	


	void SUV::print(){
		Vehicle::print();	
		std::cout<<"Number of seatrows"<<SUV::seatrows<<std::endl;
		std::cout<<std::endl;
		}
