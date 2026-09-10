// war.c
// This daemon controls the wars in the mud. 
// By Annihilator@Eastern.Stories (1-6-94)

#define ITOWN "/d/island/town/"
#define IMOB  "/d/island/war/"

mapping attackers = ([
	ITOWN"museum" : ({ IMOB"juibei",IMOB"w_leader",IMOB"lizard05" }),
	ITOWN"town02" : ({ IMOB"war3",IMOB"war3" }),
	ITOWN"town04" : ({ IMOB"war2",IMOB"war3",IMOB"war3" }),
	ITOWN"town06" : ({ IMOB"lizard03",IMOB"lizard02",IMOB"lizard01" }),
	ITOWN"town08" : ({ IMOB"mage2",IMOB"warrior",IMOB"mage1" }),
        ITOWN"square01" : ({ IMOB"lizard01" }),		
	ITOWN"square03" : ({ IMOB"war1",IMOB"war2" }),
	ITOWN"square04" : ({ IMOB"lizard03",IMOB"lizard02" }),
	ITOWN"square05" : ({ IMOB"lizard04",IMOB"lizard02" }),
	ITOWN"square07" : ({ IMOB"mage",IMOB"mage2" }),
	ITOWN"square08" : ({ IMOB"warrior",IMOB"mage2" })
	]);

int on_war;
object *army;

void create()
{
	seteuid(getuid());
}

void announce( string msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=sizeof(usr)-1; i>=0; i-- ) {
		if( !environment(usr[i]) ) continue;
	usr[i]->quick_message(set_color(msg, "HIG", usr[i]) );
	}
}

void start_war()
{
	if( sizeof(army)!=0 ) return;
	announce(@LONG
由武士堡來一騎白色的快馬，直衝入武士教練場.....
十兵衛狂傲的嘯聲從裡頭傳出:兄弟們，準備吃烤蜥蜴尾巴和魔族傢伙的翅膀吧。
LONG
	);
	call_out( "start_war0",7 );
}

void start_war0()
{
	announce(@LONG

天上傳來魔族守護靈們的旨意:子民們，為光大我魔族聲威而奮戰吧。
LONG
	);  
	call_out("start_war1",3 );
}

void start_war1()
{
	string *loc;
	int i, j;
	object ob, room;

	loc = keys(attackers);
	army = ({});
	call_out( "check_war", 300 );
	announce(@LONG
	
南邊的蜥蜴人齊聲高喊:看不起蜥蜴人的愚蠢者，明年今天就是你們的忌日了。
LONG
             );
		 
	// Clone the attackers and put them to the pre-defined rooms.
	for(i=0 ; i<sizeof(loc) ; i++ )
	 {
		if( !(j= sizeof(attackers[loc[i]])) ) continue;
		// Find the room to put.
		room = find_object(loc[i]);
		if( !room ) call_other( loc[i], "???" );
		room = find_object(loc[i]);
		if( !room ) continue;

		tell_room( room,@LONG
		
幾條迅捷的人影忽然從附近的營地裡面衝出來。

LONG
			);
		while( j-- ) {
			ob = new( attackers[loc[i]][j] );
			ob->move( room );
			army += ({ob});
		}
	}
	for( i=0; i<sizeof(army); i++ )
		army[i]->enable_war();
}


void check_war()
{
	// Remove those victims in the war.
	army -= ({ 0 });
	remove_call_out( "check_war" );
	if( !sizeof(army) ) {
		announce(@LONG
☆ 謫仙島恢復了和平 ☆
LONG
		 );
		on_war = 0;
		return;
	}
	call_out( "check_war",300 );
}
