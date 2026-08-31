#include "rtsyn/internal/rthybrid_amplitude_scale_offset.h"
#include "rtsyn/internal/rthybrid_amplitude_scale_offset/read_state.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_read_state(const void *instance, uint32_t state_index, void *out_value)
{
    const rtsyn_rthybrid_amplitude_scale_offset_instance_t *self = (const rtsyn_rthybrid_amplitude_scale_offset_instance_t *)instance;
    if (!self || !out_value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    switch (state_index) {

    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MIN1: *(double *)out_value = self->min1; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MAX1: *(double *)out_value = self->max1; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MIN2: *(double *)out_value = self->min2; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MAX2: *(double *)out_value = self->max2; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_S12: *(double *)out_value = self->s12; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_O12: *(double *)out_value = self->o12; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_S21: *(double *)out_value = self->s21; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_O21: *(double *)out_value = self->o21; return RTSYN_ABI_STATUS_OK;

    default:
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
}
