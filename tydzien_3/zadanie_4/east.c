//east.c
#include <stdio.h>
#include "agents.h"

void east(struct agent *a)
{
	(*a).x += 1;
}
