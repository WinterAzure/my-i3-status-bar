#ifndef __COMMON_HXX
#define __COMMON_HXX

#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <unistd.h>

/* colors */
#define COL_RED     "\033[31m"
#define COL_WHITE   "\033[0m"
#define COL_GREEN   "\033[32m"
#define COL_MAGE    "\033[35m"

#define STR_RED(X)      (COL_RED X COL_WHITE)
#define STR_GREEN(X)    (COL_GREEN X COL_WHITE)
#define STR_MAGE(X)     (COL_MAGE X COL_WHITE)

/* disks */
std::list <std::pair<const char *,const char *>> filesystem_monitor{
    {"/",   "Root"},
    {"/mnt","Data"}
};

/* batteries */
#define BATTERY_MAX_ENERGY 84240000
const std::string proc_file="/sys/class/power_supply/BAT0/";

/* CPU temp in /proc */
#define TEMP_F "/sys/class/hwmon/hwmon1/temp1_input"

#endif