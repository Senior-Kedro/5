#include <stdio.h>
#include <math.h>


// Function to check if a number has three or more consecutive fives
int check(int n) {
    int check_count = 0;
    int consecutiveFives = 0;
    // Loop through the digits of the number from right to left
    while (n > 0) {
        int number = n % 10;
        n /= 10;

        // If the current digit is 1, increment the consecutiveFives count
        if (number == 1) {
            consecutiveFives++;
            // If there are three or more consecutive fives, increment the check_count and break the loop
            if (consecutiveFives >= 3) {
                check_count++;
                break;
            }
        }
        // Reset the consecutiveFives count if the current digit is not 1
        else {
            consecutiveFives = 0;
        }
    }
    return check_count;
}

// Function to count the number of valid numbers with r digits
int countNumbers(int r) {
    // Base cases
    if (r == 1)
        return 2;  // Only two possibilities: 1 and 0
    if (r == 2)
        return 4;  // Four possibilities: 11, 10, 01, 00

    int current = 0;  // Number of possibilities for r digits
    int total_count = pow(2, r);
    // Calculate the number of possibilities for r digits
    for (int i = 0; i < total_count; i++) {
        int combinedNumber = 0;
        for (int j = r - 1; j >= 0; j--) {
            int bit = (i >> j) & 1;
            int digit = bit ? 1 : 0;
            combinedNumber += digit * pow(10, j);
        }
        // Call the function to сheck if the combined number contains three or more consecutive fives and update the count
        current += check(combinedNumber);
    }

    // Calculate the final count by subtracting the number of invalid numbers from the total count
    return total_count - current;
}

int main() {
    int r;  // Number of digits
    printf("Enter the number of digits (r): ");
    scanf("%d", &r);

    if (r>=1){
        // Call the function to count the number of valid numbers with r digits
        int count = countNumbers(r);

        // Print the result
        printf("The number of valid numbers with %d digits is: %u\n", r, count);
    } else{
        printf("You entered a wrong number of digits, it can't be less than 1");
    }
    
    return 0;
}
