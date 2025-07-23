#ifndef CMDS_H
#define CMDS_H

extern char echoStr[];
extern char userEchoMsg[];
extern char osInfoStr[];
extern char osInfo[];
extern char exitStr[];
extern char helpStr[];
extern char rmStr[];
extern char rmFile[];
extern char clrsStr[];
extern char chngUserNameStr[];
extern char chngUserPassStr[];
extern char userNameIn[];
extern char userPassIn[];
extern char userEchoStr[];
extern char userPassAtt[];
extern char strLenStr[];
extern char crtFlStr[];
extern char crtFlUserIn[];
extern int strLen;

void echof(void);
void osInfof(void);
void exitf(void);
void helpf(void);
void rmf();
void clrsf(void);
void chngUserName(void);
void chngUserPass(void);
void userEcho(void);
void strLenf(void);
int crtFlf();

#endif