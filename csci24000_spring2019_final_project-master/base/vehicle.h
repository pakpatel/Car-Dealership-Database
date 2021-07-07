//vehicle.h
//
//
#ifndef VEHICLE_H_EXISTS
#define VEHICLE_H_EXISTS


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

class Vehicle {
	protected:
		std::string Make;
		std::string Model;
		int Year;
		std::string Color;
		std::string BodyStyle;//most important part of this whole class
		int Price;
		int Mileage;
		std::string VIN;//string so value does not change later

	public:
		Vehicle();
		Vehicle(std::string,std::string,int,std::string,std::string,int,int,std::string);
		~Vehicle();
		std::string getMake();
		std::string getModel();
		int getYear();
		std::string getColor();
		std::string getBodyStyle();
		int getPrice();
		int getMileage();
		std::string getVIN();
		void setMake(std::string);
		void setModel(std::string);
		void setYear(int);
		void setColor(std::string);
		void setBodyStyle(std::string);
		void setPrice(int);
		void setMileage(int);
		void setVIN(std::string);
 		virtual	void print();//will be the base for the print of each type of vehicle	


};
#endif 
		
