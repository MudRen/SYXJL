// /clone/board/kedian_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("留言板", ({ "board" }) );
        set("location", "/d/chang'an/zhonglouerceng");
        set("board_id", "ca_b");
	set("long", "有有用的话就往这里说，乱灌水杀无赦。\n" );

	setup();

          set("capacity", 1000);
	replace_program(BULLETIN_BOARD);

}



