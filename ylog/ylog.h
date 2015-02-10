//
//  ylog.h
//  ylog
//
//  Created by pengyunchou on 15-1-6.
//  Copyright (c) 2015年 pengyunchou. All rights reserved.
//

#ifndef __ylog__ylog__
#define __ylog__ylog__

#include <stdio.h>

typedef enum{
    ylog_level_info,
    ylog_level_debug,
    ylog_level_error
} ylog_level;

typedef struct{
    FILE *file;
    int isopen;
    int enableconsole;
    ylog_level level;
} ylog_context;

void ylog_open(ylog_context *ctx,char *logfile);
void ylog_enable_console(ylog_context *ctx);
void ylog_set_level(ylog_context *ctx,ylog_level level);
void ylog_log0(ylog_context *ctx,ylog_level level,char *line);
void ylog_log1(ylog_context *ctx,ylog_level level,char *format,...);
void ylog_log2(ylog_context *ctx,char *category,char *file,int line,ylog_level level,char *format,...);
#define ylog_log3(ctx,category,level,fmt,...) do{ylog_log2(ctx,category,__FILE__,__LINE__,level,fmt,##__VA_ARGS__);}while(0)
void ylog_close(ylog_context *ctx);

#endif /* defined(__ylog__ylog__) */
