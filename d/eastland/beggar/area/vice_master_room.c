#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "vice_master_room", "副幫主之室" );
	set_long(@C_LONG
這裡是全副幫主住的地方。這裡沒什麼貴重的擺設,房子中間放著一張大紅桌
子,桌子裡還有幾個抽屜, 抽屜裡不知道放的是什麼東西。桌子後面的牆壁上供奉
著幾尊不知明的神明,神明兩旁寫著『風調雨順』之類的對聯, 對聯上面的字歪歪
斜斜一看就知道不是出自於名家手筆。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "out":DBEGGAR"west9.c"
	]) );
        set( "c_item_desc", ([
                 "closet" :"一個用檀木做的抽屜。\n"
        ]) );
        set( "objects", ([
                      "unary":DMONSTER"unary.c",
                        "dog":DMONSTER"dog.c"
        ]) );              
     reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
    object ob1;
    
      if ( !arg || arg != "closet" ) {
         tell_object(this_player(),"你在找什麼東西？\n");
         return 1;
      }      
      if ( this_object()->query_temp("be_searched") ) {
         tell_object(this_player(),"抽屜己經被別人找過了。\n");
         return 1;
      }
      if ( !this_player()->query_temp("gonfu_asked") ) {
         tell_object(this_player(),"你在找什麼東西?\n");     
         return 1;
      }    
      else {
         tell_object( this_player(),
            "你找到了一封白色的信件。\n");
         ob1=new(DITEM"letter");          
         ob1->set("master",this_player()->query("name"));
         ob1->move(this_player());
         this_object()->set_temp("be_searched",1);
         call_out("recover",1800,this_object());
         return 1;
      }
}
void recover(object obj)
{  
     obj->delete_temp("be_searched");
}
void reset()
{
     this_object()->delete_temp("be_searched");
     ::reset();
}
            