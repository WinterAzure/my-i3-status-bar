#include "../globals.hxx"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/if_link.h>

#include <ifaddrs.h>
#include <netdb.h>

using namespace std;

const g_data_st *module_network(void){
    /* print network status. */
    /* no need to update too fast */
    static struct ifaddrs *ifaddr;
    int net_family, s, addrlen;

    clean_g_data();
    if (getifaddrs(&ifaddr) == -1){
L_ON_ERROR:
        ON_ERROR_SET_MARKUP("Error:module network");
        return &g_data;
    }

    for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next){
        if (ifa->ifa_addr == NULL)
            continue;
        if (strcmp(ifa->ifa_name, "lo") == 0)
            continue;
        net_family = ifa->ifa_addr->sa_family;
        if (net_family == AF_INET){
            s = getnameinfo(ifa->ifa_addr, addrlen, temp_buff,
                            sizeof(temp_buff),
                            NULL, 0, (NI_NUMERICHOST | NI_NUMERICSERV) == 0);
            g_data.full_text << "|Interface "
                             << ifa->ifa_name
                             << " IP:";
            strlen(temp_buff)==0 ? g_data.full_text<<"Unknow" : g_data.full_text<<temp_buff;
        }
    }
    if (g_data.full_text.str().size()==0){
        g_data.full_text<<"No network in all interfaces.";
        strcpy(g_data.text_color,COL_RED);
        return &g_data;
    }
    strcpy(g_data.text_color,COL_GOLE);
    return &g_data;
}