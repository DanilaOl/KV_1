#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <string>
#include <vector>

class Cl_base {
public:
	Cl_base(Cl_base* p_head_object, std::string s_object_name = "Base_object");
	bool rename(std::string new_name);
	std::string get_name();
	Cl_base* get_head_ptr();
	void print_tree();
	Cl_base* get_subordinate_ptr(std::string name);
private:
	std::string s_object_name;
	Cl_base* p_head_object;
	std::vector<Cl_base*> subordinate_objects;
};

#endif
