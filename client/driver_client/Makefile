all: client command.o driver_client.o

client: main.cpp client_socket.o tools.o command.o invalid_command.o driver_client.o
	g++ main.cpp client_socket.o tools.o command.o invalid_command.o driver_client.o -o client
	
client_socket.o: client_socket.cpp client_socket.h tools.h network_exception.h
	g++ -c client_socket.cpp
	
tools.o: tools.cpp tools.h
	g++ -c tools.cpp
command.o:command.cpp command.h
	g++ -c command.cpp
invalid_command.o:invalid_command.cpp invalid_command.h
	g++ -c invalid_command.cpp
driver_client.o:driver_client.cpp driver_client.h
	g++ -c driver_client.cpp
	
clean:
	rm *.o client
