#include <math.h>
#include "rtsyn/internal/rthybrid_amplitude_scale_offset.h"
#include "rtsyn/internal/rthybrid_amplitude_scale_offset/set_param.h"
static double finite_or(double value, double fallback) { return isfinite(value) ? value : fallback; }
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_set_param(void *instance, uint32_t param_index, const void *value)
{
    rtsyn_rthybrid_amplitude_scale_offset_instance_t *self = (rtsyn_rthybrid_amplitude_scale_offset_instance_t *)instance;
    if (!self || !value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}
