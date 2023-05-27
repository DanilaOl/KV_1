#ifndef __CL_MYCLASS2__H
#define __CL_MYCLASS2__H
#include "Cl_base.h"
class Cl_myclass2 : public Cl_base {
public:
	Cl_myclass2(Cl_base* head, std::string name);
	void signal(std::string &message);
	void handler(std::string &message);
};

#endif