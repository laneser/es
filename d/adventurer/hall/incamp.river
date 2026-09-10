#include "mudlib.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "帳蓬內" );
	set_long(
        "這是一間小小的帳蓬，空間並不是很大，但卻令人覺得非常舒適，\n"
        "如果能在這裡小睡(sleep)片刻，應該可以使你更有精神。\n"
        "在角落裡有一張小布條(note)，上面寫了一些字。\n"
	);
        set( "objects", ( [
              "bed" : "/d/adventurer/hall/obj/bed"] ) );
	set("c_item_desc",(["note":
	"帳蓬使用說明:\n"
	"1. 本帳蓬防水防風，安全衛生，是您在野外的良伴...\n"
	"2. sleep 指令可使您在帳蓬中休息，而休息的效果端視帳蓬舒適與否...\n"
	"3. wake 指令可使您叫醒在睡眠的任何人，但沒事打擾別人是不好的行為\n"
	"4. 冒險者由於其露營經驗豐富，可以在帳蓬中使用protect 指令保護別人\n"
	"5. 要解除冒險者的保護狀態可使用unprotect 指令...\n"
	"6. 請不要在危險之處搭建帳蓬，以免一睡不醒...\n"
	]));
	set( "light",1 );
        set( "no_monster",1);
        reset();
}
void init()
{
add_action("cmd_out","out");
add_action("cmd_quit","quit");
}

int cmd_out()
{ 
     object camp,env,*who;

     camp = this_player()->query_temp("last_camp");
     env = this_player()->query_temp("last_locate");
     who = (object *)camp->query_temp("who_in_camp");
     who -= ({ this_player() });
     tell_object( this_player(),
     "你把帳蓬的門打開，一溜煙鑽了出去。\n" );
     tell_room( environment(this_player()),
     this_player()->query("c_name")+"把帳蓬的門打開，一溜煙鑽了出去。\n",
                                  this_player() );
     this_player()->move_player(env,"SNEAK");
     camp->set("num",camp->query("num")-1);
     camp->set_temp("who_in_camp",who );
     return 1;
} 
int cmd_quit()
{    
          object camp,*who;
          camp = this_player()->query_temp("last_camp");
          who = (object *)camp->query_temp("who_in_camp");
          who -= ({ this_player() });
          camp->set("num",camp->query("num")-1);
          camp->set_temp("who_in_camp",who );
          return 0;   
}
          
