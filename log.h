#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

#define MAXLEN (2048)
#define MAXFILEPATH (512)
#define MAXFILENAME (50)

typedef enum {
    ERROR_1 = -1,
    ERROR_2 = -2,
    ERROR_3 = -3
} ERROR0;


typedef enum {
    NONE = 0,
    INFO = 1,
    DEBUG = 2,
    WARNING = 3,
    FATAL = 4,
    ALL = 255
} LOGLEVEL;

typedef struct log {
    char logtime[20];
    char filepath[MAXFILEPATH];
    FILE *logfile;
} LOG;

typedef struct logseting {
    char filepath[MAXFILEPATH];
    unsigned int maxfilelen;
    unsigned char loglevel;
} LOGSET;

int LogWrite(unsigned char loglevel,char *fromat,...);

#ifndef LOG_DEBUG 
#define LOG_DEBUG(fmt, arg...) do { \
    LogWrite(DEBUG,"[%s:%d] " fmt,\
            __FILE__, __LINE__, ## arg); \
} while (0)
#endif

#ifndef LOG_WARNING
#define LOG_WARNING(fmt, arg...) do { \
    LogWrite(WARNING,"[%s:%d] " fmt,\
            __FILE__, __LINE__, ## arg); \
} while (0)
#endif

#ifndef LOG_FATAL
#define LOG_FATAL(fmt, arg...) do { \
    LogWrite(FATAL,"[%s:%d] " fmt,\
            __FILE__, __LINE__, ## arg); \
} while (0)
#endif

#ifndef LOG_INFO
#define LOG_INFO(fmt, arg...) do { \
    LogWrite(INFO,"[%s:%d] " fmt,\
            __FILE__, __LINE__, ## arg); \
} while (0)
#endif

#endif /* __LOG_H__ */

