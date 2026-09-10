#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

 void create()
{
        ::create();
        set_level(18);
        set_name("mad snake","猛暴海蛇");
        add("id",({"snake"})); 
        set_short("猛暴海蛇");
	set_long(@C_LONG
猛暴海蛇－通常，海蛇的毒性一般要遠遠超過陸蛇
的一百倍上以上，這條眼露青光的海蛇正在水中游
走著，亮麗的黃－黑相間的條紋正要說明它那兇殘
並且擁有令人致命的毒性。
C_LONG
        );
        set( "unit", "條" );
	set( "alignment", -1500 );
         set( "max_hp", 500 );
          set( "hit_points", 500 );
   set_perm_stat( "dex", 30 );
	set("likefish",1);
        set( "natural_weapon_class1", 46 );
        set( "natural_min_damage1", 24 );
        set( "natural_max_damage1", 38 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "頭部", "閃亮的身體", "美麗的尾巴" }) );
        set_c_verbs( ({ "%s迴游旋繞，向%s優柔地環曲咬下" }) );
   set( "killer", 1 );
}
int emit_poison()
{
        object victim;

        if( random(15)>6 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "猛暴海蛇迴游到你身邊，優雅地咬向你，一陣松麻傳來\n", 
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
5, 36 );
        return 1;
}       
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE

猛暴海蛇捲曲扭動，口中翻出一個手鐲，吐了口氣，回姥姥家了!

DIE
,this_object());
   obj=new("/d/noden/drow/arm/lucky_bracers");
    obj->move(this_object());
   ::die(1);
   }


