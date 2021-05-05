//main.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "vehicle.h"
#include "truck.h"
#include "car.h"
#include "suv.h"
#include "van.h"



void CarMenu(){//made the menu into a print function so it was easier to refer too

	std::cout << "Insert Name Here Car Dealership Main Menu" << std::endl;

	std::cout << "1. Import vehicles from file" << std::endl;

	std::cout << "2. Add a vehicle to the database" << std::endl;

	std::cout << "3. Remove a vehicle from the database" << std::endl;

	std::cout << "4. See all vehicles in the database" << std::endl;

	std::cout << "5. Search for a vehicle by VIN number" << std::endl;

	std::cout << "6. Sort vehicles by Make" << std::endl;

	std::cout << "7. Save to file and Exit" << std::endl;

	std::cout << std::endl;

}


bool CheckByVIN(std::string VIN, std::vector<Vehicle*> &list)//checks if the vin is in the vector for search and sort choices
{
	bool flag = false;//boolean value that will be returned

		for (int temp = 0; temp < list.size(); temp++) //loop that goes through the vector 

		if ((*list[temp]).getVIN() == VIN)//loop that checks the given vin to the vin at current position

		flag = true;//flag is only changed if the vin is found

		return flag;
	}

void swap(Vehicle &a, Vehicle &b) //swap for sort function
{	
	Vehicle temp=a;
	a=b;
	b=temp;
}

void sort(std::vector<Vehicle*> &list){//bubble sort
for (int m=0;m<list.size();m++)
	for(int n=0;n<list.size()-m-1;n++)
	if((*list[n]).getMake()>(*list[n+1]).getMake())
	swap((*list[n]),(*list[n+1]));
}


