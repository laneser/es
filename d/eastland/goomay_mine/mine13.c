
#include "zeus.h"

inherit ROOM;

void create()
{
	::create();
	set_short("水流上游");
	set_long(@CLong
這是一個不大的地方，有一點像小型的港口，想必又是一個運送貨物的
地點，鐵軌到了這兒又是一個終點．這裡似乎瀰漫著一股血腥的氣息，一陣
陣肅殺的氣氛令人不寒而慄，南方是一條湍急的水流(river) ，如果想通過
它，沒有十分高超的游泳技術是不行的．
CLong
);
set("item_desc",(["river":
"這是一條流速非常快的河流，河對面不知是什麼地方，也許可以過去看看．．\n"
	]) ); 

set("exits",([ "north":ZROOM"/mine12"
	]));

reset();
}
void init()
{
add_action("do_pass","pass");
}
int do_pass(string str){
 	int skills;
	skills = (int)this_player()->query_skill("swimming");
	if(!str||str!="river"){
	write("你想通過什麼?\n");
	return 1;
		}
	if ( random(skills) < 40 && skills < 40){
	write("\n你很想游過去，但是很不幸的被水給沖走了．．．\n");
	tell_room(environment(this_player()),(
	"你看到"+this_player()->query("c_name")+"很帥氣的跳進水中，不過卻邊遊邊喊救命！\n")
	,this_player());
	this_player()->move_player(ZROOM"/port.c","SNEAK");
	return 1;
	}
	if (random(skills) < 40  && skills >40 ){
	write("\n你很努力的往前遊，但是被水給衝回來了．．．\n");
	tell_room(environment(this_player()),(
	"你看到"+this_player()->query("c_name")+"以一種可笑的姿勢，慢慢的遊了回來．\n")
	,this_player() 
	              );
	return 1;
	}
	write("你憑藉著高超的泳技，克服洶湧的浪濤抵達彼岸！！\n");
	tell_room(environment(this_player()),(
	"你看到"+this_player()->query("c_name")+"很辛苦地游到了對岸！！\n")
	,this_player());
	this_player()->move_player(ZROOM"/store_room.c","SNEAK");
	return 1;
}