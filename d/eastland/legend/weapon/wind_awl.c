#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Wind awl","疾風破月錐");
    add("id", ({ "awl","wind awl" }) );
    set_short("疾風破月錐");
    set_long(@LONG
一把四寸長的金屬錐。相傳這種奇形兵刃是四川青城派的獨門兵器之一，叫作
破月錐，和雷公轟是青城派雙絕。你手上的這把破月錐通體湛藍，透出絲絲冷
氣，似乎隨時都會脫手飛向天際。
LONG
    );
    set( "unit", "把" );
    set( "weapon_class", 30 );
    set( "type","polearm" );
    set( "min_damage", 12 );
    set( "max_damage", 23 );
    set( "weight", 70 );
    set( "wield_func","weapon_wield");
    set( "unwield_func","weapon_unwield");
    set( "value", ({ 10, "gold" }) );
    set( "bleeding",15);
    set( "second", 1 );
}

void weapon_wield()
{
  object holder;
  int my_ali,holder_level;

  holder=environment(this_object());

  if (my_ali=(int)holder->query("war_score")>20000) {
    holder_level=(int)holder->query_level();
    set("min_damage", holder_level+1);
    set("max_damage", holder_level+19);
    set("weapon_class", (int)(holder->query_perm_skill("polearm")/2)-5);
    }
}

void weapon_unwield()
{
    set("min_damage", 12);
    set("max_damage", 23);
    set("weapon_class", 30);
}
