#ifndef CMDS_H
#define CMDS_H

//-BASIC VARIBLES-//

// Echo command variable
extern char userEchoMsg[];
// OS info command variable
extern char osInfo[];
// String length command variable
extern char strLenUserIn[];
extern int strLen;

//---------------//

// FUNCTIONS

//-BASIC FUNCTIONS-//

// Echo function
int echof(void);
// OS info function
int osInfof(void);
// Help function
int helpf(void);
// Clear screen function
int clrsf(void);
// String length function
int strLenf();
// Show ANSI color table
int shwClrTbl(void);
// Shell info function
int shellInfo(void); 
// Exit function
int exitf(void);

//-----------------//
#endif