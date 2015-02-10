//
//  ylog.c
//  ylog
//
//  Created by pengyunchou on 15-1-6.
//  Copyright (c) 2015年 pengyunchou. All rights reserved.
//

#include "ylog.h"
#include <string.h>
#include <time.h>
#include <stdarg.h>
void ylog_open(ylog_context *ctx,char *logfile){
    memset(ctx, 0x0, sizeof(ylog_context));
    ctx->file=fopen(logfile, "ab");
    if (ctx->file!=NULL) {
        ctx->isopen=1;
    }
}
void ylog_enable_console(ylog_context *ctx){
    ctx->enableconsole=1;
}
void ylog_set_level(ylog_context *ctx,ylog_level level){
    ctx->level=level;
}
void ylog_log0(ylog_context *ctx,ylog_level level,char *line){
    if (level>=ctx->level) {
        fprintf(ctx->file, "%s\n",line);
        fflush(ctx->file);
        if (ctx->enableconsole) {
            fprintf(stderr, "%s\n",line);
        }
    }
}
void ylog_log1(ylog_context *ctx,ylog_level level,char *format,...){
    va_list   arg_ptr;
    va_start(arg_ptr,format);
    char line[2*1024];
    bzero(line, sizeof(line));
    vsprintf(line, format, arg_ptr);
    va_end(arg_ptr);
    ylog_log0(ctx, level, line);
}
void ylog_log2(ylog_context *ctx,char *category,char *file,int line,ylog_level level,char *fmt,...){
    va_list   arg_ptr;
    va_start(arg_ptr,fmt);
    char msg[2*1024];
    bzero(msg, sizeof(msg));
    vsprintf(msg, fmt, arg_ptr);
    va_end(arg_ptr);
    char data[2*1024];
    sprintf(data, "%ld %s %s(%d) %s",time(NULL),category,file,line,msg);
    ylog_log0(ctx, level, data);
}
void ylog_close(ylog_context *ctx){
    fclose(ctx->file);
    ctx->isopen=0;
}