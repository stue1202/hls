#ifndef linear_and_add_h
#include "kan_paras.h"
void b_splines(const fixed_t x[1024*2]){
    fixed_t h = (grid_range[1] - grid_range[0]) / (fixed_t)grid_size;
    for (int i = -spline_order; i <= grid_size + spline_order + 1; ++i) {
        grid_arr[i+spline_order] = i * h + grid_range[0];
    }
    for (int i = 0; i < get_dim(3,x_dim); ++i) {
        for (int j = 0; j < get_dim(2,x_dim); ++j) {
            for (int k = 0; k < get_dim(1,x_dim); ++k) {
                fixed_t target= x[get_index(i,j,k,x_dim)];
                for(int l=0;l<len(grid_dim)-1;l++){
                    if(target>=grid_arr[l]&&target<grid_arr[l+1]){
                        bases_arr[get_index(j,k,l,bases_dim)]=1;
                    }else{
                        bases_arr[get_index(j,k,l,bases_dim)]=0;
                    }
                }
            }
        }
    }
    for(int t=1;t<=spline_order;t++){
        for(int i=0;i<get_dim(3,bases_dim);i++){
            for(int j=0;j<get_dim(2,bases_dim);j++){//data
                fixed_t target=x[get_index(0,i,j,x_dim)];
                for(int k=0;k<get_dim(1,bases_dim);k++){//every knots
                    bases_arr[get_index(i,j,k,bases_dim)]=(target-grid_arr[k])/(grid_arr[k+t]-grid_arr[k])*bases_arr[get_index(i,j,k,bases_dim)] + (grid_arr[k+t+1]-target)/(grid_arr[k+t+1]-grid_arr[k+1])*bases_arr[get_index(i,j,k+1,bases_dim)];
                }
            }
        }
        bases_dim[2]--;//bases.dim1--;
    }
    view(bases_dim);
}
#endif
