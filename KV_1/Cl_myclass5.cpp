#include "Cl_myclass5.h"
#include <iostream>

Cl_myclass5::Cl_myclass5(Cl_base *head, std::string name) : Cl_base(head, name) {
	this->set_class_num(5);
}

void Cl_myclass5::signal(std::string &message)
{
	std::cout << std::endl << "Signal from " << this->get_abs_path();
	message += " (class: 5)";
}

void Cl_myclass5::handler(std::string &message)
{
	std::cout << std::endl << "Signal to " << this->get_abs_path() << " Text:  " << message;
}
