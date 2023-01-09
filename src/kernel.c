#include "console.h"
#include "opensbi.h"

void kinit(unsigned long long hartid, void* fdt) {
    (void) hartid;
    (void) fdt;
    kprintf("%s %x %i nya", "hewo uwu", 0x1234abcd, 69);

    while(1);
}

