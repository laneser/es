#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey Father", "桂老爹" );
   add( "id", ({ "guey", "father" }) );
   set_short( "桂老爹" );
	set_long(
        "你看到一個狀似痴呆, 面黃肌瘦的老頭, 正獨自怔怔地望著天空。\n"
        "而且你不時聽到一種幽幽淡淡, 若有似無的嘆息聲。\n"
	);
   set( "race", "human" );
	set( "gender", "male" );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
	set( "inquiry", ([
       "cut" : "去問我女婿吧!\n",
       "sheaumei" : "TEST\n",
       "sheaumei" : @DAUGHTER
唉 .... 我可憐的女兒 ........

我深深記得半年之前, 那個月色昏暗的夜晚 ........
小梅和女婿行完大禮, 並送走賓客之後; 老伴正忙著
收拾杯盤殘餚, 而女婿卻已醉臥於地, 老夫只好先去
安撫女兒。而當我甫至房前時, 竟見大門敞開, 女兒
倒臥於地! 於是急忙衝入房內探視小女, 可嘆已無力
迴天 ...............

但於踏入房門之際, 曾見一黑影躍窗而出, 其背影竟
彷佛一隻大犬! 老夫真恨不得生吞此畜牲之心!!
大俠, 您能否助我完成此願?
DAUGHTER
	]) );
}

int accept_item(object who,object item)
{
   object devil;

   if ( !item->query_cutted() ) {
         tell_room( environment(), 
@NOEAT
桂老爹喜道: 多謝大俠。
桂老爹拿起狼心欲一口吞下 ......
但很明顯地, 他無法吞下它 ......
桂老爹嘆道: 大俠, 您能再幫我切碎(cut)它嗎?
NOEAT
   );
         command("give heart to "+who->query("name"));
         return 1;
             }
   item->remove();

     tell_room( environment(), 
@CHANGE
桂老爹喜道: 多謝大俠。
桂老爹拿起切碎的狼心一口吞下 ......

突然桂老爹面色猙獰, 大笑道: 哈 ...哈 ...哈 ......
那隻畜牲終於死了! 那個可恨的傢伙總是與我爭奪獵物,
多謝你替我除去一大麻煩。而女兒其實是我殺的, 因為她
『抵死不從』, 不肯『孝敬』。至於你, 愚蠢的人, 下地
獄陪她們吧!

CHANGE
   );

   devil = new( IANMOB"devil" );
   devil->move(environment(this_object()));
   devil->kill_ob(who);
   this_object()->remove();
   return 1;
}
