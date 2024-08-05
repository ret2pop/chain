#ifndef VM_H
#define VM_H
#include "array.h"
#include "astring.h"
#include <stdlib.h>
#include "crypto.h"

typedef string_t *bytecode_t; /* string_t can be used to append bytes */

typedef struct {
  enum {
    VM_NUMBER,
    VM_STRING,
    VM_STACK,
  } type;
  union {
    long double number;
    string_t *string;
    array_t *stack;
    unsigned long long address;
  };
} value_t;

typedef struct BST_NODE {
  struct BST_NODE *l;
  struct BST_NODE *r;
  void *v; /* value_t */
} bst_t;

typedef struct {
  size_t size;
  bst_t **buckets;
} ht_t;

typedef struct {
  enum {
    /* MISC */
    OP_NOP = 0x0,
    OP_ADD = 0x1,
    OP_SUB = 0x2,
    OP_MUL = 0x3,
    OP_DIV = 0x4,
    OP_MOD = 0x5,
    OP_LTE = 0x6,
    OP_GTE = 0x7,
    OP_LT = 0x8,
    OP_GT = 0x9,
    OP_EQ = 0xA,
    /* BITWISE OPS */
    OP_XOR = 0xB,
    OP_AND = 0xC,
    OP_OR = 0xD,
    /* COMBINATORS */
    OP_CALL = 0xE,
    OP_IF = 0xF,
    OP_DIP = 0x10,
    OP_DUP = 0x11,
    OP_EVAL = 0x12,

    OP_CURRY = 0x13,
    OP_UNCURRY = 0x14,
    OP_NTH = 0x15,
    OP_SWAP = 0x16,
    OP_PUSHINT = 0x17,
    OP_PUSHLABEL = 0x18,
    OP_PUSHESTACK = 0x19, /* push empty stack */
    OP_STACKSTACK = 0x2A,
    OP_EXTERN = 0x2B,
    OP_HALT = 0x2C,
    OP_KECCAK256 = 0x2D,
    OP_CONCAT = 0x2E,
    OP_VERIFY_SIG = 0x2F,

    NOTOP_STR = 0xFE,
    NOTOP_END = 0xFF,
  } opcodes;

  array_t *stack; /* array of value_ts */
  ht_t *vars;
  bytecode_t bytecode;
  unsigned long long n; /* the nth byte to read */
} vm_t;

/* Initialize memory for new VM */
vm_t *init_vm(bytecode_t bytecode);

/* Increments the VM by one byte */
void vm_increment(vm_t *vm);

/* Executes current instruction */
void vm_execute_cur(vm_t *vm);

/* executes all the bytecode */
void vm_execute_all(vm_t *vm);

#endif
