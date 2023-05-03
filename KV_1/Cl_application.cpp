#include "Cl_application.h"
#include <iostream>

using namespace std;

Cl_application::Cl_application(Cl_base* p_head_object, std::string s_object_name) :Cl_base(p_head_object, s_object_name) {
	string temp;
	cin >> temp;
	rename(temp);
}

void Cl_application::build_tree_objects() {
	string head_name, sub_name;
	//vector<Cl_base*> objects{this};
	while (cin >> head_name >> sub_name)
		if (head_name == sub_name) break;
		if (head_name == get_name()) {
			Cl_base* ob = new Cl_base(this, sub_name);
			//objects.push_back(ob);
		}
		else {
			
			Cl_base* ob = new Cl_base(get_subordinate_ptr(head_name), sub_name);
			//objects.push_back(ob);
		}
}

int Cl_application::exec_app() {
	this->print_tree();
	return 0;
}