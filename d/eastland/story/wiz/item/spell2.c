#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set("short", "@@query_short");
	set("long", "@@query_long");
 	set_name( "wonderful-spell", "萬相俱滅術" );
        add("id",({"wonderful"}));
	set( "unit", "張" );
	set("weight", 10);
	set("value", ({ 5, "silver" }));
	set("fuel", 3600); 
}


void init()
{
	add_action("cast_me", "cast-me");
	add_action("uncast_me", "uncast-me");
}

int cast_me(string arg)
{
     object player;
     player=environment();
     if ( !living(player) )
	 return notify_fail("請撿起來再施為。\n");
     if ( !arg || arg!="wonderful" ) 
	 return notify_fail("Syntax <cast-me wonderful>\n");
     if( query("wonderful_used") ) 
	 return notify_fail( "這萬相俱滅術正在施展中\n");
     if( player->query_temp("wonderful_spell") )
         return notify_fail("你己經施展萬相俱滅術了。\n");         
     write("你開始施展萬相俱滅術試著把自己變成一顆塵埃。\n");
     set("wonderful_used", 1);
     set("prevent_get",1);
     set("prevent_drop",1);
     set("prevent_insert",1);
     player->set_temp("wonderful_spell",1);
     call_out("burn_out",query("fuel"));
     return 1;
}

int uncast_me(string arg)
{
     object player;
     player=environment();
     if ( !living(player) )
         return notify_fail("請撿起來再施為。\n");
     if ( !arg || arg!="wonderful" )
             return notify_fail("Syntax <uncast-me wonderful>\n");
     if( !query("wonderful_used") )
	 return notify_fail( "這萬相俱滅術還未施展那來的終止？\n");
	                 
     write("你暫時先終止萬相俱滅術的施展，變回原來的模樣。\n");
     set("wonderful_used", 0);
     set("prevent_get",0);
     set("prevent_drop",0);
     set("prevent_insert",0);
     player->delete_temp("wonderful_spell");
     set("fuel", remove_call_out("burn_out"));
     return 1;
}
void burn_out()
{
     object owner;

     owner = environment(); 
     if( living(owner) )
        tell_object( owner,"萬相俱滅術的能源已經耗盡了．．\n");
     owner->delete_temp("wonderful_spell");
     this_object()->remove();
}
string query_short()
{
     if(query("fuel"))
        return sprintf("萬象俱滅術%s", (query("wonderful_used") ? " (使用中)" : "") );
}

string query_long()
{
     if(query("fuel"))
	return (@LONG
萬相俱滅術是金石老人多年研究有形無形等物質的心得而來的。萬相俱滅術在於隱
藏自已的形蹤變成空氣中的塵埃，並在空間放著一個自己的法相用以欺騙敵人，以
達到保護自已的功用。不過，由於研究的不完全，所以只能對某些特定的怪物而使
用。使用時，你只要　(　cast-me wonderful　)　就可以了，不過請切記，這術
有使用的時效，如果想變回只需　( uncast-me wonderful )　就可以了。據金石
老人的估計，全部有半個時辰的時效。
LONG
     );
}
