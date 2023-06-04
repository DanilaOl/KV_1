#include "Cl_myclass6.h"
#include <iostream>

Cl_myclass6::Cl_myclass6(Cl_base *head, std::string name) : Cl_base(head, name) {
	this->set_class_num(6);
}

void Cl_myclass6::signal(std::string &message)
{
	std::cout << std::endl << "Signal from " << this->get_abs_path();
	message += " (class: 6)";
}

void Cl_myclass6::handler(std::string &message)
{
	std::cout << std::endl << "Signal to " << this->get_abs_path() << " Text:  " << message;
}
