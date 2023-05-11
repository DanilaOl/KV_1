#include "Cl_application.h"
#include "Cl_myclass.h"
#include <iostream>

using namespace std;

//Cl_application::Cl_application(Cl_base* p_head_object, std::string s_object_name) :Cl_base(p_head_object, 1, s_object_name) {
Cl_application::Cl_application(Cl_base *head) : Cl_base(head) {}

void Cl_application::build_tree_objects() {
	string head_name, sub_name;
	Cl_base *current_head = this, *last_added = nullptr;

	cin >> head_name;
	this->rename(head_name);

	while (cin >> head_name >> sub_name) {
		if (head_name == sub_name) break;
		else if (head_name == current_head->get_name() && current_head->get_subordinate_ptr(sub_name) == nullptr) {
			last_added = new Cl_myclass(current_head, sub_name);
		}
		else if (current_head->get_subordinate_ptr(head_name) != nullptr && last_added->get_name() == head_name) {
			current_head = current_head->get_subordinate_ptr(head_name);
			last_added = new Cl_myclass(current_head, sub_name); //maybe wrong, think about
		}
	}
	//cl_base* ob, *sub, *head;
	//string head_name, sub_name;
	//int class_num, state_num;
	//while (cin >> head_name) {
	//	if (head_name == "endtree") break;
	//	cin >> sub_name >> class_num;
	//	if (class_num < 2 || class_num > 6) continue;

	//	head = find_in_tree(head_name);
	//	sub = find_in_tree(sub_name);

	//	if (sub != nullptr || head == nullptr) continue;

	//	ob = new cl_base(head, class_num, sub_name);
	//}
	//while (cin >> head_name >> state_num) {
	//	head = find_in_tree(head_name);
	//	if (head == nullptr) continue;
	//	else {
	//		head->set_readiness(state_num);
	//	}
	//} for KV_2
}

//int Cl_application::exec_app() {
//	this->print_branch();
//	this->print_branch_readiness();
//	return 0;
//} for KV_2

int Cl_application::exec_app() {
	this->print_tree();
	return 0;
}