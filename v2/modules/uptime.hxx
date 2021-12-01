#include "../globals.hxx"

const g_data_st *module_uptime(void){
    /* test if status bar is actually running */
    static long uptime_seconds;
    clean_g_data();
    
    if ((temp_fp=fopen(UPTIME_FILE,"r"))==NULL){
        ON_ERROR_SET_MARKUP("Error:module uptime.");
        return &g_data;
    }
    fgets(temp_buff,128,temp_fp);
    uptime_seconds=atol(strtok(temp_buff," "));
    g_data.full_text<<"Uptime:"
                    <<uptime_seconds/86400
                    <<" days "
                    <<(uptime_seconds%86400)/3600
                    <<" hours";
    strcpy(g_data.text_color,COL_GOLE);
    return &g_data;
}