#include "../mumar.h"
inherit MONSTER;
 
void create()
{
        object ob1;
 
        ::create();
        set_level(4);
        set_name( "guard soldier", "警戒兵" );
        set_short( "警戒兵" );
        add( "id", ({ "guard","soldier" }) );
        set_long(
                "這是一個警戒兵，負責牧馬關的警戒安全。\n"
        );
        set( "gender", "male" );
        set( "alignment", 100 );
        set( "killer", 1 );
        set( "wealth/silver", 40 );
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 6 );
        set_natural_weapon( 4,1,3 );
        set_perm_stat( "str", 3 );
        set_perm_stat( "dex", 7 );
        set_skill( "parry", 30 );
 
        set( "moving",1 );
        set( "pursuing",1 );
        set( "speed",50 );
 
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
  "警戒兵大聲說著：「老兄，你有權保持緘默，我以擅入軍事重地為由逮捕你!!」。\n",
        }) );
 
        ob1 = new( OBJS"club" );
        ob1->move(this_object());
        wield_weapon(ob1);
}
