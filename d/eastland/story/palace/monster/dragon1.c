#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "Great dragon","[1;32m□[1;36m□[0;37m[1;32m□[1;36ms[m");
        add( "id", ({ "dragon" }) );
        set_short( "[1;32m□[1;36m□[0;37m[1;32m□[1;36ms[m");
        set_long(@C_LONG
一隻性情頗為溫馴的動物，它比起許多兇惡的應龍中溫善許多了。它是黃帝最心愛
的寵物，現在正伏臥在地上，頗為悠閒自在。
C_LONG
        );        
        set( "unit", "只" );
        set( "race", "龍族");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,33,53 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "mountable", 1);
        set( "max_load",3000 );
        set_c_limbs(({"身體","頭部","前爪","後爪"}));
        set_c_verbs(({
            "%s用它的利爪向%s抓去",
            "%s伸出它那長滿利牙的嘴巴向%s咬去"
        }));
}
void init()
{
    mount::init();
}
int stop_attack()
{
   object king;
   if ( king=present("the king huang",environment()) ) {
      tell_room(environment(),"應龍招喚它的主人來攻擊它的敵人！\n\n");
      king->kill_ob(this_player());
   }
   return 0;
}
int do_mount(string arg)
{
   object king;
   
   if ( arg!="dragon" ) return ::do_mount(arg);
   if ( this_player()->query_temp("mounting") ) return ::do_mount(arg);
   if ( king=present("the king huang",environment()) ) {
     tell_room(environment(),sprintf("%s說道：想騎啊，先打敗我再說！！\n"
      ,king->query("c_name")));
     king->kill_ob(this_player());
   }
   else ::do_mount(arg);
   return 1;
}
