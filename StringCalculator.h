
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_input(char *input_string, char *delimiter) {
    if (strncmp(input_string, "//", 2) == 0) {
        *delimiter = input_string[2];
        return 4;
    }
    *delimiter = ',';
    return 0;
}

int *split_and_convert(char *input_string, char delimiter, int *count) {
    char *token;
    char *delim = malloc(2 * sizeof(char));
    delim[0] = delimiter;
    delim[1] = '\0';
    int *numbers = malloc(0 * sizeof(int));
    *count = 0;

    token = strtok(input_string, delim);
    while (token != NULL) {
        numbers = realloc(numbers, (*count + 1) * sizeof(int));
        numbers[*count] = atoi(token);
        (*count)++;
        token = strtok(NULL, delim);
    }

    free(delim);
    return numbers;
}

int filter_numbers(int *numbers, int count) {
    int filtered_count = 0;
    int *filtered_numbers = malloc(0 * sizeof(int));

    for (int i = 0; i < count; i++) {
        if (numbers[i] <= 1000) {
            filtered_numbers = realloc(filtered_numbers, (filtered_count + 1) * sizeof(int));
            filtered_numbers[filtered_count] = numbers[i];
            filtered_count++;
        }
    }

    free(numbers);
    return filtered_count;
}

int add(char *input_string) {
    if (input_string[0] == '\0') {
        return 0;
    }

    char delimiter;
    int offset = parse_input(input_string, &delimiter);
    char *parsed_input = input_string + offset;

    int count;
    int *numbers = split_and_convert(parsed_input, delimiter, &count);

    int filtered_count = filter_numbers(numbers, count);
    int sum = 0;
    for (int i = 0; i < filtered_count; i++) {
        sum += numbers[i];
    }

    free(numbers);
    return sum;
}


