#include <stdio.h>
#include <string.h>

void save_to_history(float num1, float num2, char operator, float result) {
    FILE *file = fopen("history.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    fclose(file);
}

int main() {
    float num1, num2, result;
 int choice;
char operator;
char answer[10];
  printf("WELCOME TO ONLINE CALCULATOR\n");

    do {
   printf("\nENTER FIRST NUMBER: ");
   scanf("%f", &num1);
   printf("ENTER SECOND NUMBER: ");
   scanf("%f", &num2);
   printf("Choose the operator:\n");
    printf("1. '+'\n");
  printf("2. '-'\n");
  printf("3. '/'\n");
   printf("4. '*'\n");

 printf("Enter the number corresponding to the operator: ");
 scanf("%d", &choice);
        switch (choice) {
            case 1:
                result = num1 + num2;
                operator = '+';
                break;
            case 2:
                result = num1 - num2;
                operator = '-';
                break;
            case 3:
                if (num2 != 0) {
                    result = num1 / num2;
                    operator = '/';
                } else {
                    printf("Error: Division by zero\n");
                    return 1;
                }
                break;
            case 4:
                result = num1 * num2;
                operator = '*';
                break;
            default:
                printf("Invalid choice\n");
                return 1;
        }
        printf("Result: %.2f\n", result);
        save_to_history(num1, num2, operator, result);
        printf("Calculation saved to history.\n");
        printf("\nDo you want more calculations? (yes/no): ");
        scanf("%s", answer);

    } while (strcmp(answer, "yes") == 0 || strcmp(answer, "YES") == 0);

    printf("Thank you for using the calculator!\n");

    return 0;
}
