#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include<string.h>

// Functions from convert.c
void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(uint32_t n, char *out);
void to_ones_complement (uint32_t n, char *out);
void to_twos_complement (uint32_t n, char *out);

int main() {
    FILE * file = fopen ( "a2_test.txt" , "r" ) ;
        if ( file == NULL ) {
        printf ( "Error : Could not open file \n" ) ;
        return 1;
    }
    //Variables
    char line [256];
    int currentTest = 1;
    int totalTests = 0;
    int testsPassed = 0;

    // Process each line
    while ( fgets ( line, sizeof (line), file ) != NULL ) {
        // Skip line if it's a comment or newline
        if (line[0] == '#' || line[0] == '\n'){
            continue;
        }

        //Test Variables
        char function[33];
        char input[100];
        char expectedOutput[65];
        char output[65];
        int meetsExpected;

        //Process line text
        int arguments = sscanf(line, "%31s %99s %64s", function, &input, expectedOutput);

        //if oct_to_bin
        if (strcmp(function, "oct_to_bin") == 0 && arguments == 3) {
            //Call function
            oct_to_bin(input, output);
            meetsExpected = strcmp(output, expectedOutput) == 0;

            //Check if expected output was met or not
            printf("Test %d: oct_to_bin(%s) -> Expected: \"%s\", Got: \"%s\" ", currentTest++, input, expectedOutput, output);
            //Passed test
            if (meetsExpected) {
                printf("[PASS]\n");
                testsPassed++;
            }
            //Failed test
            else {
                printf("[FAIL]\n");
            }

            //Increase total test count
            totalTests++;
        }

        //if oct_to_hex
        else if (strcmp(function, "oct_to_hex") == 0 && arguments == 3) {
            //Call function
            oct_to_hex(input, output);
            meetsExpected = strcmp(output, expectedOutput) == 0;

            //Check if expected output was met or not
            printf("Test %d: oct_to_hex(%s) -> Expected: \"%s\", Got: \"%s\" ", currentTest++, input, expectedOutput, output);
            //Passed test
            if (meetsExpected) {
                printf("[PASS]\n");
                testsPassed++;
            }
            //Failed test
            else {
                printf("[FAIL]\n");
            }

            //Increase total test count
            totalTests++;
        }

        //if hex_to_bin
        else if (strcmp(function, "hex_to_bin") == 0 && arguments == 3) {
            //Call function
            hex_to_bin(input, output);
            meetsExpected = strcmp(output, expectedOutput) == 0;

            //Check if expected output was met or not
            printf("Test %d: hex_to_bin(%s) -> Expected: \"%s\", Got: \"%s\" ", currentTest++, input, expectedOutput, output);
            //Passed test
            if (meetsExpected) {
                printf("[PASS]\n");
                testsPassed++;
            }
            //Failed test
            else {
                printf("[FAIL]\n");
            }

            //Increase total test count
            totalTests++;
        }

        //if to_sign_magnitude
        else if (strcmp(function, "to_sign_magnitude") == 0 && arguments == 3) {
            //Convert input to integer
            int32_t n = atoi(input);

            //Call function
            to_sign_magnitude(n, output);
            meetsExpected = strcmp(output, expectedOutput) == 0;

            //Check if expected output was met or not
            printf("Test %d: to_sign_magnitude(%s) -> Expected: \"%s\", Got: \"%s\" ", currentTest++, input, expectedOutput, output);
            //Passed test
            if (meetsExpected) {
                printf("[PASS]\n");
                testsPassed++;
            }
            //Failed test
            else {
                printf("[FAIL]\n");
            }

            //Increase total test count
            totalTests++;
        }

        //if to_ones_complement
        else if (strcmp(function, "to_ones_complement") == 0 && arguments == 3) {
            //Convert input to integer
            int32_t n = atoi(input);

            //Call function
            to_ones_complement(n, output);
            meetsExpected = strcmp(output, expectedOutput) == 0;

            //Check if expected output was met or not
            printf("Test %d: to_ones_complement(%s) -> Expected: \"%s\", Got: \"%s\" ", currentTest++, input, expectedOutput, output);
            //Passed test
            if (meetsExpected) {
                printf("[PASS]\n");
                testsPassed++;
            }
            //Failed test
            else {
                printf("[FAIL]\n");
            }

            //Increase total test count
            totalTests++;
        }

        //if to_twos_complement
        else if (strcmp(function, "to_twos_complement") == 0 && arguments == 3) {
            //Convert input to integer
            int32_t n = atoi(input);

            //Call function
            to_twos_complement(n, output);
            meetsExpected = strcmp(output, expectedOutput) == 0;

            //Check if expected output was met or not
            printf("Test %d: to_twos_complement(%s) -> Expected: \"%s\", Got: \"%s\" ", currentTest++, input, expectedOutput, output);
            //Passed test
            if (meetsExpected) {
                printf("[PASS]\n");
                testsPassed++;
            }
            //Failed test
            else {
                printf("[FAIL]\n");
            }

            //Increase total test count
            totalTests++;
        }

    }
    //Close file and show test count
    fclose (file);

    printf("...\n");
    printf("Summary: %d/%d tests passed\n", testsPassed, totalTests);
    return 0;
}