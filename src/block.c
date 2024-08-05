#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "include/crypto.h"
#include "include/block.h"
#define EULER_NUMBER_L 2.71828182845904523536

block_t *init_first_block() {
  block_t *b = (block_t *) calloc(1, sizeof(block_t *));
  b->bytecodes = init_array();
  b->txns = init_array();
  b->nonce = 456;
  b->prev_hash = 123;
  return b;
}

long double next_miner_reward(block_t *cur) {
  long long x = (cur->seqno / 210000) * 2;
  if (x == 0)
    return 5000;
  return 5000 / x;
}

unsigned int next_nonce_difficulty(block_t *cur) {
  return floor((1 / (1 + pow(EULER_NUMBER_L, -cur->nonce))) * 64);
}

unsigned long long block_hash(block_t *cur) {
  unsigned long long nonce_hash = keecak256long(cur->nonce);
  unsigned long long seqnohash = keecak256long(cur->seqno);
  // TODO: hash the txns and bytecodes together and hash the entire thing
  unsigned long long hashtogether = keecak256long(nonce_hash + seqnohash);
  return hashtogether;
}

bool verify(block_t *cur, block_t *v) {
  unsigned long long bhash = block_hash(cur);
  unsigned long long bhashnew = block_hash(v);
  unsigned int difficulty = next_nonce_difficulty(cur);
  int mask = (1 << difficulty)  - 1;

  return ((bhash & mask) == (bhashnew & mask));
}
