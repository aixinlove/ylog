//
//  main.c
//  ylog
//
//  Created by pengyunchou on 15-1-6.
//  Copyright (c) 2015年 pengyunchou. All rights reserved.
//

#include <stdio.h>
#include "ylog.h"
int main(int argc, const char * argv[]) {
    ylog_context ylog;
    ylog_open(&ylog, "a.txt");
    ylog_enable_console(&ylog);
    ylog_set_level(&ylog, ylog_level_debug);
    ylog_log0(&ylog,ylog_level_debug, "a test log");
    ylog_log1(&ylog, ylog_level_debug, "hello %s","world");
    ylog_log3(&ylog, "log", ylog_level_debug, "%s","this is ylog3");
    ylog_close(&ylog);
    return 0;
}
