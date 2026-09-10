#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "shell", "千年老蚌" );
        add ("id", ({ "shell" }) );
        set_short( "千年老蚌");
        set("unit","個");
        set_long(
           "    你看到一個非常巨大的蚌，粗糙的外殼就如同石頭般堅硬，表面長滿\n"
           "了許多水生藻類，使你看不清原來的紋路，在兩片蚌殼的接縫處，隱隱透\n"
           "出一股淡淡的寶光。\n"
        );
        set( "likefish",1);
        set( "unbleeding",1);
        set( "max_hp",700 );
        set( "hit_points",500 );
        set("alignment",200);
        set_perm_stat("str", 28);
        set_perm_stat("dex", 25);
        set_perm_stat("kar",27);
        set_natural_weapon( 50, 30, 50 );
        set_natural_armor( 150, 65 );
        set ("gender", "male");
        set ("race", "monster");
        set_c_limbs(({"硬殼"}));
        set_c_verbs( ({"%s捲動整個湖水，一片漩渦猛然襲向%s","%s怪嗚數聲，一束極速沙石轟然砸向%s","%s打開蚌殼，一道寒光並出，射向%s","%s用硬殼緊緊夾住%s","%s用水管噴出一股強勁水流，打向%s"}));
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TOBJ"pearl");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      "\n你的最後一擊打破了這個堅硬的蚌殼，使你能夠看清楚蚌殼的內部\n\n\n\n"
      "你在蚌殼內發現到一個相當罕見的美麗珠子，正發出美麗的光芒，你看\n"
      "的合不攏嘴，馬上伸手進去把珠子掏出來。\n",
      this_object());
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}
