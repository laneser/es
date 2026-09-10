
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
        ::create();
    set_short("少林朝陽心法房");
        set_long( @LONG_DESCRIPTION
這房間的神桌上供著一尊地藏王菩薩的塑像，屋內洋溢著一股和善莊嚴的氣氛。
如果你學會了羅漢心法而且天資聰敏、多行善事而成為一代大俠的話，你便能在此地
學得少林的另外一套心法『少林朝陽心法』。至於其它更強的心法嘛，就看你的福氣 
和機運了。牆上畫了一幅幅的經脈人形(shape)，你不妨去看看。
往南通往少林內功心法房。
LONG_DESCRIPTION
        );
    set("c_item_desc",([
         "shape":@BOOK
牆上寫著『少林朝陽心法』但經脈和人形都已剝落不明瞭，你也看不懂其上的梵文  
怎麼辦呢? 心誠則靈，也許該試試向地藏王祈禱(pray god) 看看他會不會顯顯靈。


注意∶內力值大小和 [所習心法] 及 [基本內功] 有關 
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
                "south" : "/u/b/boss/workroom.c" ]) );
        reset();
}

void init()
{
 add_action("to_study","pray");
}

int to_study(string arg)
{
  string class;
  int alignment,effect,inte;

  inte=(int)this_player()->query_stat("int"); 
  effect=(int)this_player()->query("force_effect"); 
  alignment=(int)this_player()->query("alignment"); 
  class=(string)this_player()->query("class");

  if ( !arg || arg!="god") return 0;

  else if ( class !="monk") {
     tell_object(this_player(),"抱歉你不是本公會的人所以你不能學此心法\n");
     return 1;
                            }
  else if (effect>=5) {
tell_object(this_player(),
" 你看見地藏王在瞪你，似乎要罵你貪心，你馬上改口說\n 
『菩薩啊，我是來感謝您教導我『朝陽心法』的，不是想再多學些什麼的啦!!!』
  你諂媚的向他一笑，地藏王聽完差點從供桌上摔下來...\n\n " );
          return 1;
                    }       
  else if (effect<2) {
tell_object(this_player(),
" 一個老和尚經過你身邊，搖了搖頭說\n 
『連羅漢心法都不會的人還想學朝陽心法，唉... 人心不足蛇吞象啊!』\n\n " );
          return 1;
                    }       
else if (inte<=8) {
tell_object(this_player(),
"\n一個小沙彌跑出來問你: 
『一加一等於幾? 哇!!! 連這個都不知道! 你現在還是太笨了，別想學啦!』\n\n");
         return 1;
                  } 
else if (alignment<5000) {
tell_object(this_player(),
" 一個金甲神從牆上跳了出來，大腳將你踢出門外去  
『朝陽神功只傳給一代大俠，就憑你也配學!!!』 \n\n" );
this_player()->move_player( SAULIN"inner_room","SNEAK");
          return 1;
                                 }       
   else      {

        this_player()->set_temp("chutan", 1 );
    if( !wizardp( this_player() ) ) {
          this_player()->set_temp("block_command", 1 );
        }
          this_player()->set_temp("chutaning", 1 );

 tell_object(this_player(),"你突然覺得好累，不覺昏沉沉的睡著了......
 
ＺＺＺｚｚｚｚｚ.... \n\n\n\n\n\n" ); 
 call_out("appear_old",5,this_player());
        return 1;  
             } 
}


void appear_old(object player)
 {
tell_object(player,@APPEAR
突然你看見一個白髮老公公走了過來，他摸摸他的長鬚笑著對你說 :
「嗯，閣下又聰明又有一顆好心腸，我就傳你朝陽心法吧! 盼你多行善事!
 造福世人! 切記 切記!!!」


你忽見大地一片光明，老公公全身被陽光籠罩著... 一篇篇心法大要，突然
出現在你的腦海... 你不禁欣喜若狂，跪下謝謝老公公，而後迅速打坐練功
，習頌起少林朝陽心法。
APPEAR
        );
player->set("force_effect",5);
call_out("wake_up",25,player);
 }
void wake_up(object player)
 {
 tell_object(player,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n『懶...豬.豬..啊!!! 起.起...床..啦.!!! 偶..偶.要..掃.地..了....啦』
  一個口吃的掃地僧用掃把柄敲著你的頭。 

  你發現你全身都是口水，但卻充滿了力氣，你的內功修為似忽增進不少...
  抬頭一看，你發現地藏王的樣子和老公公好像啊，它似乎也在對你微笑著...
  你心滿意足的站了起來 \n\n");
        player->set_temp("chutan", 0 );
    if( !wizardp( player ) ) {
          player->set_temp("block_command", 0 );
        }
          player->set_temp("chutaning", 0 );
}


