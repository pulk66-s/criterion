#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib/asserts/io.h"
#include "lib/tests/tests.h"

int stdout_save;
char std_output_buffer[BUFFER_SIZE] = {0};
char std_error_buffer[BUFFER_SIZE] = {0};

void replace_stdout()
{
    fflush(stdout); //clean everything first
    stdout_save = dup(STDOUT_FILENO); //save the stdout state
    freopen("NUL", "a", stdout); //redirect stdout to null pointer
    setvbuf(stdout, std_output_buffer, _IOFBF, BUFFER_SIZE); //set buffer to stdout
}

void restore_stdout()
{
    freopen("NUL", "a", stdout); //redirect stdout to null again
    dup2(stdout_save, STDOUT_FILENO); //restore the previous state of stdout
    setvbuf(stdout, NULL, _IONBF, BUFFER_SIZE); //disable buffer to print to screen instantly
}

void clear_output_buffer()
{
    memset(std_output_buffer, 0, BUFFER_SIZE);
}

void clear_error_buffer()
{
    memset(std_error_buffer, 0, BUFFER_SIZE);
}

void assert_stdout(const char *expected)
{
    current_test_set_success(strcmp(std_output_buffer, expected) == 0);
}

void assert_stderr(const char *expected)
{
    current_test_set_success(strcmp(std_error_buffer, expected) == 0);
}

void replace_stderr()
{
    fflush(stderr); //clean everything first
    stdout_save = dup(STDERR_FILENO); //save the stderr state
    freopen("NUL", "a", stderr); //redirect stderr to null pointer
    setvbuf(stderr, std_error_buffer, _IOFBF, BUFFER_SIZE); //set buffer to stderr
}

void restore_stderr()
{
    freopen("NUL", "a", stderr); //redirect stderr to null again
    dup2(stdout_save, STDERR_FILENO); //restore the previous state of stderr
    setvbuf(stderr, NULL, _IONBF, BUFFER_SIZE); //disable buffer to print to screen instantly
}