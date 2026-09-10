#include "../dony.h"

inherit ROOM;

int corner_search,have_exit;

void create()
{
	::create();
        set_short( "east7", "村路" );
	set_long(@C_LONG
你現在正走在一條由碎石子鋪成的村路上,村路延申到這裡似乎已是盡頭。村
路不很大,約可容納一匹馬行駛的寬度。在路旁長著一些奇形怪狀的植物 ,那上面
更開著許多不知名的小花,小花聞起來有點淡淡的香味, 那味道說不出的使得你心
曠神怡。鳥語蛙嗚, 頓時你煩惱盡失,站在這裡真是有如仙境。你的東邊是一間白
色的建築物,原來是祠堂 ( church )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
	           "south":DBEGGAR"east5.c"
	]) );
        set( "item_func", ([
                 "corner" : "exam_corner"
        ]) );
        set("c_item_desc",([
                 "church":"一間白色的老舊祠堂,你可以進去看看 ( enter )。\n"
        ]) );
        corner_search = 0;
     reset();
}
void init()
{
      add_action("do_touch","touch");
      add_action("do_search","search" );
      add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str) return 0;
    if (str=="church") {
        this_player()->move_player(DBEGGAR"church",({
            "%s進入了一間老舊的祠堂。\n",
            "%s從外面走了進來.\n"}),"");
        return 1;
    }
    else {
        write("你想進入那裡?\n");
        return 1;
    }
}

void exam_corner()
{
    if( !corner_search ) {
       write("你覺得這個角落怪怪的,可以找找看 ( search ) 是否有什麼?\n");
       return;
    }
    write("北邊角落的泥土已經被弄鬆了,說不定牆會倒了下來。\n");                                                    
}

int do_touch(string arg)
{
    if ( !corner_search )
            return notify_fail("你要做什麼?\n");
    
    if ( !arg || arg != "corner" )
        return notify_fail("你要碰什麼東西？\n");
    
    if ( !query("exits/north") ) {
       write(@C_LONG
你伸出手觸摸北邊被弄鬆的角落，突然『碰』的一聲, 北邊的牆壁嘩啦啦地倒塌
了,瞬間把你給壓的扁扁的。唉呀!你隱隱覺得不對,好像中計了!!!
C_LONG
       );
    (DBEGGAR"east8")->set("exits/south",DBEGGAR"east7");
    if ( ( this_player() )->query_temp("jail_asked") ) {
       this_player()->receive_damage(15);
    } else { this_player()->receive_damage(100); }
    this_player()->set_temp("block_command",1);
    call_out("recover",15,this_player());
    tell_room(this_object(),this_player()->query("c_name")+
        "伸手摸摸北邊的角落,突然『碰』的一聲，北邊的牆倒塌了把他給壓扁了..\n",
         this_player() );
    set("exits/north",DBEGGAR"east8");
      return 1;
    }
    write("你攝手攝腳地拿著泥巴把北邊的牆偷偷給封了起來......\n");
    corner_search=0;
    delete("exits/north");
    (DBEGGAR"east8")->delete("exits/south");
    return 1;
}                                        

void recover(object toucher)
{
   toucher->set_temp("block_command",0);
   tell_object(toucher,"你滿身灰塵地爬了起來,甚是狼狽。\n");
}

int do_search(string arg)
{
   if( !arg || arg!= "corner" ) 
      return notify_fail("你要找什麼呢?\n");
   
   write( "你倒是沒有找到什麼值錢的東西,反而北邊角落的泥土被你弄鬆了。\n");
   corner_search=1;                        
   return 1;
}
void reset()
{
    (DBEGGAR"east8")->delete("exits/south");
    delete("exits/north");
    ::reset();
}
                                                                          