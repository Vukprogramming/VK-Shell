#ifndef CMDS_H
#define CMDS_H

//-BASIC VARIBLES-//

// Echo command variables
extern char echoStr[];
extern char userEchoMsg[];
// OS info command variables
extern char osInfoStr[];
extern char osInfo[];
// Exit command variable
extern char exitStr[];
// Help command variable
extern char helpStr[];
// String length command variables
extern char strLenStr[];
extern int strLen;
// User password attempt variable
extern char userPassAtt[];
// Clear screen command variable
extern char clrsStr[];

//---------------//

//-USER ACCOUNT VARIABLES-//

// Change user username command variables
extern char chngUserNameStr[];
extern char userNameIn[];
// Change user password command variables
extern char chngUserPassStr[];
extern char userPassIn[];
// Echo all user information command variable
extern char userEchoStr[];

//-----------------------//

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

//----------------//

// FUNCTIONS

//-BASIC FUNCTIONS-//

// Echo function
void echof(void);
// OS info function
void osInfof(void);
// Help function
void helpf(void);
// Clear screen function
void clrsf(void);
// String length function
void strLenf(void);
// Exit function
void exitf(void);

//-----------------//

//-USER ACCOUNT FUNCTIONS-//

// Change user username function
void chngUserName(void);
// Change user password function
void chngUserPass(void);
// Echo all user info function
void userEcho(void);

//------------------------//

//-FILE FUNCTIONS-//

// Create file function
int crtFlf();
// Remove file function
void rmf();
// Write to file functions
int wrtFl();
// Append content to file function (Still counts as a write to file functions)
int wrtApFl();
int wrtFlApNl();
// Read file function
int rdFl();
//---------------//

#endif