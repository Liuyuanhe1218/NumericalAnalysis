#include "depend.h"

double temp_switch_to_K(double temp_in, temperature_type_t type) {
    if (type == temperature_type_K) {
        return temp_in;
    } else if (type == temperature_type_F) {
        return (temp_in + 459.67) * (5 / 9);
    } else if (type == temperature_type_R) {
        return temp_in * (5 / 9);
    } else if (type == temperature_type_C) {
        return temp_in + 273.15;
    }

    LOG(ERROR) << "Error type of temperature " << type;
    return 0;
}

double density_switch_to_api(double density_in, density_t type) {

    if (type == Density_API) {
        return density_in;
    } else if (type == Density_SG) {

        if (density_in != 0) {
            return 141.5 / density_in - 131.5;
        } else {
            LOG(ERROR) << "Error input density " << density_in;
            return 0;
        }
    }
    LOG(ERROR) << "Error type of density type " << type;
    return 0;
}

std::vector<double> TDMA(std::vector<double> a_vec, std::vector<double> b_vec, std::vector<double> c_vec,
                         std::vector<double> d_vec) {
    if (a_vec.empty() || b_vec.empty() || c_vec.empty()) {
        LOG(ERROR) << "Empty imput vector";
        return std::vector<double>();
    }

    if (a_vec.size() != b_vec.size() || b_vec.size() != c_vec.size() || c_vec.size() != a_vec.size()) {
        LOG(ERROR) << "Different imput vector size ";
        return std::vector<double>();
    }
    size_t num_size = a_vec.size();

    std::vector<double> result;
    result.resize(num_size);

    c_vec[0] = c_vec[0] / b_vec[0];
    d_vec[0] = d_vec[0] / b_vec[0];

    for (int i = 1; i < num_size - 1; ++i) {
        c_vec[i] = c_vec[i] / (b_vec[i] - c_vec[i - 1] * a_vec[i]);
    }
    for (int i = 1; i < num_size; ++i) {
        d_vec[i] = (d_vec[i] - d_vec[i - 1] * a_vec[i]) / (b_vec[i] - c_vec[i - 1] * a_vec[i]);
    }

    result[num_size - 1] = d_vec[num_size - 1];

    for (int i = num_size - 2; i >= 0; i--) {
        result[i] = d_vec[i] - c_vec[i] * result[i + 1];
    }

    return result;
}