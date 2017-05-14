all: server

server: main.cpp server_socket.o server.o user.o passenger.o driver.o vip_driver.o admin.o date_time.o galaxy.o planet.o spaceship.o address.o code.o Vip_trip.o trip.o invalid_command.o bad_command_exception.o command.o space_taxi_server.o space_taxi_system.o	tools.o
	g++ main.cpp server_socket.o server.o user.o passenger.o driver.o vip_driver.o admin.o date_time.o galaxy.o planet.o spaceship.o address.o code.o Vip_trip.o trip.o invalid_command.o bad_command_exception.o command.o space_taxi_server.o space_taxi_system.o tools.o -o server

server.o: server.cpp server.h
	g++ -c server.cpp
	
server_socket.o: server_socket.cpp server_socket.h tools.h network_exception.h
	g++ -c server_socket.cpp
	
tools.o: tools.cpp tools.h
	g++ -c tools.cpp
space_taxi_server.o:space_taxi_server.cpp space_taxi_server.h
	g++ -c space_taxi_server.cpp
user.o:user.cpp user.h
	g++ -c user.cpp
passenger.o:passenger.cpp passenger.h
	g++ -c passenger.cpp
driver.o:driver.cpp driver.h
	g++ -c driver.cpp
vip_driver.o:vip_driver.cpp vip_driver.h
	g++ -c vip_driver.cpp
admin.o:admin.cpp admin.h
	g++ -c admin.cpp
date_time.o:date_time.cpp date_time.h
	g++ -c date_time.cpp
galaxy.o:galaxy.cpp galaxy.h
	g++ -c galaxy.cpp
planet.o:planet.cpp planet.h
	g++ -c planet.cpp
spaceship.o:spaceship.cpp spaceship.h
	g++ -c spaceship.cpp
address.o:address.cpp address.h
	g++ -c address.cpp
code.o:code.cpp code.h
	g++ -c code.cpp
trip.o:trip.cpp trip.h
	g++ -c trip.cpp
Vip_trip.o:Vip_trip.cpp Vip_trip.h
	g++ -c Vip_trip.cpp
bad_command_exception.o:bad_command_exception.cpp bad_command_exception.h
	g++ -c bad_command_exception.cpp
invalid_command.o:invalid_command.cpp invalid_command.h
	g++ -c invalid_command.cpp
command.o:command.cpp command.h
	g++ -c command.cpp
space_taxi_server.o:space_taxi_server.cpp space_taxi_server.h
	g++ -c space_taxi_server.cpp 
space_taxi_system.o:space_taxi_system.cpp space_taxi_system.h
	g++ -c space_taxi_system.cpp
	
clean:
	rm *.o server
