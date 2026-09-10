#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "gorden dreaming carp", "黃金夢幻鯉魚" );
        add ("id", ({ "fish","carp" }) );
        set_short( "黃金夢幻鯉魚");
        set("unit","尾");
        set_long(
           "    哇！多漂亮的一條鯉魚呀，黃金色的鱗片閃耀著炫目的光芒，這大概\n"
           "就是達婆婆口中所說的黃金夢幻鯉魚吧。\n"
        );
        set( "likefish",1);
        set( "unbleeding",1);
        set( "max_hp",300 );
        set( "hit_points",300 );
        set("alignment",200);
        set_perm_stat("str", 18);
        set_perm_stat("dex", 22);
        set_perm_stat("kar",15);
        set_natural_weapon( 30, 20, 35 );
        set_natural_armor( 50, 30 );
        set ("gender", "male");
        set_c_limbs(({"頭部","身體","尾鰭"}));
        set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TOBJ"sashimi");
   killer = query("last_attacker");
   if( !killer ) {
     ::die(1);
     return;
   }
   tell_room(environment(this_object()),
      "\n你的最後一擊終於打扁了這條不乖的鯉魚的頭，這世界上從此又少了一條\n"
      "夢幻黃金鯉魚了，為了紀念你釣上這種魚，於是你把它身上的肉割下來，做\n"
      "成了生魚片，並且順手把剩下的□體埋在附近的地上，焚香祭拜。\n",
      this_object());
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die(1);   
}
