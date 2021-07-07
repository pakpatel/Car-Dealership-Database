//van.cpp
//
//


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "van.h"


Van::Van(): Vehicle(){//constructor
	Van::slidingdoor= true;
	Van::seatrows= 4;
	}	


Van::Van(std::string make1,std::string model1,int year1,std::string color1,std::string bodystyle1,int price1,int mile1,std::string vin1,std::string sd1,int sr1):Vehicle (make1,model1,year1,color1,bodystyle1,price1,mile1,vin1){//data
	Van::slidingdoor=sd1;
	Van::seatrows=sr1;
	}


Van::~Van(){//destructor
	
	}


	std::string Van::getSlideDoor(){
		return Van::slidingdoor;
	}


	int Van::getSeatRows(){
		return Van::seatrows;
	}


	void Van::setSlideDoor(std::string  ss2){
		Van::slidingdoor=ss2;
	}	


	void Van::setSeatRows(int sr2){
		Van::seatrows=sr2;
	}

	void Van::print(){
		Vehicle::print();
		std::cout<<"Does is have a sliding door"<<Van::slidingdoor<<std::endl;
		std::cout<<"Number of seat rows is"<<Van::seatrows<<std::endl;
		std::cout<<std::endl;
	}

