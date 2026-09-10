#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set("broken",0);
	set_short("達摩面壁處");
	set_long( @C_LONG_DESCRIPTION
這裡是達摩祖師面壁十年的地方，雖然狹小陰暗，但是卻是少林寺的
聖地，對面的石壁還留有一片黑影(shadow)，相傳是達摩祖師的影子在十
年面壁期間所化，現在院內仍有許多僧人靜靜面壁，希望也能得證涅盤。
C_LONG_DESCRIPTION
	);
    set("item_desc",([ "shadow" : @C_LONG
你仔細的查看那面黑影，影子忽然活動起來，同時，在你的耳畔想起一陣嗡嗡的話
語 ： 哈哈 !! 我是達摩 .... 的影子，達摩那個死傢伙以前在這裡面壁，就是為
了要把我從他身上趕出去，他做到了，卻把我孤零零的留在這面石壁(wall)上，我
努力修煉了千百年，還是出不了這面牆，如果你肯幫我打破(break) 這面牆，放我
出去看看這個大千世界，我就告訴你一些有關達摩的秘密。
C_LONG
    ]));
        set_outside("eastland");
	set( "exits", ([
		"west" : SAULIN"stone_path3",
	]) );
	reset();	
}

void init()
{
    add_action("break_wall", "break");
}

int break_wall(string arg)
{
	if( !arg || arg !="wall" )
	  if( !this_object()->query("broken") )
        return notify_fail( "影子哈哈大笑：打破什麼？你的笨腦袋嗎？\n" );
      else
        return notify_fail("打破什麼？\n");
	if( !this_object()->query("broken") ) {
      tell_object(this_player(),@SHADOW_OUT
  你舉起一塊大石頭往石壁砸去，轟隆一聲巨響，石壁完好無損，影子卻藉著這一擊
  從石壁衝了出來，飛到半空中。它高興的大喊大叫：我出來了 ! 我出來了!死達摩 
  ! 說什麼要成佛就要禁制惡念，我這不是出來了嗎？到底是你強還是我強？哈哈哈
  !! 它又指著你大笑：你這個白痴凡人，我什麼也不會告訴你 !!!
  你覺得你好像闖了大禍了 !! 
SHADOW_OUT
      );
      new( SAULIN_MONSTER"damo" )->move( this_object() );
      this_object()->set("broken",1);   
      this_player()->set_explore("eastland#33");
    } else
      tell_object(this_player(),@NOTHING
你舉起一塊大石頭往石壁砸去，轟隆一聲巨響，石壁完好無損，
但影子似乎已無力逃出來。
NOTHING
      );
    return 1;
}

void reset()
{
    ::reset();
    set("broken",0);
}
