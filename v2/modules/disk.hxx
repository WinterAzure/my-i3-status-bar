#include "../globals.hxx"

#include <sys/vfs.h>

using namespace std;

const g_data_st *module_disk(void){
    /* get disk space left */
    static struct statfs buf;

    clean_g_data();
    for (auto &i:filesystem_monitor){
        if (statfs(i.first,&buf)!=0){
            ON_ERROR_SET_MARKUP("Error:module text");
            return &g_data;
        }
        float free_space=buf.f_bsize*buf.f_bavail/1024.0f/1024.0f/1024.0f;
        g_data.full_text<<i.second
                        <<":"
                        <<free_space
                        <<"GiB ";
        strcpy(g_data.text_color,COL_WHITE);
    }
    return &g_data;
}