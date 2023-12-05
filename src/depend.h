#pragma once
#include <glog/logging.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum temperature_type_t { temperature_type_K, temperature_type_F, temperature_type_R, temperature_type_C };

enum density_t {
    Density_API,
    Density_SG,
};

double temp_switch_to_K(double temp_in, temperature_type_t type);

double density_switch_to_api(double density_in, density_t type);

std::vector<double> TDMA(std::vector<double> a_vec, std::vector<double> b_vec, std::vector<double> c_vec,
                         std::vector<double> d_vec);