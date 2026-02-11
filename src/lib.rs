use rtsyn_plugin::prelude::*;
use serde_json::Value;
use std::mem::MaybeUninit;

#[repr(C)]
struct RthybridAmplitudeScaleOffsetCState {
    min1: f64,
    max1: f64,
    min2: f64,
    max2: f64,
    s12: f64,
    o12: f64,
    s21: f64,
    o21: f64,
}

unsafe extern "C" {
    fn rthybrid_amplitude_scale_offset_c_init(state: *mut RthybridAmplitudeScaleOffsetCState);
    fn rthybrid_amplitude_scale_offset_c_set_input(
        state: *mut RthybridAmplitudeScaleOffsetCState,
        key: *const u8,
        len: usize,
        value: f64,
    );
    fn rthybrid_amplitude_scale_offset_c_process(state: *mut RthybridAmplitudeScaleOffsetCState);
    fn rthybrid_amplitude_scale_offset_c_get_output(
        state: *const RthybridAmplitudeScaleOffsetCState,
        key: *const u8,
        len: usize,
    ) -> f64;
}

struct RthybridAmplitudeScaleOffsetC {
    state: RthybridAmplitudeScaleOffsetCState,
}

impl Default for RthybridAmplitudeScaleOffsetC {
    fn default() -> Self {
        let mut state = MaybeUninit::<RthybridAmplitudeScaleOffsetCState>::uninit();
        unsafe {
            rthybrid_amplitude_scale_offset_c_init(state.as_mut_ptr());
            Self {
                state: state.assume_init(),
            }
        }
    }
}

impl PluginDescriptor for RthybridAmplitudeScaleOffsetC {
    fn name() -> &'static str {
        "RTHybrid Amplitude Scale Offset"
    }

    fn kind() -> &'static str {
        "rthybrid_amplitude_scale_offset"
    }

    fn plugin_type() -> PluginType {
        PluginType::Standard
    }

    fn inputs() -> &'static [&'static str] {
        &["Min 1 (V)", "Max 1 (V)", "Min 2 (V)", "Max 2 (V)"]
    }

    fn outputs() -> &'static [&'static str] {
        &["Scale 1-2", "Offset 1-2", "Scale 2-1", "Offset 2-1"]
    }

    fn internal_variables() -> &'static [&'static str] {
        &["min1", "max1", "min2", "max2", "s12", "o12", "s21", "o21"]
    }

    fn default_vars() -> Vec<(&'static str, Value)> {
        Vec::new()
    }

    fn behavior() -> PluginBehavior {
        PluginBehavior {
            supports_start_stop: true,
            supports_restart: true,
            supports_apply: false,
            extendable_inputs: ExtendableInputs::None,
            loads_started: false,
            external_window: false,
            starts_expanded: true,
            start_requires_connected_inputs: Vec::new(),
            start_requires_connected_outputs: Vec::new(),
        }
    }
}

impl PluginRuntime for RthybridAmplitudeScaleOffsetC {
    fn set_config_value(&mut self, _key: &str, _value: &Value) {}

    fn set_input_value(&mut self, key: &str, value: f64) {
        unsafe {
            rthybrid_amplitude_scale_offset_c_set_input(
                &mut self.state,
                key.as_ptr(),
                key.len(),
                value,
            );
        }
    }

    fn process_tick(&mut self, _tick: u64, _period_seconds: f64) {
        unsafe { rthybrid_amplitude_scale_offset_c_process(&mut self.state) };
    }

    fn get_output_value(&self, key: &str) -> f64 {
        unsafe { rthybrid_amplitude_scale_offset_c_get_output(&self.state, key.as_ptr(), key.len()) }
    }

    fn get_internal_value(&self, key: &str) -> Option<f64> {
        match key {
            "min1" => Some(self.state.min1),
            "max1" => Some(self.state.max1),
            "min2" => Some(self.state.min2),
            "max2" => Some(self.state.max2),
            "s12" => Some(self.state.s12),
            "o12" => Some(self.state.o12),
            "s21" => Some(self.state.s21),
            "o21" => Some(self.state.o21),
            _ => None,
        }
    }
}

rtsyn_plugin::export_plugin!(RthybridAmplitudeScaleOffsetC);
