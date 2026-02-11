#pragma once
#include <stddef.h>

typedef struct {
  double min1;
  double max1;
  double min2;
  double max2;
  double s12;
  double o12;
  double s21;
  double o21;
} rthybrid_amplitude_scale_offset_c_state_t;

void rthybrid_amplitude_scale_offset_c_init(rthybrid_amplitude_scale_offset_c_state_t *s);
void rthybrid_amplitude_scale_offset_c_set_input(rthybrid_amplitude_scale_offset_c_state_t *s, const char *key, size_t len, double v);
void rthybrid_amplitude_scale_offset_c_process(rthybrid_amplitude_scale_offset_c_state_t *s);
double rthybrid_amplitude_scale_offset_c_get_output(const rthybrid_amplitude_scale_offset_c_state_t *s, const char *key, size_t len);
