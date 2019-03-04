#include "cache.h"
#include "bits.h"

int get_set (Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //
  int ns = cache -> block_bits;
  address = address >> ns;
  ns = 32 - (cache-> set_bits);
  address = address << ns;
  address = address >> ns;
  return (int)address;
}

int get_line (Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
  int nl = cache-> set_bits + cache -> block_bits;
  address = address >> nl;
  return (int)address;
}

int get_byte (Cache *cache, address_type address) {
  // TODO
  // Extract the block (byte index) bits from a 32-bit address.
  //
  int nb = 32 - cache -> block_bits;

  address = address << nb;
  address = address >> nb;
  return (int)address;
}

