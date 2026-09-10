
#include "../echobomber.h"

inherit ROOM;
inherit Deathland+"/mine/daemon/lever";
void create()
{
  ::create();
  set_short(" Drawf mine ","矮人礦坑");
  set_long(@Long
Long
,@CLong
這裡是礦坑的深處.你能看到的是一個周圍的巖壁充滿著被挖掘的痕跡以及
用木頭架設著以免塌陷的巖洞.在地上有鐵軌鋪設著.專供運礦車通行使用.你能
看到許多運礦車來來往往.在鐵軌的旁邊有一個推杆(lever),似乎常被人使用著.
CLong
);

set("direction","south");
set("exits",([
             "north":Mine"/m21",
             "south":Mine"/m43",
             "southwest":Mine"/m44",
             ]));
set("c_item_desc",([
    "lever":"一個推杆,似乎是用來控制鐵軌的方向,你可以試著拉動(pull)它.\n",
    "rail":"@@rail_c_long",
    ]) );

reset();
}

void init()
{
     add_action("to_pull","pull");
}

int to_pull(string str)
{
    return pull_lever(this_object(),str);
}

string rail_c_long()
{
     return "目前鐵軌通向"+to_chinese( query("direction") )+"方\n";  

}

reset()
{
  string dir;
  dir=query("direction");
  ::reset();
  set("direction",dir); 
}
