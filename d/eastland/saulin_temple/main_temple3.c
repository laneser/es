#include "saulin_temple.h"

inherit ROOM;

int turn=0 ,push=0;

void create()
{
       ::create();
       set_short("少林寺大雄寶殿");
       set_long( @C_LONG_DESC
你現在來到了大雄寶殿的大廳，當你一踏進大廳你就被眼前那尊金色巨大的
釋迦牟尼像(Statue of Buddha)所震懾住了。在佛像的下面有個供桌，上面擺了
很多的鮮花素果，供桌的兩邊各有一盞長生燈。大廳的四周立著四根柱子(post)
上面好像有寫字。從這裡往北有個廣場，南邊則是前廳。
C_LONG_DESC
               );
       set("light",1);
       set("exits",([
           "north" : SAULIN"hallway0",
           "south" : SAULIN"main_temple2"
       ]) );
       set("objects",(["leader" : SAULIN_MONSTER"leader_monk"]));
       set("item_desc",([ "statue": @C_LONG
這是一尊由純金打造，十分巨大的佛像，據說裡面供著釋迦牟尼的舍利子
(Relic)。莊嚴肅穆的氣氛使得你不禁想誠心正意的膜拜(worship)他。
佛像的前面的小香爐(censer)上面插滿了點燃的檀香。似乎正提醒你，拜
拜的人可真不少。
C_LONG
                           ,"censer": @C_LONG
這是個銅做的小香爐，香爐兩邊的把手似乎磨損的很嚴重。
C_LONG
       ]));
	   reset();
}

void init()
{
     add_action("turn_censer", "turn");
     add_action("push_statue", "push");
     add_action("enter_hole", "enter");
     add_action("do_worship","worship");
}
int do_worship()
{
	tell_object(this_player(),
	"你誠心正意的向佛像拜了幾拜，突然感覺這尊佛像好像正在對著你笑。\n");
	this_player()->save_me();
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
int turn_censer(string str)
{
    if( !str || str != "censer" )
      return notify_fail("你要轉動什麼?\n");
    tell_object( this_player(),@C_LONG
你緩緩的轉動香爐。突然你聽到奇怪的聲音從佛像後面傳來，好像是觸動了
什麼機關。當你抬頭一看，發現佛像似乎略有移動。
C_LONG
    );
    turn = 1;
    return 1;
}
                   
int push_statue(string str)
{   
    if( !str || str != "statue" || !turn )
      return notify_fail("你要推動什麼?\n");
    if( (int)this_player()->query_stat("str") < 15 )
      return notify_fail(@ALONG
你用盡了全身的力氣，可是因為力量太小而推不動佛像。
你已經四肢發軟坐在地上喘氣。 
ALONG
      );
    tell_object( this_player(),@C_LONG
你費盡了千辛萬苦終於把佛像往旁邊推開了。你看到有個洞口(hole)，也許\
可以進去看看。
C_LONG
     );
        this_player()->set_explore("eastland#30");
     push = 1;
     return 1;
}

int enter_hole(string str)
{
      if( !str || str != "hole" || !push )
        return notify_fail( "你要進去哪裡?\n4");
      this_player()->move_player(SAULIN"road1","SNEAK");
      return 1;
}

void reset()
{
	::reset();
	turn = 0;
	push = 0;
}
