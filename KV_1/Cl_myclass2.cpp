#include "Cl_myclass2.h"
#include <iostream>

Cl_myclass2::Cl_myclass2(Cl_base *head, std::string name) : Cl_base(head, name) {
	this->set_class_num(2);
}

void Cl_myclass2::signal(std::string &message)
{
	std::cout << std::endl << "Signal from " << this->get_abs_path();
	message += " (class: 2)";
}

void Cl_myclass2::handler(std::string &message)
{
	std::cout << std::endl << "Signal to " << this->get_abs_path() << "   Text: " << message;
}
