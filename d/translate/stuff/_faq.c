//#pragma save_binary
 
// _faq.c
// Print the MUD's FAQ list.
// Rather old. Probably originally authored in late 1991, and probably by
// Sulam. No header was written at that time.
// Mobydick added this header and the help on 11-14-92.
// Elon add Chinese switches. Sat  08-20-94
 
#include <mudlib.h>
 
inherit DAEMON ;
 
#define ES_FAQ_FILE "/adm/news/faq"
#define C_ES_FAQ_FILE "/adm/news/c_faq"
 
int cmd_faq(string unused) {
        string p;
    if (can_read_chinese()) {
        previous_object()->more(C_ES_FAQ_FILE);
        return 1;
    }
    else {
        previous_object()->more(ES_FAQ_FILE);
        return 1;
    }
}
 
int help() {
        write (can_read_chinese()?
"指令格式: faq\n\n"+
"這裡列出一些玩家常問的問題. 如果你有問題要問, 最好先看看這裡是\n"+
"不是已經有答案了.\n":
"Usage: faq\n\n"+
"This command will show you the FAQ file. FAQ stands for frequently\n"+
"asked questions, and the file contains the answers. It is good to read\n"+
"this before bothering a wizard or admin with questions.\n") ;
        return 1 ;
}
 
 
