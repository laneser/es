#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
   set_name( "raccoon dog", "野□" );
   add( "id", ({ "dog", "raccoon" }) );
   set_short( "野□" );
   set_long( "這是東方大陸北方特產的動物, 傳說它會施咒及變身。\n" );
   set( "race", "beast" );
   set( "gender", "male" );
	set("unit","只");
	set_perm_stat( "dex", 10 );
   set( "alt_corpse", IANMOB"satyr" );
	set_c_verbs( ({ "%s，用嘴咬向%s", "%s用前爪往%s抓下" }) );
	set_c_limbs( ({ "頭部", "身體", "腳部","尾巴" }) );
}

void die()
{
        tell_room( environment(this_object()), 
          "\n野□身受重傷, 不支倒地........\n\n"
          "就在你想離去時............\n\n"
          "突然野□從地上捉起一片樹葉放在頭上..........\n\n"
          "在一個後空翻之後......野□竟變成一魁武強悍的色狼!!\n\n"
          , this_object() );
        ::die(1);
}
