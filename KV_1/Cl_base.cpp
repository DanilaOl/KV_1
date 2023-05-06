#include "Cl_base.h"
#include <iostream>

Cl_base::Cl_base(Cl_base* p_head_object, std::string s_object_name) {
	this->p_head_object = p_head_object;
	this->s_object_name = s_object_name;
	if (p_head_object != nullptr) {
		p_head_object->subordinate_objects.push_back(this);
	}
}

bool Cl_base::rename(std::string new_name) {
	if (p_head_object == nullptr) {
		s_object_name = new_name;
		return true;
	}
	for (int i = 0; i < p_head_object->subordinate_objects.size(); i++) {
		if (p_head_object->subordinate_objects[i]->s_object_name == new_name) return false;
	}
	s_object_name = new_name;
	return true;
}

std::string Cl_base::get_name() {
	return s_object_name;
}

Cl_base* Cl_base::get_head_ptr() {
	return p_head_object;
}

void Cl_base::print_tree() {
	if (p_head_object == nullptr)
		std::cout << s_object_name << '\n';
	std::cout << s_object_name;
	for (int i = 0; i < subordinate_objects.size(); i++) {
		std::cout <<"  " << subordinate_objects[i]->s_object_name;
	}
	if (subordinate_objects.back()->subordinate_objects.size() != 0) {
		std::cout << std::endl;
		subordinate_objects.back()->print_tree();
	}
}

Cl_base* Cl_base::get_subordinate_ptr(std::string name) {
	for (int i = 0; i < subordinate_objects.size(); i++) {
		if (subordinate_objects[i]->s_object_name == name)
			return subordinate_objects[i];
	}
	return nullptr;
}

Cl_base::~Cl_base() {
	for (auto it = subordinate_objects.begin(); it != subordinate_objects.end(); ++it) {
		delete *it;
	}
	subordinate_objects.clear();
}