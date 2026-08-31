/**
     * @file rtsyn/internal/rthybrid_amplitude_scale_offset.h
     * @brief Internal state for the RTHybrid Amplitude Scale Offset module.
     *
     * SPDX-License-Identifier: GPL-3.0-or-later
     */
    #ifndef RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_H
    #define RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_H

    #include <stddef.h>
    #include <stdint.h>

    #ifdef __cplusplus
    extern "C" {
    #endif

    typedef struct rtsyn_rthybrid_amplitude_scale_offset_instance_s {
        double min1;
double max1;
double min2;
double max2;
double s12;
double o12;
double s21;
double o21;
    } rtsyn_rthybrid_amplitude_scale_offset_instance_t;

    typedef enum rtsyn_rthybrid_amplitude_scale_offset_instance_ports_e : uint32_t {
        RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MIN_1_V = 0,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MAX_1_V = 1,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MIN_2_V = 2,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MAX_2_V = 3,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_SCALE_1_2 = 4,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_OFFSET_1_2 = 5,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_SCALE_2_1 = 6,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_OFFSET_2_1 = 7,
        RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_COUNT = 8,
    } rtsyn_rthybrid_amplitude_scale_offset_instance_ports_t;

    typedef enum rtsyn_rthybrid_amplitude_scale_offset_instance_params_e : uint32_t {

        RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PARAM_COUNT = 0,
    } rtsyn_rthybrid_amplitude_scale_offset_instance_params_t;

    typedef enum rtsyn_rthybrid_amplitude_scale_offset_instance_states_e : uint32_t {
        RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MIN1 = 0,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MAX1 = 1,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MIN2 = 2,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MAX2 = 3,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_S12 = 4,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_O12 = 5,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_S21 = 6,
RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_O21 = 7,
        RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_COUNT = 8,
    } rtsyn_rthybrid_amplitude_scale_offset_instance_states_t;

    #ifdef __cplusplus
    }
    #endif

    #endif /* RTSYN_INTERNAL_RTHYBRID_AMPLITUDE_SCALE_OFFSET_H */
