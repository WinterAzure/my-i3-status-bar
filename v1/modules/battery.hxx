#include "common.hxx"

using namespace std;

const string module_battery(void){
    static stringstream output;
    static char buff[256]={0};
    static int percentage;

    output.str("");
    FILE *fp=fopen((proc_file+"status").c_str(),"r");
    if (fp==NULL)
        return STR_RED("Error in module battery::fopen status");
    switch (fgetc(fp)){
        case 'D' : output<<"BAT ";break;
        case 'C' : output<<STR_MAGE("CHR ");break;
        default  : output<<STR_RED("UKW ");break;
    }
    fclose(fp);
    /* read battery percentage */
    if ((fp=fopen((proc_file+"energy_now").c_str(),"r"))==NULL)
        return STR_RED("Error in module battery::fopen energy_now");
    fgets(buff,255,fp);
    percentage=stoi(buff)/(BATTERY_MAX_ENERGY/100);
    if (percentage<=30)
        output<<COL_RED+to_string(percentage);
    else if (percentage>30 && percentage<=60)
        output<<COL_MAGE+to_string(percentage);
    else 
        output<<to_string(percentage);
    output<<" %"
          <<STR_GREEN("|");
    return output.str();
}