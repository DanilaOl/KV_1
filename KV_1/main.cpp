#include "Cl_application.h"
#include "Cl_base.h"

int main() {
    Cl_application ob_cl_application(nullptr); // �������� ��������� �������
    ob_cl_application.build_tree_objects();       // ��������������� �������, ���������� ������ ��������
    return ob_cl_application.exec_app();         // ������ �������
}