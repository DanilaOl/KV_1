#include "Cl_base.h"
#include <iostream>
#include <vector>

Cl_base::Cl_base(Cl_base *head, std::string name) {
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

Cl_base *Cl_base::get_head_ptr() {
	return head;
}

Cl_base *Cl_base::get_subordinate_ptr(std::string name) {
	for (int i = 0; i < subordinate_objects.size(); i++) {
		if (subordinate_objects[i]->get_name() == name)
			return subordinate_objects[i];
	}
	return nullptr;
}

Cl_base *Cl_base::find_in_branch(std::string name) {
	Cl_base *ob = nullptr, *current;
	std::vector<Cl_base *> objects;
	objects.push_back(this);
	while (objects.size() != 0) {
		current = objects[0];
		for (auto it : current->subordinate_objects) {
			objects.push_back(it);
		}
		if (current->get_name() == name) {
			if (ob == nullptr)
				ob = current;
			else
				return nullptr;
		}
		objects.erase(objects.begin());
	}
	return ob;
}

Cl_base *Cl_base::find_in_tree(std::string name) {
	Cl_base *current = this;
	while (current->get_head_ptr() != nullptr) {
		current = current->get_head_ptr();
	}
	return current->find_in_branch(name);
}

void Cl_base::print_branch(int indent) {
	std::string prefix = "";
	for (int i = 0; i < indent; i++) {
		prefix += "    ";
	}
	if (this->get_head_ptr() == nullptr) std::cout << prefix << this->get_name();
	else std::cout << std::endl << prefix << this->get_name();
	for (auto it : subordinate_objects) {
		it->print_branch(indent + 1);
	}
}

void Cl_base::print_branch_readiness(int indent) {
	std::string prefix = "";
	for (int i = 0; i < indent; i++) {
		prefix += "    ";
	}
	if (this->get_head_ptr() == nullptr) std::cout << "The tree of objects and their readiness";
	std::cout << std::endl << prefix << this->get_name();
	if (this->state != 0) std::cout << " is ready";
	else std::cout << " is not ready";
	for (auto it : subordinate_objects) {
		it->print_branch_readiness(indent + 1);
	}
}

void Cl_base::set_readiness(int state) {
	if (state != 0) {
		if (this->get_head_ptr() == nullptr) {
			this->state = state;
			return;
		}
		Cl_base *parent = this->get_head_ptr();
		while (parent != nullptr) {
			if (parent->state == 0) return;
			else parent = parent->get_head_ptr();
		}
		this->state = state;
	}
	else {
		this->state = state;
		for (auto it : subordinate_objects) {
			it->set_readiness(state);
		}
	}
}

bool Cl_base::rebase(Cl_base *new_head)
{
	Cl_base *temp = new_head, *head = this->get_head_ptr();
	if (head == new_head) return true;
	if (head == nullptr || new_head == nullptr) return false;
	if (new_head->get_subordinate_ptr(this->get_name()) != nullptr)
		return false; 

	//Если new_head - один из потомков текущего объекта
	while (temp != nullptr) {
		temp = temp->get_head_ptr();
		if (temp == this) return false;
	}

	//Удаление текущего объекта из вектора родителя
	for (auto it = head->subordinate_objects.begin(); it != head->subordinate_objects.end(); it++) {
		if ((*it)->get_name() == this->get_name()) {
			head->subordinate_objects.erase(it);
			break;
		}
	}
	new_head->subordinate_objects.push_back(this);
	this->head = new_head;
	return true;
}

void Cl_base::delete_sub_object(std::string name)
{
	for (auto it = subordinate_objects.begin(); it != subordinate_objects.end(); it++) {
		if ((*it)->get_name() == name) {
			delete *it;
			subordinate_objects.erase(it);
			break;
		}
	}
}

Cl_base *Cl_base::find_path(std::string path) {
	Cl_base *root = this, *current = this;
	while (root->get_head_ptr() != nullptr) {
		root = root->get_head_ptr();
	}
	if (path == "/") return root;
	if (path == ".") return this;
	if (path[0] == '/' && path[1] == '/') {
		path.erase(0, 2);
		return root->find_in_branch(path);
	}
	if (path[0] == '/' && path[1] != '/') {
		path.erase(path.begin());
		std::string temp = "";
		std::vector<std::string> names;
		for (auto ch : path) {
			if (ch != '/')
				temp.push_back(ch);
			else {
				names.push_back(temp);
				temp = "";
			}
		}
		names.push_back(temp);
		for (auto name : names) {
			root = root->get_subordinate_ptr(name);
			if (root == nullptr) break;
		}
		return root;
	}
	if (path[0] == '.') {
		path.erase(path.begin());
		return this->find_in_branch(path);
	}
	if (path[0] != '.' && path[0] != '/') {
		std::string temp = "";
		std::vector<std::string> names;
		for (auto ch : path) {
			if (ch != '/')
				temp.push_back(ch);
			else {
				names.push_back(temp);
				temp = "";
			}
		}
		names.push_back(temp);
		for (auto name : names) {
			current = current->get_subordinate_ptr(name);
			if (current == nullptr) break;
		}
		return current;
	}
	return nullptr;
}

void Cl_base::connect(TYPE_SIGNAL signal, Cl_base *target, TYPE_HANDLER handler)
{
	connection *value;

	for (int i = 0; i < connections.size(); i++) {
		if (connections[i]->p_signal == signal && 
			connections[i]->target == target &&
			connections[i]->p_handler == handler) {return;}
	}
}

void Cl_base::disconnect(TYPE_SIGNAL signal, Cl_base *target, TYPE_HANDLER handler)
{
}

void Cl_base::transmit(TYPE_SIGNAL signal, std::string &message)
{
}

std::string Cl_base::get_abs_path()
{
	return std::string();
}

Cl_base::~Cl_base() {
	for (int i = 0; i < subordinate_objects.size(); i++) {
		delete subordinate_objects[i];
	}
}