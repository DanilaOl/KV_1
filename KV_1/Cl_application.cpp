#include "Cl_application.h"
#include "Cl_base.h"
#include "Cl_myclass2.h"
#include "Cl_myclass3.h"
#include "Cl_myclass4.h"
#include "Cl_myclass5.h"
#include "Cl_myclass6.h"
#include <iostream>

using namespace std;

Cl_application::Cl_application(Cl_base *head) : Cl_base(head) {}

//void Cl_application::build_tree_objects() {
//	Cl_base* ob = this, *head, *sub;
//	string head_name, sub_name;
//	int num;
//	cin >> head_name;
//	this->rename(head_name);
//	while (cin >> head_name) {
//		if (head_name == "endtree") break;
//		cin >> sub_name >> num;
//		if (num < 2 || num > 6) continue;
//
//		head = ob->find_in_tree(head_name);
//		sub = ob->find_in_tree(sub_name);
//
//		if (sub != nullptr || head == nullptr) continue;
//
//		switch (num) {
//		case 2:
//			ob = new Cl_myclass2(head, sub_name);
//			break;
//		case 3:
//			ob = new Cl_myclass3(head, sub_name);
//			break;
//		case 4:
//			ob = new Cl_myclass4(head, sub_name);
//			break;
//		case 5:
//			ob = new Cl_myclass5(head, sub_name);
//			break;
//		case 6:
//			ob = new Cl_myclass6(head, sub_name);
//			break;
//		default:
//			break;
//		}
//	}
//	while (cin >> head_name >> num) {
//		head = ob->find_in_tree(head_name);
//		if (head == nullptr) continue;
//		else {
//			head->set_readiness(num);
//		}
//	}
//}

void Cl_application::build_tree_objects() {
	Cl_base *ob = this, *head, *sub;
	string head_path, sub_name;
	int num;
	cin >> head_path;
	this->rename(head_path);
	while (cin >> head_path) {
		if (head_path == "endtree") break;
		if (head_path[0] != '/') continue;

		head = find_path(head_path);
		if (head == nullptr) {
			std::cout << "Object tree\n";
			this->print_branch();
			std::cout << "\nThe head object " << head_path << " is not found";
			exit(1);
		}

		cin >> sub_name >> num;
		sub = head->get_subordinate_ptr(sub_name);
		if (sub != nullptr) {
			std::cout << head_path << "     Dubbing the names of subordinate objects";
			continue;
		}
		if (num < 2 || num > 6) continue;

		switch (num) {
		case 2:
			ob = new Cl_myclass2(head, sub_name);
			break;
		case 3:
			ob = new Cl_myclass3(head, sub_name);
			break;
		case 4:
			ob = new Cl_myclass4(head, sub_name);
			break;
		case 5:
			ob = new Cl_myclass5(head, sub_name);
			break;
		case 6:
			ob = new Cl_myclass6(head, sub_name);
			break;
		default:
			break;
		}
	}
}

int Cl_application::exec_app() {
	std::cout << "Object tree";
	this->print_branch();
	std::cout << std::endl;
	std::string command, path;
	Cl_base *current = this, *temp = nullptr;
	while (cin >> command) {
		if (command == "END") break;

		cin >> path;
		temp = current->find_path(path);
		if (command == "SET") {
			if (temp == nullptr) {
				std::cout << "The object was not found at the specified coordinate: " << path << std::endl;
			}
			else {
				current = temp;
				std::cout << "Object is set: " << current->get_name() << std::endl;
			}
			continue;
		}
		if (command == "FIND") {
			if (temp == nullptr) 
				std::cout << path << "     Object is not found" << std::endl;
			else 
				std::cout << path << "     Object name: " << temp->get_name() << std::endl;
			continue;
		}
		if (command == "MOVE") {
			if (temp == nullptr) 
				std::cout << path << "     Head object is not found" << std::endl;
			else if (temp->get_subordinate_ptr(current->get_name()) != nullptr) 
				std::cout << path << "     Dubbing the names of subordinate objects" << std::endl;
			else if (!current->rebase(temp)) 
				std::cout << path << "     Redefining the head object failed" << std::endl;
			else 
				std::cout << "New head object: " << temp->get_name() << std::endl;
			continue;
		}
		if (command == "DELETE") {
			if (current->get_subordinate_ptr(path) == nullptr) continue;
			current->delete_sub_object(path);
			std::string abs_path = '/' + path;
			temp = current;
			while (temp != nullptr) {
				abs_path = '/' + temp->get_name() + abs_path;
				temp = temp->get_head_ptr();
			}
			std::cout << "The object " << abs_path << " has been deleted" << std::endl;
		}
	}
	std::cout << "Current object hierarchy tree\n";
	this->print_branch();
	return 0;
}