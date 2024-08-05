#include "./include/astring.h"
#include "./include/misc.h"
#include <stdlib.h>
#include <string.h>

string_t *init_string() {
  string_t *s = calloc(1, sizeof(string_t *));
  nerror(s, "out of memory on calloc string_t; abort");
  s->bufsize = 10;
  s->size = 0;
  s->buf = calloc(s->bufsize, sizeof(char));
  return s;
}

void string_push(string_t *s, char c) {
  if (s->size == s->bufsize - 2) {
    s->bufsize = s->bufsize * 2;
    s = realloc(s, (s->bufsize) * sizeof(char));
    nerror(s, "out of memory on realloc; abort");
  }
  s->buf[s->size] = c;
  s->size ++;
}
char *string_concat(string_t *s1, char *s2) {
  for (int i = 0; i < strlen(s2); i ++) {
    string_push(s1, s2[i]);
  }
  return s2;
}

void string_free(void *s) {
  free(((string_t *) s)->buf);
  free(s);
}
