#include "../globals.hxx"

const g_data_st *module_counter(void){
    static uint64_t counter;

    clean_g_data();
    g_data.full_text<<(counter++);
    return &g_data;
}