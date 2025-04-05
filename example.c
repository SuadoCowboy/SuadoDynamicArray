#include <stdio.h>
#include <time.h>

#include "sda.h"
#include "object.h"

void printUsage(const obj_array* pArray) {
	printf("Usage: %d/%d\n\n", pArray->size, pArray->capacity);
}

int main() {
	printf("objarr_init(2)\n");
	obj_array objects = objarr_init(2);
	printUsage(&objects);

	// printf("objarr_reserve(2)\n");
	// objarr_reserve(&objects, 2);
	// printUsage(&objects);

	Object object;
	printf("objarr_push() x4\n");
	for (unsigned short i = 0; i < 4; ++i) {
		object.value = i;
		objarr_push(&objects, &object);
		printUsage(&objects);
	}

	// printf("objarr_reserve(2)\n");
	// objarr_reserve(&objects, 2);
	// printUsage(&objects);

	// printf("objarr_push(69)\n");
	// object.value = 69;
	// objarr_push(&objects, &object);
	// printUsage(&objects);

	// printf("objarr_push(420)\n");
	// object.value = 420;
	// objarr_push(&objects, &object);
	// printUsage(&objects);

	// printf("objarr_pop(1)\n");
	// objarr_pop(&objects, 1);
	// printUsage(&objects);


	// printf("objarr_fit_capacity_to_size()\n");
	// objarr_fit_capacity_to_size(&objects);
	// printUsage(&objects);

	// printf("objarr_get(0)->value = 32;\n");
	// objarr_get(&objects, 0)->value = 32;
	// printUsage(&objects);

	// printf("objarr_free()\n");
	// objarr_free(&objects);
	// printf("Data:\t\t%p\n", objects.pData);
	// printUsage(&objects);

	// printf("objarr_clear()\n");
	// objarr_clear(&objects);
	// printf("Data:\t\t%p\n", objects.pData);
	// printUsage(&objects);

	printf("print(objects.pData)\n");
	for (unsigned short i = 0; i < objects.size; ++i) {
		Object* pObject = objarr_get(&objects, i);
		printf("%d ", pObject->value);
	}
	printf("\n\n");

	printf("objarr_free()\n");
	objarr_free(&objects);
	printf("Data:\t\t%p\n", objects.pData);
	printUsage(&objects);
}