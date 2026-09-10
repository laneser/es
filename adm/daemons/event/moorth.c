// war.c
// This daemon controls the wars in the mud. 
// By Annihilator@Eastern.Stories (1-6-94)

#define NODANIA "/d/noden/nodania/"
#define MOORTH_NPC "/d/moorth/monster/"

mapping attackers = ([
	NODANIA"nodania_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r2": ({
		MOORTH_NPC"officer",
		MOORTH_NPC"officer",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier"}),
	NODANIA"s_gate": ({
		MOORTH_NPC"warlord",
		MOORTH_NPC"knight",
		MOORTH_NPC"knight",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier",
            MOORTH_NPC"warlock",
		MOORTH_NPC"healer" })
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
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
	usr[i]->quick_message(set_color(msg,"HIY",usr[i]));
	}
}

void start_war()
{
	if( sizeof(army)!=0 ) return;
	announce(
		"\n你聽到天空中傳來一陣尖細的笑聲 ....　\n"
		"\n這個聲音隨後發出一陣狂笑，說道: 那個騎士已經死了，去稟告女皇陛下 ....\n"
		"\n隨著聲音的消失，天空整個暗了下來　\n"
	);
	call_out( "start_war1", 15 );
}

void start_war1()
{
	string *loc;
	int i, j;
	object ob, room;

	loc = keys(attackers);
	army = ({});
	call_out( "check_war", 300 );
	announce(
		"\n忽然，一道閃亮刺眼的閃電伴隨著隱隱的雷聲劃破寂靜的天空 ....　\n"
		"\n西方的天空中出現許多像是彩虹一般的光暈，使得天空中呈現一股詭異的氣氛 ....　\n"
		"\n雷思騎士團長大叫: 默爾斯人又來了！皇家騎士們，為諾頓的光榮而戰吧！\n\n" );
	// Clone the attackers and put them to the pre-defined rooms.
	for(i=0; i<sizeof(loc); i++ ) {
		if( !(j= sizeof(attackers[loc[i]])) ) continue;
		// Find the room to put.
		room = find_object(loc[i]);
		if( !room ) call_other( loc[i], "???" );
		room = find_object(loc[i]);
		if( !room ) continue;

        tell_room( room,
            "突然你看到一陣煙霧從空氣中升起，裡面走出幾條人影！\n" );
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
           announce( "\n*** 戰爭結束了 ***\n\n" );
		on_war = 0;
		return;
	}
	call_out( "check_war", 300 );
}
