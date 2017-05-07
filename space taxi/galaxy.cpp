#include "galaxy.h"

using namespace std;
bool find_planet_rec(Planet* root,string planet_name,Planet*& target_planet){
	if(root->get_name() == planet_name){
		target_planet=root;
		return true;
	}else{
		std::vector<Planet*> planets=root->get_planets();
		for (int i = 0; i < planets.size(); ++i)
		{
			bool find;
			find=find_planet_rec(planets[i],planet_name,target_planet);
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
void delete_planets_rec(Planet* root){
	vector<Planet*> children=root->get_planets();
	if (children.size() != 0)
	{
		for (int i = 0; i < children.size(); ++i)
		{
			delete_planets_rec(children[i]);
		}
		delete root;
	}else{
		delete root;
	}
}
Galaxy::Galaxy(string _name){
	name=_name;
}
Galaxy::~Galaxy(){
	delete_planets_rec(root);
}
void Galaxy::add_root(Planet* _root){
	root=_root;
}
int Galaxy::calculate_distance(string from_planet,string to_planet){
	Planet* target;
	int distance=0;
	int distance_first_from_root=get_distance(root,from_planet,distance);distance=0;
	int distance_other_from_root=get_distance(root,to_planet,distance);distance=0;
	if(distance_first_from_root <= distance_other_from_root){
		find_planet_rec(root,from_planet,target);
		return get_distance(target,to_planet,distance);
	}else{
		find_planet_rec(root,to_planet,target);
		return get_distance(target,from_planet,distance);
	}
}
int Galaxy::calculate_distance_to(string planet_name){
	int distance=0;
	return get_distance(root,planet_name,distance);
}
bool Galaxy::find_planet(std::string planet_name){
	Planet* target;
	return find_planet_rec(root,planet_name,target);
}