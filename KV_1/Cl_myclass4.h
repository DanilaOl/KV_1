#ifndef __CL_MYCLASS4__H
#define __CL_MYCLASS4__H

#include "Cl_base.h"
class Cl_myclass4 : public Cl_base {
public:
	Cl_myclass4(Cl_base *head, std::string name);
	void signal(std::string &message);
	void handler(std::string &message);
};

#endif