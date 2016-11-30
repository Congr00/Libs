#include "..\Headers\Array2d.h"

int main(void) {

	struct Array2D* table = (struct Array2D*)malloc(sizeof(struct Array2D));

	int x = 3, y = 6;
	Init(x, y, table);

	for (int j = 0, k = 1; j < y; j++) 
		for (int i = 0; i < x; i++, k++)
			set_cell(table, i, j, k);

	print_table(table);
	printf("\n");

	resize(table, x - 2, y - 3);

	print_table(table);
	printf("\n");

	return 0;
}