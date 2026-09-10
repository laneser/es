#include "../tsunami.h"
#include "/include/move.h"

inherit ROOM;

int radish;

void create()
{
    ::create();
    set_short("『八哩八哩農場』的倉庫");
    set_long(@LONG
這裡是『八哩八哩農場』的倉庫，裡頭堆放了半人馬族近幾年的收成；當然，
其中有不少是準備要交給魔族當稅捐的。這些年來魔族戰禍連綿，需要大量的戰備
糧食，因此大幅提高半人馬族糧食捐；半人馬族心中雖不滿，但是由於毫無戰力，
所以只能默默屈服。
LONG
            );
    set("light",1);
    set("exits",([
        "east":CITY"farm5"]) );
    set("objects",([
        "wife":TMOB"wife"]) );
    reset();
}

void init()
{
    add_action("do_search","search");
}
    
void reset()
{
    ::reset();
    radish = 3;
}

int do_search(string str)
{
    if( !str || str !="there"){
        if(present("farmer's wife")){
        write("你要死啦，跟你說那邊了啊你還給我亂翻.....那邊啦！！\n");
        return 1;
        }
        write("一隻小老鼠在那邊咬著紅紅的東東，好像就是你要找的耶！\n");
        return 1;
    }
    if( radish == 0){
    write("你找來找去，還是找不到那該死的蘿蔔，一定是被人拿光了！\n");
    return 1;
    }
    else{
    write("\n為了那該死的蘿蔔，你一個箱子一個箱子的檢查，終於 ....\n.\n.\n不\n行\n了...\n\n");
    tell_room( environment(this_player()),
       this_player()->query("c_name")+"為了找一根蘿蔔，竟然累的睡著了！\n",
       this_player() );
    this_player()->set_temp("block_command",1);
    call_out("get_radish",5,this_player());
    return 1;
    }
}

int get_radish(object me)
{    
    tell_object(me,@BLONG
隱隱約約你聽到有人在唱歌：........................
          嘿呦嘿呦拔蘿蔔，嘿呦嘿呦拔蘿蔔
仔細一看，原來是你在拔蘿蔔啦；由於你求勝心切，不屈不撓，終於把它拔起來了！
你抱著這隻大蘿蔔，心中覺得好滿足喔！！
一時熊熊忽然間，蘿蔔越變越大，大得快要把你壓扁了，
你拼命掙扎，努力掙扎，還是沒用，心想：糟了，要去遠風鎮了...........
BLONG
         );
    call_out("wake",7,me);
    return 1;
}

int wake(object me)
{
	object ob;
   ob=new(TOBJ"radish");
   
   tell_object(me,"\n\n你被這惡夢嚇得驚醒了，正慶幸還好只是做夢時，赫然看到手中握著一隻蘿蔔......\n\n\n");
   me->set_temp("block_command",0);
   ob->set("owner",(string)me->query("name"));
   ob->move(me);
   tell_room( environment(me),
     "你看到"+me->query("c_name")+"突然驚醒，並望著手中的蘿蔔發呆！\n"
     , me );
   radish = radish - 1;
   return 1;
}                  
