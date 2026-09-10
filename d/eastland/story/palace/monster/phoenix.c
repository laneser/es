#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "Red phoenix","[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[m"  );
        add( "id", ({ "phoenix" }) );
        set_short( "[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[m" );
        set_long(@C_LONG
一隻顓頊養的寵物，全身火炭也似的鳳凰，全身羽毛毫無斑雜，俊美極了。這隻火
鳳凰正在剔翎刷毛，神情頗為自在。
C_LONG
        );        
        set( "unit", "只" );
        set( "race", "monster");
        set( "race","鳳鳥");
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
        set( "max_load", 2600 );
        set_c_limbs( ({ "鳳冠", "身體", "爪", "尾巴","翅膀" }) );
        set_c_verbs( ({ "%s抬起鳳爪, 往%s一抓", 
                        "%s用它的喙子往%s一啄"}) );
}
void init()
{
    mount::init();
}
int stop_attack()
{
   object king;
   if ( king=present("ra-shan",environment()) ) {
      tell_room(environment(),"火鳳凰招喚它的主人來攻擊它的敵人！\n\n");
      king->kill_ob(this_player());
   }
   return 0;
}
int do_mount(string arg)
{
   object king;
   
   if ( arg!="phoenix" ) return ::do_mount(arg);
   if ( this_player()->query_temp("mounting") ) return ::do_mount(arg);
   if ( king=present("ra-shan",environment()) ) {
     tell_room(environment(),sprintf("%s怒道：想偷我的鳳凰，門都沒有，看來我不好好教訓你，你是不知道偷竊是犯法的，給我死死去！！\n"
      ,king->query("c_name")));
     king->kill_ob(this_player());
   }
   else ::do_mount(arg);
   return 1;
}
