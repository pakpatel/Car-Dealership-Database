//car.cpp
//

#include "car.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

Car::Car(): Vehicle(){ //constructor

	Car::Spoiler="Yes";
	}

Car::Car(std::string make1,std::string model1,int year1,std::string color1,std::string bodystyle1,int price1,int mile1,std::string vin1 ,std::string spoiler1) :Vehicle (make1,model1,year1,color1,bodystyle1,price1,mile1,vin1){//data inheriting from vehicle and adding new data
	Car::Spoiler= spoiler1;
	}

Car::~Car(){

	
	}


	std::string Car::getSpoiler(){
		return Car::Spoiler;
	}


	void Car::setSpoiler(std::string spoiler2){
		Car::Spoiler=spoiler2;
	}	

	void Car::print()//added the spoiler to the parent print function
	{
		Vehicle::print();
		std::cout<<"Spoiler "<<Car::Spoiler<<std::endl;
		std::cout<<std::endl;
	}
