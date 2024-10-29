#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char menu() {
	char option;
	printf("Select one of the following items:\n");
        printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
        printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
        printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
        printf("V) – Define variables and assign them values.\n");
        printf("E) - Exit\n");
        scanf(" %c", &option);

        while (1) {
            switch (option) {
                case 'B':
                case 'U':
                case 'A':
                case 'V':
                case 'E':
                    return option;
                default:
                    printf("Invalid option. Please try again: ");
                    scanf(" %c", &option);
                    continue;
            }
            break;
        }
}

void Ecase() {
	printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
	exit(0);
}

double Bcase(double num1, char operation, double num2) {
    switch (operation) {
        case '+' :
            return num1 + num2;
        case '-' :
            return num1 - num2;
        case '*' :
            return num1 * num2;
        case '/' :
            if (num2 != 0)
                return num1 / num2;
            else {
                printf("Error division\n");
                return NAN;
            }
        case '%' :
            return fmod(num1, num2);
        case 'P' :
            return pow(num1, num2);
        case 'X' :
            return fmax(num1, num2);
        case 'I' :
            return fmin(num1, num2);
        default : printf("Invalid operation\n");
            return NAN;
    }
}

double Ucase(double num, char operation) {
    switch (operation) {
        case 'S' :
            if (num >= 0)
                return sqrt(num);
            else {
                printf("Error square root\n");
                return NAN;
            }
        case 'L' :
            if (num > 0)
                return log(num);
            else {
                printf("Error logarithm base e\n");
                return NAN;
            }
        case 'E' :
            return exp(num);
        case 'C' :
            return ceil(num);
        case 'F' :
            return floor(num);
        default : printf("Invalid operation\n");
            return NAN;
    }
}
double read_num() {
    double num;
    while (1) {
        if (scanf("%lf", &num) == 1) {
            return num;
        } else {
            printf("Invalid number. Please enter a number: ");
            while (getchar() != '\n');
        }
    }
}
int main() {
    double num1, num2, num;
    char operation;
    char option;
    char memoryslot;
    double memoryvalue[5] = {0.0};

    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer : Duc Nguyen\n");
    printf("Version : Assignment 3\n");
    printf("Date : March 31st, 2024\n");

    while (1) {
        option = menu();

        switch (option) {
            case 'B':
                printf("Enter the first number: ");
	            num1 = read_num();
	            printf("Enter the operation (+, -, *, /, %, P, X, I): ");
	            scanf(" %c", &operation);
	            printf("Enter the second number: ");
    	        num2 = read_num();
	            printf("The result is %lf\n", Bcase(num1, operation, num2));
                break;
            case 'U':
                printf("Enter a number: ");
	            num = read_num();
	            printf("Enter the operation (S, L, E, C, F): ");
	            scanf(" %c", &operation);
	            printf("The result is %lf\n", Ucase(num, operation));
                break;
            case 'A':
                printf("Select one of the following items:\n");
                printf("B) - Binary Mathematical Operations\n");
                printf("U) - Unary Mathematical Operations\n");
                printf("E) - Exit to main menu\n");
                scanf(" %c", &option);
                while (option != 'E') {
                    switch(option) {
                        case 'B' :
                            printf("Enter the first number or memory slot (a, b, c, d, e): ");
                            while(1) {
                        	    if(scanf("%lf", &num1) == 1) {
                        		    break;
							    } else {
								    scanf(" %c", &memoryslot);
								    if (memoryslot >= 'a' && memoryslot <= 'e') {
									    num1 = memoryvalue[memoryslot - 'a'];
									    break;
								    } else {
									    printf("Invalid input. Enter the first number or memory slot (a, b, c, d, e): ");
								}
							}
						}
                            printf("Enter the operation (+, -, *, /, %, P, X, I): ");
                            scanf(" %c", &operation);
                            printf("Enter the second number or memory slot (a, b, c, d, e): ");
                            while(1) {
                        	    if(scanf("%lf", &num2) == 1) {
                        		    break;
							    } else {
								    scanf(" %c", &memoryslot);
								    if (memoryslot >= 'a' && memoryslot <= 'e') {
									    num2 = memoryvalue[memoryslot - 'a'];
									    break;
								    } else {
									    printf("Invalid input. Enter the first number or memory slot (a, b, c, d, e): ");
								}
							}
						}
                            printf("The result is %lf\n", Bcase(num1, operation, num2));
                        break;
                        case 'U' :
                            printf("Enter the number or a memory slot (a, b, c, d, e): ");
                            while(1) {
                        	    if(scanf("%lf", &num) == 1) {
                        		    break;
							    } else {
								    scanf(" %c", &memoryslot);
								    if (memoryslot >= 'a' && memoryslot <= 'e') {
									    num = memoryvalue[memoryslot - 'a'];
									    break;
								    } else {
									    printf("Invalid input. Enter the first number or memory slot (a, b, c, d, e): ");
								}
							}
						}
                            printf("Enter the operation (S, L, E, C, F): ");
                            scanf(" %c", &operation);
                            printf("The result is %lf\n", Ucase(num, operation));
                            break;
                        default : printf("Invalid option\n");
                            break;
                    }
                    printf("Select one of the following items:\n");
                    printf("B) - Binary Mathematical Operations\n");
                    printf("U) - Unary Mathematical Operations\n");
                    printf("E) - Exit to main menu\n");
                    scanf(" %c", &option);
                }
                    break;
            case 'V':
                printf("Enter a memory slot (a, b, c, d, e): ");
	            scanf(" %c", &memoryslot);
	            printf("Enter a number to assign: ");
	            scanf("%lf", &memoryvalue[memoryslot - 'a']);
	            printf("The number %lf has been assigned to variable %c\n", memoryvalue[memoryslot - 'a'], memoryslot);
                break;
            case 'E':
            	Ecase();
            	break;
        }
    }
    return 0;
}