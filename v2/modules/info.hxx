#include "../globals.hxx"

const g_data_st *module_info(void){
    /* this module show info */
    static uint64_t counter;

    clean_g_data();
    g_data.full_text<<"TUC:"<<(counter++)
                    <<" PID:"<<bar_pid;
    return &g_data;
}