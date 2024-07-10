
int add(const char* input) {
    if (input == NULL || input[0] == '\0') {
        return 0;
    }

    // Check if the input starts with a custom delimiter definition
    const char* delim = ",\n"; // Default delimiters: comma and newline
    if (strncmp(input, "//", 2) == 0) {
        // Custom delimiter format: "//[delimiter]\n[numbers...]"
        delim = strtok((char*)(input + 2), "\n");
        input = strchr(input, '\n') + 1;
    }

    int sum = 0;
    char* token = strtok((char*)input, delim);
    while (token != NULL) {
        int number = atoi(token);
        if (number <= 1000) {
            sum += number;
        }
        token = strtok(NULL, delim);
    }

    return sum;
}
