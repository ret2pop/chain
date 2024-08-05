#ifndef BLOCK_H
#define BLOCK_H
#include "array.h"
#include "crypto.h"
#include <stdbool.h>

typedef unsigned char uint8;

typedef struct {

} transfer_t;

typedef struct {
} call_t;

typedef struct {
} req_bc_t;

typedef struct {
  enum {
    REQ_TRANSFER,
    REQ_CALL,
    REQ_BYTECODE,
  } type;
  union {
    transfer_t *transfer;
    call_t *call;
    req_bc_t *bc;
  };
} txn_req_t;

typedef struct {
  signer_t *signer;
  unsigned long long seqno;
  txn_req_t *req;
} txn_t;

typedef struct {
  array_t *txns;
  array_t *bytecodes; /* txns and bytecodes can have variable block size but
                         attempted commit from RPC must exclude further
                         submittions from the next block at some point. Stores
                         type bytecode_t and txn_t */
  unsigned long long seqno;     /*current block number */
  unsigned long long nonce;     /* nonce is altered during mining process */
  unsigned long long prev_hash; /* previous block hash */
  signer_t *signer;
} block_t;

/* Allocates memory for first block */
block_t *init_first_block();

/* Calculates the reward for mining the next block */
long double next_miner_reward(block_t *cur);

/* Calculates the next nonce difficulty (the first `n` bits to match the
 * previous block's hash) */
unsigned int next_nonce_difficulty(block_t *cur);

/* Gets the current block hash */
unsigned long long block_hash(block_t *cur);

/* verifies the next block against the most recent block */
bool verify(block_t *cur, block_t *v);

/* Writes a block to disk at a given directory */
bool write_block(block_t *b, char *path);

/* Frees block memory */
void block_free(void *block);

#endif
