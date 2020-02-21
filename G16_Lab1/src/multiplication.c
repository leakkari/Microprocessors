#include <stdio.h>
#include <asm_multiplication.h> // header file that links assembly to c code
#include <stdlib.h>
#include <arm_math.h> // math function
	
	float DSP_mult[1000];
	float result[1000];
void multiplication(float *f1_array, float *f2_array, int N){

	//----C multiplication function-----//
	int i;
	
	for(i=0; i<N ; i++) {
		result[i] = f1_array[i]*f2_array[i];
	}
	
	
	
	//----DSP multiplication function-----//
	//void 	arm_mult_f32 (const float32_t *pSrcA, const float32_t *pSrcB, float32_t *pDst, uint32_t blockSize)
	// DSP_mul for result
	arm_mult_f32(f1_array, f2_array, DSP_mult , N );
	
	
	//----Assembly multiplication function-----//
	// result in f1 this time ( overwrite)
	asm_multiplication(f1_array, f2_array, N);
	

	
	/* Print Results */
	
	printf("C: \n");

	for(i = 0; i < N; i++)
		printf("%f ", result[i]);
	
	printf("\n");
	
	printf("Assembly: \n");
	for(i = 0; i < N; i++)
		printf("%f ", f1_array[i]);
		
			printf("\n");
	
	printf("DSP: \n");
	
	for(i = 0; i < N; i++)
		printf("%f ", DSP_mult[i]);
}