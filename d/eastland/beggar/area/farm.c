#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "farm", "菜圃" );
	set_long(@C_LONG
這是一小片種滿大白菜的園圃。因為剛被收成不久,於是地上變得坑坑洞洞的
,有點寸步難行。旁邊還有一個大籠子,是用來關小雞用的。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "east":DBEGGAR"west6.c"
	]) );
        set( "c_item_desc", ([
                  "hole" :"一個小坑洞。\n",
        ]) );
        set( "objects",([
                      "little_chicken1":DMONSTER"little_chicken.c",
                      "little_chicken2":DMONSTER"little_chicken.c",   
                      "little_chicken3":DMONSTER"little_chicken.c",
                      "mother_chicken":DMONSTER"mother_chicken.c",
                      "peacock1":DMONSTER"peacock.c",
                      "peacock2":DMONSTER"peacock.c",
        ]) );
        reset();
}
void init()
{
   add_action("do_search","search");
}

int do_search(string arg)
{
    object ob1;
    
    if ( !arg || arg != "hole" )
        return notify_fail("你在找什麼東西？\n");
    if ( (present("little chicken",this_object())) ||
         (present("peacock",this_object())) )
        return notify_fail("你在找什麼東西？\n");
    if ( ! this_player()->query_temp("old_asked") ) 
        return notify_fail("你在找什麼東西？\n");
    if ( this_object()->query("be_searched") )
        return notify_fail("這裡似乎被別人找過了。\n");
              
    ob1=new(DITEM"sun_pill");
    ob1->set("master",this_player()->query("name"));
    tell_object( this_player(),
       "哦,你發現了一顆六陽正氣丹!!\n");
    ob1->move( this_player() );   
    this_object()->set("be_searched",1);
    call_out("recover1",1800,this_object());
    return 1;
}
void recover1(object obj)
{
    obj->delete("be_searched");   
}
void reset()
{
     this_object()->delete_temp("be_searched");
     ::reset();
}
          