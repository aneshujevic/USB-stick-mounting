#ifndef USB
#define USB

#define DEV_NAME_L 	32
#define PATH_L 		256
#define COMMAND_L 	64

#include "mmount.c"
#include "ummount.c"

int mount(void*);
int umount(void*);

#endif
