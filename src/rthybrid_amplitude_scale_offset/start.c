#include "rtsyn/internal/rthybrid_amplitude_scale_offset.h"
#include "rtsyn/internal/rthybrid_amplitude_scale_offset/start.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_start(void *instance)
{
    return instance ? RTSYN_ABI_STATUS_OK : RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}
