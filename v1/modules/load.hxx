#include "common.hxx"

using namespace std;

const string module_load(void){
    static stringstream output;
    static double loadavg[3];

    output.str("");
    //output<<output.precision(3);
    if (getloadavg(loadavg,3)==-1)
        return STR_RED("Error in module load::getloadavg");
    output<<STR_GREEN(" |Load ")
          <<loadavg[0]
          <<STR_GREEN(" ")
          <<loadavg[1];
    return output.str();
}