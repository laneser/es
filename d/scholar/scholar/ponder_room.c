#include <mudlib.h>

#define FORCE ({ "六合", "玄陰", "紫霞", "天機", })

inherit ROOM;

void create()
{
	::create();
        set_short("傲梅軒");
	set("long","@@query_c_long");
	set("long.txt", "Need Translation.\n");
	set("c_long.txt",
"這是舞墨軒內讓書生們靜修的地方, 名曰「傲梅」。簡單的佈置加上\n"
"一座檀香爐, 你覺得這絕對是一個靜修(ponder)的好場所。空氣中瀰漫\n"
"著一股肅穆的氣息, 使人很容易進入忘我的境界。\n");
	set("light", 1);
	set("has_one", 0);
	set("exits", ([ 
		"west"  : "/d/scholar/scholar/hall", ]) );
	set("objects", ([
	        "list"  :"/d/scholar/scholar/list" ]));
	reset();
}

string query_long()
{
	return query("long.txt");
}

string query_c_long()
{
	object me;

	me = query("has_one");
	if( !me )
		return query("c_long.txt");
	else
		return ( query("c_long.txt")+"    "+me->query("c_name")+
			"正端坐在蒲團上靜修。\n" );
}

void init()
{
	add_action("to_ponder", "ponder");
}

int to_ponder(string arg)
{
	object me;

	me = this_player();
	if( arg ) return 0;
	if( query("has_one") ) {
	  write("已經有人捷足先登了, 你找不到好地方坐下來靜修。\n");
	  return 1;
	}
	set("has_one", me);
	write("你靜下心來端坐在蒲團上, 思想逐漸空明, 進入忘我之境...\n");
	tell_room(this_object(),
		me->query("c_name")+"端坐於蒲團上, 雙眼微閉, 進入忘我之境。\n"
		, me);
	me->set_temp("block_command", 1);
	call_out("result", 3+random(3), me, 0, this_object());
	return 1;
}

void result(object me, int count, object place)
{
	string mtd;
	int fp, max;

	if( !me ) {
		place->set("has_one", 0);
		return;
	}
	if( count < 4+random(4) ) {
		tell_object(me, "..................................\n");
//		fp = (int)me->query("force_points");
//		max = (int)me->query("max_fp");
//		if( fp < max * 2 / 3 && (fp+count) < max )
//			me->set("force_points", fp+count);
		call_out("result", 2+random(2), me, count+1, place);
		return;
	}
	place->set("has_one", 0);
	me->delete_temp("block_command");
	tell_object(me,
		"你的思想逐漸清悉, 終於回到了現實。\n");
	if( random((int)me->query_level()) > 15 &&
		(int)me->query("force_effect") < 3 ) {
		mtd = FORCE[random(sizeof(FORCE))];
		tell_object(me, 
			"....... 你竟悟出了"+set_color(mtd+"心法", "HIY", me)+"!!\n"+
			"突然你感到一股熊熊的內力湧向丹田!!\n");
		me->add("force_effect", 1);
		me->set("force_points", (int)me->query("max_fp"));
	}
        if (me->query("couples"))
          if (!me->query("scholar_gonfu/couples_sword"))
             if (me->query_level() > 17) {
               me->set("scholar_gonfu/couples_sword",1);
               tell_object(me,set_color("你突然悟出了多情劍法的真義。\n","HIR"));
               tell_object(me,"你可以 enhant couples_sword 來施展多情劍法。\n");
               me->delete("couples");
             }
	tell_room(place,
		me->query("c_name")+"從蒲團上站了起來。\n" , me);
}
void reset()
{
  int i;
  object *player;
                
  ::reset();
  player = users();
  for( i=0; i<sizeof(player); i++ )
    "/d/scholar/scholar/topscholar2"->log_player(player[i]);
}
                                                        