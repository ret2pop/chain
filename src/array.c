#include "./include/array.h"
#include "./include/misc.h"
#include <stdlib.h>

array_t *init_array() {
  array_t *a = calloc(1, sizeof(array_t *));
  nerror(a, "error on calloc");
  a->bufsize = 10;
  a->items = calloc(a->bufsize, sizeof(void *));
  a->size = 0;
  return a;
}

void array_push(array_t *a, void *item) {
}

void *array_pop(array_t *a) {
}

void array_free(void *a) {
}
