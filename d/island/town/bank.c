#include "../island.h"

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("寶來號");
	set_long( @C_LONG
這裡是一家頗負盛名的錢莊，只見頭上一片匾額『財源滾滾』，似乎
暗示著這店的老闆是位精打細算的傢伙。你可以在這兒開戶，只要25枚金
幣就能將錢存在錢莊中；要是你已經有戶頭了，也可以在這裡存提款。錢
莊裡除了存提款，也提供錢幣的兌換服務，當然你在這兒可以兌換身上的
錢幣。牆上還貼了一張字條(help_list)，可以看看！
C_LONG
	);
	set("item_desc",(["help_list":@LONG
⊙ 專門給不會用指令的看的 ⊙

   (1) 開帳戶：
        □ 先確定你的確有二十五塊金幣（一定要金幣唷！ 沒有要先換）
        □ 再來就用 open account 來開戶就可以了，簡單吧....:P
        □ 還有那些散形的啊，提款卡掉了，只要再 open account 一次就可以了！
        
   (2) 存款和提款：
        □ 存款用 deposit 這個字，格式是： deposit [數量] [錢幣種類] 。
        □ 提款用 withdraw 就可以，格式是： withdraw [數量] [錢幣種類] 。
        
   (3) 換幣：
        □ 只要用 convert 我們就會幫你換錢啦！ 格式有兩種 ：
           □ convert [數量] [錢幣種類] to [新的錢幣種類] 。
           □ convert [錢幣種類] to [新的錢幣種類] 。
        □ 秘密大公開：（英文不好的看這邊）
           ES 錢幣種類列表 ：
              □ 白金幣 → platinum  (你也可以去看某種原子筆上的 mark)
              □ 金  幣 → gold
              □ 銀  幣 → silver        
              □ 銅  幣 → copper    (把錢換成銅幣，看來比較多...:P)
LONG
        ]));
	set( "light", 1 );
	set( "exits", ([ 
		"south" : ITOWN"town04" ]) );
	set("objects",([
	        "taxman" : IMON"taxman" ]) );	
	reset();
}

void init()
{
	bank::init();
	exchange::init();
}
