use rtsyn_plugin::prelude::*;
use serde_json::Value;

#[derive(Debug)]
struct RthybridAmplitudeScaleOffsetRust {
    in_0: f64,
    in_1: f64,
    in_2: f64,
    in_3: f64,
    out_0: f64,
    out_1: f64,
    out_2: f64,
    out_3: f64,
}

impl Default for RthybridAmplitudeScaleOffsetRust {
    fn default() -> Self {
        Self {
            in_0: 0.0,
            in_1: 0.0,
            in_2: 0.0,
            in_3: 0.0,
            out_0: 0.0,
            out_1: 0.0,
            out_2: 0.0,
            out_3: 0.0,
        }
    }
}

impl PluginDescriptor for RthybridAmplitudeScaleOffsetRust {
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

impl PluginRuntime for RthybridAmplitudeScaleOffsetRust {
    fn set_config_value(&mut self, key: &str, value: &Value) {
        let _ = (key, value);
    }

    fn set_input_value(&mut self, key: &str, v: f64) {
        match key {
            "Min 1 (V)" => self.in_0 = if v.is_finite() { v } else { 0.0 },
            "Max 1 (V)" => self.in_1 = if v.is_finite() { v } else { 0.0 },
            "Min 2 (V)" => self.in_2 = if v.is_finite() { v } else { 0.0 },
            "Max 2 (V)" => self.in_3 = if v.is_finite() { v } else { 0.0 },
            _ => {}
        }
    }

    fn process_tick(&mut self, _tick: u64, period_seconds: f64) {
        let _ = period_seconds;
        if !self.in_0.is_finite()
            || !self.in_1.is_finite()
            || !self.in_2.is_finite()
            || !self.in_3.is_finite()
        {
            self.out_0 = 1.0;
            self.out_1 = 0.0;
            self.out_2 = 1.0;
            self.out_3 = 0.0;
            return;
        }
        let range1 = self.in_1 - self.in_0;
        let range2 = self.in_3 - self.in_2;
        if !range1.is_finite()
            || !range2.is_finite()
            || range1.abs() < 1e-15
            || range2.abs() < 1e-15
        {
            self.out_0 = 1.0;
            self.out_1 = 0.0;
            self.out_2 = 1.0;
            self.out_3 = 0.0;
            return;
        }
        self.out_0 = (range2 / range1).clamp(-1e6, 1e6);
        self.out_2 = (range1 / range2).clamp(-1e6, 1e6);
        self.out_1 = (self.in_2 - self.in_0 * self.out_0).clamp(-1e6, 1e6);
        self.out_3 = (self.in_0 - self.in_2 * self.out_2).clamp(-1e6, 1e6);
    }

    fn get_output_value(&self, key: &str) -> f64 {
        match key {
            "Scale 1-2" => self.out_0,
            "Offset 1-2" => self.out_1,
            "Scale 2-1" => self.out_2,
            "Offset 2-1" => self.out_3,
            _ => 0.0,
        }
    }

    fn get_internal_value(&self, key: &str) -> Option<f64> {
        match key {
            "min1" => Some(self.in_0),
            "max1" => Some(self.in_1),
            "min2" => Some(self.in_2),
            "max2" => Some(self.in_3),
            "s12" => Some(self.out_0),
            "o12" => Some(self.out_1),
            "s21" => Some(self.out_2),
            "o21" => Some(self.out_3),
            _ => None,
        }
    }
}

rtsyn_plugin::export_plugin!(RthybridAmplitudeScaleOffsetRust);
