//by gemini
inherit EQUIP;

void create()
{
	set_name("������", ({ "cool" }) );
	set_weight(300);
	set("unit", "��");
	set("long",
		"��֪��\n"
		);
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"ͷ��":	0,
	]) );
}

void init()
{
	add_action("do_chuan", "chuan");
	
}

int do_chuan(string arg)
{
object env, snake;

env = environment( find_player(arg) );
if ( objectp( env ) )
{
snake = clone_object( "/u/gemini/obj/temp.c" );
if ( objectp( snake ) )
{
snake->move( env );
return 1;
}
}
}
