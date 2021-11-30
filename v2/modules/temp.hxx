#include "../config.hxx"

using namespace std;

const g_data_st *module_temperature(void){
    static float temp;

    clean_g_data();
    if ((temp_fp=fopen(TEMP_F,"r"))==NULL){
        ON_ERROR_SET_MARKUP("Error:module temp");
        return &g_data;
    }
    fgets(temp_buff,63,temp_fp);
    temp=atof(temp_buff)/1000;
    g_data.full_text<<temp<<" ℃";
    if (temp<=45.0f){
        strcpy(g_data.text_color,COL_MAGENTA);
    }
    else if (temp>45.0f && temp<=60.0f){
        strcpy(g_data.text_color,COL_GOLE);
        strcpy(g_data.bg_color,COL_PINK);
    }else{
        strcpy(g_data.text_color,COL_GOLE);
        strcpy(g_data.bg_color,COL_RED);
    }
    return &g_data;
}