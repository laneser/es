#include "../layuter.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "thiris", "席理斯" );
        add ("id", ({ "thief", "daemon","thiris" }) );
        set_short( "席理斯" );
        set("unit","位");
        set_long(
           " 他是當惡魔入侵精靈村時被引入迷宮的殘存惡魔族人，是一位可惡的小偷。\n"
        );
        set("alignment",-1000);
        set("wealth/gold",20);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 30);
        set_perm_stat("kar",30);
        set_natural_weapon( 15, 10, 28 );
        set_natural_armor( 70, 20 );
        set ("gender", "male");
        set ("race", "daemon");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(LWEAPON"daemon_dagger");
        equip_armor(LARMOR"daemon_amulet");
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(LARMOR"statue");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room( environment(this_object()),
      "\n\n席理斯以微弱的聲音說道：在我以前做了許多的壞事，偷了非常多的東西\n"
      "最近我又利用迷宮因年久失修而產生的破洞，出去撈了好幾筆，其中有一個雕像我很喜歡\n"
      "，但是聽說它的原主人因為不見了它因而茶飯不思，我很過意不去，希望你能幫我還給他\n"
      "，這是我臨終的遺言，希望你幫我完成。\n\n"
      "你見他從床底下拿出一個雕像給你。\n"
      "當他說完此段話, 你便見他兩腿一伸回姥姥家了。\n" );
   ob1->set("killer",(string)killer->query("name"));
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}
