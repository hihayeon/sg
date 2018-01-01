#include <stdio.h>
#include <syscall.h>

int pibonacci(int n);
int sum_of_four_integers(int a, int b, int c, int d);

int pibonacci (int n){
	int res = 1, i;
	int tmp1 = 0, tmp2 = 0;

	if(n>=3){
		tmp1 = tmp2 = 1;
		for(i = 0 ; i < n-2 ; i++){
			res = tmp1 + tmp2;
			tmp2 = tmp1;
			tmp1 = res;
		}
	}

	return res;
}

int sum_of_four_integers(int a, int b, int c, int d){
	return a+b+c+d;
}

int main(int argc, char **argv)
{
	int sum_of_four_res, pibo_res;
	int n[4];
	int i;

	for(i = 1 ; i < argc ; i++){
		n[i-1] = *argv[i]-48;
	}

	sum_of_four_res = sum_of_four_integers(n[0], n[1], n[2], n[3]);
	pibo_res = pibonacci(n[0]);

	printf("%d %d\n", pibo_res, sum_of_four_res);
	return EXIT_SUCCESS;
}

