
#include "saulin_temple.h" 
#define  BOARD "/d/monk/guild/monk_board"

inherit GUILD;

void create()
{
	::create();
	set_short("A monk guild", "羅漢堂");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
一踏進羅漢堂你的眼光馬上被兩旁供奉的十八羅漢所震攝。降龍、伏虎、迦葉、阿難
．．．  十八尊羅漢塑像之神態姿勢各不相同。他們分立在左右牆邊，牆後的壁畫繪著每
名羅漢得道成佛的過程。
少林羅漢堂是少林寺中武僧們互相切磋武學的地方，不少僧人目前正在此處練功、舞棍及
討論武技，拳來腳往刀光劍影的十分熱鬧。如果你想加入少林武僧的行列，你可以在這裡 
得到相關的資訊。你發現羅漢堂角落的牆上(wall)被人用金剛指力刻了一些字。  
東、南、北方的三個出口，分別通往三類練功房，西方則可以回到穿堂。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"wall" : @LONG_TEXT
————————————————————————————————
羅漢堂是所有少林僧人學習武藝之處，也有人稱它是少林和尚公會。
『眾生無我  一切隨緣』，除了吸血的吸血鬼和沒有手的眼魔外，我 
們都歡迎你來加入，但少林百年寺規———本地不招待女客，所以如
果你是女子，請恕本堂無法讓你加入(join)。

help guild 可以得到進一步的公會指令說明。
help monks 可以得知少林和尚公會的屬性限制及說明。

另外你要特別注意
『本寺武僧若犯戒殺害任何玩家，經被害人申訴屬實者，殺無赦』  
 即本公會嚴禁ＰＫ任何人，但若為防身自衛則不算　　
————————————————————————————————
LONG_TEXT
 ]) );
	set( "exits", ([ 
	        "south": SAULIN"gonfu_room4",
 	        "east" : SAULIN"gonfu_room1",
 	        "west" : SAULIN"monk_pass",
                "north": SAULIN"gonfu_room3" ]) );
	set( "no_monster", 1 );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"shan-chi" ]) );
	                 BOARD->frog();
	set_guild( "monk" );
        set( "pre_exit_func", ([    "north" : "check_monk",
                                    "south" : "check_monk",
                                    "east"  : "check_monk" 
	])  ); 
reset();
}

int check_monk()
{   
        if( wizardp( this_player() ) ) return 0; 

 if( (string)this_player()->query("class")!="monk" && present("shan chi") ) {
//if( (string)this_player()->query("class")!="monk"  ) {
		write( can_read_chinese()?
                "玄慈雙手合十，揖身道曰：「這位施主對不起，少林禁地只有少林武僧才能進去。」\n":
			"Sorry, that is for monk only.\n" );
		return 1;
	}
	
  if( (int)this_player()->query("alignment")<-200 && present("shan chi") ) {
		write( can_read_chinese()?
"玄慈怒目而視道曰：「身為少林武僧在外為非做歹，還想回來學武藝!!!」\n":
			"Get out of here!!!\n" );
		return 1;
	}
	return 0;

}
