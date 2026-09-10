#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("東方武術塔心法房");
        set_long( @LONG_DESCRIPTION
這裡是東方武術研究所的心法房,東方武術能以空手對會強悍的敵人和怪物
的原因是神秘內功,現在研究所終於可以為騎士學習基本的內功心法,以更好
的對抗敵人。心法房裡面有一堵（wall）刻著內功心法，能否學到就要靠自
己的造化了。
LONG_DESCRIPTION
        );

    set("c_item_desc",([
         "wall":@WALL
牆後草草的寫了幾個字...
『楊家內功基礎心法』  
你可以用(study basic) 學到此內功心法。
注意∶還要練好基本內力技巧才會有內力  
WALL
         ,"wall":@BOOK
書皮上寫著『楊家內功心法』  
只要大叫『萬能的天神 請賜給我神奇的力量』(god help) 你將會學到此內功心法。
注意∶內力值大小和 [所習心法] 及 [基本內功\] 有關 
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/u/c/creative/workroom",
                 "up"     : "/u/b/boss/workroom"]));
                 reset();
}

void init()
{
 add_action("to_study","god");
 add_action("basic","study");
}



int basic(string arg)
{
  string class;

  class=(string)this_player()->query("class");
  if ( !arg || arg!="basic") return 0;
  else if ( class !="knight"){
     write("抱歉你不是本公會的人所以你不能學此心法\n");
     return 1;
                           }
 
        else if ((int)this_player()->query("force_effect")>=1){
write(
" 一個在一旁練功的騎士看看你，大聲的笑道 \n 
『你是白痴啊! 你已經學過基礎心法或更好的心法了啦!!! 還鬧!』\n\n" );
          return 1;
                                                              }       
        else {
write(
"\n\n 你看見書中發出一道光芒照耀著你 \n");

call_out("idle_teme",10); 
write("一個很柔和的聲音說道...... \n

        歡迎加入保衛國家的行列
        基礎心法只是很基本的心法，希望它對你有所助益 \n\n"); 
        this_player()->set("force_effect",1);
        return 1;  
             } 

}

int to_study(string arg)
{
  string class;
  int level;

  level=(int)this_player()->query_level(); 
  class=(string)this_player()->query("class");
  if ( !arg || arg!="help") return 0;
  else if ( class !="knight"){
     write("抱歉你不是本公會的人所以你不能學此心法\n");
     return 1;
                           }
    else if (level<18){
    write("『天神說: 兄弟啊!!! 只有騎士將軍才能教授內功心法啦!』\n\n");
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
@@@ 楊家列祖神明乍現大喝，你終於領悟到楊家內功心法的奧義 @@@ 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n" );
             this_player()->set("max_fp", "@@query_max_fp");
        this_player()->set("force_effect",2);
        return 1;  
             } 
}

 
void idle_time()
{
write(" \n");
}
 

