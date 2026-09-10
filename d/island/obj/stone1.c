#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name( "peace stone", "和平紀念碑" );
	add( "id", ({ "stone" }) );
	set_short( "和平紀念碑" );
	set_long(@LONG
代表和平的紀念碑，不過倒置的武器造型，讓你覺的相當有趣！
LONG
	);
	set( "unit", "座" );
	set( "prevent_get",1 );
}

void init()
{ 
	add_action( "do_beg", "beg" ); 
}

int do_beg(string arg)
{
	object obj,obj1,env,player;
	int i;
	string pname;

	env=environment(this_object());
	player=this_player();
	pname=player->query( "c_name" );

	if( !arg )
		return notify_fail( "你想做什麼！？\n" );

	if( arg == "holy_knight" )
	{
	if( (int)player->query_level()<=3 )
		return notify_fail( "小小年紀，不要學做壞事！\n" );
		
	else
	{
	  if( !(obj=present("lizardman holy knight",env)) )
		return notify_fail("人不在這兒啊！\n");
	  	
	    if( (int)player->query_temp("jousting")==1 )
	    {
	      if( (int)(obj->query("no_jousting"))==0 )
	      {
//		obj1=new( IWEP"jousting" );
//		obj1->move( player );
		i=player->query( "max_tp" );
		player->set( "talk_points",i );
		player->force_me( "shout 對不起，我不小心把戰爭發動了～～～" );
		obj->set("no_jousting",1);
		write("\n聖騎士將石碑拔起交給了你，咦？竟變成創世神戟了！\n\n");
		tell_room(env,set_color(
		"\n你看到聖騎士伸出雙手用力地握住石碑，石碑的外殼立刻化為碎片；\n"+
		"就在石碑碎掉的同時，一道耀眼的光芒由聖騎士手上發出，令你幾乎張不開眼睛。\n"+
		"你好奇的往聖騎士雙手看去。咦，那不就是傳說中的『創世神戟』嗎？\n\n"+
		"接著聖騎士便把戟交給了"+pname+"\n","HIY"),player );
//		obj->command("go up");
		call_out("s_war",2);
		return 1;
		}
		
              else
              return notify_fail( "\n聖騎士對你說：『抱歉，神戟早被ㄎㄧㄤ走了。』\n\n" ); 
              }
              
          i=(int)( player->query("max_tp") );
	  player->set( "talk_points",i );
	  player->force_me( "shout 我要發動謫仙島三族戰爭羅！各路英雄好漢和戰爭狂快快會和吧！ " );
	  tell_room( environment(player),set_color( 
	  "\n聖騎士舉起手掌，輕輕在石碑上一拍，石碑就灰飛湮滅了\n","HIR" ) );
	  obj->leave();
	  call_out("s_war",2);
	  return 1;
	  }
	}
	else
	{
	write("求誰啊？\n");
	return 1;
	}
}

void s_war()
{
	find_object_or_load("/open/odin/island/war/islandwar")->start_war();
	remove();
}
