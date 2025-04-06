#pragma once

#include <malloc.h>

#define SDA_DEFINE_ARRAY_HEADER(type, name, functionNamePrefix, sizeType, declspecPrefix) \
typedef struct declspecPrefix name { \
	sizeType capacity; \
	sizeType size; \
	type* pData; \
} name; \
declspecPrefix name functionNamePrefix##init(sizeType initialCapacity); \
declspecPrefix void functionNamePrefix##push(name *pArray, const type *pValue); \
declspecPrefix void functionNamePrefix##free(name *pArray); \
declspecPrefix type* functionNamePrefix##get(const name *pArray, sizeType index); \
declspecPrefix void functionNamePrefix##pop(name *pArray, sizeType index); \
declspecPrefix void functionNamePrefix##reserve(name *pArray, sizeType toReserve); \
declspecPrefix void functionNamePrefix##fit_capacity_to_size(name *pArray);

#define SDA_DEFINE_ARRAY_IMPLEMENTATION(type, name, functionNamePrefix, sizeType) \
name functionNamePrefix##init(sizeType initialCapacity) { \
	name array; \
	array.capacity = initialCapacity; \
	array.size = 0; \
	array.pData = initialCapacity == 0? NULL : malloc(initialCapacity * sizeof(type)); \
	return array; \
} \
void functionNamePrefix##push(name *pArray, const type *pValue) { \
	if (pArray->size == pArray->capacity) { \
		pArray->capacity++; \
		if (pArray->pData == NULL) \
			pArray->pData = malloc(pArray->capacity * sizeof(type)); \
		else \
			pArray->pData = realloc(pArray->pData, pArray->capacity * sizeof(type)); \
	} \
	pArray->pData[pArray->size++] = *pValue; \
} \
void functionNamePrefix##free(name *pArray) { \
	if (pArray->pData == NULL) return; \
	free(pArray->pData); \
	pArray->pData = NULL; \
	pArray->size = pArray->capacity = 0; \
} \
type* functionNamePrefix##get(const name *pArray, sizeType index) { \
	return pArray->pData+index; \
} \
void functionNamePrefix##pop(name *pArray, sizeType index) { \
	for (sizeType i = index; i < pArray->size; ++i) { \
		pArray->pData[i] = pArray->pData[i+1]; \
	} \
	pArray->size--; \
} \
void functionNamePrefix##reserve(name *pArray, sizeType toReserve) { \
	pArray->capacity += toReserve; \
	pArray->pData = realloc(pArray->pData, pArray->capacity * sizeof(type)); \
} \
void functionNamePrefix##fit_capacity_to_size(name *pArray) { \
	if (pArray->capacity == pArray->size) return; \
	if (pArray->size == 0) { \
		functionNamePrefix##free(pArray); \
		return; \
	} \
	pArray->pData = realloc(pArray->pData, pArray->size * sizeof(type)); \
	pArray->capacity = pArray->size; \
}
