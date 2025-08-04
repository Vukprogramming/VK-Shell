#ifndef FILE_IO_H
#define FILE_IO_H
//-FILE VARIABLES-//

// Create file command variables
extern char crtFlStr[];
extern char crtFlUserIn[];
// Remove file command variables
extern char rmStr[];
extern char rmFile[];
// Write to file command variables
extern char wrtFlStr[];
extern char wrtFlNm[];
extern char wrtFlInStr[];
extern char wrtFlApStr[];
extern char wrtFlApNlStr[];
// Read file command variables
extern char rdFlStr[];
extern char rdFlNm[];
extern char buffer[];
// Make directory command variable
extern char dirName[];
// Remove directory
//-FILE FUNCTIONS-//

// Create file function
int crtFlf(void);
// Remove file function
int rmf(void);
// Write to file functions
int wrtFl(void);
// Append content to file function (Still counts as a write to file functions)
int wrtApFl(void);
int wrtFlApNl(void);
// Read file function
int rdFl(void);
// Read file function (hardcoded file)
int rdHcFl(const char* artFile);
// Make directory function
int mkDir(void);
// Remove directory function
int rmDir(void);
//---------------//

//----------------//

#endif