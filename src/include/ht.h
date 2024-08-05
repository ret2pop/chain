#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "array.h"
#include <stdlib.h>

typedef struct {
  array_t **buckets;
  size_t size;
} ht_t;

ht_t *init_ht(size_t size);

#endif
