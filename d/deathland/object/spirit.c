

#include "../echobomber.h"
inherit OBJECT;

void create()
{
  seteuid(getuid());
  set_name("Ancient Evil Spirit","古代邪惡的靈魂");
  
  set_short("Ancient Evil Spirit","古代邪惡的靈魂");
  set("c_long",@ScryBall
被禁錮的古代邪惡的靈魂, 當你釋放它的時候, 它將監視它被放出來
的地方, 而你將能知道那裡的一舉一動, 直到你把它毀掉為止.
--Use <info spirit> 獲得更詳細的資料.
ScryBall
);
  add("id",({"spirit",}));
  set( "unit", "個");
  set("weight", 0);
  set("c_extra_look","$N的身旁有著可怕的靈魂圍繞著他.\n");
  set("prevent_drop",1);
  set("prevent_insert",1);
}

void init()
{
    add_action("to_info","info");
    add_action("to_scry","scry");
    add_action("to_toss","toss");
    add_action("to_release","release");
}

int to_release(string str)
{
    string room;
    if (!id(str)) 
      return 0;
    if (query("release")) 
      return notify_fail("這靈魂已經被釋放出來了.\n");
    
    room = file_name( environment( this_player() ) );
    
    set("where",room);
    
    set("release",1);
    write("你在這裡釋放出古代邪惡靈魂來.\n");
    return 1;     
}

int to_scry(string str)
{
    object room,*item;
    int chinese_mode;
    string room_desc,desc;
    
    if (!id(str)) 
      return 0;
    if (!query("release")) 
      return notify_fail("這靈魂尚未被釋放出來.\n");
    
    room_desc = query("where");
    chinese_mode=can_read_chinese();
    if ( !(room = find_object( room_desc )) ) room=new(room_desc);
    desc=call_other("/cmds/std/_look","remote_look_room",room,0,1,chinese_mode);
    write(desc);
    return 1;      
}

int to_toss(string str)
{
    if (!id(str)) return 0;
    write("你把古代邪惡靈魂給毀掉了.\n");
    this_object()->remove();
    return 1;
}

int to_info(string str)
{
    if (!id(str)) return 0;
    
    write(
    "------------------------\n"
    "釋放靈魂: release spirit\n"
    "監視房間  scry spirit   \n"
    "毀掉靈魂  toss spirit   \n"
    );
    return 1;
}

