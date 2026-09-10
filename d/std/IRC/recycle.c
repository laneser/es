// Recycle bin..  to clean up some empty containers.
// Elon@eastern.Stories   Sun  08-21-94
 
#include <irc.h>
 
inherit OBJECT;
 
void create() {
  seteuid(getuid());
  set_name("recycle bin","資源回收桶");
  set("id",({"bin","tube"}));
  set_short("綠色桶子");
  set("prevent_get",1);
  set_long(
@CLONG
你看到一個漆成綠色的桶子. 上面寫著 [資源回收桶], 為了保持 ES 的清潔
請隨手將空瓶, 空罐之類的可回收資源送到這裡 (recycle).
(就算你不是環保小尖兵, 看在錢的份上也來回收吧.)
 
CLONG
);
 
}
 
void init() {
  add_action("recycle_me", "recycle");
}
 
int recycle_me(string str)
{
    string tmps;
    object *objs;
    int i,mon,tmpi;
    if (!str || str=="") {
        return notify_fail("Syntax: recycle <item>\n");
    }
    objs=all_inventory(this_player());
    for (i=0; i<sizeof(objs); i++) {
        if ((string)objs[i]->query("name")==str) {
        if (sscanf(file_name(objs[i]),"%sempty#%d",tmps,tmpi)==2) {
//            if (objs[i]->query("recycle")) {
                    mon=(int)objs[i]->query("recycle");
                    write("你將"+objs[i]->query("short")+"丟進回收筒內. 得到 "+mon+" 個銅幣.\n");
                    this_player()->credit("copper",mon);
                    objs[i]->remove();
                    return 1;
                    }
                else {
                write("這樣東西不能回收.\n");
                return 1;
                }
            }
        }
        write("你沒有這樣東西.\n");
        return 1;
}
 
