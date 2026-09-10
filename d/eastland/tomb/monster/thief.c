#include "../almuhara.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(5);
    set_name("Tomb Thief","盜墓賊");
    add ("id", ({ "thief"}) );
    set_short( "盜墓賊");
    set_long(
@C_LONG
一個盜墓賊，他正在找尋陵墓的入口。
C_LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "str", 10);
    set_perm_stat( "dex", 10);
	set_skill("dagger",40);
    set ("max_hp",150);
    set ("max_sp",0);
    set ("hit_points",150);
    set ("spell_points",0);
    set ("wealth", ([ "gold":10]) );
    set_natural_weapon(20,5,13);
    set_natural_armor(40,5);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output", ({
        "盜墓賊說道: 聽說地底廣場中央有機關可以找到陵墓之門.....\n",
        "盜墓賊說道: 聽說地底廣場中央有機關可以找到陵墓之門.....\n",
        "盜墓賊自言自語: 我一定要找到那顆寶珠。\n",
    	"盜墓賊邪笑著對你說道: 敢情閣下跟俺做的是同樣的無本生意 ??\n",
    	"盜墓賊抓抓他的頭，似乎在思考什麼。\n" }) );
    set("att_chat_output",({   
        "那賊喊道: 你不想活了，竟敢跟我搶地盤 ?\n"
       }) );
    set( "moving", 1 );
    set( "speed", 40 );
    set( "patrol", ({ "east", "east", "north", "north", "north", "east",
		"north", "north", "east", "east" }) );
    wield_weapon(WEAPONS"/dagger1");
}


