
#include <stdio.h>
#include <stdlib.h>
#include "log.h"

int main(int argv,char**argc) {
    printf("%s\n",argc[0]);

    LOG_INFO("%s","Hello World!");
    LogWrite(INFO,"%s","Hello World!");
    LOG_DEBUG("%s","H.e.l.l.o W.o.r.l.d!");
    LogWrite(DEBUG,"%s","H.e.l.l.o W.o.r.l.d!");
    LOG_WARNING("%s","H e l l o W o r l d!");
    LogWrite(WARNING,"%s","H e l l o W o r l d!");
    LOG_FATAL("%s","Hallo World!");
    LogWrite(FATAL,"%s","Hallo World!");

    return 0;
}

