#include <stdio.h>

	int main() {
	    int num[10], j;

	    for (int i = 0; i < 10; i++) {
	        scanf("%d", &num[i]);

	        for (int c = 0; c < 9; c++) {
	            if (num[c] > num[i]) {
	                j = num[c];
	                num[c] = num[i];
	                num[i] = j;
	            }
	        }
	    }

	    for (int p = 0; p < 9; p++) {
	        printf("%d ", num[p]);
	    }
	    return 0;
	}
