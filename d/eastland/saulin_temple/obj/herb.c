#include <mudlib.h>

inherit OBJECT;

void create()
{
	set("packked",0);
	set_name( "Herb of re-live", "回陽草" );
	add( "id", ({ "herb" }) );
	set_short( "回陽草" );
	set_long(@C_LONG
這是一株回陽草，它現在被挖離泥土了，所以顯得有些枯萎，你最
好趕快把它包好(pack)、種(plant)回去，再澆(water)些水。
C_LONG
	);
	set( "unit", "株" );
	set( "weight", 5 );
	set( "packked", 0 );
	set( "value", ({ 1, "copper" }) );
//	set( "no_sale", 1 );
	set( "useless", 1 );
}

void init()
{
	add_action( "do_plant", "plant" );
	add_action( "do_pack", "pack" );
	call_out( "mess_up", 30, this_object(), 1 );
}

int do_pack(string arg)
{
    if( !arg || arg!="herb" )
    	return notify_fail( can_read_chinese() ?
    		"包什麼？\n" : "pack what?\n"
    	);
    if( query("packked") )
    	return notify_fail( "這株回陽草已經包過了。\n");
    tell_object(this_player(),
     	"你仔細的把回陽草連土包好，看來它可以維持長一點的時間。\n"
    );
	set("packked", 1);
    return 1;
}

int do_plant(string arg)
{
	object obj;

	obj=environment( this_player() );
   	if( !arg || arg != "herb" )
    	return notify_fail("種什麼？\n");
	if( (string)obj->query("short")=="藥圃" ) {
	  if( query("packked") ) {
        tell_object(this_player(),
                    "你把回陽草種在藥圃上，可是它還是垂頭喪氣的。\n"
		);
		this_player()->set_temp("herb_quest/step",1);
	  } else
        tell_object(this_player(),
            "由於你沒有把回陽草包好，它已經七零八落的活不成了，你只好把它丟了。\n"
        );
      remove();
	} else
       tell_object(this_player(),
         "你要把回陽草種在這裡？你確定？\n"
       );
    return 1;
}

void mess_up(object what, int first)
{
    object owner;
    
    owner = environment(what);
    if( what->query("packked") && first ) {
    	call_out( "mess_up", 100, what, !first );
    	return;
    }
    if( living(owner) )
      tell_object( owner,  
		"啊! 回陽草枯了，你只好把它扔了。\n" 
      );
    what->remove();
}
