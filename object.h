#pragma once

#include "sda.h"

typedef struct Object {
	unsigned short value;
} Object;

SDA_DEFINE_ARRAY_HEADER(Object, obj_array, objarr_, unsigned short)
void objarr_clear(obj_array* pArray);