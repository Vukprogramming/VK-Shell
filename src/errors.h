#ifndef ERRORS_H
#define ERRORS_H

struct errors {
    const char *input_read_error;
    const char *invalid_command_error;
    const char *incorrect_password_error;
    const char *no_input_entered;
    const char *failed_create_file;
    const char *failed_removing_file;
    const char *failed_write_to_file;
    const char *failed_to_read_file;
    const char *failed_create_directory;
    const char *failed_remove_directory;
};

extern const struct errors ERRORS;

#endif