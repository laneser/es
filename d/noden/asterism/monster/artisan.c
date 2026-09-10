#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Artisan Leo", "半身人工匠李歐" );
	add("id",({"artisan","halfling","leo"}) );
	set_short( "半身人工匠李歐" );
	set_long(
		"一個正在修理(fix)魔法物品的矮人工匠。\n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 600 );
	set( "time_to_heal", 8 );
        set("max_hp",500);
        set("hit_points",500);
	set_natural_armor( 80, 39 );
	set_natural_weapon( 60 , 30 , 48 );
	set_perm_stat( "str", 27 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "con", 35 ); 
        set_perm_stat( "kar", 30 );
        set("special_defense",(["all":40,"none":0]));
        set("aim_difficulty",(["critical":30,"weakest":30,
                               "vascular":30,"ganglion":30 ])) ;

        set_skill("dodge",65)    ;
        set_skill("unarmed",100) ;
	set( "wealth/gold", 100 );
	set( "inquiry" , ([ "fix":"@@fixing",]) ) ;

}

void init()
{
  add_action("fix_item","fix") ;
}

void fixing(object who)
{
  tell_object(who,"李歐說:是的，只要是本城的產品，我應該會修。\n") ;
}

int fix_item(string s)
{
     if( !s || s!="wand" )
        return notify_fail("李歐說: 修理什麼東西 ? 修理你嗎 ??\n" );
     write("修理費要三百個金幣,要修就把東西給我吧 !!\n" );
     return 1;
}

int accept_item(object me,object item)
{
	string name ;
	name = (string)item->query("name");
	if ( name != "Wand of Ultimate" ) {
		tell_object(me,"李歐搖搖頭 : 我不修理這種東西。\n");
		command("give "+name+" to "+(string)me->query("name"));
		return 1;
	} else
	if (!item->query("damaged"))	{
		tell_object(me,"李歐搖搖頭 : 這把杖並沒有壞。李歐把永恆之杖還給你。\n");
		item->move(me);
		return 1;
	} else
	if ((int)me->query("wealth/gold")< 300)	{
		tell_object(me,"李歐搖搖頭 : 你的錢不夠。李歐把永恆之杖還給你。\n");
		item->move(me);
		return 1;
	} else {
	tell_object(me,"李歐轉過頭，開始努力工作 !!\n");
	call_out("do_fix",4,me,item);
	return 1;
	}
}

int do_fix(object me,object wand)
{         
          me->add("wealth/gold",-300) ;                
          wand->set("short","永恆之杖") ;
          wand->set("weapon_class",40) ;
          wand->set("damaged",0) ;
          wand->set("min_damage",24);
          wand->set("max_damage",37);             
          write("李歐說: 修好了，這麼好的武器別再弄壞了。\n" );
		  command("give wand to "+(string)me->query("name"));
          return 1 ;
}


