#include "add_axi.h"

void add_axi(AXI_VAL a, AXI_VAL b, AXI_VAL* result) {
    #pragma HLS INTERFACE s_axilite port=a bundle=CTRL
    #pragma HLS INTERFACE s_axilite port=b bundle=CTRL
    #pragma HLS INTERFACE s_axilite port=result bundle=CTRL
    #pragma HLS INTERFACE s_axilite port=return bundle=CTRL

    *result = a + b;
}
