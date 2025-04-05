#include "object.h"

SDA_DEFINE_ARRAY_IMPLEMENTATION(Object, obj_array, objarr_, unsigned short)
void objarr_clear(obj_array* pArray) {
	while (pArray->size != 0) {
		pArray->pData[--pArray->size].value = 0;
	}
}