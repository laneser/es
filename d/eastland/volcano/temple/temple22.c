#include "../oldcat.h"

inherit ROOM;

int be_get2,be_get3;
void create()
{
	::create();
    set_short( "神殿器物室");
	set_long( 
@LONG_DESCRIPTION
這是一間神殿器物室，左邊的架子(shell)上盡是一些祭祀時所要穿戴的東西，
右邊的櫃子(closet)裡放著一些香油蠟燭之類的，還有一些碗盤碟子的器皿，地上另
外還堆了一大堆雜七雜八的物品。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple13",
     ]) );
set("item_desc",([
    "closet":"一個紅木櫃子，上面的漆已經差不多掉光了，裡面放的是一些器皿之類的東西。\n",
    "shell":"一個鐵架，在每一層的架子上都有標示這層是擺那一類的東西，從頭到腳的祭祀服裝\n都放在這裡。\n",
    ]) );
set("search_desc", ([
    "closet":"@@to_search_right",
    "shell":"@@to_search_left",
    ]) );
reset();
}

string to_search_right()
{
  string str;
  object ob;

  if (be_get2)
    return "你沒有找到任何有用的東西。\n";
  str="\n你把櫃子打開，翻了一下，找到一隻小槌子。\n";
  ob=new(OOBJ"club");
  ob->move(this_player());
  be_get2=1;
  return str;
}

string to_search_left()
{
  string str;
  object ob;

  if (be_get3)
    return "你沒有找到任何有用的東西。\n";
  str="\n你在架子上找了找，終於找到一塊布。\n";
  ob=new(OOBJ"cloth");
  ob->move(this_player());
  be_get3=1;
  return str;
}

void reset()
{
  ::reset();
  be_get2=0;
  be_get3=0;
}
