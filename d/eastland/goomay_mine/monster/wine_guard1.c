#include "../zeus.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name("paradise guard", "守衛騎士");
	add( "id", ({ "guard" }) );
	set_short("酒境守衛");
	set_long(@AA
這個守衛是段家特地從巨人國所請來的武士，雖然在他的武功不是頂尖的
但是忠誠的信念卻是無人可比的．他的眼光緊緊地盯著鐵門，不讓任何一
個人偷偷溜進去．
AA
);
	set_perm_stat("str", 27);
	set_perm_stat("int", 20);
	set_perm_stat("dex", 22);
	set_perm_stat("kar", 20);
	set_skill("blunt", 100);
	set_skill("parry", 100);
	set( "hit_points", 500 );
	set( "max_hp", 500 );
	set( "alignment", 100 );

	set( "gender", "male" );
	set( "race", "troll" );
	set_natural_armor( 50, 20 );
	set_natural_weapon( 20, 10, 20 );
	set( "class", "knight" );
	set( "special_defense", ([ "all": 25 ]) );

	wield_weapon( ZOBJ"/black_staff" );

	equip_armor( ZOBJ"/black_plate" );
	equip_armor( ZOBJ"/black_leggings" );
}
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE

你發覺守衛騎士藏在腰帶中的一把鑰匙，掉了出來．

DIE
,this_object());
   ::die(1);
   obj=new(ZOBJ"/wine_key");
    obj->move(this_object());
   }