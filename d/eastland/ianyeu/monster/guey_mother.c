#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey mother", "桂老媽" );
   add( "id", ({ "guey", "mother" }) );
   set_short( "桂老媽" );
	set_long(
        "你看到一位年約四十的中年婦人, 她不斷地唉聲嘆氣, 不知為何所苦.\n"
	);
   set( "gender", "female" );
	set( "race", "human" );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 25 );
   set( "wealth/copper", 10 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "桂老媽嘆道: 我可憐的女兒, 你怎麼狠心丟下老媽?\n",
        "桂老媽自語: 老爹(dad)又出去了!\n"
	}) );
   set( "inquiry", ([
        "sheaumei" : "唉..........\n",
        "daughter" : "唉..........\n",
        "dad" : "老爹大概又去女兒的墳前了.\n"
     ]) );
}
