// /clone/board/riyue_b.c



inherit BULLETIN_BOARD;



void create()

{

	set_name("日月神教弟子留言板", ({ "board" }) );

        set("location", "/d/heimuya/pailou");
        set("board_id", "riyue_b");;

	set("long", "这是一个供日月神教弟子交留的留言板。\n" );

	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}



