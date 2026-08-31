#include <stdlib.h>
#include "rtsyn/internal/rthybrid_amplitude_scale_offset.h"
#include "rtsyn/internal/rthybrid_amplitude_scale_offset/destroy.h"
void RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_destroy(void *instance)
{
    free((rtsyn_rthybrid_amplitude_scale_offset_instance_t *)instance);
}
