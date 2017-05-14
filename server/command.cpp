#include "command.h"

using namespace std;


string find_next_part(string& line){
	int find=line.find(' ');
	if(find == -1){
		return line;
	}else{
		string temp=line.substr(0,find);
		line=line.substr(find+1);
		if(temp == " " || temp == ""){
			throw invalid_command("this line is not a correct command!"); 
		}
		return temp;
	}
}
string replace_multiple_spaces_to_one(string line){
	bool find_space=false;
	string result;
	for (int i = 0; i < line.size(); ++i)
	{
		if(line[i] == ' ' && find_space == false){
			result.push_back(line[i]);
		}else if(line[i] != ' '){
			result.push_back(line[i]);
		}
		if(line[i] != ' '){
			find_space=false;
		}else{
			find_space=true;
		}
	}
	return result;
}
int find_number_of_spaces(string line){
	int counter=0;
	for (int i = 0; i < line.size(); ++i)
	{
		if(line[i] == ' '){
			counter++;
		}
	}
	return counter;
}

Command::Command(std::string line){
	command_line=line;
	string temp=line;
	spaces=find_number_of_spaces(line);
	//cout<<replace_multiple_spaces_to_one(line)<<endl;
	int counter=0;
	while(line.find(' ') != -1){
		if(counter == 0){
			username=find_next_part(line);
			//cout<<username<<endl;
			counter++;
		}else if(counter == 1){
			type=find_next_part(line);
			//cout<<type<<endl;
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
	//cout<<"command destructor"<<endl;
}