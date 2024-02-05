#include <stdio.h>
#include <math.h>

void hanoi(int n, char from, char to, char aux) {
	if (n == 1) {
		printf("Move disk from %c to %c\n", from, to);
	}
	else {
		hanoi(n - 1, from, aux, to);
		printf("Move disk from %c to %c\n", from, to);
		hanoi(n - 1, aux, to, from);
	}
}

int main() {

	int disks, moves;
	printf("Enter the number of disks: \n");
	scanf("%d", &disks);

	moves = pow(2, disks) - 1;
	printf("Required moves is = %d\n", moves);
	hanoi(disks, 'A', 'C', 'B');

	return 0;
}