#include "../globals.hxx"

using namespace std;

const g_data_st *module_battery(void){
    static stringstream output;
    static int percentage;

    clean_g_data();
    temp_fp=fopen((proc_file+"status").c_str(),"r");
    if (temp_fp==NULL){
        ON_ERROR_SET_MARKUP("Error:module battery::status");
        return &g_data;
    }
    switch (fgetc(temp_fp)){
        case 'D' :  g_data.full_text<<"BAT ";break;
        case 'C' :  g_data.full_text<<"CHR ";break;
        default  :  g_data.full_text<<"UKN ";break;
    }
    fclose(temp_fp);
    /* read battery percentage */
    if ((temp_fp=fopen((proc_file+"energy_now").c_str(),"r"))==NULL){
        ON_ERROR_SET_MARKUP("Error:module battery::energy now");
        return &g_data;
    }
    fgets(temp_buff,255,temp_fp);
    percentage=stoi(temp_buff)/(BATTERY_MAX_ENERGY/100);
    g_data.full_text<<to_string(percentage)<<" %";
    if (percentage<=30){
        strcpy(g_data.text_color,COL_BLACK);
        strcpy(g_data.bg_color,COL_RED);
    }
    else if (percentage>30 && percentage<=60)
        strcpy(g_data.text_color,COL_PINK);
    else 
        strcpy(g_data.text_color,COL_WHITE);
    return &g_data;
}