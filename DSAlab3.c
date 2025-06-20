#include <stdio.h>

// 1
int sumOfNaturalNumbers(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumOfNaturalNumbers(n - 1);
}

// 2
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 3
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciSeries(int n) {
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// 4
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// 5
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else if (a == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    printf("--- LAB 3: Recursion Demonstrations ---\n\n");

    printf("1. Sum of Natural Numbers:\n");
    int numSum1 = 5;
    printf("Sum of natural numbers up to %d: %d\n", numSum1, sumOfNaturalNumbers(numSum1));



    printf("2. Factorial:\n");
    int numFact1 = 5;
    printf("Factorial of %d: %lld\n", numFact1, factorial(numFact1));


    printf("3. Fibonacci Series:\n");
    int numFibTerms1 = 10;
    printFibonacciSeries(numFibTerms1);


    printf("4. Tower of Hanoi:\n");
    int numDisks1 = 3;
    printf("Steps for Tower of Hanoi with %d disks:\n", numDisks1);
    towerOfHanoi(numDisks1, 'A', 'B', 'C');
    printf("\n");



    printf("5. GCD of two numbers:\n");
    int numGCD1_a = 48, numGCD1_b = 18;
    printf("GCD of %d and %d: %d\n", numGCD1_a, numGCD1_b, gcd(numGCD1_a, numGCD1_b));


    return 0;
}