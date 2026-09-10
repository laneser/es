#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(6);
   set_name( "liang mother", "梁母" );
   add( "id", ({ "liang", "mother" }) );
   set_short( "梁母" );
	set_long(@C_LONG
一位年約三十的中年婦女。當你注視她時, 明顯覺得她對你不懷好感,
甚至想立刻趕你出門。
C_LONG
	);
	set( "race", "human" );
   set( "gender", "female" );
   set( "alignment", 350 );
   set_perm_stat( "str", 10 );
   set_perm_stat( "dex", 10 );
   set_perm_stat( "kar", 5 );
   set_skill( "dodge", 40 );
   set( "wealth/copper", 50 );
	set_natural_weapon( 8, 8, 8 );
   set_natural_armor( 40, 8 );

   set( "chat_chance", 15 );
   set( "chat_output", ({
        "梁母道: 寶寶別怕! 媽在這.\n"
        }) );
}
