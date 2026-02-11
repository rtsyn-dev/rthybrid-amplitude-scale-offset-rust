#include "rthybrid_amplitude_scale_offset_c.h"
#include <math.h>
#include <string.h>

static int key_eq(const char *key, size_t len, const char *lit) {
  size_t n = strlen(lit);
  return (len == n) && (strncmp(key, lit, n) == 0);
}

void rthybrid_amplitude_scale_offset_c_init(rthybrid_amplitude_scale_offset_c_state_t *s) {
  s->min1 = 0.0;
  s->max1 = 1.0;
  s->min2 = 0.0;
  s->max2 = 1.0;
  s->s12 = 1.0;
  s->o12 = 0.0;
  s->s21 = 1.0;
  s->o21 = 0.0;
}

void rthybrid_amplitude_scale_offset_c_set_input(rthybrid_amplitude_scale_offset_c_state_t *s, const char *key, size_t len, double v) {
  if (!isfinite(v)) return;
  if (key_eq(key, len, "Min 1 (V)")) s->min1 = v;
  else if (key_eq(key, len, "Max 1 (V)")) s->max1 = v;
  else if (key_eq(key, len, "Min 2 (V)")) s->min2 = v;
  else if (key_eq(key, len, "Max 2 (V)")) s->max2 = v;
}

void rthybrid_amplitude_scale_offset_c_process(rthybrid_amplitude_scale_offset_c_state_t *s) {
  if (!isfinite(s->min1) || !isfinite(s->max1) || !isfinite(s->min2) || !isfinite(s->max2)) {
    s->s12 = 1.0;
    s->s21 = 1.0;
    s->o12 = 0.0;
    s->o21 = 0.0;
    return;
  }
  double range1 = s->max1 - s->min1;
  double range2 = s->max2 - s->min2;
  if (!isfinite(range1) || !isfinite(range2) || fabs(range1) < 1e-15 || fabs(range2) < 1e-15) {
    s->s12 = 1.0;
    s->s21 = 1.0;
    s->o12 = 0.0;
    s->o21 = 0.0;
    return;
  }
  s->s12 = range2 / range1;
  s->s21 = range1 / range2;
  s->o12 = s->min2 - (s->min1 * s->s12);
  s->o21 = s->min1 - (s->min2 * s->s21);
  if (!isfinite(s->s12) || !isfinite(s->s21) || !isfinite(s->o12) || !isfinite(s->o21)) {
    s->s12 = 1.0;
    s->s21 = 1.0;
    s->o12 = 0.0;
    s->o21 = 0.0;
    return;
  }
  if (fabs(s->s12) > 1e6) s->s12 = (s->s12 > 0.0) ? 1e6 : -1e6;
  if (fabs(s->s21) > 1e6) s->s21 = (s->s21 > 0.0) ? 1e6 : -1e6;
  if (fabs(s->o12) > 1e6) s->o12 = (s->o12 > 0.0) ? 1e6 : -1e6;
  if (fabs(s->o21) > 1e6) s->o21 = (s->o21 > 0.0) ? 1e6 : -1e6;
}

double rthybrid_amplitude_scale_offset_c_get_output(const rthybrid_amplitude_scale_offset_c_state_t *s, const char *key, size_t len) {
  if (key_eq(key, len, "Scale 1-2")) return s->s12;
  if (key_eq(key, len, "Offset 1-2")) return s->o12;
  if (key_eq(key, len, "Scale 2-1")) return s->s21;
  if (key_eq(key, len, "Offset 2-1")) return s->o21;
  return 0.0;
}
