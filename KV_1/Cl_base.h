#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <string>
#include <vector>

class Cl_base;

#define SIGNAL_D(signal_f) (TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f) (TYPE_HANDLER)(&handler_f)

typedef void (Cl_base::*TYPE_SIGNAL)(std::string &);
typedef void (Cl_base::*TYPE_HANDLER)(std::string);

class Cl_base {
private:
	std::string name;
	Cl_base *head;
	int state = 0;
	int class_num;
	std::vector<Cl_base *> subordinate_objects;
	struct connection {
		TYPE_SIGNAL p_signal;
		Cl_base *target;
		TYPE_HANDLER p_handler;
	};
	std::vector<connection*> connections;
public:
	Cl_base(Cl_base* p_head_object, std::string s_object_name = "Base_object");
	~Cl_base();
	bool rename(std::string new_name);
	std::string get_name();
	Cl_base* get_head_ptr();
	Cl_base* get_subordinate_ptr(std::string name);
	Cl_base* find_in_branch(std::string name);
	Cl_base* find_in_tree(std::string name);
	void print_branch(int indent=0);
	void print_branch_readiness(int indent=0);
	void set_readiness(int state);
	int get_state();
	bool rebase(Cl_base *new_head);
	void delete_sub_object(std::string name);
	Cl_base* find_path(std::string path);

	void connect(TYPE_SIGNAL signal, Cl_base *target, TYPE_HANDLER handler);
	void disconnect(TYPE_SIGNAL signal, Cl_base *target, TYPE_HANDLER handler);
	void transmit(TYPE_SIGNAL signal, std::string &message);
	std::string get_abs_path();
	void set_class_num(int num);
	int get_class_num();
	void set_all_objects_state(int state);
};

#endif
