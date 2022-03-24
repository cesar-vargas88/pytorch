#pragma once

#include <functional>
#include <ATen/core/dispatch/Dispatcher.h>
#include <ATen/core/ivalue.h>
#include <ATen/core/stack.h>

namespace torch {
namespace lazy {

bool force_eager_fallback(c10::Symbol op);
void ltc_eager_fallback(
    const c10::OperatorHandle& op,
    torch::jit::Stack* stack);

void ts_eager_fallback(
    const c10::OperatorHandle& op,
    torch::jit::Stack* stack,
    c10::DeviceType device_type);

extern std::function<void(void)> register_ts_ltc_eager_fallback;

} // namespace lazy
} // namespace torch
