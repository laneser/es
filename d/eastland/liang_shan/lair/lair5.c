#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

#define LONG1 "這個裂縫不大，不過如果你不怕髒的話，勉強可以擠進去(enter)看。\n" 
#define LONG2 "這個裂縫被一塊大石頭(rock)擋住了....\n"


inherit ROOM;

void create()
{
	::create();
	set_short( "奇怪的地方" );
	set_long(@C_LONG
你來到了一個奇怪的地方，位於群山環抱的一個谷底，四周全都是難以攀爬的懸崖
峭壁，在中央的空地有一個奇異的星形五芒魔法陣(circle)，在每一個陣角上，都
放了一個奇怪的髑髏(skeleton)，髑髏的外面，又擺了一圈水晶 (crystal)。在南
面的峭壁下，就是你爬上來的巖隙(crack)，除此之外，似乎別無去路。
C_LONG	
	);
        set("c_item_desc",(["circle":
                "一個巨大的五芒星魔法陣，是用一種奇異的紅色顏料(color)畫成的， \n"
                "魔法陣的上面似乎聚集了強大的魔法能源，使得空間發生了奇怪的扭\n"
                "曲，你注意到在魔法陣的中間，似乎有一個巨大的生物存在，但由於距\n"
                "離太遠，你看的不很清楚...\n"
                 ,"skeleton":
                "你仔細觀察這些巨大的髑髏，看起來都是些巨大爬蟲，他們空洞的雙眼\n"                 
                "正注視著魔法陣的中心。正當你轉身欲行，其中的一個髑髏突然轉過\n"
                "頭看著你，你感到一陣毛骨悚然，低頭裝著沒看到。\n"
                ,"crystal":
                  "一圈晶瑩剔透的水晶，它們跟這兒的詭異氣氛有點不太搭調...\n"
                  "傳說水晶具有集中魔法的能力，或許是因此它們才會出現在這兒。\n"
                ,"color":
                "你低頭研究這些暗紅色的線條和文字，使用的顏料看來髒髒的，不是很好看。\n"
                "你隨手摳了一點下來聞，一股血腥氣直衝你的腦門，你發現原來這個魔法陣\n"
                "是用血畫成的，你感到一陣噁心。\n"
                ,"crack":"@@query_crack"                            
                     ]));
        set_outside("eastland");
        set( "objects", ([
                "mob1" : "/d/noden/tomb/monster/small_centipede.c",
                "mob2" : "/d/noden/tomb/monster/small_centipede.c",
                "mob3" : "/d/noden/tomb/monster/red_spider.c",
                "mob4" : "/d/noden/tomb/monster/red_spider.c"
        ]) );
        reset();
}
void init()
{
add_action("do_enter","enter");
add_action("do_search","search");
}
string query_crack()
{
    if ( ! present("rock") )
          return LONG1;
              else
                  return LONG2;
}

int do_enter(string str)
{
    if ( str =="crack" ) {

  if ( present("rock",environment(this_player())) ) {
  write("這個巖隙被一塊大石頭擋住了，你沒有辦法鑽進去...\n");
    return 0;
    }
    write("你走到那個巖隙前，一頭鑽了進去..........\n");
    this_player()->move_player(TROOM"lair/lair4","你看到"+this_player()->query("c_name")+"鑽進一個巖隙中...\n");
    return 1;
    }
if ( str =="circle" ) {
  write("你走進那個五芒星魔法陣..........\n");
  write("你感到一股說不出來的感覺，好像是一部份的靈魂離開了你的身體...\n");
  (CONDITION_PREFIX + "weak")->apply_effect( this_player(), 2, 12 );
  this_player()->move_player(TROOM"lair/lair6","一陣空間的擾動後，你看到一個人突然出現\n");
  return 1;
  }
  return 0;
}
int do_search(string str)
{
if ( str =="skeleton" ) {
    write("你仔細檢查這些髑髏，你發現從它們的身上，不停滴下鮮血，而這些\n"
          "鮮血，則被一股力量牽引，而導入魔法陣中心。不過髑髏怎麼會有鮮血\n"
          "流出呢，你搖搖頭不願多想這個問題...\n");
          return 1;
          }
     return 0;
}          
          
int clean_up() { return 0; }
