#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <string>
#include <vector>

class Cl_base {
private:
	Cl_base *head;
	std::string name;
	std::vector<Cl_base *> subordinate_objects;
public:
	/*int state = 0;
	int class_num;*/
	//Cl_base(Cl_base* p_head_object, int class_num, std::string s_object_name = "Base_object"); for KV_2
	Cl_base(Cl_base* head, std::string name = "Base_name");
	~Cl_base();
	bool rename(std::string new_name);
	std::string get_name();
	Cl_base* get_head_ptr();
	void print_tree();
	Cl_base* get_subordinate_ptr(std::string name);
	//Cl_base* find_in_branch(std::string name);
	//Cl_base* find_in_tree(std::string name);
	//void print_branch(int indent=0);
	//void print_branch_readiness(int indent=0);
	//void set_readiness(int state);
};

#endif
