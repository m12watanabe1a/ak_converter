/*
 * Copyright (c) 2024 WATANABE Aoi
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <math.h>
#include <stdlib.h>

namespace ak
{
#ifdef AK60
  static const float P_MIN = -12.5;
  static const float P_MAX = 12.5;
  static const float V_MIN = -45.0;
  static const float V_MAX = 45.0;
  static const float T_MIN = -15.0;
  static const float T_MAX = 15.0;
  static const float Kp_MIN = 0.0;
  static const float Kp_MAX = 500.0;
  static const float Kd_MIN = 0.0;
  static const float Kd_MAX = 5.0;
#endif
#ifdef AK70
  static const float P_MIN = -12.5;
  static const float P_MAX = 12.5;
  static const float V_MIN = -50.0;
  static const float V_MAX = 50.0;
  static const float T_MIN = -25.0;
  static const float T_MAX = 25.0;
  static const float Kp_MIN = 0.0;
  static const float Kp_MAX = 500.0;
  static const float Kd_MIN = 0.0;
  static const float Kd_MAX = 5.0;
#endif
  static const float RPM2RPS = 2.0 * M_PI / 60.0;
  static const float RPS2RPM = 60.0 / 2.0 / M_PI;

  uint16_t f2u(const float x, const float x_min, const float x_max, const size_t bits);
}; // namespace ak
