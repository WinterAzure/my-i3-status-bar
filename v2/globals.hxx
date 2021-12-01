/* config modules and global structs */

#pragma once

#ifndef __COMMON
#define __COMMON

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <utility>

#include <cstring>

#include <unistd.h>
#include <sys/sysinfo.h>

#define COL_BLACK   "#000000"
#define COL_WHITE   "#FFFFFF"
#define COL_BLUE    "#0000FF"
#define COL_GOLE    "#FFD700"
#define COL_RED     "#FFF000"
#define COL_PINK    "#FFC0CB"
#define COL_MAGENTA "#FF00FF"

#endif

using namespace std;

struct g_data_st{
    char *text_color;
    char *bg_color;
    stringstream full_text;
} g_data;

extern g_data_st g_data;

/* output text */
stringstream output;

/* stringstream for format usage */
stringstream fmt_ss;

/* temp buff for text processing */
char temp_buff[512]={0};

/* FILE * for temp use */
FILE *temp_fp;

/* configs for modules */
std::list <std::pair<const char *,const char *>> filesystem_monitor{
    {"/",   "Root"},
    {"/mnt","Data"}
};

/* batteries */
#define BATTERY_MAX_ENERGY 84240000
const std::string proc_file="/sys/class/power_supply/BAT0/";

/* CPU temp in /proc */
#define TEMP_F "/sys/class/hwmon/hwmon1/temp1_input"

/* Uptime file */
#define UPTIME_FILE "/proc/uptime"

inline void clean_g_data(){
    g_data.full_text.str("");
    strcpy(g_data.bg_color,"");
    strcpy(g_data.text_color,"");
    strcpy(temp_buff,"");
    temp_fp=NULL;
}

#define ON_ERROR_SET_MARKUP(TEXT)   g_data.full_text.str(TEXT);  \
                                    strcpy(g_data.bg_color,COL_RED);\
                                    strcpy(g_data.text_color,COL_WHITE)
