#include "../mad.h"

inherit MONSTER;

void create()
{
   object key;

	::create();
   set_level(5);
   set_name( "poor scholar", "窮酸書生" );
   add( "id", ({ "scholar" }) );
   set_short( "窮酸書生" );
	set_long(
        "一個看起來落破窮酸的中年書生, 他正一個人在角落獨自飲茶.\n"
	);
   set( "gender", "male" );
	set( "race", "human" );
   set( "alignment", -50 );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 30 );
   set( "wealth/copper", 10 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "窮酸書生拿起茶壺斟了一杯茶, 然後一口飲盡.\n",
        "窮酸書生吟道: 吾家有女粗長成, 藏在深閨人不知;\n"
        "              可憐毛賊視茫茫, 莫名垂涎無鹽色.\n"
	}) );
   set( "inquiry", ([
        "daughter" : "唉..........\n",
     ]) );

   key = new( IANOBJ"key" );
   key->move(this_object());
}
