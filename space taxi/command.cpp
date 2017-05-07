#include "command.h"

using namespace std;


string find_next_part(string& line){
	int find=line.find(' ');
	if(find == -1){
		return line;
	}else{
		string temp=line.substr(0,find);
		line=line.substr(find+1);
		return temp;
	}
}

Command::Command(std::string line){
	cout<<line<<endl;
	string temp=line;
	int counter=0;
	while(line.find(' ') != -1){
		if(counter == 0){
			username=find_next_part(line);
			cout<<username<<endl;
			counter++;
		}else if(counter == 1){
			type=find_next_part(line);
			cout<<type<<endl;
			counter++;
		}else{
			parameters.push_back(find_next_part(line));
		}
	}if(line.find(' ') == -1 && counter == 0){
		throw invalid_command(temp+" is not a complete command!");
	}
	if(line.find(' ') == -1 && counter == 1){
		type=line;
	}else{
		parameters.push_back(line);
	}
}
Command::~Command(){
	cout<<"command destructor"<<endl;
}