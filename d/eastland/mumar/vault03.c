#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
  set_short("The vault of kitchen","庫房");
  set_long(@Long
Long
,@CLong
這裡是糧食庫，堆放了如山的米袋和各種食物，平時這兒應該是很乾淨的，但是
你卻覺得你腳下全是米粒，踩起來怪不舒服的，而且米袋(bag) 也放得歪七扭八地，
像是被人翻箱倒櫃過一般。
CLong
);
set("light",1);
set("c_item_desc",([ "bag":"@@to_bag" ]) );
set("exits",([ "west":MUMAR"kitchen" ]));
set("objects",([ "cookie":MOB"cook_master"]) );
reset();
}
 
string to_bag()
{
    return "你看著看著，不知不覺數了起來......一共是三十二包。\n";
}
