#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_input(const char *input_string, char *delimiter) {
    if (strncmp(input_string, "//", 2) == 0) {
        *delimiter = input_string[2];
        return atoi(input_string + 4);
    }
    *delimiter = ',';
    return atoi(input_string);
}

int split_and_convert(const char *input_string, char delimiter, int *numbers, int *count) {
    char *token;
    char *delim = malloc(2);
    delim[0] = delimiter;
    delim[1] = '\0';
    *count = 0;
    token = strtok((char *)input_string, delim);
    while (token != NULL) {
        numbers[*count] = atoi(token);
        (*count)++;
        token = strtok(NULL, delim);
    }
    free(delim);
    return *count;
}

int filter_numbers(int *numbers, int count) {
    int i, j = 0;
    for (i = 0; i < count; i++) {
        if (numbers[i] <= 1000) {
            numbers[j++] = numbers[i];
        }
    }
    return j;
}

int add(const char *input_string) {
    if (strlen(input_string) == 0) {
        return 0;
    }
    char delimiter;
    int parsed_input = parse_input(input_string, &delimiter);
    int numbers[1000];
    int count;
    int filtered_count = split_and_convert(input_string + parsed_input, delimiter, numbers, &count);
    int sum = 0;
    for (int i = 0; i < filtered_count; i++) {
        sum += numbers[i];
    }
    return sum;
}
