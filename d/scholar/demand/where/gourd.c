#include <mudlib.h>

inherit OBJECT;

int filled = 0;
void create()
{
	set_name("broken gourd", "破掉的葫蘆瓢兒");
	add( "id", ({ "gourd" }) );
	set_short("破掉的葫蘆瓢兒" );
	set_long(
		"@@query_c_long"
	);
	set( "weight", 3 );
	filled = 0;
}

string query_c_long()
{
	if( filled )
		return "這個葫蘆瓢兒裝滿了清水。\n";
	else
		return @C_LONG
這個葫蘆瓢兒可以用來裝水。當然你可以用它來喝水，但是現在它好像是用來
給植物澆水(water) 用的，不管你要怎麼用，總得要先把它裝滿(fill)水吧! 
不過它底部裂了個小縫，恐怕撐不了多久。
C_LONG
		;
}

int query_filled() { return filled; }

void init()
{
	add_action( "fill_water", "fill" );
	add_action( "squirt_water", "water" );
}

int fill_water(string arg)
{
	object env;

	if( !arg || arg!="gourd" )
		return notify_fail("用什麼裝水？\n");
	if( filled )
		return notify_fail("葫蘆瓢兒中已經裝滿清水了。\n" );

	env = environment(this_object());
	if( living(env) ) env = environment(env);
	if( !env->query("water_source") )
		return notify_fail("這裡沒有水....。\n" );
	filled = 1;
	write("你把葫蘆瓢兒裝滿清水。\n");

	call_out("mess_up",180);
	return 1;
}

int squirt_water(string arg)
{

	if( !arg || arg!="herb" )
		return notify_fail("澆什麼？\n");

	if( !filled ) return notify_fail("葫蘆瓢兒是空的。\n" );

	filled = 0;

	if ((string)environment(this_player())->query("short") != "藥圃") 
		return notify_fail("你把葫蘆瓢中的水澆在身邊的地上。\n");


	if( this_player()->query_temp("herb_quest/step") ) {
	  write(
		"你把葫蘆瓢兒中的水澆在你種的回陽草上，它好像很振奮，看來你的移植\n"
		"成功了。你最好去跟天心大師報告(report)一下，他一定會很高興的!!\n\n");

	if( (int)this_player()->query_quest_level("Tenshin's herb") < 1 ){
		this_player()->finish_quest( "Tenshin's herb", 1 );
		write( set_color("[你完成了天心大師的任務，得到 1500 點經驗]\n","HIY"));
		this_player()->gain_experience(1500);
                if((string)this_player()->query("class")=="scholar") {
   write("你似乎聽到回陽草微弱的聲音，謝謝你把我救活，我會把你的義行轉告給\n掌管我們的草精靈，也許你會有需要它的地方。\n");
                   this_player()->set("demand/grass",1);
                }
	} else 
	    tell_object(this_player(),
	      "你又種活了一棵回陽草，天心大師一定會很高興的 !!\n");

	  this_player()->set_temp("herb_quest/step",0);
	}
	return 1;
}

void mess_up()
{
        object owner;

	if ( !filled ) return ; 
        owner = environment(this_object());
        if( living(owner) )
          tell_object( owner, "啊 ! 不知不覺中瓢中的水已經漏光了。\n" );
	filled=0;
}
