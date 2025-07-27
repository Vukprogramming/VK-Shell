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

//-USER ACCOUNT VARIABLES-//

// Change user username command variable
extern char userNameIn[];
// Change user password command variable
extern char userPassIn[];

//-----------------------//

//-FILE VARIABLES-//

// Create file command variable
extern char crtFlUserIn[];
// Remove file command variable
extern char rmFile[];
// Write to file command variable
extern char wrtFlNm[];
extern char wrtFlInStr[];
// Read file command variables
extern char rdFlNm[];
extern char buffer[];

//----------------//

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
int strLenf(void);
// Show ANSI color table
int shwClrTbl(void);
// Caclulator functions

// Exit function
int exitf(void);

//-----------------//

//-USER ACCOUNT FUNCTIONS-//

// Change user username function
int chngUserName(void);
// Change user password function
int chngUserPass(void);
// Echo all user info function
int userEcho(void);

//------------------------//

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
//---------------//


#endif