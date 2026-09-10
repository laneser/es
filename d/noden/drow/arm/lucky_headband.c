#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky headband", "幸運頭巾");
   add( "id", ({ "headband" }) );
        set_short( "幸運頭巾" );
        set_long(
@C_LONG
這是張乳白色的頭巾，在扎發的尾端織有小刀的標記，看起來大方
而自然，可能也是畢老爹遺失的東西吧！
C_LONG
        );
        set( "unit", "條");
        set( "type", "head" );
        set( "material", "cloth" );
        set( "armor_class", 2 );
   set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "poison": 5, "fire": 10, "cold" : -15 ]) );
        set( "weight", 30 );
        set( "value", ({ 1960, "silver" }) );
   set( "no_sale", 1 );
        set( "equip_func","equip_headband" );
        set( "unequip_func","unequip_headband" );
}

void equip_headband()
{
        string cla,him;
        him=this_player()->query( "c_name" );
        cla=this_player()->query( "class" );
        if( cla!="thief" )
        {
         tell_object(this_player(),"\n只有小偷才能引發它的幸運魔力啦！\n\n");
         tell_room(environment(this_player()),
         "\n你看到"+him+"戴上幸運頭巾後，像乩童般的跳起舞來，還流一地口水，天啊。\n\n",this_player());
        }
        else
        {
         tell_room(environment(this_player()),"\n你看見"+him+"戴上幸運頭巾後，舉起手作Ｖ手勢，神經！\n\n"
         ,this_player());
         tell_object(this_player(),"\n你戴上頭巾後，感覺精神一震！似乎幸運女神就在你身邊！\n\n"
         );    
   set( "armor_class", 6 );
   set("material","thief");
   set( "defense_bonus", 5 );
        }
        return ;
}

void unequip_headband()
{
        set( "armor_class",2 );
   set( "defense_bonus", 2 );
        return ;
}
                                                                                                
