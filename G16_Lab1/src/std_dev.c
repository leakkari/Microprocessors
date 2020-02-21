#include <stdio.h>
#include <std_dev.h>
#include <math.h>
void arm_std_f32(float *pSrc,int blocksize,float * Results);
void std_dev(float *f_array, int N){
	
	float variance;
	float sum;
	float mean;
	float std_dev;
	
	float a_std_dev;
	
	float DSP_std_dev;
	
	/* LOOP TO FIND SUM*/
	int i;
	sum = 0;
	for(i=0 ; i<N ; i++) {
		sum += f_array[i];
	}
	
	mean = 0;
	mean = sum/N;

	variance = 0;
	for(i=0 ; i<N; i++){
		variance+= (f_array[i]-mean)*(f_array[i]-mean)/(N-1);
	}
	
	std_dev = sqrt(variance);
	

	
	/* Assembly */
	asm_std_dev(f_array, N, &a_std_dev);
	
	/* CMSIS-DSP */
	arm_std_f32(f_array, N, &DSP_std_dev);
	
	
		
	printf("C  = %f\n", std_dev);
	printf("Assembly = %f\n", a_std_dev);
	printf("DSP = %f\n", DSP_std_dev);	
}


