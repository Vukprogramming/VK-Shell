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
int echof(void);
// OS info function
int osInfof(void);
// Help function
int helpf(void);
// Clear screen function
int clrsf(void);
// String length function
int strLenf(void);
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