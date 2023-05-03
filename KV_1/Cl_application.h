#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H

#include "Cl_base.h"
#include <string>

class Cl_application : public Cl_base {
public:
	Cl_application(Cl_base* p_head_object, std::string s_object_name = "Base_object");
	void build_tree_objects();
	int exec_app();
};

#endif