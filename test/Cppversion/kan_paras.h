#ifndef kan_paras
typedef float fixed_t;
const int grid_size=5;
const int spline_order=3;
const float scale_base=1.0;
const float scale_spline=1.0;
const int enable_standalone_scale_spline=1;
const float grid_eps=0.02;
const int grid_range[2]={-1, 1};
const int hiden_layers=3;
struct fpgaARR
{
    float *arr;
    int dim1;
    int dim2;
    int dim3;
    void view() {
        this->dim1*=this->dim2;
        this->dim2=this->dim3;
        this->dim3=1;
    }
    int len() {
        return this->dim1*this->dim2*this->dim3;
    }
    float get(int i, int j, int k) const {
        return this->arr[i * this->dim2 * this->dim1  + j * this->dim1 + k];
    }
    void set(int i, int j, int k,float value) const {
        this->arr[i * this->dim2 * this->dim1  + j * this->dim1 + k]=value;
    }
    fpgaARR(float *arr, int dim3, int dim2, int dim1) : arr(arr), dim1(dim1), dim2(dim2), dim3(dim3) {}
};
fpgaARR layers_0_base_weight = {
    new float[3 * 2] {-0.6335, -0.2360, -0.6080, -0.3417, 0.6330, 0.5733},
    1,3,2
};
fpgaARR layers_0_spline_weight = {
    new float[3 * 2 * 8] {
        -3.0776e-10, 3.3747e-09, 1.3112e-08, 5.9135e-09, 1.0272e-08, 1.0224e-08, -6.0491e-09, -1.3825e-09,
        1.9554e-09, 2.3645e-08, 3.8890e-08, 1.8446e-08, 2.7702e-09, -6.4991e-09, -9.9835e-09, -1.7277e-09,
        -5.5773e-10, -5.8572e-10, 3.9641e-09, -6.4413e-09, -1.3370e-08, -2.4077e-08, -2.5515e-08, -3.0608e-09,
        5.3521e-11, 1.4518e-10, 2.6038e-10, -1.7279e-11, -3.5076e-10, -7.0528e-10, -5.1637e-10, -9.4657e-11,
        1.1376e-09, 3.2219e-09, -5.5578e-09, -2.2601e-09, -1.2646e-08, -1.3209e-08, 7.8388e-09, 1.7613e-09,
        -1.7365e-10, -3.1993e-09, -8.6954e-09, -5.6934e-09, -2.6869e-09, -1.2755e-11, 3.5855e-09, 8.1429e-10
    },
    3, 2, 8
};
fpgaARR layers_0_spline_scaler = {
    new float[3 * 2] {0.3008, 0.5762, -0.7051, -0.0114, 0.2279, 0.1865},
    1,3,2
};
fpgaARR layers_1_base_weight = {
    new float[3 * 3] {0.3569, -0.1007, 0.2012, 0.2349, 0.0860, -0.2791, 0.4790, -0.3286, -0.4684},
    1,3, 3
};
fpgaARR layers_1_spline_weight = {
    new float[3 * 3 * 8] {
        -1.1268e-09, -3.7672e-09, 2.6320e-08, 5.2638e-08, -1.0122e-08, -2.2428e-08, -1.9127e-08, -2.3668e-09,
        9.5259e-10, -2.9518e-09, -2.5468e-08, -1.9076e-08, 8.4533e-09, 1.5728e-08, 9.0292e-09, 1.4746e-09,
        -2.7368e-10, -2.2573e-09, -5.8904e-09, -3.3389e-10, 7.6338e-09, 4.9206e-09, -2.4099e-10, 6.9739e-12,
        3.5006e-09, 2.3240e-08, -1.5685e-09, -5.0441e-08, -6.6387e-09, 1.9633e-09, 1.2000e-08, 1.7471e-09,
        1.1218e-09, 4.1386e-09, -3.5517e-09, -8.1166e-09, -2.0767e-09, 1.7170e-09, 2.1775e-09, 5.4089e-10,
        1.2399e-09, 6.3154e-09, 1.4040e-08, -2.0015e-08, -3.7039e-08, 9.9632e-10, 1.9312e-08, 2.1235e-09,
        -3.7845e-09, -2.6594e-08, -1.8488e-09, 5.7621e-08, 1.2521e-08, -8.3752e-10, -1.5378e-08, -2.3517e-09,
        6.5864e-09, 2.7618e-08, -1.4092e-08, -5.3193e-08, -2.3915e-08, 1.0108e-08, 1.6772e-08, 3.5362e-09,
        3.0227e-09, 1.6324e-08, 2.8696e-08, -5.9399e-08, -8.0241e-08, 1.5367e-08, 4.3634e-08, 4.1582e-09
    },
    3, 3, 8
};
fpgaARR layers_1_spline_scaler = {
    new float[3 * 3] {-0.5390, 0.3132, -0.0860, -0.3755, -0.0923, -0.2988, 0.3649, -0.5077, -0.5468},
    1, 3, 3
};
fpgaARR layers_2_base_weight = {
    new float[1 * 3] {0.1959, -0.3349, -0.4020},
    1, 1, 3
};
fpgaARR layers_2_spline_weight = {
    new float[1 * 3 * 8] {
        8.1571e-09, -8.6782e-08, -3.5593e-07, -6.4872e-07, 4.2007e-07, 4.6637e-07, 1.3623e-07, 1.0801e-08,
        6.1854e-09, 3.1181e-08, -4.3499e-09, -5.3605e-08, -1.2841e-08, 6.3710e-09, 9.3972e-09, 2.1327e-09,
        -3.7641e-10, -8.5146e-08, -6.2426e-08, 2.2075e-07, 6.2331e-08, -5.3474e-08, -2.4725e-08, -2.9146e-09
    },
    1, 3, 8
};
fpgaARR layers_2_spline_scaler = {
    new float[1 * 3] {0.4120, 0.1307, -0.4507},
    1,1, 3
};
fpgaARR layers_base_weight[hiden_layers]={
    layers_0_base_weight,
    layers_1_base_weight,
    layers_2_base_weight
};
fpgaARR layers_spline_weight[hiden_layers]={
    layers_0_spline_weight,
    layers_1_spline_weight,
    layers_2_spline_weight
};
fpgaARR layers_spline_scaler[hiden_layers]={
    layers_0_spline_scaler,
    layers_1_spline_scaler,
    layers_2_spline_scaler
};
#endif
