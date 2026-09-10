#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "懸崖上的平臺" );
	set_long(
	"你現在站在高高的懸崖上突出的一個小平臺上，美麗的大湖橫亙在你的腳下，羿水\n"
	"河向東方滔滔奔流而去，這壯觀的景像深深的感動了你的心靈，使你忘記了你目前\n"
	"受困在這個懸崖上。\n"
	);
        set("c_item_desc",(["up":
                "上方大概三尺高，是你鑽出來的那個洞，不過崖璧很光滑，你應該是爬不上去的\n"
                "再上去五十尺，好像就是崖頂。\n",
                            "lake":
                "美麗的大湖｛雲蒸霞蔚，有一種朦朧的美感...\n",            
                            "down":
                "你到崖邊探頭下望，哇....好高，你想你是不可能用爬的下去了\n"
                "下面的湖呈現一種異樣的藍綠色，使你有一種昏眩的感覺，你趕\n"
                "快退了回去。\n"            
                ]));
        set_outside("eastland");
        reset();
}
void init()
{
add_action("suicide","jump");
}
int suicide(string arg)
{
    if ( !arg || arg != "down") return 0;
    write("你走到崖邊，奮力往下跳去....呼呼的強風吹過你的身旁，強大的風壓\n");
    write("使你短暫的失去意識，直到你感覺......\n");
    this_player()->receive_damage(15);
    this_player()->move_player(TROOM"lake/underwater1","通.......一個人突然從天而降\n");
    return 1;
}
int clean_up() { return 0; }