int main(){

	//declares and opens files
	std::ifstream input; 
	input.open("inventory.txt");
	std::ofstream output;
	output.open("output.txt");
	//Most of the variables being used
	std::string Make;
	std::string Model;
	int Year;
	std::string Color;
	std::string BodyStyle;
	int Price;
	int Mileage;
	std::string VIN;
	std::vector<Vehicle*> carlist;
	int option;
	int choicesearch;
	int menuf=1;
	std::string Spoiler;
	std::string truckbed;
	std::string sidestep;
	int seatrows;
	std::string slidingdoor;
	int temp;
	
	while(menuf=1)//keeps menu open
	{
		CarMenu();//prints menu until loop is exited completly
		std::cout << "What would you like to do?";
		std::cin>> option;
		switch(option)
		{
			case 1:
			{//import from file. Had trouble where nothing would happen when this case was used
			if (input.is_open()){ //does the following if input file is open
				std::string filestuff; //string that will grab text
				while (!input.eof()){//loop that goes through the file
				std::getline(input,filestuff); //gets stuff from input and moves it to filestuff
				std::stringstream ss1(filestuff); //makes a string stream with the stuff from filestuff
			while (ss1){
				std::string fmake,fmodel,fyear,fcolor,fbodystyle,fprice,fmile,fvin,fspoiler,ftb,fss,fsr,fsd;
				getline(ss1,fmake, ','); //will get the vehicle data from the stream
				getline(ss1,fmodel, ',');
				getline(ss1,fyear, ',');
				getline(ss1,fcolor, ',');
				getline(ss1,fbodystyle, ',');
				getline(ss1,fprice, ',');
				getline(ss1,fmile, ',');
				getline(ss1,fvin, ',');
				int IYear,IPrice,IMile,ISR; //changes any need values to int
				IYear=atoi(fyear.c_str());
				IPrice=atoi(fprice.c_str());
				IMile=atoi(fmile.c_str());

				if (fbodystyle== "Car"){ //cases to create the different types of vehicles depending on what was found
				getline(ss1,fspoiler,' ');			
				carlist.push_back(new Car(fmake,fmodel,IYear,fcolor,fbodystyle,IPrice,IMile,fvin,fspoiler));
				}
				else if (fbodystyle=="Truck"){
				getline(ss1,fss,',');
				getline(ss1,ftb,' ');
				carlist.push_back(new Truck(fmake,fmodel,IYear,fcolor,fbodystyle,IPrice,IMile,fvin,fss,ftb));
					}

				else if (fbodystyle== "SUV"){
				getline(ss1,fsr,' ');
				ISR=atoi(fsr.c_str());
				carlist.push_back(new SUV(fmake,fmodel,IYear,fcolor,fbodystyle,IPrice,IMile,fvin,ISR));
					}
				else if (fbodystyle== "Van"){
				getline(ss1,fsd,',');
				getline(ss1,fsr,' ');
				ISR=atoi(fsr.c_str());
				carlist.push_back(new Van(fmake,fmodel,IYear,fcolor,fbodystyle,IPrice,IMile,fvin,fsd,ISR));

				}
				
				}

			}
			break;	
			}
			}//ends case1
			

			

			case 2:
			{//add vehicle
			std::cout<<"Enter the Make of the new car: ";
			std::cin>>Make;
			std::cout<<"Enter the Model of the new car: ";
			std::cin>>Model;
			std::cout<<"Enther the Year of the car: ";
			std::cin>>Year;
			std::cout<<"Enter the color of the car: ";
			std::cin>>Color;
			std::cout<<"Enter the price of the car: ";
			std::cin>>Price;
			std::cout<<"enter the mileage of the car: ";
			std::cin>>Mileage;
			std::cout<<"Enter the vin: ";
			std::cin>>VIN;
			bool cchecker = CheckByVIN(VIN,carlist); //checks to make sure a car with the entered vin does not exist
			if(cchecker==true){
			std::cout<<"A car with that vin already exists"<<std::endl;
			break;
			}
			std::cout<<"Enter the type of vehicle "; //asks for type of vehicle then gets data depending on what was entered
			std::cin>>BodyStyle;	
			if(BodyStyle == "Car")
			{
			std::string spoilerstatus;
			std::cout<<"Does is it have a spoiler ";
			std::cin>>spoilerstatus;
			if(spoilerstatus== "Yes")
				{
				Spoiler="Yes";
				}
			else
				Spoiler="No";
				carlist.push_back(new Car(Make,Model,Year,Color,BodyStyle,Price,Mileage,VIN,Spoiler));
			}
			else if (BodyStyle== "Truck")
			{	truckbed="Yes";
				sidestep="Yes";
				carlist.push_back(new Truck(Make,Model,Year,Color,BodyStyle,Price,Mileage,VIN,sidestep,truckbed));
			}
			else if (BodyStyle == "SUV")
				{std::cout<<"Enter the rows of seats ";
				std::cin>>seatrows;
				carlist.push_back(new SUV(Make,Model,Year,Color,BodyStyle,Price,Mileage,VIN,seatrows));
				}
			else if (BodyStyle =="Van")
				{slidingdoor= "Yes";
				std::cout<<"Enter the rows of seats: ";
				std::cin>>seatrows;
				carlist.push_back(new Van(Make,Model,Year,Color,BodyStyle,Price,Mileage,VIN,slidingdoor,seatrows));
				}
			else
				std::cout<<"Style not recognized "; //if not recognized then the menu will be shown again
				break;
			}//enmds case 2

			case 3:
			{//remove vehicle
			std::cout<<"Enter the vin of the car you want to remove: ";
			std::cin>> VIN;
			bool remover = CheckByVIN(VIN,carlist);//checks to see if vin exists
			if(remover==0)
			std::cout<<"No car found in inventory with that vin "<<std::endl;
			else
			{for (int temp = 0;temp<carlist.size();temp++) //if vin was found then loops look through vector and erase the vehicle specified
				if((*carlist[temp]).getVIN()==VIN)
					{ 
					carlist.erase(carlist.begin()+temp);
					std::cout<<"Car removed."<<std::endl;
					break;
					}
				}
			} //ends case 3
	
			case 4:
			{//see inventory
			std::cout<<"Showing present inventory"<<std::endl;
			for(int i=0;i<carlist.size();i++) //loop that goes through current vector and prints everything
				(*carlist[i]).print();		
				break;
			}//ends case 4

			case 5:
			{//search by vin
			std::cout<<"Enter a vin: ";
			std::cin>>VIN;
			bool searcher = CheckByVIN(VIN,carlist); //searches by vin to see if car exists
			if(searcher == false)
			{std::cout<< "No car with that VIN is in the database"<< std::endl; //if it does not exist then told so and returned to menu
			}
			else
			{std::cout<<"A car with that VIN is in the database"<<std::endl; //if a car is found then it is shown
			for (int vinn = 0; vinn < carlist.size(); vinn++)
			if ((*carlist[vinn]).getVIN() == VIN)
			((*carlist[vinn]).print());
			break;
			}
			break;
			} //ends case 5
			

			case 6:
			{//sort by make
			std::cout<<"Sorting the inventory:"<<std::endl; //bubble sort and swap called to sort the vector 
			sort(carlist);
			break;

					
			}//ends case 6
			
			case 7:
			{//save and exit. attempt at save and exit but had trouble with the specific qualities of each vehicle
			for(int j=0;j<carlist.size();j++){ //goes through vector and prints all data to seperate file

			output<<(*carlist[j]).getMake()<<", ";
			output<<(*carlist[j]).getModel()<<", ";
			output<<(*carlist[j]).getYear()<<", ";
			output<<(*carlist[j]).getColor()<<", ";
			output<<(*carlist[j]).getBodyStyle()<<", ";
			output<<(*carlist[j]).getPrice()<<", ";
			output<<(*carlist[j]).getMileage()<<", ";
			output<<(*carlist[j]).getVIN()<<", ";
			output<<std::endl;
			if ((*carlist[j]).getBodyStyle()=="Car"){
			output<<"Spoiler"<< " ";	//placeholder value until it is fixed
		//	output<<(*carlist[j]).getSpoiler()<<" ";
			}
			else if((*carlist[j]).getBodyStyle()=="Truck"){
			output<<"Yes"<<", "; //placeholders
			output<<"Yes"<<" ";
			}
			else if((*carlist[j]).getBodyStyle()=="SUV"){
			output<<"2"<<" "; //placeholder
		//	output<<(*carlist[j]).getSeatRows()<<" ";
			}
			else if((*carlist[j]).getBodyStyle()=="Van"){
			output<<"Yes"<<", "; //placeholder
			output<<"3"<<" "; //placeholder
		//	output<<(*carlist[j]).getSlideDoor()<<" ";
		//	output<<(*carlist[j]).getSeatRows()<<" ";

			
			}

			}
			input.close(); //closes files and exits menu
			output.close();
			menuf=0;
			exit(0);
			}//ends case 7
		
			}//ends switch		
			}//ends while
	
			return 0;}//ends main


