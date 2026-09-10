#include "saulin_temple.h" 

inherit ROOM;

mixed *gonfu_level_exp;
int do_help(string arg);
void set_gonfu_level_exp();

void create()
{
	::create();
	seteuid( getuid() );
	set_gonfu_level_exp();
	set_short("Training Room", "少林武僧練武房");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你看到一群群的武僧在此訓練武學，此地乃少林武僧訓練所學之處。所謂師父帶
進門，修行在各人。所有的少林武學和七十二絕技都有二十五重境界，當你勤練一種
武學至一定程度，可在此地修練成更高的境界。詳細的說明請看牆上(wall) 
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"wall" : @LONG_TEXT
————————————————————————————————
cost              告訴你每重武學的升級要求
train <功夫名字>  用此指令以訓練下一重武學 

你的各種武學修為到 第幾重 和 熟練經驗值 都顯示在 gonfus 中。
————————————————————————————————
LONG_TEXT
 ]) );

	set( "exits", ([ 
 	    "north" : SAULIN"monk_pass",
    ]));
	reset();
}

void set_gonfu_level_exp()
{
	int exp, i;
	
	exp = MAX_GONFU_EXP;
	gonfu_level_exp = allocate(MAX_GONFU_LEVEL);
	for( i=MAX_GONFU_LEVEL-1; i>=0; i-- ) {
		gonfu_level_exp[i] = exp;
		switch( i ) {
			case  0..1  : exp -= exp /  2; break;
			case  2..5  : exp -= exp /  3; break;
			case  6..10  : exp -= exp /  4; break;
			case  11..17 : exp -= exp /  5; break;
			case  18..25 : exp -= exp /  6; break;
			default : break;
		}
	}
}

void init()
{
	add_action("do_advance", "train");
	add_action("do_cost", "cost");
	add_action("do_help", "help");
}

int do_advance(string arg)
{
	int need_exp, exp, lvl, i;
	string *needed = ({ "bolo-mi", "chu-han", "fu-mo", "gi-mei", "tai-zuo", 
		"da-mo", "wu-sur", "body-def", "bolo-fist", "dragon-claw", "keep-flower", "power-finger" });
 
	if( !arg ) return do_help("train");
	lvl = (int)this_player()->query("monk_gonfu/"+arg);
	if( member_array(arg, needed) != -1 && undefinedp(lvl) )
		return notify_fail( can_read_chinese()?
			"你還不會這武功, 怎麼訓練?\n":
			"You don't know such a gonfu!\n");

	if( member_array(arg, needed) == -1  ) {
		write(can_read_chinese()?
			"沒有這個功夫!(只有少林武學和七十二絕技需要訓練哦!拳法和醫療武功不必) \n如果不是你打錯字了，請通知巫師。\n":
			"You can't train that here, please report to wizard.\n" );
		return 1;
        }

	if( lvl >= MAX_GONFU_LEVEL ) {
		write(can_read_chinese()?
			"你已經完全瞭解"+to_chinese(arg)+"武學的精義了。\n":
			"You can't train any more.\n" );
		return 1;
	}

	exp = (int)this_player()->query("gonfus_exp/"+arg);
	need_exp = gonfu_level_exp[lvl];
	if( exp < need_exp ) {
		write(can_read_chinese()?
			"你還需要 "+(need_exp-exp)+" 點經驗才能提升"+
			to_chinese(arg)+"的武學境界。\n" :
			"You need more "+(need_exp-exp)+" to advance your "+arg+" gonfu.\n"
		);
		return 1;
	} else {
		this_player()->set("monk_gonfu/"+arg, lvl+1);
		write(can_read_chinese()?
			"經過一番緞練, 你 "+to_chinese(arg)+" 武學的境界增加了。\n":
			"Your practiced of "+arg+" increases.\n"
		);
		return 1;
	}
}

int do_cost()
{
	int i;
	write( can_read_chinese()? "提升各類武功所需要的熟練經驗值\n":"");
	for( i=0; i<MAX_GONFU_LEVEL; i++ ) {
	  if( can_read_chinese() )

 printf("第%2d重境界: %8d 點熟練經驗。%s",i+1,gonfu_level_exp[i],(i%2?"\n":"\t") );
	  else
	    printf("  Level %2d : %15d experiences。\n",i+1,gonfu_level_exp[i]);
	}
 printf("\n\n");
	return 1;
}

int do_help(string arg)
{
	if( !arg || arg != "train" ) return 0;
	write("Syntax: train <gonfu name>\n\n"
		"The command let you train your practiced of gonfus you know.\n"
		"Type cost to see how many experiences needed for each level.\n");
	return 1;
}
