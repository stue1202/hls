#include <cmath>
#include "kan_paras.h"
#include "linear_and_add.h"
#include "b_spline.h"



void KAN(fixed_t x[1024*2],fixed_t result[1024*1]){
	#pragma HLS INTERFACE s_axilite port=x bundle=input
	#pragma HLS INTERFACE s_axilite port=result bundle=output
	b_splines(x);
    silu(x);
    linear_1(x,layers_0_base_weight_arr,bases_arr,layers_0_spline_weight_arr);
    silu(linear_output_arr);
    b_splines(linear_output_arr);
    linear_2(linear_output_arr,layers_1_base_weight_arr,bases_arr,layers_1_spline_weight_arr);
    silu(linear_output_arr);
    b_splines(linear_output_arr);
    linear_3(linear_output_arr,layers_2_base_weight_arr,bases_arr,layers_2_spline_weight_arr);
}
