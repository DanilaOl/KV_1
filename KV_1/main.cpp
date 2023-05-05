#include "Cl_application.h"
#include "Cl_base.h"

int main() {
    Cl_application app(nullptr);
    app.build_tree_objects();
    return app.exec_app();
}