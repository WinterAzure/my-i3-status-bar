#include "common.hxx"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/if_link.h>

#include <ifaddrs.h>
#include <netdb.h>

using namespace std;

const string module_network(void)
{
    /* print network status. */
    static struct ifaddrs *ifaddr;
    int net_family, s, addrlen;
    static char hostbuff[1024] = {0};
    static stringstream output;

    output.str("");
    if (getifaddrs(&ifaddr) == -1){
        return STR_RED("Syscall error in module network::getifaddrs()");
    }

    for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
            continue;
        if (strcmp(ifa->ifa_name, "lo") == 0)
            continue;
        net_family = ifa->ifa_addr->sa_family;
        if (net_family == AF_INET)
        {
            s = getnameinfo(ifa->ifa_addr, addrlen, hostbuff,
                            sizeof(hostbuff),
                            NULL, 0, (NI_NUMERICHOST | NI_NUMERICSERV) == 0);
            if (s != 0){
                return STR_RED("Systemcall error in module network::getnameinfo()");
            }
            output << STR_GREEN("Interface ")
                   << ifa->ifa_name
                   << STR_GREEN(" IP:")
                   << hostbuff
                   << STR_GREEN("|");
        }
    }
    if (output.str().size()==0)
        return STR_RED("No network in all interfaces.|");
    return output.str();
}