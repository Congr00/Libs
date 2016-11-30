#ifndef ARRAY2D
#define ARRAY2D

#include <stdio.h>
#include <stdlib.h>

struct Array2D
{
	unsigned int width;
	unsigned int height;
	int *table;
};

/* init pointer of desired size x * y  */
void Init(int width, int height, struct Array2D *p) {
	p->table = (int*)calloc(width * height, sizeof(int));
	p->width = width;
	p->height = height;
}
/* get value of virtual table at [x][y] */
int get_cell(const struct Array2D *array, unsigned int x, unsigned int y) {
	return 	array->table[(array->width * y) + x];
}
/* set value of virtual table at [x][y] */
void set_cell(struct Array2D *array, unsigned int x, unsigned int y, int val) {
	array->table[(array->width * y) + x] = val;
}
/* print table per row */
void print_table(struct Array2D *array) {
	for (unsigned int i = 0; i < array->width * array->height; i++) {
		if (!(i % array->width)) {
			printf("\n");
		}
		printf("%d ", array->table[i]);
	}
}
/* resize table to [x][y] if desired size is less then original data is lost 
if more then new values are filled with 0 if size = 0 table is null pointer */
void resize(struct Array2D *array, unsigned int width, unsigned int height) {

	unsigned int wdth = array->width; // strange

	if (width < wdth && width != 0) {
		int div = (array->width - width);
		for (unsigned int i = array->width, j = 0; i < (array->width * array->height) - (array->width - width); i++, j++) {
			if (j == width) {
				j = 0;
				i += array->width - width;
				div += (array->width - width);
			}
			array->table[i - div] = array->table[i];
		}
	}
	array->table = (int*)realloc(array->table, width * height * sizeof(int));
	if (width > wdth && width != 0) {
		unsigned int h = 0;
		unsigned int div = 0;
		if (height < array->height) {
			h = height;
			div = (width * height - (height* array->width)) - (width - array->width);
		}
		else {
			h = array->height;
			div = (width * array->height - (array->height * array->width)) - (width - array->width);
		}
		for (unsigned int i = (array->width * h) - 1, j = 0; i >= array->width; i--, j++) {
			if (j == array->width) {
				j = 0;
				div -= (width - array->width);
			}
			array->table[i + div] = array->table[i];
			array->table[i] = 0;
		}
	}
	if (height > array->height) {
		for (unsigned int i = 0; i < width*height; i++) {
			if (array->table[i] < 0)
				array->table[i] = 0;
		}
	}
	if (width > array->width) {
		for (unsigned int i = array->width; i < width * array->height; i++) {
			array->table[i] = 0;
			if (!(i + 1) % width)
				i += array->width;
		}
	}
	array->width = width;
	array->height = height;
	if (width == 0 || height == 0) {
		array->width = 0;
		array->height = 0;
	}
}

#endif // !Array2D

