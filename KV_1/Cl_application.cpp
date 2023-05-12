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

void Cl_application::build_tree_objects() {
	Cl_base* ob = this, *head, *sub;
	string head_name, sub_name;
	int num;
	cin >> head_name;
	this->rename(head_name);
	while (cin >> head_name) {
		if (head_name == "endtree") break;
		cin >> sub_name >> num;
		if (num < 2 || num > 6) continue;

		head = ob->find_in_tree(head_name);
		sub = ob->find_in_tree(sub_name);

		if (sub != nullptr || head == nullptr) continue;

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
	while (cin >> head_name >> num) {
		head = ob->find_in_tree(head_name);
		if (head == nullptr) continue;
		else {
			head->set_readiness(num);
		}
	}
}

int Cl_application::exec_app() {
	this->print_branch();
	cout << endl;
	this->print_branch_readiness();
	return 0;
}