#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int Fib(int n){
    if(n<=1) return n;
    return Fib(n-1) + Fib(n-2);
}

int main() {
    int n = 3; 
    printf("Tower of Hanoi solution for %d disks:\n", n);
    // towerOfHanoi(n, 'A', 'B', 'C');
    printf("Fibonacci of %d is %d\n ", n, Fib(n));
    return 0;
}