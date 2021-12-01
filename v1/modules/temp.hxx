#include "common.hxx"

using namespace std;

const string module_temperature(void){
    static stringstream output;
    static char buff[64];
    static float temp;
    FILE *fp;

    output.str("");
    if ((fp=fopen(TEMP_F,"r"))==NULL)
        return STR_RED("Error in module temp::fopen");
    fgets(buff,63,fp);
    temp=atof(buff)/1000;
    if (temp<=40.0f)
        output<<temp<<" ℃";
    else if (temp>40.0f && temp<=60.0f)
        output<<COL_MAGE<<temp<<" ℃"<<COL_WHITE;
    else
        output<<COL_RED<<temp<<" ℃"<<COL_WHITE;
    return output.str();
}