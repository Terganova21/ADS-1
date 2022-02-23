// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int num = 0;
  int value = 1;
  while (num != n) {
    value++;
    if (checkPrime(value) == true) {
      num++;
    }
  }
  return value;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  if (checkPrime(value))
    return value;
  return nextPrime(value);
}

uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  hbound--;
  for (hbound; hbound > 1; hbound--) {
    if (checkPrime(hbound))
      sum += hbound;
  }
  return sum;
}
