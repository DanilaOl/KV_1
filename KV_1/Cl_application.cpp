#include "Cl_application.h"
#include <iostream>

using namespace std;

Cl_application::Cl_application(Cl_base* p_head_object, std::string s_object_name):Cl_base(p_head_object, s_object_name) {
	string temp;
	cin >> temp;
	rename(temp);
}

void Cl_application::build_tree_objects() {
	string head_name, sub_name;
	Cl_base *current_head_level = this, *ob = nullptr, *new_head = nullptr;
	while (cin >> head_name >> sub_name) {
		if (head_name == sub_name) break;
		else if (head_name == current_head_level->get_name()) {
			ob = new Cl_base(current_head_level, sub_name);
		}
		else if (current_head_level->get_subordinate_ptr(head_name) != nullptr
			&& current_head_level->subordinate_objects.back()->get_name() == head_name) {
			new_head = current_head_level->get_subordinate_ptr(head_name);
			ob = new Cl_base(new_head, sub_name);
			current_head_level = new_head;
		}
	}
}

int Cl_application::exec_app() {
	this->print_tree();
	return 0;
}