#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("black cloth","黑色緊身衣");
        add("id",({"cloth"}) );
        set_short("黑色緊身衣");
	set_long(@C_LONG
這是一件黑色的衣服,雖然穿起來很緊, 卻有利於行動。尤其是對於某些特殊的行
業,行動能更敏捷往往是玫勝的因素。 
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","thief");
	set( "armor_class", 15 );
	set("special_defense",
	     (["evil":15,"divine":-20]) );
	set( "value", ({ 1480, "silver" }) );
}
