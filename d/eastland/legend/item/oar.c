#include <mudlib.h>
#include "../legend.h"

inherit OBJECT;
int pl1,pl2;

void create()
{
        set( "extra_look", "$N正坐在一艘小船上");
        set_name("Oak oar", "橡木槳");
        add("id", ({ "oak oar","oar" }) );        
        set_short("橡木槳");
        set_long( @LONG
    一支橡木做的槳，看起來已經很舊了，但是還是很堅實耐用。你可以打
(help_me oak_oar)，如果你不知道怎麼划船的話。
LONG
        );
        pl2=random(5);
        set( "unit", "支" );
        set( "weight", 10 );
        set( "prevent_drop",1);
        set( "prevent_insert",1);
}

void init()
{
  add_action("help_me", "help_me");
  add_action("do_oar", "oar");
}

int do_oar(string arg)
{
    string c_dir,dest;

    if( !arg )
      return notify_fail( "你想要往哪邊劃呢？\n");
    switch(arg) {
      case "east"  :
           pl1=pl1+3;
           pl2=pl2+3;
           c_dir="東";
           break;
      case "west"  :
           pl1=pl1+2;
           pl2=pl2+5;
           c_dir="西";
           break;
      case "south" :
           pl1=pl1+5;
           pl2=pl2-2;
           c_dir="南";
           break;
      case "north" :
           pl1=0;pl2=random(5);
           c_dir="北";
           break;
      default :
      return notify_fail( "你想要往哪邊劃呢？\n");
    };
    tell_object(this_player(),sprintf("你努力的往%s邊劃去。\n",c_dir));
    tell_room(environment(this_player()),sprintf(
     "%s努力的向%s邊劃了過去。\n",this_player()->query("c_name"),c_dir),this_player());
    if ((pl2==13)||(pl2==19)||(pl2==31)||(pl2==37)) {
      pl2=pl1=0;
      this_player()->move_player(LAKE"lake05","SNEAK");
      tell_room(environment(this_player()),sprintf(
        "%s搖著槳，慢慢地劃了過來。\n",this_player()->query("c_name")),this_player());
      return 1;
    }
    dest=LAKE"l_maze"+(string)((pl1 % 7));
    this_player()->move_player(dest,"SNEAK");
    tell_room(environment(this_player()),sprintf(
        "%s搖著槳，慢慢地劃了過來。\n",this_player()->query("c_name")),this_player());
    pl1=(pl1>100)?0:pl1;
    if ((pl2<-1)||(pl2>40)) pl2=random(5);
    return 1;
}

int help_me(string arg)
{
  if( !arg || arg!="oak_oar" ) return 0;
  tell_object(this_player(),@LONG
   你突然發現你不會划船，不論你怎麼使力，船只是不停地在原地打轉。
   無計可施之下，你只好大聲呼  
            救......救        命        呀！！！
   
   一隻小白魚游出水面，用著鄙夷的眼光看著你，並說道
   沒看過這麼差的，不會划船也遨遊大海。我就好心教你一下吧，注意聽啊: 
   你可以划向--某個方向  (oar direction) ，例如< oar east >。這裡是
   大海，你隨便劃任何方向  (east south west north)都不會撞壁啦。
   
   小白魚說完就一頭溜進水裡去了。 


LONG    
    );
      return 1; 
}       
