#ifndef __CRITERION_LIB_ASSERTS_IO_H__
    #define __CRITERION_LIB_ASSERTS_IO_H__

    #define BUFFER_SIZE 4096

void assert_stdout(const char *expected);
void assert_stderr(const char *expected);
void replace_stdout();
void replace_stderr();
void restore_stdout();
void restore_stderr();
void clear_output_buffer();
void clear_error_buffer();

#endif