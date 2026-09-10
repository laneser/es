#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(3);
	set_name( "dying man", "瀕臨死亡的人" );
	set_short( "瀕臨死亡的人" );
        add("id",({"man"}));
	set_long( 
             @LONG
你看他倒在地上□□一息的樣子，想救他又恨自己沒這個能力，他能活到現在，完全
是為了要把一個秘密(secret)講出來。
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "human" );
        set("hit_points",1);
        set("no_attack",1);
        set ("chat_chance", 5);
        set ("chat_output", ({
             "你聽到那快死的人說：快，把耳朵靠過來，我支持不下去了\n"
             }) );
        set ( "inquiry", ([
              "secret" : "@@ask_secret",
              ]) );
        call_out("disappear",100);
}

void disappear()
{
  tell_room(environment(),"這瀕臨死亡的人化成一縷白煙向天飄去。\n");
  remove();
}

void ask_secret(object who)
{
  if (this_player()->query_temp("ohio")<2) {
    tell_object(who,
      "瀕臨死亡的人說：你假如對別人仁慈，我也會對你仁慈。\n");
  }
  else {
    tell_object(who,
      "瀕臨死亡的人說：想要救人的話，就去摸山頂那個圖案。\n");
   }
   tell_room(environment(),"他終於□下了最後一口氣，你看到□體化成一絲白煙向天飄去。\n");
   this_object()->remove();
   return;
}
