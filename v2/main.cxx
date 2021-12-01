#include "globals.hxx"
#include "config.hxx"

const string fmt(g_data_st *data){
    if (data==NULL)
        return "{\"full_text\":\"ERROR\"},";
    fmt_ss.str("");
    fmt_ss<<"{\"full_text\":\""
          <<g_data.full_text.str()
          <<"\",";
    fmt_ss<<"\"color\":\""
          <<g_data.text_color;
    if (strlen(g_data.bg_color)!=0){
        fmt_ss<<"\",\"background\":\""
            <<g_data.bg_color;
    }
    fmt_ss<<"\"},";
    return fmt_ss.str();
}

int main(int argc,char *argv[]){
    g_data.bg_color=(char *)malloc(64);
    g_data.text_color=(char *)malloc(64);

    cout.setf(ios::unitbuf);    /* IMPORTANT */
    cout<<"{\"version\":1}\n[\n";
    cout<<"[]\n";
    while (1){
        output.str("");
        output<<",[";
        for (auto &m:modules){
            if (m()==NULL){
                cerr<<"Error in main loop."<<endl;
                return EXIT_FAILURE;
            }
            output<<fmt(&g_data);
        }
        output<<"]";
        cout<<output.str().substr(0,output.str().length()-2)<<"]\n";
        sleep(3);
    }
}