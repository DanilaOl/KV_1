#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H

#include "Cl_base.h"
#include <string>

class Cl_application : public Cl_base {
public:
	Cl_application(Cl_base* head);
	void build_tree_objects();
	int exec_app();
	void signal(std::string &message);
	void handler(std::string &message);
	TYPE_SIGNAL get_signal_function(Cl_base *object);
	TYPE_HANDLER get_handler_function(Cl_base *object);
};

#endif