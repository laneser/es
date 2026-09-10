#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Ling Cheng", "天才火藥師 凌振" );
	add("id",({"ling","cheng"}));
	set_short( "天才火藥師 凌振" );
	set_long(
		"    凌振外號轟天雷，少年時遠赴默爾斯大陸學習火術爆藥，同時解\n"
		"決一大群敵人是他的專長。雖沒有過人的勇猛及出眾的武藝，但憑著\n"
	        "他的專長，也立下了無數汗馬功勞。\n"
	);
	set( "race", "elf" );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 19 );
	set_skill( "unarmed", 80 );
	set_skill( "dodge", 70 );
	set( "wealth/gold", 20 );
	set( "special_defense", (["magic": 20 ]) );
	set("tactic_func","special_attack");
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 10 );
        equip_armor( TARMOR"vest");
        equip_armor( TARMOR"one_hood");
}
void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
}
int special_attack()
{
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<4) return 0;
    tell_room( environment( this_object() ), 
      "\n天才火藥師凌振發出一陣狂笑，揚手丟出一捆炸藥，一聲驚天動地的巨響\n"
      "後，在場的人都受到嚴重的傷害，暫時失去攻擊能力。\n",
      this_object()
    );
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_damage(random(10)+5);
           inv[i]->block_attack(random(2)+1);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}
//void die()
//{  
//   object ob1,killer;
//   ob1 = new(TOBJ"bomb");
//   killer = query("last_attacker");
//   if( !killer ) {
//     ::die();
//     return;
//   }
//   tell_room(environment(this_object()),
//      "\n凌振叫道: 果然好武藝，吃我最後一顆炸彈吧，哈哈哈.....\n"
//      "凌振無力的把一顆炸彈丟向"+killer->query("c_name")+"，而後力竭倒地...\n",
//      this_object());
//   if( (int)(ob1->move(killer)) != MOVE_OK )
//		ob1->move(environment(this_object()));  
//   ::die();   
//}
