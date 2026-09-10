#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "black camisole","黑色緊身衣" );
        add( "id", ({ "black camisole","camisole" }) );
        set_short( "黑色緊身衣" );
        set_long(
 "一套黑色的緊身衣，看來給身裁曼妙的女賊穿是最適合不過的了。\n"
        );
        set( "unit", "領" );
        set("material","thief");
        set( "type", "body" );
	set( "armor_class", 33 );
	set( "defense_bonus", 5 );
        set( "weight", 90 );
        set( "value", ({ 1500, "silver" }) );
	set( "extra_skills", ([ "backstab" :10 , "sneak" :-15 ]) );
        set( "special_defense",(["evil":10,   "fire":-15,]));

}

int stop_equip()
{	
        if ((string)this_player()->query("gender") != "female")
        {
                tell_object(this_player(),@LONG
你拼命想要穿上這件剪裁精美的緊身衣，卻發現自己該凸的地方不凸，
該凹的地方不凹，穿起來有夠難看，一氣之下就把衣服給撕爛了。
LONG
                );
        call_out( "tear_cloth", 2 );
        return 1;
        }
      return 0;
}

void tear_cloth()
{
   this_object()->remove();
}
