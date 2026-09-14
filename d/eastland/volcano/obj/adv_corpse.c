#include "../oldcat.h"

inherit "/obj/corpse";
int be_cut;

void create()
{
    ::create();
    ::set_name("advanturer","冒險者");
    set_c_open_long("這是冒險者的遺體，你可以割(cut)下他的頭做為戰利品。\n");
    set("weight",800);
    set("load",1000);
    be_cut=0;
}

void init()
{
  add_action("cut_head","cut");
}

int cut_head(string arg)
{
   int i;
   object wep,obj,*item;

   if (!arg || arg!="head")
      return notify_fail("你要割啥?\n");

   if (be_cut)
      return notify_fail(
         "這個冒險者的頭已經被割走了。\n");
   item=all_inventory(this_player());
   for (i=0;i<sizeof(item);i++)
     if ((string)item[i]->query("name")=="sharp knife") {
       write("你用你手中的銳利小刀把冒險者的頭從屍體上割了下來。\n");
       obj=new(OOBJ"head");
       obj->move(this_player());
       be_cut=1;
       return 1;
     }
   write("你沒有適當的工具可以把頭割下來。\n");
   return 1;
}
