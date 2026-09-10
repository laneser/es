#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "topaz shield", "閃晶盾" );
        add( "id", ({ "shield" }) );
        set_short( "閃晶盾" );
        set_long(
        "你看到一塊碩大質純的酒黃寶石, 當你注視它時,\n"
        "彷佛看到如夕陽般美麗的景色。你是否想要擦(rub)\n"
        "去上面的灰塵, 以便看得清楚些?\n"
        );
        set("unit","塊");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([
               "fire" : -15, "cold": -15, "acid" : -15,
               "energy" : 12, "magic" : 12, "electric" : 12
          ]) );
        set( "weight", 100 );
        set( "value", ({ 2150, "silver" }) );
        set( "no_sale", 1 );
}

void init()
{
   add_action( "rub_shield", "rub" );
}

int rub_shield(string str)
{
   if( !str || !id(str) )
        return notify_fail( "你要摩擦什麼?\n" );
   if( (int)this_player()->query("spell_points")<50 )
        return notify_fail( "你的精神太差了, 無法有效摩擦盾牌。\n" );
   if( query("light") )
        return notify_fail( "它已經被摩擦過了。\n" );
   write( "你用力地摩擦盾牌, 盾牌逐漸地發出微弱的光芒。\n" );
   this_player()->add( "spell_points", -50 );
   set( "light", 1 );
   call_out( "run_out", 240 );
   return 1;
}

void run_out()
{
   object owner;

owner = environment(this_object());

   if( living(owner) )
   tell_object( owner, "閃晶盾的電光漸漸微弱...最後終於停止發光...\n" );
   set( "light", 0 );
}
