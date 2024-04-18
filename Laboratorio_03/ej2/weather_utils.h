#ifndef _WEATHER_UTILS_C
#define _WEATHER_UTILS_C

#include <stdbool.h>

int min_temp_hist(WeatherTable weather);

void proc_max_anual(WeatherTable a, int output[YEARS]);

void proc_max_pres_m(WeatherTable a, int output[YEARS]);

#endif