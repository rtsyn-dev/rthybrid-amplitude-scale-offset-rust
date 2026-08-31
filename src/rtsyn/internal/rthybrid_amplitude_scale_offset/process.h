/**
 * @file rtsyn/internal/rthybrid_amplitude_scale_offset/process.h
 * @brief process callback declaration for RTHybrid Amplitude Scale Offset.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PROCESS_H
#define RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PROCESS_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_process(void *instance, const rtsyn_abi_runtime_context_t *context);
#ifdef __cplusplus
}
#endif
#endif
