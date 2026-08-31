#include <stddef.h>
        #include "rtsyn/rthybrid_amplitude_scale_offset.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/create.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/destroy.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/process.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/read_state.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/set_param.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/start.h"
        #include "rtsyn/internal/rthybrid_amplitude_scale_offset/stop.h"

        static const rtsyn_abi_port_descriptor_t rtsyn_rthybrid_amplitude_scale_offset_ports[RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_COUNT] = {
            [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MIN_1_V] =
        {
            .name = "min_1_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MAX_1_V] =
        {
            .name = "max_1_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MIN_2_V] =
        {
            .name = "min_2_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_MAX_2_V] =
        {
            .name = "max_2_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_SCALE_1_2] =
        {
            .name = "scale_1_to_2",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_OFFSET_1_2] =
        {
            .name = "offset_1_to_2",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_SCALE_2_1] =
        {
            .name = "scale_2_to_1",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_OFFSET_2_1] =
        {
            .name = "offset_2_to_1",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
        };


        static const rtsyn_abi_state_descriptor_t rtsyn_rthybrid_amplitude_scale_offset_states[RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_COUNT] = {
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MIN1] =
        {
            .name = "min1",
            .description = "Last range 1 minimum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MAX1] =
        {
            .name = "max1",
            .description = "Last range 1 maximum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MIN2] =
        {
            .name = "min2",
            .description = "Last range 2 minimum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_MAX2] =
        {
            .name = "max2",
            .description = "Last range 2 maximum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_S12] =
        {
            .name = "s12",
            .description = "Scale from range 1 to range 2",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_O12] =
        {
            .name = "o12",
            .description = "Offset from range 1 to range 2",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_S21] =
        {
            .name = "s21",
            .description = "Scale from range 2 to range 1",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_O21] =
        {
            .name = "o21",
            .description = "Offset from range 2 to range 1",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_node_descriptor_t rtsyn_rthybrid_amplitude_scale_offset_descriptor = {
            .name = "rthybrid_amplitude_scale_offset",
            .node_type = RTSYN_ABI_NODE_PLUGIN,
            .port_count = RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PORT_COUNT,
            .ports = rtsyn_rthybrid_amplitude_scale_offset_ports,
            .param_count = RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_PARAM_COUNT,
            .params = NULL,
            .state_count = RTSYN_RTHYBRID_AMPLITUDE_SCALE_OFFSET_STATE_COUNT,
            .states = rtsyn_rthybrid_amplitude_scale_offset_states,
            .callbacks = {
                .create = rtsyn_rthybrid_amplitude_scale_offset_create,
                .set_param = rtsyn_rthybrid_amplitude_scale_offset_set_param,
                .read_state = rtsyn_rthybrid_amplitude_scale_offset_read_state,
                .start = rtsyn_rthybrid_amplitude_scale_offset_start,
                .process = rtsyn_rthybrid_amplitude_scale_offset_process,
                .stop = rtsyn_rthybrid_amplitude_scale_offset_stop,
                .destroy = rtsyn_rthybrid_amplitude_scale_offset_destroy,
            },
        };

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_rthybrid_amplitude_scale_offset_get_descriptor(void)
        {
            return &rtsyn_rthybrid_amplitude_scale_offset_descriptor;
        }

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_module_get_descriptor(void)
        {
            return rtsyn_rthybrid_amplitude_scale_offset_get_descriptor();
        }
