/*
 * Copyright (c) 2024 WATANABE Aoi
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ak.hpp"

namespace ak
{
	uint16_t f2u(const float x, const float x_min, const float x_max, const size_t bits)
	{
		if (x < x_min)
		{
			return x_min;
		}
		else if (x > x_max)
		{
			return x_max;
		}
		return (uint16_t)((x - x_min) * (float)((2 << (bits - 1)) - 1) / (x_max - x_min));
	}
}; // namespace ak
