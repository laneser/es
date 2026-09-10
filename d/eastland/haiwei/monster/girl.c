#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "tea girl", "賣茶姑娘" );
	add( "id", ({ "girl" }) );
	set_short( "賣茶姑娘" );
	set_long(@C_LONG
這位賣茶姑娘看起來大概只有十五、六歲，她笑起來臉上有著甜甜
的酒渦。
C_LONG
   	        );
	set( "gender", "female" );
	set( "race", "human" );
	set( "no_attack", 1 );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"賣茶姑娘愉快地對著你微笑。\n",
		"賣茶姑娘說道: 大爺進來喝杯茶，歇歇腿吧。\n",
		"賣茶姑娘說道: 我們的茶遠近馳名，清涼止渴。\n",
		"賣茶姑娘說道: 歡迎光臨，請這邊坐。\n"
	}) );
        set( "inquiry", ([
	        "diet": "@@ask_diet",
	        "brother": "@@ask_brother"
        ]) );
}
void init()
{
    ::init();
    add_action("do_answer","answer");
}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/diet")) || this_player()->query_temp("fat_quest/diet")<1) {
write(
"賣茶姑娘賞了你一巴掌，罵道: 我身材這麼好? 需要減肥嗎??\n");
}
else {
write(
"\n賣茶姑娘說道: 沒錯，我們是有賣減肥茶，但是我就快下班了，你可不可以明天\n"
"再來??\n");
command("giggle "+(string)this_player()->query("name"));
return 1;
}
}
int ask_brother()
{
if (this_player()->query_temp("fat_quest/diet")<1) {
write(
"賣茶姑娘說道: 你是誰啊? 幹嘛問東問西的...\n");
return 1;
}
else {
write(
"\n賣茶姑娘說道: 沒錯，我是有一個哥哥，叫作安道全，生性刁蠻古怪，從小就不\n"
"太照顧我，一天到晚都幫人治病去；不過因為他是我唯一的哥哥，我也對他很尊敬，\n"
"有一天，他有一個病人送我一顆大珍珠，由於我自小就非常喜歡珍珠，所以他就把珍\n"
"珠送給我，但是他隨口虧了我幾句，我氣不過就離家出走啦，現在想想，我也真是幼\n"
"稚............................\n\n");
call_out("ask_brother1",10,this_player());
return 1;
}
}
int ask_brother1()
{
write(
"賣茶姑娘繼續說道: 你身上有藥味，是我哥叫你來的吧? 他這個人倒還好，只是\n"
"嘴巴太毒了，不過他畢竟是我哥哥，等店裡的生意告一段落，我會回去看看他的\n");
return 1;
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="blue pearl" && name != "pearl ring" && name != "Moon pearl") ) return 1;
	if (name == "pearl ring")
{
     tell_object(me,
@RING
賣茶姑娘接過珍珠戒指，端詳了幾眼，說道: 這是默爾斯人作的假珍珠。你對著光照
照看，就會看到許多小小氣泡。說完，賣茶姑娘把戒指還給你.....
RING
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if (name == "blue pearl")
{     
     tell_object(me,
@BLUE
賣茶姑娘接過藍珍珠，看了幾眼後搖搖頭說道: 這藍珍珠雖然是真品，而且又很漂亮，
可是根據默爾斯人的講法，藍色是因為受到魔法元素汙染的結果，常常把玩，對身體
會有不好的影響，你最好小心一點。說完，賣茶姑娘把戒指還給你.....
BLUE
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if (name == "Moon pearl")
{     
     tell_object(me,
@MOON
賣茶姑娘接過夜明珠，兩眼忽然一亮，開始把玩這顆大珍珠，臉上流露出愛不釋手的
表情........
MOON
	);
	item->remove();
call_out("play_pearl",20,this_player());
	return 1;
}
}		
int play_pearl(object me)
{
write("十分鐘以後，賣茶姑娘終於抬起頭來，說道: 這顆珍珠真不錯，你是要拿來送我的嗎?\n"
      "(answer yes or no)...........\n");
		me->set_temp("fat_quest/diet",2);
        return 1;
}
int do_answer(string arg,object ob1)
{
   if (this_player()->query_temp("fat_quest/diet")<2) return 0;
   if (this_player()->query_temp("fat_quest/get_tea")) return 0;
   if ( !arg || (arg != "yes" && arg != "no")) {
   write(
@ANSWER1
賣茶姑娘罵道: 我要下班了，要還是不要啦.....
ANSWER1
);
return 1;
}
   if ( arg == "yes" ) {
   write(
@ANSWER2
賣茶姑娘笑道，那我就謝謝你啦，對了，你不是要買減肥茶嗎? 我這就送你一份
說完，賣茶姑娘七手八腳的泡了一杯茶給你。
ANSWER2
);
   
   ob1 = new("/d/eastland/liang_shan/obj/diet_tea");
   ob1->move(environment(this_object()));  
   this_player()->set_temp("fat_quest/diet",3);
   this_player()->set_temp("fat_quest/get_tea",1);
return 1;
}
   if ( arg == "no" ) {
   write(
@ANSWER3
賣茶姑娘罵道: 耍我啊，我都快下班了還浪費我時間......說完把珍珠往你頭上
丟去，把你打的鮮血淋漓，珍珠也被打壞了。
ANSWER3
);
   return 1;
}
}