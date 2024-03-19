/*
 * Copyright (c) 2024 Aoi WATANABE
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <cstdlib>
#include <string>

#include "ak.hpp"


void print_help(void) {
  printf("ak_torq [val]\n");
  printf("\t[val]: float value to convert u16 packet as hex\n");
  return;
}

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("invalid number of argument given");
    print_help();
    return -EXIT_FAILURE;
  }

  if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    print_help();
    return EXIT_SUCCESS;
  }

  float in = 0.0;
  try {
    in = std::stof(argv[1]);
  } catch (const std::invalid_argument &e) {
    printf("error: %s\n", e.what());
    print_help();
    return EXIT_FAILURE;
  }

  const uint16_t out = ak::f2u(in, ak::T_MIN, ak::T_MAX, 12);
  printf("0x%03X\n", out);
  return EXIT_SUCCESS;
}