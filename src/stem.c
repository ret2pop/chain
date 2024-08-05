#include "include/stem.h"
#include "include/misc.h"
#include "include/astring.h"
#include <stdlib.h>

stem_t *init_stem_comp(string_t *source) {
  stem_t *s = calloc(1, sizeof(stem_t *));
  nerror(s, "dead on calloc");
  s->source = init_string();
  return s;
}

void gen_next(stem_t *s) {
  
  switch (s->c) {
  }
}
