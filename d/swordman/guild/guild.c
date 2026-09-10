//#pragma save_binary

#include <mudlib.h>
inherit GUILD;

void create()
{
	object guild_master;

	::create();
	set_short("沖霄殿");
	set_long(@LONG
你現在來到一座宏偉的大廳，廳堂正中懸著一方巨匾，兩條黃金鑄成
的巨龍正盤在匾上，昂首凝視著懸在匾上的一把綠鞘古劍。大廳的四壁掛
滿了各式各樣的劍，或古樸或含煞，雖然都隱於鞘中，滿廳肅殺之氣卻不
可自抑。你抬頭看看巨匾，上頭題了四個大字「劍氣沖霄」。大廳左首牆
上嵌了一方白漢玉板(plate)，正靜靜地發出柔和光輝。
LONG
	);

	set("c_item_desc", ([
		"plate"	: @LONG
——————————————————————————————
白漢玉石板上刻著 :

	屠龍劍派三大戒 		凡我門下不可違

	輕犯者追回武功		重違者引劍自裁

	一戒欺師滅祖，殘殺同門。
	
	二戒結交奸邪，助紂為虐。
	
	三戒輕佻放浪，貪色採花。
	
其餘門規，詳閱入門劍譜心法。欲入我門者，請先 help swordman
以瞭解本派。
——————————————————————————————
LONG
	]) );

	set("exits", ([
		"down" : "/u/r/ruby/rooms/workroom",
	]) );

	set ("light", 1);
	guild_master = new("/d/swordman/guild/monsters/master");
	guild_master->move( this_object() );

	set( "pre_exit_func", ([
		"east" : "check_swordman" ]) );
	set( "no_monster", 1 );

	call_other("/d/swordman/guild/swordman_board", "???");

	set_guild( "swordman" );
	reset();
}

int clean_up() { return 0; }

int check_swordman()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="swordman" ) {
		write("對不起，只有本派同門才能進去。\n" );
		return 1;
	}
	return 0;
}

