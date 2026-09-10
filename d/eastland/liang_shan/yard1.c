#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "庭院" );
	set_long(
	"這是一個小小的庭院，安靜而且典雅，濃蔭如傘，木葉之外有蟬聲搖曳，\n"
	"卻顯得天地更為寂靜，紅塵中的喧鬧煩囂，似已久未入庭院。北邊有一間小小\n"
	"的建築，東邊是一片山壁，你注意到一個洞穴，似乎有人經常出入的樣子。從\n"
	"山壁上，垂下一條繩梯(rope)，好像可以爬上去的樣子。\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set("c_item_desc",(["rope":
"這是一條老舊的黃色粗繩，看起來似乎有些歷史的樣子，你拉了拉繩子，似乎還\n"
"算堅固，也許你可以用它爬到山頂上看看風景\n"            
            ]));        
        set( "exits", ([
                "north"  : TROOM"bed5",
                "cave" : TROOM"cave5",
                "west" : TROOM"path6",
        ]) );
        reset();
}
void init()
{
     add_action("do_climb","climb");
}
int do_climb(string arg)
{
 if ( !arg || arg != "rope")
    return notify_fail(
    "哇，好強的徒手攀巖?\n");
    write (
    "你用力一跳，抓住了繩梯，試著慢慢的爬上山去。\n");
    tell_room(this_object(),
	"你看到"+this_player()->query("c_name")+"抓住繩索, 用笨拙的姿勢往上爬去....\n",
    this_player());
 if ( (int)this_player()->query_skill("climbing")<50+random(8) ) {
    write (
       "你一個不小心，手一滑，一下子從山上摔到地面.....\n");
       this_player()->receive_special_damage("none",20);
       tell_room(this_object(),
	"你看到"+this_player()->query("c_name")+"一個不小心, 從繩子上摔下來, 摔的頭破血流..\n",
       this_player());
       return 1;
       }
 this_player()->move_player("/d/eastland/liang_shan/cannon","SNEAK");
 tell_room("/d/eastland/liang_shan/cannon",
"你看到"+this_player()->query("c_name")+"氣喘噓噓的從山上爬下來。\n",
 this_player());
 return 1;
}    
int clean_up() { return 0; }