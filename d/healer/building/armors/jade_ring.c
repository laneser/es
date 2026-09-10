#include <mudlib.h>
#include <conditions.h>

inherit ARMOR;

int wielded;
object player;

void create()
{
        wielded=0;
        seteuid(getuid());
	set_name( "jade ring", "寒玉戒指" );
	add( "id", ({ "ring", "xyz", }) );
	set_short( "jade ring", "寒玉戒指");
	set_long( "這是由萬年寒玉製成的戒指, 表面散發出陣陣的寒氣。\n"
	);
	set( "unit", "個" );
	set( "weight", 10 );
	set( "type", "finger" );
        set( "material", "element" );
	set( "defense_bonus", 3 );
	set( "no_sale", 1);
	set( "value", ({ 1800, "silver" }) );
	set( "equip_func", "heal_sp" );
	set( "unequip_func", "stop_heal_sp" );
}

void effect()
{
  int sp;
  int max_sp;
  int hp;
    
  if (wielded!=1) return;
  if ( ((int) player->query("npc")) == 1 ) return;
    
  tell_object( player, 
               set_color("從戒指上傳來一陣寒氣使你頭腦略為清醒, 但同時也使你受了點寒毒。\n","HIC"),
              );
  sp = player->query("spell_points");
  hp = player->query("hit_points");
  max_sp = player->query("max_sp");
  sp = sp + 4; 
  if ( sp > max_sp ) sp = max_sp;
  player->set("spell_points",sp);
  ("/std/conditions/simple_poison")->apply_effect(player,12,1);
  if (hp<80) {
    tell_object( player,
                 set_color("你覺得身體狀況不是很好, 決定將寒玉戒指取下, 以測安全。\n","HIY"),
               ) ;
    this_object()->unequip();
    return;                 
  }
  call_out("effect",10);

}         

void heal_sp()
{
    wielded=1;
    player=this_player();
    call_out("effect", 10);
}

void stop_heal_sp()
{
   wielded=0;
   remove_call_out("effect");
}

