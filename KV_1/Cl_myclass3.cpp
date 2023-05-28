#include "Cl_myclass3.h"
#include <iostream>

Cl_myclass3::Cl_myclass3(Cl_base *head, std::string name) : Cl_base(head, name) {
	this->set_class_num(3);
}

void Cl_myclass3::signal(std::string &message)
{
	std::cout << std::endl << "Signal from " << this->get_abs_path();
	message += " (class: 3)";
}

void Cl_myclass3::handler(std::string &message)
{
	std::cout << std::endl << "Signal to " << this->get_abs_path() << "   Text: " << message;
}
