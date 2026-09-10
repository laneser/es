#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("Sky eye", "蒼天之眼");
        add( "id", ({ "eye","sky" }) );
        set_short("蒼天之眼");
        set_long(@C_LONG
你看到一個像眼珠的東西，散發出一片淡藍色祥和溫暖的光茫。 
這相傳是地藏王菩薩看見邪惡橫行，眾生慘遭屠害，由它的嘆息所幻化成的。 
它的防護力並不高，但相傳戴上它後便具有看清虛幻不實物品之能力。 
C_LONG
                   );
        set("unit","顆");
        set( "type", "head" );
        set( "material", "wood");
        set( "armor_class", 1 );
        set( "defense_bonus", 2 );
	set( "equip_func", "angel" );
	set( "unequip_func", "ruby" );
        set( "special_defense",
               ([ "fire":1, "cold":1, "electric":1 ]) );
        set( "weight", 10 );
        set( "value", ({ 10, "gold" }) );
} 

void angel()
{
int ali; 
object holder;

 holder = environment(this_object());
 ali=(int)holder->query("alignment");
 if (ali < 1500) {

     tell_object( holder, 
     "\n\n眼珠突然射出一陣光芒，它似乎不願臣服於你，蹦的一聲掉在地上... 
   \n"); 
        this_object()->move(environment(environment(this_object())) );
                   }
       else {

    tell_object( holder, 
 "\n『萬能的天神，賜給這位善良的人看清虛幻不實物體的力量吧!!!』
『但是別忘了，要為正義和公理加油啊!』眼球散發出天藍色的光輝\n"
     ); 
	holder->set_temp("detect_invi",1);
            }   
}

void ruby()
{
object holder;

 holder = environment(this_object());


    tell_object( holder, 
 "\n
『別忘了，還是要為正義和公理加油啊!』眼球恢復成原本的淡藍色\n"
     ); 
	holder->set_temp("detect_invi",0);
}

