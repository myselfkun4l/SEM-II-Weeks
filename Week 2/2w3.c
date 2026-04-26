#include <stdio.h>


struct Complex {
    float real;
    float imag;
};


struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main() {
    struct Complex num1, num2, sum;

    printf("Enter first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imag);
    
    printf("\nEnter second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imag);

    
    sum = addComplex(num1, num2);

    
    printf("\nSum = %.2f + %.2fi\n", sum.real, sum.imag);

    return 0;
}
