// /clone/board/wudang_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("镇南王府留言板", ({ "board" }) );
         set("location", "/d/dali/wfdating");
        set("board_id", "dali_b");
        set("long", "这是一个供大理段家弟子交留的留言板。\n" );
	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}



