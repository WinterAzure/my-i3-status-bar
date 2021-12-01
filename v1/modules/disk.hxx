#include "common.hxx"

#include <sys/vfs.h>

using namespace std;

const string module_disk(void){
    /* get disk space left */
    static struct statfs buf;
    static stringstream output;
    output<<output.precision(5);

    output.str("");
    for (auto &i:filesystem_monitor){
        if (statfs(i.first,&buf)!=0){
            return STR_RED("Error in module disk::statfs");
            perror("Error:");
        }
        float free_space=buf.f_bsize*buf.f_bavail/1024.0f/1024.0f/1024.0f;
        output<<i.second
              <<":"
              <<free_space
              <<"GiB"
              <<STR_GREEN("|");
    }

    return output.str();
}