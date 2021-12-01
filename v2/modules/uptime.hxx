#include "../globals.hxx"

const g_data_st *module_uptime(void){
    /* test if status bar is actually running */
    static long uptime_seconds;

    clean_g_data();
    uptime_seconds=info.uptime;
    g_data.full_text<<"Uptime:"
                    <<uptime_seconds/86400
                    <<" days "
                    <<(uptime_seconds%86400)/3600
                    <<" hours";
    strcpy(g_data.text_color,COL_GOLE);
    return &g_data;
}