#ifndef linear_and_add_h
#include "kan_paras.h"
void linear_1(const fixed_t x[1024*2],const fixed_t layers_0_base_weight_arr[1*3*2],const fixed_t bases_arr[1024*3*10],const fixed_t layers_0_spline_weight_arr[3*2*8]){
    //fixed_t tmp[weight.dim2*x.dim2]={0};
    for (fixed_i i = 0; i < get_dim(2,x_dim); ++i) {
        for (fixed_i j = 0; j < get_dim(2,layers_0_base_weight_dim); ++j) {
            for (fixed_i k = 0; k < get_dim(1,x_dim); ++k) {
                linear_output_arr[get_index(1,i,j,linear_output_dim)]+=x[get_index(1,i,k,x_dim)]*layers_0_base_weight_arr[get_index(1,j,k,layers_0_base_weight_dim)];
            }
        }
    }
    for (fixed_i i = 0; i < get_dim(2,bases_dim); ++i) {
        for (fixed_i j = 0; j < get_dim(2,layers_0_spline_weight_dim); ++j) {
            for (fixed_i k = 0; k < get_dim(1,bases_dim); ++k) {
                linear_output_arr[get_index(1,i,j,linear_output_dim)]+=bases_arr[get_index(1,i,k,bases_dim)]*layers_0_spline_weight_arr[get_index(1,j,k,layers_0_spline_weight_dim)];
            }
        }
    }
}
void linear_2(const fixed_t x[1024*2],const fixed_t layers_1_base_weight_arr[1*3*3],const fixed_t bases_arr[1024*3*10],const fixed_t layers_1_spline_weight_arr[3*3*8]){
    //fixed_t tmp[weight.dim2*x.dim2]={0};
    for (fixed_i i = 0; i < get_dim(2,x_dim); ++i) {
        for (fixed_i j = 0; j < get_dim(2,layers_1_base_weight_dim); ++j) {
            for (fixed_i k = 0; k < get_dim(1,x_dim); ++k) {
                linear_output_arr[get_index(1,i,j,linear_output_dim)]+=x[get_index(1,i,k,x_dim)]*layers_1_base_weight_arr[get_index(1,j,k,layers_1_base_weight_dim)];
            }
        }
    }
    for (fixed_i i = 0; i < get_dim(2,bases_dim); ++i) {
        for (fixed_i j = 0; j < get_dim(2,layers_1_spline_weight_dim); ++j) {
            for (fixed_i k = 0; k < get_dim(1,bases_dim); ++k) {
                linear_output_arr[get_index(1,i,j,linear_output_dim)]+=bases_arr[get_index(1,i,k,bases_dim)]*layers_1_spline_weight_arr[get_index(1,j,k,layers_1_spline_weight_dim)];
            }
        }
    }
}
void linear_3(const fixed_t x[1024*2],const fixed_t layers_2_base_weight_arr[1*1*3],const fixed_t bases_arr[1024*3*10],const fixed_t layers_2_spline_weight_arr[1*3*8]){
    //fixed_t tmp[weight.dim2*x.dim2]={0};
    for (fixed_i i = 0; i < get_dim(2,x_dim); ++i) {
        for (fixed_i j = 0; j < get_dim(2,layers_2_base_weight_dim); ++j) {
            for (fixed_i k = 0; k < get_dim(1,x_dim); ++k) {
                linear_output_arr[get_index(1,i,j,linear_output_dim)]+=x[get_index(1,i,k,x_dim)]*layers_2_base_weight_arr[get_index(1,j,k,layers_2_base_weight_dim)];
            }
        }
    }
    for (fixed_i i = 0; i < get_dim(2,bases_dim); ++i) {
        for (fixed_i j = 0; j < get_dim(2,layers_2_spline_weight_dim); ++j) {
            for (fixed_i k = 0; k < get_dim(1,bases_dim); ++k) {
                linear_output_arr[get_index(1,i,j,linear_output_dim)]+=bases_arr[get_index(1,i,k,bases_dim)]*layers_2_spline_weight_arr[get_index(1,j,k,layers_2_spline_weight_dim)];
            }
        }
    }
}
#endif
