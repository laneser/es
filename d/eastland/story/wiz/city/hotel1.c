#include "../../story.h"

inherit ROOM;
int number=0;
void create()
{
	::create();
        set_short("旅館");
	set("long",@LONG
此處是「巫咸城」裡唯一的一家旅館，你可以在這裡休息過夜。尤其是每當受傷風
寒，除了需要妥善包紮以外，睡上一覺不但傷口易於痊癒，一覺起來更是精神飽滿！這
裡的價錢相當公道，不二價，全寫在牆壁上一張黃色紙(paper)上。	
LONG
	);
	set("light", 1);
	set("exits", ([ 
            "west" : SCITY"ww"
        ]) );
        set("c_item_desc", ([
           "paper" :" 斗大的字上面寫著：過夜(sleep)一次 500 金幣。\n"
        ]) );
        set("objects", ([
           "boss" : SWMOB"boss1"
        ]) );
	reset();
}

void init()
{
     add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
     object player;
     string name;
     if ( number > 5 ) {
        write("這位客倌真對不起，本店已經客滿了，下次請早。謝謝。\n"); 
        return 1;
     }
     player = this_player();
     name=player->query("c_name");
     if ( !player->debit("gold", 500) ) {
         write("這位客倌真對不起，您身上所帶的錢不夠。\n");
         return 1;
     }
     number++;
     write(@LONG

旅館老闆大喊道：小二，快帶這位客倌休息去。


於是，店小二急急忙忙地引你到二樓，準備休息去...

LONG 
     );
     tell_room(this_object(),sprintf(
         "%s看起來很疲倦地隨著店小二上二樓休息去。\n",player->query("c_name")),player);
     player->move_player(SCITY"hotel2","SNEAK");
     player->set_temp("block_command", 1);
     call_out("result", 6,player, 0 ,this_object());
     return 1;
}

void result(object me, int count, object place)
{
     int sp,fp,med,max_fp,max_sp;
     if( !me ) return 0;
     if( count < 10 ) {
     tell_object(me, "Z z Ｚ ｚ Z z\n");
         if ( me->query("max_fp") ) me->add("force_points",5);
         if ( me->query("max_sp") ) me->add("spell_points",7);
         me->set_temp("block_command",1);
         me->add("medication_resistance",-15);
         me->receive_healing(25);
         call_out( "result",6,me,count+1,place);
         return ;
     }
     med=me->query("medication_resistance");
     fp=me->query("force_points");
     sp=me->query("spell_points");
     max_fp=me->query("max_fp");
     max_sp=me->query("max_sp");
     if ( med<0 ) me->set("medication_resistance",0);
     if ( fp>max_fp ) me->set("force_points",max_fp);
     if ( sp>max_sp ) me->set("spell_points",max_sp);
     me->move_player(SCITY"hotel1","SNEAK");
     me->delete_temp("block_command");
     tell_object(me,
	"你伸個懶腰,看看時間,嗯,休息夠了也該上路了。\n");
     tell_room(place,sprintf(
	"%s從樓上走了下來,精神好極了。\n",me->query("c_name")),me);
     return ;
}
void reset()
{
   number=0;   
   ::reset();
}