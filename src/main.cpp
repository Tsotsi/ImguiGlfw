#include "vm.h"
#include "my_imgui.h"

int main(int argc, char** argv)
{
    vm_init();
    vm_open();
    vm_run();
    vm_close();
    imgui_init();
    return 0;
}
