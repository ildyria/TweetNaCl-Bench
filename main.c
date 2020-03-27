#include "tweetnacl.h"
#include <stdio.h>
#include <time.h>

typedef unsigned char u8;

int main(int argc, char const *argv[]) {

  long long count = 999;
  u8 n[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  u8 q[32] = {0};
  clock_t startTime, endTime, timeElapsed;

  startTime = clock();
  crypto_scalarmult_curve25519_tweet_base(q,n);
  for (long long i = 0; i < count; i++) {
    crypto_scalarmult_curve25519_tweet(q,q,n);
  }
  endTime = clock();
  timeElapsed = endTime - startTime;

  printf("timeElapsed = %ld\n", timeElapsed);
  for(int j = 0; j < 32; j+=4)
  {
    printf("%02lx%02lx%02lx%02lx ",q[j],q[j+1],q[j+2],q[j+3]);
  }
  printf("\n");

  return 0;
}
