#ifndef STEM_H
#define STEM_H
#include "astring.h"
#include "array.h"

typedef struct { /* LABEL TABLE */

} ltable_t;

typedef struct {
  unsigned int i;
  char c;
  string_t *source;
  string_t *bc;
} stem_t;

stem_t *init_stem_comp(string_t *source);

void gen_next(stem_t *comp);

#endif
