#include <mudlib.h>

inherit MONSTER;

void create()
{
   ::create();
    set_level(10);
    set_name( "Morish Dio" , "摩理斯 迪奧" );
    add( "id", ({ "dio","morish","vendor","seller" }) );
    set_short( "摩理斯 迪奧" );
    set_long(@CLONG
摩理斯  迪奧曾經是一位出色的冒險者，但是在他經歷過許多次差點    
致命的危機後，他對金錢的興趣，漸漸取代了他原先對冒險的熱情。
雖然如此，他仍是不捨離去他過去最愛的冒險活動，因此他決定在此
投資開設冒險工具專賣店，一方面以此幫助後進，另一方面也可以此
累積財富。
你可以問他有關 price的事，相信他一定樂於幫助你的。
CLONG
    );
    set( "gender", "male" );
    set( "inquiry" , ([
    "price" : "@@ask_price"
    ]) );
}
void ask_price()
{
write(
"摩理斯 迪奧說道: menu 就貼在牆上，你可以去參考看看\n"
"如果你會搭營帳的話，這裡也可以買營帳喔....\n");
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "摩理斯 迪奧奸笑道: 謝了! 白痴!\n"
        "( 摩理斯 迪奧把"+item->query("c_name")+"收起來! )\n" );
   item->remove();
   return 1;
}

void init()
{
   npc::init();
   add_action("do_buy", "buy");
}

int do_buy(string str)
{
   object *who,tool,me;
   int loop,num,i;
   string *file_name;

   me = this_object();
   num = 3000*( 2 - (int)this_player()->query_skill("trading")/70);
   if( str == "tool" || str == "camp" ) {
       who = (object *)me->query("who_buy_camp");
//       for (loop=0;loop<sizeof(who);loop++) {
//       if (who[loop]->query("name") == this_player()->query("name")) {
//       printf( "老闆說: 一個人只能買一個帳蓬!\n" );
//       command( "kick "+this_player()->query("name"));
//       this_player()->receive_damage(10);
//       return 1;
//      }
//       continue ;
//      }
       if( present("camp tools",this_player())) {
       printf( "老闆說: 你已經有一個了!\n" );
       command( "kick "+this_player()->query("name"));
       this_player()->receive_damage(10);
       return 1;
       }
       if( this_player()->query("wealth/silver")<num ) {
       printf( "老闆說: 等你有足夠的銀幣再來吧!\n" );
       return 1;
       }
       if( !this_player()->query_skill("camp") ) {
       printf( "老闆說: 你不會紮營，賣給你也是浪費...\n" );
       return 1;
       }
       tool = new( "/obj/camp_tool" );

       printf( "你買下一包帳蓬工具\n" );
       if ( !this_object()->query("who_buy_camp") || 
       this_object()->query("who_buy_camp")=="") {
            file_name = get_dir("/d/adventurer/hall/camp/");
            for( i=0; i<sizeof(file_name); i++ )
            rm("/d/adventurer/hall/camp/" + file_name[i]);
            }
       this_object()->add("who_buy_camp", ({ this_player() }) ) ;                           
       tool->move(this_player());
       this_player()->debit("silver", num);
       this_object()->credit("silver", num);
       return 1;
       }
       return 0;
}
void announce( string c_msg )
{
    object *usr;
    int i;
                
    usr = users();
    for( i=0; i<sizeof(usr); i++ ) {
    if( !environment(usr[i]) ) continue;
    tell_object( usr[i], c_msg);
    }
}
void die()
{
   object killer;
   mapping bank;
   killer = query("last_attacker");
   if( !killer ) {
   ::die();
   return;
   }
   bank = killer->query("bank_balance");
   if( !bank ) bank = ([]);
   killer->set("bank_balance",([]));
   announce(
     "\n"+killer->query("c_name")+"給了摩理斯 迪奧致命的最後一擊....\n"
     "摩理斯 迪奧痛苦的大叫: 我親愛的朋友們，一定要幫我報仇....\n\n"
     "稅務官畢卡博，牛萬金和希露芙齊聲高喊: 可惡的"+killer->query("c_name")+"\n"
     "你一定會因此付出慘痛的代價的。\n\n");
   ::die();
  }
