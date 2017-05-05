#include "galaxy.h"

using namespace std;
bool find_planet_rec(Planet* root,string planet_name){
	if(root->get_name() == planet_name){
		return true;
	}else{
		std::vector<Planet*> planets=root->get_planets();
		for (int i = 0; i < planets.size(); ++i)
		{
			bool find;
			find=find_planet_rec(planets[i],planet_name);
			if(find == true){
				return find;
			}
		}
	}
	return false;
}
int get_distance(Planet* root,string name,int distance){
	//cout<<distance<<endl;
	//cout<<root->get_name()<<endl;
	//cout<<find<<endl;
	if (root->get_name() == name)
	{
		return distance;
	}
	else{
		std::vector<Planet*> planets=root->get_planets();
		for (int i = 0; i < planets.size(); ++i)
		{
			distance=get_distance(planets[i],name,distance+1);
			if(distance >= 0){
				return distance;
			}
		}
	}
	return -1;
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
	int distance=0;
	cout<< get_distance(root,planet_name,distance)<<endl;
	return distance;
}
bool Galaxy::find_planet(std::string planet_name){
	return find_planet_rec(root,planet_name);
}