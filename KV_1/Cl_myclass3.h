#ifndef __CL_MYCLASS3__H
#define __CL_MYCLASS3__H

#include "Cl_base.h"
class Cl_myclass3 : public Cl_base {
public:
	Cl_myclass3(Cl_base *head, std::string name);
	void signal(std::string &message);
	void handler(std::string &message);
};

#endif