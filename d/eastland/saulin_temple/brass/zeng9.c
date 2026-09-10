#include <almuhara.h>
#define SLAB_FILE "/d/eastland/data/brassman.txt"

inherit ROOM;

void create()
{
        ::create();
        set_short( "銅人陣中" );
        set_long(
@C_LONG
你進入了一個寬廣的石室，這兒和前面幾間石室唯一不同的是，竟
然沒有銅人在這裡 !! 在你面前的是一個巨大的銅香爐(censer)，嫋嫋
的暗香在空間中浮動著，令人精神一振。你心想這其中必有古怪，還是
靜下心來好好想想吧....
C_LONG
        );

	set( "time",0);
        set( "light",1 );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        add( "item_desc", ([
        	"censer" :
"這是一個巨大的香爐，上面鑄著羅漢降龍伏虎之像。你忽然想到在
小時候的印象中，想過銅人陣好像要搬開(move)大香爐喔...\n"
	]) );
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
	add_action("do_songin","songin");
	add_action("do_move","move");
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

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"突然兩個紅衣羅漢自牆中暗門走出，將你抬了出去。\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("你看到兩個紅衣羅漢將%s像抬豬公一樣抬了出來。\n",
				obj->query("c_name") ) );
		this_object()->set("time",0);
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"突然兩個紅衣羅漢自牆中暗門走出，將你抬了出去。\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("你看到兩個紅衣羅漢將%s像抬豬公一樣抬了出來。\n",
			obj->query("c_name") ) );
		this_object()->set("time",0);
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_auction()
{
	return 1;
}

int do_songin()
{
	object obj;
	obj = this_player();
	if( !query_temp("alignment") ) {
		set_temp("alignment",obj->query("alignment"));
		return 0; }
	if( obj->query("alignment") > 10000 ) {
		this_object()->add("time",1);
		if( (int)this_object()->query("time") > (4+random(3)) ) {
			new("/d/eastland/saulin_temple/brass/obj/brassman6")->move(this_object());
			new("/d/eastland/saulin_temple/brass/obj/brassman7")->move(this_object());
			new("/d/eastland/saulin_temple/brass/obj/brassman8")->move(this_object());
			return 1; }
		return 0; }		
	else if( ((int)obj->query("alignment")-(int)query_temp("alignment")) > 500 ) {
		new("/d/eastland/saulin_temple/brass/obj/brassman6")->move(this_object());
		new("/d/eastland/saulin_temple/brass/obj/brassman7")->move(this_object());
		new("/d/eastland/saulin_temple/brass/obj/brassman8")->move(this_object());
		return 1; }
	else return 0;
}
	
int do_move(string str)
{
	object obj,ob1;
	string fame;
	seteuid(getuid());
	obj = this_player();
	
	if( !str || str == "" ) return 1;
	
	if( str == "censer" ) {
		if ( !obj->query_temp("be_k") ) {
			tell_object(obj,
				 "奇怪 !! 你怎樣都搬不動它耶。\n");
			return 1; }
		tell_object(obj,
			"你使勁去搬動香爐，忽然一陣大力將你向外送出去 !!\n" );
		announce(
set_color("\n突然從少林寺方向傳來陣陣鐘聲～～～\n"
"\n銅人陣長老慧元大聲喊道： 恭禧 "+obj->query("c_name")+" 順利通過十八銅人陣的\n"
"考驗 ！！\n\n","HIB") );
		this_object()->set("time",0);
		obj->set("18brass",1);
		obj->move_player(SAULIN"/entrance","SNEAK");
		fame = "     "+(string)this_player()->query("c_name")+"("+
		(string)this_player()->query("name")+")"+" 於 "+
		"/adm/daemons/weather_d"->query_c_game_time()+" 過陣 !!\n";
		write_file(SLAB_FILE, fame+"\n");
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("你看到%s大搖大擺的走了出來，一副很臭屁的樣子。\n",
			obj->query("c_name") ),obj );
		ob1->set("enter",0);
		reset();
		return 1; }
	return 1;
}
