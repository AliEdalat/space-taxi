#include "galaxy.h"

using namespace std;
void get_distance(Planet* root,string name,bool& find,int& distance){
	//cout<<distance<<endl;
	//cout<<root->get_name()<<endl;
	//cout<<find<<endl;
	if (root->get_name() == name)
	{
		distance+=0;
		find=true;
		return;
	}
	std::vector<Planet*> planets=root->get_planets();
	for (int i = 0; i < planets.size(); ++i)
	{
		distance++;
		get_distance(planets[i],name,find,distance);
		if(find == false){
			distance--;
		}
	}
}
Galaxy::Galaxy(string _name){
	name=_name;
}
void Galaxy::add_root(Planet* _root){
	root=_root;
}
int calculate_distance(string from_planet,string to_planet){
	
}
int Galaxy::calculate_distance_to(string planet_name){
	bool find=false;
	int distance=0;
	get_distance(root,planet_name,find,distance);
	return distance;
}