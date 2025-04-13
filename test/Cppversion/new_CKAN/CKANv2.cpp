#include "kan_paras.h"
#include "linear_and_add.h"
#include "b_spline.h"
#include <ap_axi_sdata.h>

#define input_size 2048;
#define output_size 1024;
#define HW_DATA_WIDTH 32;

void KAN(ap_axis<HW_DATA_WIDTH,1,1,1>src[input_size],ap_axis<HW_DATA_WIDTH,1,1,1>ans[output_size]){

	for(int i=0; i<input_size; i++){
		src[i].data = x[i];
	}

	b_splines(x);
    silu(x);
    linear_1(x,layers_0_base_weight_arr,bases_arr,layers_0_spline_weight_arr);
    silu(linear_output_arr);
    b_splines(linear_output_arr);
    linear_2(linear_output_arr,layers_1_base_weight_arr,bases_arr,layers_1_spline_weight_arr);
    silu(linear_output_arr);
    b_splines(linear_output_arr);
    linear_3(linear_output_arr,layers_2_base_weight_arr,bases_arr,layers_2_spline_weight_arr);

    Output:
	for(int i=0; i<CLASSES-1; i++){
		dst[i].data = ((float)output[i])*DATA_CONVERT_MUL;//((int*)output)[i];
		//cout<<output[i]<<' '<<((float)output[i])<<' '<<((float)output[i])*DATA_CONVERT_MUL<<endl;
		dst[i].keep = data[i].keep;
		dst[i].strb = data[i].strb;
		dst[i].user = data[i].user;
		dst[i].last = data[i].last;
		dst[i].id = data[i].id;
		dst[i].dest = data[i].dest;
	}

	dst[CLASSES-1].data = ((float)output[CLASSES-1])*DATA_CONVERT_MUL;//((int*)output)[i];
	//cout<<output[i]<<' '<<((float)output[i])<<' '<<((float)output[i])*DATA_CONVERT_MUL<<endl;
	dst[CLASSES-1].keep = data[CLASSES-1].keep;
	dst[CLASSES-1].strb = data[CLASSES-1].strb;
	dst[CLASSES-1].user = data[CLASSES-1].user;
	dst[CLASSES-1].last = 1;
	dst[CLASSES-1].id = data[CLASSES-1].id;
	dst[CLASSES-1].dest = data[CLASSES-1].dest;
}
