#include "Cl_base.h"
#include <iostream>

//Cl_base::Cl_base(Cl_base* p_head_object, int class_num, std::string s_object_name) {
//	this->p_head_object = p_head_object;
//	this->s_object_name = s_object_name;
//	this->class_num = class_num;
//	if (p_head_object != nullptr) {
//		p_head_object->subordinate_objects.push_back(this);
//	}
//} for KV_2

Cl_base::Cl_base(Cl_base* head, std::string name) {
	this->head = head;
	this->name = name;
	if (head != nullptr) {
		head->subordinate_objects.push_back(this);
	}
}

bool Cl_base::rename(std::string new_name) {
	if (head == nullptr) {
		name = new_name;
		return true;
	}
	for (int i = 0; i < head->subordinate_objects.size(); i++) {
		if (head->subordinate_objects[i]->get_name() == new_name) return false;
	}
	name = new_name;
	return true;
}

std::string Cl_base::get_name() {
	return name;
}

Cl_base* Cl_base::get_head_ptr() {
	return head;
}

void Cl_base::print_tree() {
	if (head == nullptr)
		std::cout << name << '\n';
	std::cout << name;
	for (int i = 0; i < subordinate_objects.size(); i++) {
		std::cout << "  " << subordinate_objects[i]->get_name();
	}
	if (subordinate_objects.size() != 0 && subordinate_objects.back()->subordinate_objects.size() != 0) {
		std::cout << std::endl;
		subordinate_objects.back()->print_tree();
	}
}

Cl_base* Cl_base::get_subordinate_ptr(std::string name) {
	for (int i = 0; i < subordinate_objects.size(); i++) {
		if (subordinate_objects[i]->get_name() == name)
			return subordinate_objects[i];
	}
	return nullptr;
}

//Cl_base* Cl_base::find_in_branch(std::string name) {
//	Cl_base* ob;
//	if (name == this->get_name()) return this;
//	else {
//		for (auto it : subordinate_objects) {
//			ob = it->find_in_branch(name);
//			if (ob != nullptr) return ob;
//		}
//	}
//
//	return nullptr;
//}
//
//Cl_base* Cl_base::find_in_tree(std::string name) {
//	Cl_base *current = this, *parent = this->get_head_ptr();
//	while (parent != nullptr) {
//		current = parent;
//		parent = parent->get_head_ptr();
//	}
//	return current->find_in_branch(name);
//}
//
//void Cl_base::print_branch(int indent) {
//	std::string prefix = "";
//	for (int i = 0; i < indent; i++) {
//		prefix += "    ";
//	}
//	if (this->get_head_ptr() == nullptr) std::cout << "Object tree";
//	std::cout << std::endl << prefix << this->get_name();
//	for (auto it : subordinate_objects) {
//		it->print_branch(indent + 1);
//	}
//}
//
//void Cl_base::print_branch_readiness(int indent) {
//	std::string prefix = "";
//	for (int i = 0; i < indent; i++) {
//		prefix += "    ";
//	}
//	if (this->get_head_ptr() == nullptr) std::cout << "\nThe tree of objects and their readiness";
//	std::cout << std::endl << prefix << this->get_name();
//	if (this->state != 0) std::cout << " is ready";
//	else std::cout << " is not ready";
//	for (auto it : subordinate_objects) {
//		it->print_branch_readiness(indent + 1);
//	}
//}
//
//void Cl_base::set_readiness(int state) {
//	if (state != 0) {
//		if (this->get_head_ptr() == nullptr) {
//			this->state = state;
//			return;
//		}
//		Cl_base* parent = this->get_head_ptr();
//		while (parent != nullptr) {
//			if (parent->state == 0) return;
//			else parent = parent->get_head_ptr();
//		}
//		this->state = state;
//	}
//	else {
//		this->state = state;
//		for (auto it : subordinate_objects) {
//			it->set_readiness(state);
//		}
//	}
//}

Cl_base::~Cl_base() {
	for (int i = 0; i < subordinate_objects.size(); i++) {
		delete subordinate_objects[i];
	}
}