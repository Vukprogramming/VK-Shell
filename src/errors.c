#include "errors.h"
#include "ansi.h"

const struct errors ERRORS = {
    // Standard errors
    .input_read_error = COLOR_RED "0x01||Error reading user input",
    .invalid_command_error = COLOR_RED "0x02||Invalid command entered by user",
    .incorrect_password_error = COLOR_RED "0x03||Incorrent password entered by user",
    .no_input_entered = COLOR_RED "0x04||No input entered by the user",
    // File errors
    .failed_create_file = COLOR_RED "0xF1||Failed to create file: ",
    .failed_removing_file = COLOR_RED "0xF2||Failed to remove file",
    .failed_write_to_file = COLOR_RED "0xF3||Failed to write to file",
    .failed_to_read_file = COLOR_RED "0xF4||Failed to read contents of file",
    // Directory errors
    .failed_create_directory = COLOR_RED "0xD1||Failed to create directory",
    .failed_remove_directory = COLOR_RED "0xD2||Failed to remove directory"
};