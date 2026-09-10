#include <../oldcat.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(12);
	set_name( "princess", "小龍女" );
	set_short( "小龍女" );
	set_long(
		 "@@query_long"
		 );
	set( "gender", "female" );
	set( "race", "dragon" );
        set( "likefish",1);
	set( "no_attack",1);
}

string query_long()
{
 if ((int)this_player()->query_quest_level("Dragon_box"))
 {
    set("hit_points",this_object()->query("max_hp"));
    return "你看到一個面帶笑容的公主，身著白色的絲質衣服，在窗口觀賞景色。\n";
  }
 else
  {
   set("hit_points",1);
   return "你看到一個臥病在床的公主，原本紅潤的臉現在只是一片蒼白，\n"+
      "如果再沒有人為公主找到續命靈藥，恐怕她撐不了多久。\n";
  }
}

int accept_item(object me,object item)
{
     if ((string)item->query("name")!="living pill" || (int)me->query_quest_level("Dragon_box")) {
       tell_object(me,
          "小龍女微微的搖著頭：「謝謝 !! 但我不需要這東西 !!」\n");
       command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
       return 1;
     }
     if (!item->query(me->query("name"))) {
        printf("公主說：我就算是死也不吃來源不正當的東西。\n");
        item->move(me);
        return 1;
     }
     tell_object(me,
"你把公主的嘴稍微撥開，將續命藥丸讓公主吃下去，吃了藥丸以後，公主果然精神\n"+
"好多了，公主向你說：「我知道你的心事，謝謝你救了我，那朵藍色玫瑰花你就拿去吧。\n"+"看到她好多了，你覺得付出沒有白費 !!\n\n"
      );
     if ((string)me->query("class")=="scholar") {
        this_player()->set("demand/water",1);
        write("龍王說：為了感謝你為了我女兒這樣奔波，我決定將一隻水精靈供你召喚，當作是我給你的禮物。\n");
     }
     tell_object(me,set_color("龍王用心靈感應對你說道：謝謝你! [你獲得 5000 點經驗]\n","HIY"));
     item->remove();
     me->finish_quest("Dragon_box",1);
     me->gain_experience(5000);
     return 1;
}
