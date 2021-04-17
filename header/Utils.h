#pragma once
#include "Type.h"
#include <stdio.h>

#define DBGPRINTF          printf

void memory_set(void *_dst, u8 pattern, u32 nr_bytes);

