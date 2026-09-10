#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 10 );
   set_name( "Meph", "婚紗店老闆莫飛" );
   add( "id", ({ "owner", "boss" }) );
   set_short( "莫飛" );
	set_long(@C_LONG
    莫飛是一個年約三十的青年, 他在歷經一場沒有結局的苦戀後,
來到此地定居, 並開了此一結婚禮服店, 希望天下有情人均成眷屬。
你可以問他如何租借(rent)禮服。
C_LONG
    	       );
	set( "no_attack", 1 );
	set( "gender", "male" );
   set( "inquiry", ([
         "rent" : 
@LONG
首先, 請您先看我們的價目表(menu),
您可以買斷我們所提供之禮服; 但是如果您嫌貴的話, 可以在
完成婚禮後退回(return)給我, 除花, 戒指, 及護盾圓球外,
每件將退還您1500銀幣. 另外提醒您, 如果你不結婚, 戒指及
護盾圓球是不能戴上與儲存的.
LONG
     ]) );
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "商店老闆奸笑道: 謝了! 白痴!\n"
        "( 商店老闆把"+item->query("c_name")+"收起來! )\n" );
   item->remove();
   return 1;
}

void init()
{
   add_action("do_buy", "buy");
   add_action("do_return", "return");
}

int do_buy(string str)
{
   object ring, globe;

   if( str == "ring" || str == "wedding ring" ) {
       if( present("wedding ring",this_player()) ) {
       printf( "老闆說: 結婚戒指一個人只需要一隻!\n" );
       return 1;
       }
       if( this_player()->query("wealth/silver")<5000 ) {
       printf( "老闆說: 等你有足夠的銀幣再來吧!\n" );
       return 1;
       }

       ring = new( "/d/noden/farwind/wedding_obj/wedding_ring" );

       printf( "你買下一隻結婚戒指.\n" );
       ring->move(this_player());
       this_player()->credit("silver", -5000);
       return 1;
   }
   if( str == "globe" || str == "wedding globe" ) {
       if( present("wedding globe",this_player()) ) {
       printf( "老闆說: 結婚護盾圓球一個人只需要一個!\n" );
       return 1;
       }
       if( this_player()->query("wealth/silver")<8000 ) {
       printf( "老闆說: 等你有足夠的銀幣再來吧!\n" );
       return 1;
       }

        globe = new( "/d/noden/farwind/wedding_obj/wedding_globe" );

       printf( "你買下一個結婚護盾圓球.\n" );
       globe->move(this_player());
       this_player()->credit("silver", -8000);
       return 1;
   }
   if( str != "ring" && str != "wedding ring" &&
       str != "globe" && str != "wedding globe" &&
       this_player()->query("spouse") ) {
   printf( "老闆怒道: 你想重婚嗎?\n" );
   return 1;
   }
}

int do_return(string str)
{
   object player, obj;
   string armor;

   player = this_player();

   if( !str || str =="" ) return notify_fail( "你要還什麼東西?\n" );

   if ( sscanf(str, "%s", armor)==1 ) {
     obj = present(armor,player);

   if( !obj ) return notify_fail( "你沒有這東西!\n" );
   if( !obj->query("wedding_obj") )
      return notify_fail( "莫飛說: 對不起! 這件東西本店不回收!\n" );
   if( !this_player()->query("spouse") )
      return notify_fail( "莫飛說: 你還沒結婚啊! 先留著它吧!\n" );
   tell_room( environment(),
        "莫飛說: 退回押金1500銀幣, 謝謝惠顧.\n"
         "( 莫飛把"+obj->query("short")+"收起來等待清洗 )\n" );
   player->credit("silver", 1500);
   obj->remove();
   return 1;
   }
}
