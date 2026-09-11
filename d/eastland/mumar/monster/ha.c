#include "../mumar.h"
inherit MONSTER;
 
void create()
{
        object mark;
        ::create();
        set_level(16);
        set_name( "General ha", "牙將 哈將軍" );
        add ("id", ({ "general", "ha", }) );
        set_short( "牙將 哈將軍" );
        set_long(
    "牧馬關的兩位副將之一，哈將軍，他似乎被一團紅色的熱氣所籠罩。\n"
    "哈將軍現任牧馬關步兵團總指揮，管理所有士兵和守衛的調度和派遣。\n");
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
        "哈將軍對你「哈」的一聲。\n",
        "哈將軍忽然打個哈欠～，對你說道：「好睏～！」\n",
        "哈將軍全身氣孔散發著熱氣，狂笑地看著你。\n"
        }));
    set_skill("longblade",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
    set("tactic_func","fire_tactic");
    wield_weapon(OBJS"shadow_sword");
    equip_armor(OBJS"cloak01");
    equip_armor(OBJS"shield01");
 
    mark=new(OBJS"mark_a");
    mark->move(this_object());
}
 
int fire_tactic()
{
  object vvv;
  int dam;
 
  if ( !(vvv=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\n突然，哈將軍一陣狂笑，一陣懾人的火光藉著劍划向敵人。\n\n");
  dam=20 + random(10);
  vvv->receive_special_damage("fire",dam);
  return 1;
}
