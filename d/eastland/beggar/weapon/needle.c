#include <mudlib.h>
inherit WEAPON;

#define NEED_ALIGNMENT 6000

void create()
{
    set_name("small dagger","小小銀針");
    add("id",({"dagger","needle"}) );
    set_short("小小銀針");
    set_long(@C_LONG
小小銀針是『一代神醫 小雪子』拿來治療病患用的。它通體純白,既輕且薄,兩端
極其鋒利,對於用來針炙、治病是再好不過了。相傳小小銀針是由六六三十六個鐵
匠,經由七七四十九天以精火練制而成,雖然所花費的工程浩大,不過和被它活命的
人數來比,卻也是值得的。 
C_LONG
       );
    set("unit","把");
    setup_weapon( "dagger", 40, 1, 1 );
    set("weight",40);
    set("value",({150,"gold"}));
    set( "wield_func","wield_dagger");
    set( "unwield_func","unwield_dagger");
}

int stop_wield()
{
     object holder;
     int my_ali;
         holder = this_player();
         my_ali = (int)holder->query("alignment");
         if (my_ali > NEED_ALIGNMENT )
            return 0;
         else {
               notify_fail(
                   "你還不夠善良使得小小銀針不聽你的指揮，令你握不住它。\n\n"
                                                  );
               return 1; 
          }
}

int wield_dagger()
{
   int my_int;
   
   my_int=this_player()->query_perm_stat("int");
   set( "min_damage",my_int);
   set( "max_damage",my_int+10);
     return 1;
}
                  
int unwield_dagger()
{
   set( "min_damage",1);
   set( "max_damage",1);
     return 1;
}
