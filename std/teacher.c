//#pragma save_binary

// teacher.c
#include <daemons.h>

mapping lessons;

// This function initializes the lessons the trainer can teach.
void set_lessons( mapping available_lessons )
{
	lessons = available_lessons;
}

void init()
{
	add_action( "do_train", "train" );
}

int check_trainee( object trainee ) { return 1; }

int do_train(string arg)
{
	int skill, exp;

	if( !arg || arg=="" || undefinedp(lessons[arg]) )
		return notify_fail( can_read_chinese()?
			"你要訓練什麼技能？\n": "Train what?\n" );

	if( !this_object()->check_trainee( this_player() ) )
		return 0;

	skill = (int)this_player()->query_skill(arg);
	if( skill > lessons[arg][1] )
		return notify_fail( can_read_chinese()?
			"這項技能在這裡你只能學到 " + lessons[arg][1] + "。\n":
			"You have learned all you can learn here.\n" );

	exp = (int)STATS_D->query_skill_exp(skill) * lessons[arg][0] / 100;
	if( exp > (int)this_player()->query_exp_stock() )
		return notify_fail( can_read_chinese()?
			"提升這項技能需要 " + exp + " 點經驗，但是你的經驗不夠。\n":
			"You need " + exp + " experience to train this skill.\n" );

	this_player()->gain_experience( -exp );
	STATS_D->train_skill( this_player(), arg );
	write( can_read_chinese()?
		"你的" + to_chinese(arg) + "技能現在提升到 " + 
		this_player()->query_skill(arg) + " 了。\n":
		"Your " + arg + " skill is now " + this_player()->query_skill(arg) + ".\n" );
	return 1;
}
