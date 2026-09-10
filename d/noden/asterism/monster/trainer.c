#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "dwarf trainer", "矮人訓練師" );
	add("id",({"trainer","dwarf"}) );
	set_short( "矮人訓練師" );
	set_long(
		"一個矮人族的獅鷲獸訓練師.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 56, 22 );
	set_natural_weapon( 22 , 15 , 20 );
	set("max_hp",500);
	set("hit_points",500);
	set_perm_stat( "str", 24 );
        set_perm_stat( "dex", 24 );	
	set_skill( "parry",80 );
	set_skill( "dodge",80 );       
        set_skill( "whip",80 );              

	set( "wealth/gold", 3 );
	set( "special_defense", ([ "all": 12 ]) );
	wield_weapon(WEAPONS"short_whip");
	equip_armor(ARMORS"leggings02");
	set("echo_asterism",1);
        set( "tactic_func", "cast_help" ); 
}

void init()
{
     add_action("block_mount","mount") ;
}

int block_mount(string ob)
{
     object mob ;
     if( ob != "griffon") return 0 ;
            
     if( !(mob = present(ob))) return 0 ;
                      
     if(mob->query("is_griffon"))
       {
         write("訓練師擋在你身前瞪著你,不讓你向獅鷲獸靠近。\n") ;

         tell_room(environment(this_object()),
               "訓練師擋在"+this_player()->query("c_name")+
               "身前瞪著他,不讓他向獅鷲獸靠近。\n"
               ,this_player() ) ;
         return 1 ;
       }      
     else return 0 ;      
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard;
    int i;
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()),
             sprintf("馴獸師哨聲一吹, 獅鷲獸向%s撲了過去。\n",
                   victim->query("c_name")),({ guard[i],victim })
               );
      tell_object(victim,"馴獸師哨聲一吹, 獅鷲獸向你撲了過來。\n");
      guard[i]->kill_ob(victim);
    }
     return 0;
}

