#include "../globals.hxx"

const g_data_st *module_simple_counter(void){
    /* test if status bar is actually running */
    static uint32_t counter;

    clean_g_data();
    g_data.full_text<<(counter++);
    return &g_data;
}