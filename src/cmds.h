#ifndef _CMDS_H
#define _CMDS_H

#include "types.h"

typedef struct {
  char          *name;
  char          *flags;
  Function      func;
  char          *funcname;
} cmd_t;

typedef struct {
        char *name;
        struct flag_record     flags;
} mycmds;

typedef struct {
  char *name;
  Function func;
} botcmd_t;

#ifdef S_DCCPASS
typedef struct cmd_pass {
  struct cmd_pass *next;
  char *name;
  char pass[25];
} cmd_pass_t;
#endif


extern mycmds 		cmdlist[]; 
extern int		cmdi;

int check_dcc_attrs(struct userrec *, int);
int check_dcc_chanattrs(struct userrec *, char *, int, int);
int stripmodes(char *);
char *stripmasktype(int);
void gotremotecmd(char * forbot, char * frombot, char * fromhand, char * fromidx, char * cmd);
void gotremotereply(char * frombot, char * tohand, char * toidx, char * ln);

#endif /* !_CMDS_H */
