//vehicle.cpp
//
#include "vehicle.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

Vehicle::Vehicle(){ //defualt constructor
	Vehicle::Make= "Make";
	Vehicle::Model = "Model";
	Vehicle::Year = 1990;
	Vehicle::Color= "Color";
	Vehicle::BodyStyle= "Bodystyle";
	Vehicle::Price = 1000000;
	Vehicle::Mileage= 0;
	Vehicle::VIN= "111111";
}

Vehicle::Vehicle(std::string make1,std::string model1,int year1,std::string color1,std::string bodystyle1,int price1,int mile1,std::string vin1){//data
	
	Vehicle::Make= make1;
	Vehicle::Model = model1;
	Vehicle::Year = year1;
	Vehicle::Color= color1;
	Vehicle::BodyStyle= bodystyle1;
	Vehicle::Price = price1;
	Vehicle::Mileage= mile1;
	Vehicle::VIN= vin1;

}

Vehicle::~Vehicle(){//destructor


	}


	std::string Vehicle::getMake(){
		return Vehicle::Make;
	}

	std::string Vehicle::getModel(){
		return Vehicle::Model;
	}

	int Vehicle::getYear(){
		return Vehicle::Year;
	}


	std::string Vehicle::getColor(){
		return Vehicle::Color;
	}
	

	std::string Vehicle::getBodyStyle(){
		return Vehicle::BodyStyle;
	}

	int Vehicle::getPrice(){
		return Vehicle::Price;
	}


	int Vehicle::getMileage(){
		return Vehicle::Mileage;
	}


	std::string Vehicle::getVIN(){
		return Vehicle::VIN;
	}


	void Vehicle::setMake(std::string make2){
		Vehicle::Make=make2;
	}


	void Vehicle::setModel(std::string model2){
		Vehicle::Model=model2;
	}


	void Vehicle::setYear(int year2){
		Vehicle::Year=year2;
	}


	void Vehicle::setColor(std::string color2){
		Vehicle::Color=color2;
	}


	void Vehicle::setBodyStyle(std::string bs2){
		Vehicle::BodyStyle=bs2;
	}


	void Vehicle::setPrice(int price2){
		Vehicle::Price=price2;
	}


	void Vehicle::setMileage(int mile2){
		Vehicle::Mileage= mile2;
	}

	void Vehicle::setVIN(std::string vin2){
		Vehicle::VIN= vin2;
	}	

	void Vehicle::print()//default print so that later attributes will be added
	{
	std::cout<<std::endl<<std::endl;
	std::cout<<"Make:"<<Vehicle::Make<<std::endl;
	std::cout<<"Model:"<<Vehicle::Model<<std::endl;
	std::cout<<"Year:"<<Vehicle::Year<<std::endl;
	std::cout<<"Color:"<<Vehicle::Color<<std::endl;
	std::cout<<"BodyStyle:"<<Vehicle::BodyStyle<<std::endl;
	std::cout<<"Price:"<<Vehicle::Price<<std::endl;
	std::cout<<"Mileage:"<<Vehicle::Mileage<<std::endl;
	std::cout<<"VIN:"<<Vehicle::VIN<<std::endl;
	}


