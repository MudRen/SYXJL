// /clone/board/wudang_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("�����������԰�", ({ "board" }) );
         set("location", "/d/dali/wfdating");
        set("board_id", "dali_b");
        set("long", "����һ��������μҵ��ӽ��������԰塣\n" );
	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}



