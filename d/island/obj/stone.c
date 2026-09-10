#include "../island.h"

inherit OBJECT;
int announce(object ppl);

void create()
{
	seteuid( getuid() );
	set_name( "peace stone", "和平紀念碑" );
	add( "id", ({ "stone" }) );
	set_short( "和平紀念碑" );
	set_long(@LONG
象徵和平的紀念碑，不過倒置的武器造型，讓你覺的相當有趣！
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
	string pname;

	env=environment(this_object());
	player=this_player();
	pname=player->query( "c_name" );

	if( !arg )
		return notify_fail( "你想做什麼！？\n" );

	if( arg != "Lizardman Holy Knight" )
		return notify_fail( "求誰啊？\n" );

	if( (int)player->query_level()<=5 )
		return notify_fail( "小小年紀，不要學做壞事！\n" );

	if( !(obj=present("lizardman holy knight",env)) )
		return notify_fail("你想求的人不在這兒啊！\n");

	if( (int)player->query_temp("jousting")==1 ) {
		if( (int)(obj->query("no_jousting"))==0 ) {
			obj1=new( IWEP"jousting" );
			obj1->move( player );
			obj->set("no_jousting",1);
			write("\n聖騎士將石碑拔起交給了你，咦？竟變成『創世神戟』了！\n\n");
			tell_room(env,set_color("\n你看到聖騎士伸出雙手用力地握住石碑，石碑的外殼立刻化為碎片；\n就在石碑碎掉的同時，一道耀眼的光芒由聖騎士手上發出，令你幾乎張不開眼睛。\n你好奇的往聖騎士雙手看去。咦，那不就是傳說中的『創世神戟』嗎？\n接著聖騎士便把戟交給了"+pname+"\n","HIY"),player );
		}
		else {
			player->set_temp("jousting",0);
			player->set_temp("holy_knight",0);
			write("\n聖騎士對你說：『抱歉，神戟早被取走了。』\n\n" );
		}
	}
	player->set_temp("jousting",0);
	player->set_temp("holy_knight",0);
	player->set( "talk_points",50 );
	announce(player);
	tell_room( environment(player),set_color(
	"\n聖騎士舉起手掌，輕輕在石碑上一拍，石碑就灰飛湮滅了。\n","HIR" ) );
	obj->leave();
	call_out("s_war",2);
	return 1;
}

void s_war()
{
	find_object_or_load(IWAR"islandwar")->start_war();
	remove();
}

int announce(object ppl)
{
	string class1,cname,name,cclass;
	object *usr;
	int i;

	usr=users();
	cname=ppl->query("c_name");
	name=ppl->query("name");
	class1=ppl->query("class");
	if (class1=="knight") { cclass="「騎士」";}
	else if (class1=="healer") { cclass="「行醫者」";}
	else if (class1=="scholar") { cclass="「書生」";}
	else if (class1=="monk") { cclass="「武僧」";}
	else if (class1=="mage") { cclass="「魔法師」";}
	else if (class1=="thief") { cclass="「小偷」";}
	else { cclass="某個";}

	for(i=sizeof(usr)-1;i>=0;i--) {
	tell_object(usr[i],set_color("遠方傳來"+cname+"("+name+")的吶喊 :","HIR")+"我要發動摘仙島戰爭了，為了 "+set_color(cclass,"HIW")+" 的名譽\n我總有一天會清完的，呵呵.....\n*"+cname+"對你露出神秘的笑容*\n");
	}
	return 1;
}
