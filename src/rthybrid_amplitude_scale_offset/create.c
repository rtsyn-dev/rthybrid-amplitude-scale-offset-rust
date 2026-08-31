#include <math.h>
#include <stdlib.h>
#include "rtsyn/internal/rthybrid_amplitude_scale_offset.h"
#include "rtsyn/internal/rthybrid_amplitude_scale_offset/create.h"

rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_create(void **out_instance)
{
    if (!out_instance) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    rtsyn_rthybrid_amplitude_scale_offset_instance_t *self = (rtsyn_rthybrid_amplitude_scale_offset_instance_t *)malloc(sizeof(rtsyn_rthybrid_amplitude_scale_offset_instance_t));
    if (!self) return RTSYN_ABI_STATUS_ERROR;

    self->min1 = 0.0;
    self->max1 = 1.0;
    self->min2 = 0.0;
    self->max2 = 1.0;
    self->s12 = 1.0;
    self->o12 = 0.0;
    self->s21 = 1.0;
    self->o21 = 0.0;

    *out_instance = self;
    return RTSYN_ABI_STATUS_OK;
}
