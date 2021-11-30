#include "../config.hxx"

using namespace std;

const g_data_st *module_load(void){
    static double loadavg;

    clean_g_data();
    if (getloadavg(&loadavg,1)==-1){
        ON_ERROR_SET_MARKUP("Error:module load");
        return &g_data;
    }
    if (loadavg<=1.0f)
        strcpy(g_data.text_color,COL_WHITE);
    else if (loadavg>1.0f && loadavg<=8.0f)
        strcpy(g_data.text_color,COL_RED);
    else {
        strcpy(g_data.text_color,COL_GOLE);
        strcpy(g_data.bg_color,COL_RED);
    }
    g_data.full_text<<"Load "<<loadavg;
    return &g_data;
}