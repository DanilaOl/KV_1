#ifndef __CL_MYCLASS__H
#define __CL_MYCLASS__H
#include "Cl_base.h"
class Cl_myclass : public Cl_base {
public:
	Cl_myclass(Cl_base* head, std::string name);
};

#endif