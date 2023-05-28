#include "Cl_application.h"
#include "Cl_base.h"
#include "Cl_myclass2.h"
#include "Cl_myclass3.h"
#include "Cl_myclass4.h"
#include "Cl_myclass5.h"
#include "Cl_myclass6.h"
#include <iostream>

Cl_application::Cl_application(Cl_base *head) : Cl_base(head) {
	this->set_class_num(1);
}

void Cl_application::build_tree_objects() 
{
	Cl_base *ob = this, *head, *sub;
	std::string head_path, sub_path, sub_name;
	int num;

	std::cin >> head_path;
	this->rename(head_path);

	while (std::cin >> head_path) {
		if (head_path == "endtree") break;
		if (head_path[0] != '/') continue;

		head = find_path(head_path);

		if (head == nullptr) {
			std::cout << "Object tree\n";
			this->print_branch();
			std::cout << "\nThe head object " << head_path << " is not found";
			exit(1);
		}

		std::cin >> sub_name >> num;
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

	while (std::cin >> head_path) {
		if (head_path == "end_of_connections") break;
		std::cin >> sub_path;

		head = find_path(head_path);

		if (head == nullptr) {
			std::cout << std::endl << "Object " << head_path << " not found";
			continue;
		}

		sub = find_path(sub_path);

		if (sub == nullptr) {
			std::cout << std::endl << "Handler object " << sub_path << " not found";
			continue;
		}

		head->connect(get_signal_function(head), sub, get_handler_function(sub));
	}
}

int Cl_application::exec_app() 
{
	this->set_all_objects_state(1);
	std::cout << "Object tree\n";
	this->print_branch();

	std::string command, head_path, sub_path, message;
	Cl_base *head, *sub;
	int state;

	while (std::cin >> command) {
		if (command == "END") break;

		if (command == "EMIT") {
			std::cin >> head_path;
			std::getline(std::cin, message);
			message.erase(message.begin());
			head = find_path(head_path);

			if (head == nullptr) {
				std::cout << std::endl << "Object " << head_path << " not found";
				continue;
			}

			head->transmit(get_signal_function(head), message);
		}

		if (command == "SET_CONNECT") {
			std::cin >> head_path >> sub_path;
			head = find_path(head_path);
			sub = find_path(sub_path);

			if (head == nullptr) {
				std::cout << std::endl << "Object " << head_path << " not found";
				continue;
			}

			if (sub == nullptr) {
				std::cout << std::endl << "Handler object " << sub_path << " not found";
				continue;
			}

			head->connect(get_signal_function(head), sub, get_handler_function(sub));
		}

		if (command == "DELETE_CONNECT") {
			std::cin >> head_path >> sub_path;
			head = find_path(head_path);
			sub = find_path(sub_path);

			if (head == nullptr) {
				std::cout << std::endl << "Object " << head_path << " not found";
				continue;
			}

			if (sub == nullptr) {
				std::cout << std::endl << "Handler object " << sub_path << " not found";
				continue;
			}

			head->disconnect(get_signal_function(head), sub, get_handler_function(sub));
		}

		if (command == "SET_CONDITION") {
			std::cin >> head_path >> state;
			head = find_path(head_path);

			if (head == nullptr) {
				std::cout << std::endl << "Object " << head_path << " not found";
				continue;
			}

			head->set_readiness(state);
		}
	}

	return 0;
}

void Cl_application::signal(std::string &message)
{
	std::cout << std::endl << "Signal from " << this->get_abs_path();
	message += " (class: 1)";
}

void Cl_application::handler(std::string &message)
{
	std::cout << std::endl << "Signal to " << this->get_abs_path() << "   Text: " << message;
}

TYPE_SIGNAL Cl_application::get_signal_function(Cl_base *object)
{
	int num = object->get_class_num();
	switch (num) {
	case 1:
		return SIGNAL_D(Cl_application::signal);
	case 2:
		return SIGNAL_D(Cl_myclass2::signal);
	case 3:
		return SIGNAL_D(Cl_myclass3::signal);
	case 4:
		return SIGNAL_D(Cl_myclass4::signal);
	case 5:
		return SIGNAL_D(Cl_myclass5::signal);
	case 6:
		return SIGNAL_D(Cl_myclass6::signal);
	default:
		return nullptr;
	}
}

TYPE_HANDLER Cl_application::get_handler_function(Cl_base *object)
{
	int num = object->get_class_num();
	switch (num) {
	case 1:
		return HANDLER_D(Cl_application::handler);
	case 2:
		return HANDLER_D(Cl_myclass2::handler);
	case 3:
		return HANDLER_D(Cl_myclass3::handler);
	case 4:
		return HANDLER_D(Cl_myclass4::handler);
	case 5:
		return HANDLER_D(Cl_myclass5::handler);
	case 6:
		return HANDLER_D(Cl_myclass6::handler);
	default:
		return nullptr;
	}
}