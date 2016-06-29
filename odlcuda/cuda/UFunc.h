#pragma once

#include <stdint.h>
#include <sstream>
#include <type_traits>

#include <odlcuda/cuda/DeviceVector.h>
#include <odlcuda/cuda/CudaVectorImpl.h>

// clang-format off

//List of all Ufuncs
#define ODL_CUDA_FOR_EACH_UFUNC \
    X(sin) \
    X(cos) \
    X(arcsin) \
    X(arccos) \
    X(log) \
    X(exp) \
    X(absolute) \
    X(sign) \
    X(sqrt)

//Default to an error message
#define X(fun) template <typename Tin, typename Tout> void ufunc_##fun (const CudaVectorImpl<Tin>& in, CudaVectorImpl<Tout>& out) { throw std::domain_error("##fun UFunc not supported with this type"); }
ODL_CUDA_FOR_EACH_UFUNC
#undef X

//Implementations for floats
#define X(fun) template<> void ufunc_##fun <float, float>(const CudaVectorImpl<float>& in, CudaVectorImpl<float>& out);
ODL_CUDA_FOR_EACH_UFUNC
#undef X
