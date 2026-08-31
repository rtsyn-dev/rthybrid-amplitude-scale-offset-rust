/**
 * @file rtsyn/internal/rthybrid_amplitude_scale_offset/set_param.h
 * @brief set_param callback declaration for RTHybrid Amplitude Scale Offset.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_SET_PARAM_H
#define RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_SET_PARAM_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_set_param(void *instance, uint32_t param_index, const void *value);
#ifdef __cplusplus
}
#endif
#endif
