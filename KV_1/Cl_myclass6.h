#ifndef __CL_MYCLASS6__H
#define __CL_MYCLASS6__H

#include "Cl_base.h"
class Cl_myclass6 : public Cl_base {
public:
	Cl_myclass6(Cl_base *head, std::string name);
	void signal(std::string &message);
	void handler(std::string &message);
};

#endif