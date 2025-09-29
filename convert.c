#include <ctype.h>
#include<stdint.h>
#include<string.h>

// oct to bin
void oct_to_bin(const char *oct, char *out) {
    while (*oct) {
        //Check for valid octal
        if (*oct < '0' || *oct > '7') {
            *out = '\0';
            return;
        }

        //Convert oct char to integer
        int value = *oct - '0';

        //Convert to binary and add to output
        *out++ = value & 4 ? '1' : '0';
        *out++ = value & 2 ? '1' : '0';
        *out++ = value & 1 ? '1' : '0';

        //Move to next digit
        oct++;
    }
    //Null terminate
    *out = '\0';
}

// oct to hex
void oct_to_hex(const char *oct, char *out) {
    char binary[256] = {0};
    int current_num = 0;

    //Check octal and convert to binary
    while (*oct) {
        //Check for valid octal
        if (*oct < '0' || *oct > '7') {
            *out = '\0';
            return;
        }
        //Convert oct char to integer
        int value = *oct - '0';

        //Convert to binary
        binary[current_num++] = value & 4 ? '1' : '0';
        binary[current_num++] = value & 2 ? '1' : '0';
        binary[current_num++] = value & 1 ? '1' : '0';

        //Move to next digit
        oct++;
    }
    //Null terminate
    binary[current_num] = '\0';

    //Group binary by 4
    int binary_length = strlen(binary);
    int zeroes_needed = (4 - (binary_length % 4)) % 4;

    char padded_binary[100] = {0};
    for (int i = 0; i < zeroes_needed; i++) {
        padded_binary[i] = '0';
    }
    strcpy(padded_binary + zeroes_needed, binary);

    //Convert to hex
    int current_hex = 0;
    for (int i = 0; i < strlen(padded_binary); i+= 4) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            val <<= 1;
            if (padded_binary[i + j] == '1') {
                val |= 1;
            }
        }
        //Convert val to hex
        if (val < 10) {
            out[current_hex++] = '0' + val;
        }
        else {
            out[current_hex++] = 'A' + (val - 10);
        }
    }
    //Null terminate current_hex
    out[current_hex] = '\0';

    //Remove zeroes from output
    int first_nonzero = 0;
    while (out[first_nonzero] == '0' && out[first_nonzero+1] != '\0') {
        first_nonzero++;
    }
    if (first_nonzero > 0) {
        int i = 0;
        while (out[first_nonzero + i] != '\0') {
            out[i] = out[first_nonzero + i];
            i++;
        }
        out[i] = '\0';
    }
}

// hex to bin
void hex_to_bin(const char *hex, char *out) {
    int i = 0;
    while (*hex) {
        //Check for both upper and lowercase
        char hex_digit = tolower(*hex);

        //Convert to binary
        const char *bits;
        switch (hex_digit) {
            case '0': bits = "0000"; break;
            case '1': bits = "0001"; break;
            case '2': bits = "0010"; break;
            case '3': bits = "0011"; break;
            case '4': bits = "0100"; break;
            case '5': bits = "0101"; break;
            case '6': bits = "0110"; break;
            case '7': bits = "0111"; break;
            case '8': bits = "1000"; break;
            case '9': bits = "1001"; break;
            case 'a': bits = "1010"; break;
            case 'b': bits = "1011"; break;
            case 'c': bits = "1100"; break;
            case 'd': bits = "1101"; break;
            case 'e': bits = "1110"; break;
            case 'f': bits = "1111"; break;
            default:
                out[0] = '\0';
                return;
        }

        //Add to output
        for (int j = 0; j < 4; j++) {
            out[i++] = bits[j];
        }
        hex++;
    }
    //Null terminate
    out[i] = '\0';
}

// to sign magnitude
void to_sign_magnitude(int32_t n, char *out) {
    uint32_t result;

    // For positive : output as - is with leading zeros
    // For negative : set bit 31 to 1 , keep magnitude in bits 0 -30
    if ( n >= 0) {
        //Output as is
        result = (uint32_t)n;
    }
    else {
        //Set bit 31 to 1
        result = (1U << 31) | (-n);
    }

    //Convert to binary
    for (int i = 31; i >= 0; i--) {
        out[31 - i] = (result & (1U << i)) ? '1' : '0';
    }

    //Null terminate
    out[32] = '\0';
}

// to ones complement
void to_ones_complement (int32_t n, char *out) {
        uint32_t result;

    // For positive : output as - is with leading zeros
    // // For negative : flip ALL bits
    if ( n >= 0) {
        //Output as is
        result = (uint32_t)n;
    }
    else {
        //Flip all bits
        result = ~((uint32_t)(-n));
    }

    //Covert to binary
    for (int i = 31; i >= 0; i--) {
        out[31-i] = result & 1U << i ? '1' : '0';
    }

    //Null terminate
    out[32] = '\0';
}

// to twos complement
void to_twos_complement (int32_t n, char *out) {
    uint32_t result;
    // For positive : output as - is
    // For negative : flip all bits and add 1

    if ( n >= 0) {
        //Output as is
        result = (uint32_t)n;
    }
    else {
        //Flip all bits and add 1
        result = ~((uint32_t)(-n)) + 1;
    }

    //Convert to binary
    for (int i = 31; i >= 0; i--) {
        out[31-i] = result & 1U << i ? '1' : '0';
    }

    //Null terminate
    out[32] = '\0';
}