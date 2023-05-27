#ifndef __CL_MYCLASS5__H
#define __CL_MYCLASS5__H

#include "Cl_base.h"
class Cl_myclass5 : public Cl_base {
public:
	Cl_myclass5(Cl_base *head, std::string name);
	void signal(std::string &message);
	void handler(std::string &message);
};

#endif