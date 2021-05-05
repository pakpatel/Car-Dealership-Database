dealership: main.o vehicle.o car.o truck.o suv.o van.o
	g++ main.o vehicle.o car.o truck.o suv.o van.o -o dealership
vehicle.o: vehicle.h vehicle.cpp
	g++ -c vehicle.cpp
car.o: car.h car.cpp vehicle.o
	g++ -c car.cpp
truck.o: truck.h truck.cpp vehicle.o
	g++ -c truck.cpp
suv.o: suv.h suv.cpp vehicle.o
	g++ -c suv.cpp
van.o: van.h van.cpp vehicle.o
	g++ -c van.cpp
main.o: main.cpp vehicle.h car.h truck.h suv.h van.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm -f dealership
memtest: dealership
	valgrind --leak-check-yes ./dealership
run: dealership
	./dealership
