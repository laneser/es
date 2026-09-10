#include "../iigima.h"

inherit ARMOR;

void create()
{
        set_name("Lucky plate","幸運鎧甲");
        add("id",({"plate"}) );
         set_short( "幸運鎧甲");
	set_long(@C_LONG
這是一件有刻有小刀圖紋的輕質鎧甲□黝黑而不能反光
的特性證明了這是屬於某些在黑夜中活動的人的裝備，
由於質地相當輕巧，你忍不住想穿看看。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 145 );
	set( "type", "body" );
	set( "material", "thief");
	set( "armor_class", 18 );
        set( "defense_bonus",0 );
	set( "value", ({ 330, "gold" }) );
        set( "equip_func","wield_plate" );
        set( "unequip_func","unwield_plate" );        
}

void wield_plate()
{
        string cla,him,bonus;
        object player,env;
        player=this_player();
        env=environment(player);
        him=player->query( "c_name" );
        cla=player->query( "class" );
         if( cla!="thief" ) {
                tell_object(player,"\n一股邪氣自鎧甲內發出，令你渾身不愉快。\n\n");
 tell_room(env,"\n\n你看到"+him+"古怪地皺了眉頭，扭動身體好像長了痔瘡....\n\n");
 }
        else{
tell_room(env,
   "\n\n你看見"+him+"穿上幸運鎧甲後，快樂的自顧自個兒跳著舞，好像有點秀鬥..\n\n",player);         
tell_object(player,
"\n\n忽然一股勇氣與愉快的感覺自你內心發出，令你不禁手足舞蹈一番\n\n");
                set( "armor_class",30 );
                set("defense_bonus","@@lucky_bonus");
         return ;
        }
        return ;
}
void unwield_plate()
{
        set( "armor_class",18 );
        delete( "defense_bonus" );
        return ;
}
int lucky_bonus()
{ 
   return 4 + random(4);
}     
