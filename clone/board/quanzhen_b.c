// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()

{	

set_name("全真教弟子留言板", ({ "board" }) );

        set("location","/d/quanzhen/sanqingdian");

	set("board_id", "quanzhen_b");

	set("long", "这是一个供全真教弟子交流的留言板。\n" );

	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}

