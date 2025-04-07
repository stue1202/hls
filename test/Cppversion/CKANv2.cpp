#include <cmath>
#include "kan_paras.h"
void silu(fpgaARR &x){
    for(int i=0;i<x.dim3;i++){
        for(int j=0;j<x.dim2;j++){
            for(int k=0;k<x.dim1;k++){
                x.set(i,j,k,x.get(i,j,k)/(1.0+exp(-x.get(i,j,k))));
            }
        }
    }
}
fpgaARR linear(const fpgaARR &x,const fpgaARR &weight,const fpgaARR &x1,const fpgaARR &weight1){//??��?��?�维
    //fixed_t tmp[weight.dim2*x.dim2]={0};
    static fixed_t tmp[1024*1024]={0};
    fpgaARR output(tmp,1,x.dim2,weight.dim2);
    for (int i = 0; i < x.dim2; ++i) {
        for (int j = 0; j < weight.dim2; ++j) {
            for (int k = 0; k < x.dim1; ++k) {
                output.arr[i*output.dim1+j]+=x.arr[i*x.dim1+k]*weight.arr[j*weight.dim1+k];
            }
        }
    }
    static fixed_t tmp1[1024*1024]={0};
    fpgaARR output1(tmp1,1,x1.dim2,weight1.dim2);
    for (int i = 0; i < x1.dim2; ++i) {
        for (int j = 0; j < weight1.dim2; ++j) {
            for (int k = 0; k < x1.dim1; ++k) {
                output1.arr[i*output1.dim1+j]+=x1.arr[i*x.dim1+k]*weight1.arr[j*weight1.dim1+k];
            }
        }
    }
    for(int i=0;i<output.dim3;i++){
        for(int j=0;j<output.dim2;j++){
            for(int k=0;k<output.dim1;k++){
                output.arr[i*output.dim1+j]+=output1.arr[i*output.dim1+j];
            }
        }
    }
    return output;
}
fpgaARR b_splines(const fpgaARR &x){
    static fixed_t t[grid_size + 2 * spline_order + 1]={0};
    fpgaARR grid(t,1,1,grid_size + 2 * spline_order + 1);
    fixed_t h = (grid_range[1] - grid_range[0]) / (fixed_t)grid_size;
    for (int i = -spline_order; i <= grid_size + spline_order + 1; ++i) {
        grid.arr[i+spline_order] = i * h + grid_range[0];
    }
    static fixed_t tmp[1024*3*11]={0};
    fpgaARR bases(tmp,x.dim2,x.dim1,grid.len()-1);
    for (int i = 0; i < x.dim3; ++i) {
        for (int j = 0; j < x.dim2; ++j) {
            for (int k = 0; k < x.dim1; ++k) {
                fixed_t target= x.get(i,j,k);
                for(int l=0;l<grid.len()-1;l++){
                    if(target>=grid.arr[l]&&target<grid.arr[l+1]){
                        bases.set(j,k,l,1);
                    }else{
                        bases.set(j,k,l,0);
                    }
                }
            }
        }
    }
    for(int t=1;t<=spline_order;t++){
        for(int i=0;i<bases.dim3;i++){
            for(int j=0;j<bases.dim2;j++){//data
                fixed_t target=x.get(0,i,j);
                for(int k=0;k<bases.dim1;k++){//every knots
                    bases.set(i,j,k,(target-grid.arr[k])/(grid.arr[k+t]-grid.arr[k])*bases.get(i,j,k) + (grid.arr[k+t+1]-target)/(grid.arr[k+t+1]-grid.arr[k+1])*bases.get(i,j,k+1));
                }
            }
        }
        bases.dim1--;
    }
    bases.view();
    return bases;
}
void KanLayer(fpgaARR &x,int layer_now){
    silu(x);
    layers_spline_weight[layer_now].view();
    fpgaARR B=b_splines(x);
    x=linear(x, layers_base_weight[layer_now],B,layers_spline_weight[layer_now]);
}
void KAN(fixed_t a,fixed_t b,int hiden_layers_number,fixed_t result){
	#pragma HLS INTERFACE s_axilite port=a bundle=input
	#pragma HLS INTERFACE s_axilite port=b bundle=input
	#pragma HLS INTERFACE s_axilite port=hiden_layers_number bundle=CTRL
	#pragma HLS INTERFACE s_axilite port=result bundle=output
	fixed_t arr[2]={a,b};
	fpgaARR x=fpgaARR(arr, 1, 1, 2);
    for(int i=0;i<hiden_layers_number;i++){
        KanLayer(x,i);
    }
}
