
#ifndef __APP_DETAILS_H__
#define __APP_DETAILS_H__

#define SFX_APP_BANNER   "Cadence self-contained executable 0.5.0, based on UnZipSFX."

#ifndef SFX_APP_MININAME
#define SFX_APP_MININAME "cadence"
#endif

#ifdef _WIN32
#define SFX_TARGET_DIR   "%TMP%"
#define SFX_AUTORUN_CMD  ".\\" SFX_APP_MININAME ".exe"
#define SFX_AUTORUN_DIR  SFX_TARGET_DIR "\\" SFX_APP_MININAME
#else
#define SFX_TARGET_DIR   "/tmp"
#define SFX_AUTORUN_CMD  "./" SFX_APP_MININAME
#define SFX_AUTORUN_DIR  SFX_TARGET_DIR "/" SFX_APP_MININAME
#endif

void sfx_app_set_args(int argc, char** argv);
int  sfx_app_autorun_now();

#endif // __APP_DETAILS_H__
