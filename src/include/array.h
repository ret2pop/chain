#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
/*
 A simple array implementation with efficient buffer allocation
 */
typedef struct {
  void **items;
  size_t size;
  size_t bufsize;
} array_t;

array_t *init_array();

/* Pushes item onto back of array */
void array_push(array_t *a, void *item);

void *array_pop(array_t *a);

void array_free(void *a);
#endif
