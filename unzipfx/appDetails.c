
#include <stdlib.h>
#include <string.h>

#include "appDetails.h"

#define CMD_BUF_LEN 1024

int    sfx_app_argc = 0;
char** sfx_app_argv = NULL;

void sfx_app_set_args(int argc, char** argv)
{
    sfx_app_argc = argc;
    sfx_app_argv = argv;
}

int sfx_app_autorun_now()
{
    int i, cmdBufLen = 0;
    char cmdBuf[CMD_BUF_LEN];

    strcpy(cmdBuf, "cd " SFX_AUTORUN_DIR);
    strcat(cmdBuf, "; "); // cross-platform?
    strcat(cmdBuf, SFX_AUTORUN_CMD);

    cmdBufLen = strlen("cd " SFX_AUTORUN_DIR) + 2 + strlen(SFX_AUTORUN_CMD);

    for (i=0; i < sfx_app_argc; i++)
    {
        if (! sfx_app_argv[i])
            continue;

        cmdBufLen += strlen(sfx_app_argv[i]) + 1;
        if (cmdBufLen >= CMD_BUF_LEN-1)
            break;

        strcat(cmdBuf, " ");
        strcat(cmdBuf, sfx_app_argv[i]);
    }

    return system(cmdBuf);
}
