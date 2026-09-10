//#pragma save_binary

#include <mudlib.h>
#include <conditions.h>
inherit OBJECT;

// This is inherit file for reagents.
// reagents can set the following attributes:
//  1. savour /味道/
//       legal values are acidity    酸
//                        bitter     苦 
//                        acrimony   辣
//                        sweet      甜
//  2. effects => can be set to simple_poison, weak or slow
//  3. if effect is set to simple_poison then the following 
//     need to be setted
//
//     duration => how many times to be poisoned
//     damage   => hp lost in each duration 
//
//  4. if effect is set to weak or slow, then need to set 
//     the following
//                          
//     frequency => how many heart beats to recover 1 time
//     difference=> how many str or dex to be decreased.

void init()
{
  add_action("do_taste","taste");
}
  
int do_taste(string str)
{
   int duration;
   int damage;
   object me;
   
        seteuid(getuid());
	if( !id(str) ) return notify_fail(
		"你要□試什麼東西？\n");

        if ( query("savour")=="bitter") {
          write( 
                 "你將" + query("c_name") + "放在嘴邊嘗試,哇!!苦死了!!\n");
        }else if ( query("savour")=="acidity") {
          write( "你小心的舔了一下"+query("c_name")+", 哇勒, 好酸啊!!\n");
        } else if ( query("savour")=="acrimony" ){
          write( "你輕輕的舔了"+query("c_name")+"一下....哇!!快噴火了!!哪□有水??");
        } else if (query("savour")=="sweet") {
          write ("你試了試"+query("c_name")+",疑,還蠻甜的嘛!莫非是毒藥甜嘴?\n");
	} else {
	  write ( "你嚐了嚐" + query("c_name") +",但感覺不出特別的味道。\n");
	}  
	if ( query("effect")=="simple_poison") {
	  duration=(int)query("duration");
	  damage=(int)query("damage");
          me = this_player();
        ("/std/conditions/simple_poison")->apply_effect(me,duration,damage);
	}else if ( query("effect")=="weak") {
	  duration=(int)query("frequency");
	  damage=(int)query("difference");
          me = this_player();
        ("/std/conditions/weak")->apply_effect(me,duration,damage);
	}else if ( query("effect")=="slow") {
	  duration=(int)query("frequency");
	  damage=(int)query("difference");
          me = this_player();
        ("/std/conditions/slow")->apply_effect(me,duration,damage);
	} else {	
	write(
		"你將" + query("c_name") + "放在嘴邊□試，並沒有感覺什麼特殊作用。\n");
	}
	
	tell_room( environment(this_player()),
		this_player()->query("c_name") + "將" + query("c_name") + "放在嘴邊□試。\n",
		this_player() );
	return 1;
}
