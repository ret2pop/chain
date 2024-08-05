#ifndef CRYPTO_H
#define CRYPTO_H
typedef unsigned char uint8;

typedef struct {

} signer_t;

unsigned long long keecak256(uint8 *bytes);
unsigned long long keecak256long(unsigned long long nonce);
#endif
