#include "/d/eastland/beggar/dony.h"

inherit MONSTER;
void create()
{
        ::create();
        set_level(17);
        set_name( "master Wu","吳大海" );
        add ( "id", ({ "master","wu"}) );
        set_short("四大長老之 吳大海" );
        set("unit","位");
        set_long(@C_LONG
吳大海生得孔武有力,高大的身材,一雙粗壯的臂膀看起來就讓人畏懼三分。 吳
大海現今位居四大長老其中的一位,平時好喝酒為人豪爽是個直性子的人。他天
生又愛打抱不平,急公好義,同時也是幫主震八方最親密的好友。 吳大海現在正
在跟幫主討論一些機密事情。
C_LONG
        );
        set("weight",920);
        set("alignment",100);
        set("gender","male");
        set("race","lizardman");
        set("hit_points",700);
        set("max_hp",700);
        set_perm_stat("str",25);
        set_perm_stat("dex",23);
        set_natural_weapon(10, 5, 10);
        set_natural_armor(81,39);
        set( "special_defense", ([ "all": 40, "none": 45 ]) );
        set_skill("parry",60);
        set_skill("block",60);
        set_skill( "axe", 90 );
        equip_armor(DARMOR"silver_tail");
        equip_armor(DARMOR"dragon_shield");
        wield_weapon( DWEAPON"silver_axe" );
        set( "inquiry", ([
                    "war":"@@ask_war",
                   "talk":"@@ask_talk",       
                 "secret":"@@ask_secret"
            ]) );
        set("tactic_func","my_attack");
}
void ask_talk()
{
write(@C_LONG
吳大海說道:去去去,小孩子不要問大人的事情。
C_LONG
     );
}
void ask_war()
{
write(@C_LONG
吳大海面有難色似乎不太想說。
C_LONG
     );
}
void ask_secret()
{
    if ( !this_player()->query_temp("jail_asked") )
       tell_object(this_player(),"吳大海說道:去去去,小孩子不要隨便亂問。\n");
    else {
       this_player()->set_temp("wu_asked",1);
       tell_object(this_player(),"吳大海說道:嗯,最好帶幫主的手諭去。\n");
    }    
}
void die()
{
   object killer;
   string str,name;
   if ( killer=query("last_attacker") )
     name=killer->query("name");
   str="\n  "+ctime(time())+" 吳大海 killed at "+
      file_name(environment(this_player()))+" by "+name+"\n";
   write_file("/open/dony/deathlist",str);
   ::die();
}