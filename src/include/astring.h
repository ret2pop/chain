#ifndef ASTRING_H
#define ASTRING_H
#include <stdlib.h>

typedef struct {
  char *buf;
  size_t size;
  size_t bufsize;
} string_t;

/* Initializes an empty string with a buffer */
string_t *init_string();

/* Appends value to string */
void string_push(string_t *s, char value);

/* Concatenates s2 to s1 */
char *string_concat(string_t *s1, char *s2);

/* Frees string struct */
void string_free(void *s);

#endif
