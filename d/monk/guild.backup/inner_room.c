
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("inner-force room","少林內功心法房");
	set_long( @LONG_DESCRIPTION
This is the inner hall of monk's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你現在到了羅漢堂的內功心法房。請記住內功是武學之首，內功差一切都免談。
少林的初級內功是『少林基礎心法』，請參考門後的破紙上的說明(broken_paper)。   
少林的次級內功是『少林羅漢心法』，你需要有『初級武僧』以上的實力才能來學。
角落放了一本薄薄的破書(broken_book)，記錄了少林羅漢心法，你不妨去看看···  
向下回到精武房，北邊是少林朝陽心法房，向上通往少林七十二絕技練功房。
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "broken_paper":@PAPER
牆後草草的寫了幾個字...
『少林基礎心法』  
你可以用(study basic) 學到此內功心法。
注意∶還要練好基本內力技巧才會有內力  
PAPER
         ,"broken_book":@BOOK
書皮上寫著『少林羅漢心法』  
只要大叫『萬能的天神 請賜給我神奇的力量』(god help) 你將會學到此內功心法。
注意∶內力值大小和 [所習心法] 及 [基本內功] 有關 
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"north" : SAULIN"inner_room1",
		"down" : SAULIN"gonfu_room3",
		"up" : SAULIN"72" ]) );
	reset();
}

void init()
{
 add_action("to_study","god");
 add_action("basic","study");
}



int basic(string arg)
{
  string class1;

  class1=(string)this_player()->query("class");
  if ( !arg || arg!="basic") return 0;
  else if ( class1 !="monk"){
     write("抱歉你不是本公會的人所以你不能學此心法\n");
     return 1;
                           }
 
        else if ((int)this_player()->query("force_effect")>=1){
write(
" 一個在一旁練功的和尚看看你，大聲的笑道 \n 
『你是白痴啊! 你已經學過基礎心法或更好的心法了啦!!! 還鬧!』\n\n" );
          return 1;
                                                              }       
        else {
write(
"\n\n 你看見書中發出一道光芒照耀著你 \n");

call_out("idle_teme",10); 
write("一個很柔和的聲音說道...... \n

        歡迎加入少林和尚斬妖除魔的行列
        基礎心法只是很基本的心法，希望它對你有所助益 \n\n"); 
        this_player()->set("force_effect",1);
        return 1;  
             } 

}

int to_study(string arg)
{
  string class1;
  int level;

  level=(int)this_player()->query_level(); 
  class1=(string)this_player()->query("class");
  if ( !arg || arg!="help") return 0;
  else if ( class1 !="monk"){
     write("抱歉你不是本公會的人所以你不能學此心法\n");
     return 1;
                           }
    else if (level<4){
    write("『天神說: 小老弟啊!!! 方丈說得有初級武僧以上的實力才能教授心法啦!』\n\n");
         return 1;
                     } 
        else if ((int)this_player()->query("force_effect")>=2){
write(
" 神累了一天，又被你吵的不能睡覺... 他很不爽的看著你罵道\n 
『你是白痴啊! 你已經學過心法了不能再學啦!!!』\n\n" );
return 1;
                                                              }       
        else {

call_out( "idle_time",5);
write(
"\n\n突然天上一聲大吼...... \n");
call_out("idle_time",10);
write(" 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
@@@ 降龍羅漢法身乍現，你終於領悟到少林羅漢心法的奧義 @@@ 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n" );
        this_player()->set("force_effect",2);
        return 1;  
             } 
}

 
void idle_time()
{
write(" \n");
}
 


