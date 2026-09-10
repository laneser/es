#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black swallaw-tail coat", "黑色燕尾服" );
	add( "id", ({ "coat" }) );
	set_short( "黑色燕尾服" );
	set_long( @LONG
這是件相當帥氣的禮服, 男士們在正式的場合大多穿著這樣的衣服。
以禮服來說, 這件衣服的料子還不錯, 剪裁也相當用心。
LONG
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 18 );
	set( "weight", 30 );
	set( "value", ({ 500, "silver" }) );
}
