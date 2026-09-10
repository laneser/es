#include <mudlib.h>

inherit MONSTER;

void create()
{

        ::create();
        set_level(1);
        set_name( "dove", "鴿子" );
        add ("id", ({ "dove" }) );
	set( "unit", "群" );
        set_short( "很多隻鴿子" );
        set_long(
           "一隻溫馴的小白鴿，正悠閒地在廣場上漫步。\n"+
           "他似乎注意到，除了和善的精靈外，你正注視著他，\n"+
           "又對著你擺了擺頭，好像想告訴你什麼......。\n"
        );
        set_perm_stat("str", 1);
        set_perm_stat("dex", 5);
        set ("natural_armor_class", 10);
        set ("gender", "male");
        set ("race", "鴿子");
        set("alignment",300);
        set("natural_max_damage1",10);
        set("natural_min_damage1",5);
        set_c_limbs(({"身體","頭部","翅膀","腳部"}));
	set_c_verbs(({ "%s用它的嘴吧向%s啄去"}));
}

void init()
{
 add_action("kill_dove","kill");
}

int kill_dove(string arg)
{
 if( arg == "dove" && random(10) > 4 )
 {
  object dove;
  dove=this_object();

   tell_room( environment(this_object()),
        "鴿群似乎受到了驚嚇，成群結隊地飛起．．．．\n"+
        "盤旋在空中．．．．",
        this_object());
    dove->remove();
   return 1;
 }
 else
 {
  this_player()->command("kill"+arg);
 }
}

void die()
{
   object killer;

   killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#37");
   ::die();
}
