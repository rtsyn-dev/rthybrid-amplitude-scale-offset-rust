/**
 * @file rtsyn/internal/rthybrid_amplitude_scale_offset/read_state.h
 * @brief read_state callback declaration for RTHybrid Amplitude Scale Offset.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_READ_STATE_H
#define RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_READ_STATE_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_read_state(const void *instance, uint32_t state_index, void *out_value);
#ifdef __cplusplus
}
#endif
#endif
