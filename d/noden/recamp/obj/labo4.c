#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("den bo", "電擊棒");
  add("id", ({"den","bo","den bo"}) );
  set_short("den bo","電擊棒");
  set_long(
   "一把電擊棒，當心被電暈了。\n"
  );
  set( "unit", "把" );
  set( "weapon_class", 35 );
  set( "type","bo");
  set( "min_damage", 15 );
  set( "max_damage", 25 );
  set( "weight", 100 );
  set( "value", ({ 1000, "silver" }) );
}
