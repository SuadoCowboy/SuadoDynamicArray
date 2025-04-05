#pragma once

#include <malloc.h>

#define SDA_DEFINE_ARRAY_HEADER(type, name, functionsPrefix, sizeType) \
typedef struct name { \
	sizeType capacity; \
	sizeType size; \
	type* pData; \
} name; \
name functionsPrefix##init(sizeType initialCapacity); \
void functionsPrefix##push(name *pArray, const type *pValue); \
void functionsPrefix##free(name *pArray); \
type* functionsPrefix##get(const name *pArray, sizeType index); \
void functionsPrefix##pop(name *pArray, sizeType index); \
void functionsPrefix##reserve(name *pArray, sizeType toReserve); \
void functionsPrefix##fit_capacity_to_size(name *pArray);

#define SDA_DEFINE_ARRAY_IMPLEMENTATION(type, name, functionsPrefix, sizeType) \
name functionsPrefix##init(sizeType initialCapacity) { \
	name array; \
	array.capacity = initialCapacity; \
	array.size = 0; \
	array.pData = initialCapacity == 0? NULL : malloc(initialCapacity * sizeof(type)); \
	return array; \
} \
void functionsPrefix##push(name *pArray, const type *pValue) { \
	if (pArray->size == pArray->capacity) { \
		pArray->capacity++; \
		if (pArray->pData == NULL) \
			pArray->pData = malloc(pArray->capacity * sizeof(type)); \
		else \
			pArray->pData = realloc(pArray->pData, pArray->capacity * sizeof(type)); \
	} \
	pArray->pData[pArray->size++] = *pValue; \
} \
void functionsPrefix##free(name *pArray) { \
	if (pArray->pData == NULL) return; \
	free(pArray->pData); \
	pArray->pData = NULL; \
	pArray->size = pArray->capacity = 0; \
} \
type* functionsPrefix##get(const name *pArray, sizeType index) { \
	return pArray->pData+index; \
} \
void functionsPrefix##pop(name *pArray, sizeType index) { \
	for (sizeType i = index; i < pArray->size; ++i) { \
		pArray->pData[i] = pArray->pData[i+1]; \
	} \
	pArray->size--; \
} \
void functionsPrefix##reserve(name *pArray, sizeType toReserve) { \
	pArray->capacity += toReserve; \
	pArray->pData = realloc(pArray->pData, pArray->capacity * sizeof(type)); \
} \
void functionsPrefix##fit_capacity_to_size(name *pArray) { \
	if (pArray->capacity == pArray->size) return; \
	if (pArray->size == 0) { \
		functionsPrefix##free(pArray); \
		return; \
	} \
	pArray->pData = realloc(pArray->pData, pArray->size * sizeof(type)); \
	pArray->capacity = pArray->size; \
}
