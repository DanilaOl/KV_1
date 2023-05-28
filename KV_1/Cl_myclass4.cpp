#include "Cl_myclass4.h"
#include <iostream>

Cl_myclass4::Cl_myclass4(Cl_base *head, std::string name) : Cl_base(head, name) {
	this->set_class_num(4);
}

void Cl_myclass4::signal(std::string &message)
{
	std::cout << std::endl << "Signal from " << this->get_abs_path();
	message += " (class: 4)";
}

void Cl_myclass4::handler(std::string &message)
{
	std::cout << std::endl << "Signal to " << this->get_abs_path() << "   Text: " << message;
}
