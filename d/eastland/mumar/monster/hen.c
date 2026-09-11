#include "../mumar.h"
inherit MONSTER;
 
void create()
{
        object mark;
        ::create();
        set_level(16);
        set_name( "General hen", "牙將 哼將軍" );
        add ("id", ({ "general", "hen", }) );
        set_short( "牙將 哼將軍" );
        set_long(
    "牧馬關的兩位副將之一，哼將軍，他全身散發出一陣寒氣。\n"
    "哼將軍現任牧馬關騎兵團總指揮，所有騎兵和馬匹的調度，都是由他負責。\n");
 
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "個" );
    set_perm_stat( "str", 20 );
    set_perm_stat( "dex", 15 );
    set_perm_stat( "int", 10 );
    set ("wealth", ([ "gold": 30 ]) );
    set_natural_weapon(10,10,20);
    set_natural_armor(72,35);
    set ("weight", 300);
    set ("aim_difficulty",([ "critical":30,"vascular":25]) );
    set ("chat_chance", 5);
    set("chat_output",({
        "哼將軍對你「哼」的一聲。\n",
        "哼將軍忽然打個噴嚏～，對你說道：「好冷～！」\n",
        "哼將軍全身氣孔散發著寒氣，冷笑地看著你。\n"
        }));
    set_skill("longblade",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
    set("tactic_func","cold_tactic");
    wield_weapon(OBJS"shining_blade");
    equip_armor(OBJS"cloak02");
    equip_armor(OBJS"shield02");
 
    mark=new(OBJS"mark_c");
    mark->move(this_object());
}
 
int cold_tactic()
{
  object vvv;
  int dam;
 
  if ( !(vvv=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\n突然，哼將軍全身骨骼暴響，一道逼人的寒氣藉著劍划向敵人。\n\n");
  dam=20 + random(10);
  vvv->receive_special_damage("sleet",dam);
  return 1;
}
